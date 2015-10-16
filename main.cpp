/*
 * main.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: hugocm93
 */

#include "MainWindow.h"

int main(int argc, char* argv[]){
	std::cout << "Main" << std::endl;

	IupOpen(&argc, &argv);

	IupGLCanvasOpen();

	MainWindow * mainWindow = new MainWindow();

	mainWindow->show();

	IupMainLoop();

	IupClose();

	return IUP_NOERROR;
}



