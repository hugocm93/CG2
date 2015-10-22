/*
 * MainWindow.cpp
 *
 *  Created on: Oct 16, 2015
 *      Author: hugocm93
 */

#include "MainWindow.h"
#include "Scene.h"

MainWindow::MainWindow() {

	/*Create canvas, define the canvas size and bind callbacks*/
	Ihandle* canvas = IupGLCanvas(NULL);
	IupSetfAttribute(canvas, IUP_RASTERSIZE, "%dx%d", 640, 480);
	IupSetCallback(canvas, IUP_ACTION, (Icallback)repaint_cb);
	IupSetCallback(canvas, IUP_RESIZE_CB, (Icallback)resize_cb);
	this->canvas = canvas;

	/*Create message bar at the bottom of the window*/
	Ihandle* msg = IupLabel("Message...");       /* label as a msg bar */
	IupSetfAttribute(msg,IUP_RASTERSIZE,"x%d",20);     /* define height in pixels */
	IupSetAttribute(msg,"EXPAND","HORIZONTAL");
	this->messageBar = msg;

	/*Create toolBar*/
	Ihandle* toolbar;
	Ihandle* load = IupSButton("img/file_open.bmp","Load a scene",(Icallback) load_cb);
	Ihandle* render = IupSButton("img/render.bmp","Render the scene",(Icallback) render_cb);
	Ihandle* save = IupSButton("img/file_save.bmp", "Save rendered scene into a BMP file", (Icallback)save_cb);
	toolbar=IupHbox(load,render,save, NULL);
	this->toolBar = toolbar;

	/*Insert componets into the vBox*/
	Ihandle * vBox = IupVbox(this->toolBar, this->canvas,this->messageBar, NULL);

	/*Create the dialog and set its attributes*/
	Ihandle* dialog = IupDialog(vBox);
	IupSetAttribute(dialog, "TITLE", "Ray Tracing");
	IupSetAttribute(dialog, "canvas", (const char *)canvas);
	IupSetAttribute(dialog, "dialog", (const char *)dialog);
	IupSetAttribute(dialog, "image", (const char *)image);
	IupSetAttribute(dialog, "messageBar", (const char *)messageBar);
	IupSetAttribute(dialog, "CLOSE_CB", "exit_cb");
	IupSetFunction("exit_cb", (Icallback) exit_cb);
	IupSetAttribute(dialog, "RESIZE", "NO");
	this->dialog = dialog;

	/*Initialize image*/
	this->image = NULL;
}

MainWindow::~MainWindow() {
	delete image;
}

Ihandle* MainWindow::IupSButton(char const * image_file, char const * tip, Icallback callback)
{
	Ihandle* button = IupButton(NULL, NULL);
	IupSetAttribute(button, "IMAGE", image_file);
	IupSetAttribute(button,"TIP",tip);
	IupSetCallback(button, "ACTION", callback);

	return button;
}

void MainWindow::IupCanvasResize( Ihandle* canvas, Ihandle* parent_dialog, int new_width, int new_height )
{
	char buffer[64];
	sprintf(buffer,"%dx%d",new_width,new_height);
	IupStoreAttribute(canvas, IUP_RASTERSIZE, buffer);
	IupSetAttribute(parent_dialog, IUP_RASTERSIZE, NULL);
	IupShowXY(parent_dialog, IUP_CENTER, IUP_CENTER);
}

int MainWindow::repaint_cb(Ihandle *self)
{
	std::cout << "repaint" << std::endl;

	int x,y;
	IupGLMakeCurrent(self);                /* all OpenGL primitives will be directed to this canvas */
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);  /* dark grey color in the RGBA mode A is the alpha channel (ignore) */
	glClear(GL_COLOR_BUFFER_BIT);          /* clear the color buffer */

	Image* image = (Image*)IupGetAttribute(self, (const char*) "image");

	if (image!=NULL)
	{
		int h = image->imgGetHeight();
		int w = image->imgGetWidth();

		/* assing to each pixel of the canvas the color of the corresponding pixel in the image */
		glBegin(GL_POINTS);
		for (y=0;y<h;y++) {
			for (x=0;x<w;x++) {
				float r,g,b;
				image->imgGetPixel3f(x,y,&r,&g,&b); /* gets the RGB value the pixel (x,y) */
				glColor3f(r,g,b);        /* define a current color in OpenGL */
				glVertex2i(x,y);         /* paint the pixel */
			}

		}
		glEnd();
	}
	IupGLSwapBuffers(self);  /* change the back buffer with the front buffer */
	return IUP_DEFAULT; /* returns the control to the main loop */
}


/* function called in the event of changes in the width or in the height of the canvas */
int MainWindow::resize_cb(Ihandle *self, int new_width, int new_height)
{
	std::cout << "resize" << std::endl;

	IupGLMakeCurrent(self);  /* Make the canvas current in OpenGL */

	/* define the entire canvas as the viewport  */
	glViewport(0,0,new_width,new_height);

	/* transformation applied to each vertex */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();           /* identity, i. e. no transformation */

	/* projection transformation (orthographic in the xy plane) */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0.0, (GLsizei)(new_width), 0.0, (GLsizei)(new_height));  /* window of interest [0,w]x[0,h] */

	/* update canvas size and repaint */
	Ihandle* canvas = (Ihandle*)IupGetAttribute(self, (const char*) "canvas");
	repaint_cb(canvas);

	return IUP_DEFAULT; /* return to the IUP main loop */
}

int MainWindow::save_cb(Ihandle *ih)
{
	/*Update message bar*/
	Ihandle* msg = (Ihandle*)IupGetAttribute(ih, (const char*)"messageBar");
	IupSetfAttribute(msg, "TITLE", "Save callback");

	/*Open save dialog*/
	Ihandle* getfile = IupFileDlg();
	char* filename = NULL;
	IupSetAttribute(getfile, IUP_TITLE, "Save a rendered scene"  );
	IupSetAttribute(getfile, IUP_DIALOGTYPE, IUP_SAVE);
	IupSetAttribute(getfile, IUP_FILTER, "*bmp");
	IupPopup(getfile, IUP_CENTER, IUP_CENTER);
	filename = IupGetAttribute(getfile, IUP_VALUE);

	if (!filename) {
		IupSetfAttribute(msg, "TITLE", "Save failed");
		return IUP_DEFAULT;
	}

	/*Save the image*/
	Image* image = (Image*)IupGetAttribute(ih, (const char*)"image");
	if(image==NULL){
		IupSetfAttribute(msg, "TITLE", "Save failed. No image to save.");
		return IUP_DEFAULT;
	}
	image->imgWriteBMP(filename);

	return IUP_DEFAULT;
}

int MainWindow::load_cb(Ihandle* ih)
{
	/*Update message bar*/
	Ihandle* msg = (Ihandle*)IupGetAttribute(ih, (const char*)"messageBar");
	IupSetfAttribute(msg, "TITLE", "Load callback");

	/*Open load file dialog*/
	Ihandle* getfile = IupFileDlg();
	char* filename = NULL;
	IupSetAttribute(getfile, IUP_TITLE, "Load a scene"  );
	IupSetAttribute(getfile, IUP_DIALOGTYPE, IUP_OPEN);
	IupSetAttribute(getfile, IUP_FILTER, "*rt5");
	IupPopup(getfile, IUP_CENTER, IUP_CENTER);
	filename = IupGetAttribute(getfile, IUP_VALUE);

	if (!filename) {
		IupSetfAttribute(msg, "TITLE", "Selection failed");
		return IUP_DEFAULT;
	}

	/*Create scene and set it as an attribute of the dialog*/
	Scene* scene = new Scene(filename);
	Ihandle* dialog = (Ihandle*)IupGetAttribute(ih, "dialog");
	IupSetAttribute(dialog, "scene", (const char *)scene);

	IupSetfAttribute(msg, "TITLE", "Scene loaded. Click the render button.");

	return IUP_DEFAULT;
}

int MainWindow::exit_cb(Ihandle* ih)
{
	printf("Function to free memory and do finalizations...\n");
	return IUP_CLOSE;
}

int MainWindow::render_cb(Ihandle* ih)
{
	/*Retrieve scene from the dialog and render the scene*/
	Scene* scene = (Scene*)IupGetAttribute(ih, (const char*)"scene");
	if(scene==NULL){
		/*Update message bar*/
		Ihandle* msg = (Ihandle*)IupGetAttribute(ih, (const char*)"messageBar");
		IupSetfAttribute(msg, "TITLE", "Error rendering the scene. It was not loaded.");

		return IUP_DEFAULT;
	}

	/*Render the scene into an image*/
	Image* renderedScene = scene->render();

	/*Retrieve canvas*/
	Ihandle* canvas = (Ihandle*)IupGetAttribute(ih, "canvas");

	/*Retrieve dialog and reset its image*/
	Ihandle* dialog = (Ihandle*)IupGetAttribute(ih, "dialog");
	IupSetAttribute(dialog, "image", (const char *)renderedScene);
	repaint_cb(canvas);

	/* update canvas size and repaint */
	IupCanvasResize(canvas,dialog,renderedScene->imgGetWidth(),renderedScene->imgGetHeight());
	repaint_cb(canvas);

	/*Update message bar*/
	Ihandle* msg = (Ihandle*)IupGetAttribute(ih, (const char*)"messageBar");
	IupSetfAttribute(msg, "TITLE", "Scene rendered");

	return IUP_DEFAULT;
}

void MainWindow::show(){
	IupShowXY(this->dialog, IUP_CENTER, IUP_CENTER);

}

void MainWindow::hide(){
	IupHide(this->dialog);

}




