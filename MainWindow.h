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
public:
	MainWindow();
	virtual ~MainWindow();
	void show();


private:
	Ihandle* dialog;
	Ihandle* canvas;
	Ihandle* toolBar;
	Ihandle* messageBar;
	Image* image;
	int* widthh;
	int* heightt;
};

#endif /* MAINWINDOW_H_ */
