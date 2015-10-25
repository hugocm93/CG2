/*
 * MainWindow.h
 *
 *  Created on: Oct 16, 2015
 *      Author: hugocm93
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iup/iup.h>
#include <iup/iupgl.h>
#include <cstdlib>
#include <GL/gl.h>     /* OpenGL functions*/
#include <GL/glu.h>
#include <iostream>
#include "../Image.h"

class MainWindow {

private:
	Ihandle* dialog;
	Ihandle* canvas;
	Ihandle* toolBar;
	Ihandle* messageBar;
	Image* image;

public:
	MainWindow();
	virtual ~MainWindow();

	/*Shows the dialog*/
	void show();

	/*Hides the dialog*/
	void hide();

private:
	/* Callbacks*/
	static int load_cb(Ihandle* ih);
	static int save_cb(Ihandle* ih);
	static int exit_cb(Ihandle* ih);
	static int repaint_cb(Ihandle* ih);
	static int resize_cb(Ihandle *self, int new_width, int new_height);
	static int render_cb(Ihandle* ih);

	/*Intern method that makes it easier to create a button*/
	static Ihandle* IupSButton(char const * image_file, char const * tip, Icallback callback);
	static void IupCanvasResize( Ihandle* canvas, Ihandle* parent_dialog, int new_width, int new_height );

};

#endif /* MAINWINDOW_H_ */
