/*
 * MainWindow.cpp
 *
 *  Created on: Oct 16, 2015
 *      Author: hugocm93
 */

#include "MainWindow.h"


Ihandle* IupSButton(char* image_file, char* tip, Icallback callback)
{
	Ihandle* button = IupButton(NULL, NULL);
	IupSetAttribute(button, "IMAGE", image_file);
	IupSetAttribute(button,"TIP",tip);
	IupSetCallback(button, "ACTION", callback);

	return button;
}

int repaint_cb(Ihandle *self)
{
	std::cout << "repaint" << std::endl;

	int x,y;
	IupGLMakeCurrent(self);                /* all OpenGL primitives will be directed to this canvas */
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);  /* dark grey color in the RGBA mode A is the alpha channel (ignore) */
	glClear(GL_COLOR_BUFFER_BIT);          /* clear the color buffer */

	Image* image = (Image*)IupGetAttribute(self, (const char*) "image");

	if (image!=NULL)
	{
		int h = image->imgGetHeight(image);
		int w = image->imgGetWidth(image);
		/* assing to each pixel of the canvas the color of the corresponding pixel in the image */
		glBegin(GL_POINTS);
		for (y=0;y<h;y++) {
			for (x=0;x<w;x++) {
				float r,g,b;
				image->imgGetPixel3f(image,x,y,&r,&g,&b); /* gets the RGB value the pixel (x,y) */
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
int resize_cb(Ihandle *self, int new_width, int new_height)
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

	std::cout << "11" << std::endl;

	Ihandle* canvas = (Ihandle*)IupGetAttribute(self, (const char*) "canvas");
	int* width = (int*)IupGetAttribute(self, (const char*) "width");
	int* height = (int*)IupGetAttribute(self, (const char*) "height");

	std::cout << "22" << std::endl;

	/* update canvas size and repaint */
	int aux1 = (int)malloc(sizeof(int));
	int aux2 = (int)malloc(sizeof(int));
	aux1=new_width;
	aux2=new_height;
	width=&aux1;
	height=&aux2;
	repaint_cb(canvas);

	std::cout << "33" << std::endl;

	return IUP_DEFAULT; /* return to the IUP main loop */
}

int save_cb(Ihandle *ih)
{
	Ihandle* msg = (Ihandle*)IupGetAttribute(ih, (const char*)"messageBar");
	IupSetfAttribute(msg, "TITLE", "Save call back");

	Ihandle* getfile = IupFileDlg();
	char* filename = NULL;
	IupSetAttribute(getfile, IUP_TITLE, "Save File"  );
	IupSetAttribute(getfile, IUP_DIALOGTYPE, IUP_SAVE);
	IupSetAttribute(getfile, IUP_FILTER, "*rt5");
	IupSetAttribute(getfile, IUP_FILTERINFO, "Save a scene" );
	IupPopup(getfile, IUP_CENTER, IUP_CENTER);
	filename = IupGetAttribute(getfile, IUP_VALUE);

	if (!filename) {
		IupSetfAttribute(msg, "TITLE", "Save failed");
		return IUP_DEFAULT;
	}

	Image* image = (Image*)IupGetAttribute(ih, (const char*)"image");
	image->imgWriteBMP(filename, image);

	IupSetfAttribute(msg, "TITLE", "Count call back");
	return IUP_DEFAULT;
}

int load_cb(Ihandle* ih)
{
	Ihandle* msg = (Ihandle*)IupGetAttribute(ih, (const char*)"messageBar");
	IupSetfAttribute(msg, "TITLE", "Save call back");

	Ihandle* getfile = IupFileDlg();
	char* filename = NULL;
	IupSetAttribute(getfile, IUP_TITLE, "Load a scene"  );
	IupSetAttribute(getfile, IUP_DIALOGTYPE, IUP_OPEN);
	IupSetAttribute(getfile, IUP_FILTER, "*bmp");
	IupSetAttribute(getfile, IUP_FILTERINFO, "Load a scene" );
	IupPopup(getfile, IUP_CENTER, IUP_CENTER);
	filename = IupGetAttribute(getfile, IUP_VALUE);

	if (!filename) {
		IupSetfAttribute(msg, "TITLE", "Selection failed");
		return IUP_DEFAULT;
	}

	Image* image = (Image*)IupGetAttribute(ih, (const char*)"image");

	Ihandle* canvas = (Ihandle*)IupGetAttribute(ih, (const char*)"canvas");

	Ihandle* dialog = (Ihandle*)IupGetAttribute(ih, (const char*)"dialog");


	if (image!=NULL) image->imgDestroy(image);

	std::cout << "111"<< std::endl;
	image=image->imgReadBMP(filename);  /* loads the image */
	if (image!=NULL) {
		std::cout << "222"<< std::endl;
		int width = image->imgGetWidth(image);
		int height = image->imgGetHeight(image);

		std::cout << "333"<< std::endl;
		char buffer[64];
		sprintf(buffer,"%dx%d",width,height);
		IupStoreAttribute(canvas, IUP_RASTERSIZE, buffer);
		IupSetAttribute(dialog, IUP_RASTERSIZE, NULL);
		IupShowXY(dialog, IUP_CENTER, IUP_CENTER);

		IupSetAttribute(dialog, "image", (const char*)image);

		repaint_cb(canvas);
		IupSetfAttribute(msg, "TITLE", "%s", filename);
	} else
		IupSetfAttribute(msg, "TITLE", "Can't open %s", filename);


	return IUP_DEFAULT;
}

int exit_cb(Ihandle* ih)
{
	printf("Function to free memory and do finalizations...\n");
	return IUP_CLOSE;
}


MainWindow::MainWindow() {

	std::cout << "Begin MainWindow" << std::endl;

	Ihandle* canvas = IupGLCanvas(NULL);        /* create a canvas  */
	IupSetfAttribute(canvas, IUP_RASTERSIZE, "%dx%d", 640, 480);  /* define the initial size in pixels */
	IupSetAttribute(canvas,IUP_BUFFER,IUP_DOUBLE);      /* define that this OpenGL _canvas has double buffer (front and back) */

	std::cout << 1 << std::endl;

	/* bind callback actions with callback functions */
	IupSetCallback(canvas, IUP_ACTION, (Icallback)repaint_cb);
	IupSetCallback(canvas, IUP_RESIZE_CB, (Icallback)resize_cb);
	this->canvas = canvas;

	std::cout << "2" << std::endl;

	Ihandle* msg = IupLabel("Message...");       /* label as a msg bar */
	IupSetfAttribute(msg,IUP_RASTERSIZE,"x%d",20);     /* define height in pixels */
	IupSetAttribute(msg,"EXPAND","HORIZONTAL");
	this->messageBar = msg;

	std::cout << "3" << std::endl;

	Ihandle* toolbar;
	Ihandle* load = IupSButton("img/file_open.bmp","load a scene",(Icallback) load_cb);
	Ihandle* save = IupSButton("img/file_save.bmp", "save image in a BMP file", (Icallback)save_cb);
	toolbar=IupHbox(load,save, NULL);
	this->toolBar = toolbar;
	Ihandle * vBox = IupVbox(this->toolBar, this->canvas,this->messageBar, NULL);
	std::cout << "4" << std::endl;

	Ihandle* dialog = IupDialog(vBox);
	IupSetAttribute(dialog, "TITLE", "Ray Tracing");
	IupSetAttribute(dialog, "CLOSE_CB", "exit_cb");
	IupSetAttribute(dialog, "RESIZE", "NO");
	IupSetFunction("exit_cb", (Icallback) exit_cb);
	IupSetAttribute(dialog, "canvas", (const char *)canvas);
	IupSetAttribute(dialog, "dialog", (const char *)dialog);
	IupSetAttribute(dialog, "width", (const char *)widthh);
	IupSetAttribute(dialog, "height", (const char *)heightt);
	IupSetAttribute(dialog, "image", (const char *)image);
	IupSetAttribute(dialog, "messageBar", (const char *)messageBar);

	this->dialog = dialog;

	std::cout << "5" << std::endl;

	IupMap(this->dialog);

	std::cout << "End MainWindow" << std::endl;

}

MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}

void MainWindow::show(){
	IupShowXY(this->dialog, IUP_CENTER, IUP_CENTER);

}




