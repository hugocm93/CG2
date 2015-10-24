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
#include <locale>

Scene::Scene(char* fileName){

	/*Set encoding defaut for recognizing dots in the float format*/
	std::locale::global( std::locale("C"));

	/*Open file in read mode*/
	FILE* file = fopen(fileName, "r");

	/*Check if file has the rt5 tag*/
	char aux1[20];
	fscanf(file, "%[^\n]", aux1);
	if(!strcmp(aux1, "RT 5")){
		cout << "The file is not correct." << endl;
	}
	else{
		cout << "The file is correct!" << endl;
	}

	/*Read the scene parameters*/
	fscanf(file, " %[^ ]", aux1);
	fscanf(file, "\n");
	if(strcmp(aux1, "SCENE")==0){
		float r = 0, g = 0, b = 0;
		fscanf(file, " %f %f %f", &r, &g, &b);
		this->backGroundColor = new ColorRGB(r,g,b);

		fscanf(file, " %f %f %f", &r, &g, &b);
		this->ambientLightIntensity = new ColorRGB(r,g,b);

		fscanf(file, " %[^\n]", aux1);
		if(strcmp(aux1, "null")==0){
			this->texture = new Texture(NULL);
		}
		else{
			this->texture = new Texture(aux1);
		}
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
