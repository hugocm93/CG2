/*
 * Scene.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Scene.h"
#include "ColorRGB.h"
#include <cstring>
#include <iostream>
#include <cstdio>

Scene::Scene(char* fileName){
	//Initialize fields

	char aux1[20];
	FILE* file = fopen(fileName, "r");

	fscanf(file, "%[^\n]", aux1);

	if(!strcmp(aux1, "RT 5")){
		cout << "The file is not correct." << endl;
	}
	else{
		cout << "The file is correct!" << endl;
	}

	fscanf(file, " %[^ ]", aux1);

	cout << '#'<< aux1 << '#'<< endl;

	if(strcmp(aux1, "SCENE")==0){
		float r, g, b;
		fscanf(file, " %f %f %f", &r, &g, &b);
		printf("wer %f", r); fflush(stdout);
	}

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
			if((y/SQUARE)%2 == 0){
				if((x/SQUARE)%2 == 0){
					image->imgSetPixel3fv(x,y,lightGray->getColor());
				}
				else{
					image->imgSetPixel3fv(x,y,darkGray->getColor());
				}
			}
			else{
				if(((x)/SQUARE)%2 != 0){
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
