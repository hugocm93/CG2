/*
 * Scene.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Scene.h"
#include "ColorRGB.h"

#include <iostream>

Scene::Scene(char* fileName){
	std::cout << "Path is " << fileName << std::endl;

}

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}

Image* Scene::render(){
	int w = 400;
	int h = 500;
	Image* image = new Image();
	image->imgCreate(w, h, 3);

	ColorRGB* lightGray = new ColorRGB(0.8, 0.8, 0.8);
	ColorRGB* darkGray = new ColorRGB(0.5, 0.5, 0.5);

	#define SQUARE 15
	int x,y;
	for (y=0;y<h;y++){
		for (x=0;x<w;x++) {
			if(((y - y%SQUARE)/SQUARE)%2 == 0){
				if(((x - x%SQUARE)/SQUARE)%2 == 0){
					image->imgSetPixel3fv(x,y,lightGray->getColor());
				}
				else{
					image->imgSetPixel3fv(x,y,darkGray->getColor());
				}
			}
			else{
				if(((x - x%SQUARE)/SQUARE)%2 != 0){
					image->imgSetPixel3fv(x,y,lightGray->getColor());
				}
				else{
					image->imgSetPixel3fv(x,y,darkGray->getColor());
				}
			}
		}
	}

	return image;
}
