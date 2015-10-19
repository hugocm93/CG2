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
#include "Image.h"

class MainWindow {

	///////////////////////////////Fields of the class

private:
	Ihandle* dialog;
	Ihandle* canvas;
	Ihandle* toolBar;
	Ihandle* messageBar;
	Image* image;

	//////////////////////////////Methods of the class

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

	/*Intern method that makes it easier to create a button*/
	Ihandle* IupSButton(char const * image_file, char const * tip, Icallback callback);

};

#endif /* MAINWINDOW_H_ */
