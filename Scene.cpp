/*
 * Scene.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Scene.h"
#include "ColorRGB.h"
#include "Sphere.h"
#include "Box.h"
#include "Triangle.h"
#include "Ray.h"
#include <float.h>
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
	char* aux1 = (char*)malloc(sizeof(char)*500);
	fscanf(file, "%[^\n]", aux1);
	aux1 = removeGarbage(aux1);
	if(!strcmp(aux1, "RT 5")){
		cout << "The file is not correct." << endl;
	}
	else{
		cout << "The file is correct!" << endl;
	}

	/*Reserve space for the vectors*/
	this->materials.reserve(50);
	this->lights.reserve(50);
	this->objects.reserve(50);

	/*Read the scene parameters*/
	fscanf(file, " %[^ ][^\t]", aux1);
	fscanf(file, "\n");
	if(strcmp(aux1, "SCENE")==0){
		cout << "SCENE" << endl;

		float r = 0, g = 0, b = 0;
		fscanf(file, " %f %f %f", &r, &g, &b);
		this->backGroundColor = new ColorRGB(r,g,b);

		fscanf(file, " %f %f %f", &r, &g, &b);
		this->ambientLightIntensity = new ColorRGB(r,g,b);

		fscanf(file, " %[^\n]", aux1);
		aux1 = removeGarbage(aux1);
		if(strcmp(aux1, "null")==0){
			this->texture = NULL;
		}
		else{

			this->texture = new Texture(aux1);
		}
	}

	/*Read the camera parameters*/
	fscanf(file, " %[^ ][^\t]", aux1);
	fscanf(file, "\n");
	if(strcmp(aux1, "CAMERA")==0){
		cout << "CAMERA" << endl;

		float x, y, z;
		fscanf(file, " %f %f %f", &x, &y, &z);
		Vec3d *eye = new Vec3d(x, y, z);

		fscanf(file, " %f %f %f", &x, &y, &z);
		Vec3d *ref = new Vec3d(x, y, z);

		fscanf(file, " %f %f %f", &x, &y, &z);
		Vec3d *up = new Vec3d(x, y, z);

		float a, n, f;
		fscanf(file, " %f %f %f", &a, &n, &f);

		int w, h;
		fscanf(file, " %d %d", &w, &h);

		this->camera = new Camera(eye, ref, up, a, n, f, w, h);
	}

	do{

		fscanf(file, " %[^ ][^\t]", aux1);
		fscanf(file, "\n");

		/*Read the material parameters*/
		if(strcmp(aux1, "MATERIAL")==0){
			cout << "MATERIAL" << endl;

			char* name = (char*)malloc(sizeof(char)*100);
			fscanf(file,"%[^ ]", name);

			float r, g, b;
			fscanf(file, "%f %f %f",&r, &g, &b );
			ColorRGB* kd = new ColorRGB(r, g, b);
			fscanf(file, "%f %f %f",&r, &g, &b );
			ColorRGB* ks = new ColorRGB(r, g, b);

			float n, k, n2, o;
			fscanf(file, "%f %f %f %f ",&n, &k, &n2, &o );

			fscanf(file,"%[^\n][^ ][^\t]", name);
			name = removeGarbage(name);
			Texture* tex;
			if(strcmp(name, "null")==0){
				tex = NULL;
			}
			else{
				tex = new Texture(name);
			}
			fscanf(file,"\n");

			this->materials.push_back(*new Material(name,kd,ks,n, k, n2, o, tex));
		}

		/*Read the light parameters*/
		if(strcmp(aux1, "LIGHT")==0){
			cout << "LIGHT" << endl;

			float x, y, z;
			fscanf(file, "%f %f %f",&x, &y, &z );
			Vec3d* pos = new Vec3d(x, y, z);

			float r, g, b;
			fscanf(file, "%f %f %f",&r, &g, &b );
			ColorRGB* intensity = new ColorRGB(r, g, b);

			this->lights.push_back(*new Light(pos, intensity));
		}

		/*Read the sphere parameters*/
		if(strcmp(aux1, "SPHERE")==0){
			cout << "SPHERE" << endl;

			char material[40];
			fscanf(file,"%[^ ]", material);

			float r, x, y, z;
			fscanf(file,"%f %f %f %f", &r, &x, &y, &z);

			Material* temp;
			for(unsigned int i = 0; i < this->materials.size() ; i++){
				if(strcmp(this->materials[i].getName().c_str(), material)==0){
					temp = &this->materials[i];
				}
			}

			Vec3d* vec = new Vec3d(x, y, z);
			Sphere* s = new Sphere(temp, r, vec);
			this->objects.push_back((Object)*s);

		}

		/*Read the box parameters*/
		if(strcmp(aux1, "BOX")==0){
			cout << "BOX" << endl;

			char material[40];
			fscanf(file,"%[^ ]", material);

			float x, y, z;
			fscanf(file,"%f %f %f", &x, &y, &z);
			Vec3d* vec1 = new Vec3d(x, y, z);
			fscanf(file,"%f %f %f", &x, &y, &z);
			Vec3d* vec2 = new Vec3d(x, y, z);

			Material* temp;
			for(unsigned int i = 0; i < this->materials.size() ; i++){
				if(strcmp(this->materials[i].getName().c_str(), material)==0){
					temp = &this->materials[i];
				}
			}

			Box* b = new Box(temp, vec1, vec2);
			this->objects.push_back((Object)*b);
		}

		/*Read the triangle parameters*/
		if(strcmp(aux1, "TRIANGLE")==0){
			cout << "TRIANGLE" << endl;

			char material[40];
			fscanf(file,"%[^ ]", material);

			float x, y, z;
			fscanf(file,"%f %f %f", &x, &y, &z);
			Vec3d* vec1 = new Vec3d(x, y, z);
			fscanf(file,"%f %f %f", &x, &y, &z);
			Vec3d* vec2 = new Vec3d(x, y, z);
			fscanf(file,"%f %f %f", &x, &y, &z);
			Vec3d* vec3 = new Vec3d(x, y, z);

			z = 0;
			fscanf(file,"%f %f", &x, &y);
			Vec3d* vec4 = new Vec3d(x, y, z);
			fscanf(file,"%f %f", &x, &y);
			Vec3d* vec5 = new Vec3d(x, y, z);
			fscanf(file,"%f %f", &x, &y);
			Vec3d* vec6 = new Vec3d(x, y, z);

			Material* temp;
			for(unsigned int i = 0; i < this->materials.size() ; i++){
				if(strcmp(this->materials[i].getName().c_str(), material)==0){
					temp = &this->materials[i];
				}
			}

			Triangle* b = new Triangle(temp, vec1, vec2, vec3, vec4, vec5, vec6);
			this->objects.push_back((Object)*b);

		}

		/*Read the mesh parameters*/
		if(strcmp(aux1, "MESH")==0){
			cout << "MESH" << endl;

			//TO-DO: Mesh

		}

	}while(feof(file) != 1);

}
Scene::~Scene() {
	delete backGroundColor;
	delete ambientLightIntensity;
	delete texture;
	delete camera;
}

Image* Scene::blank(){
	int w = 640;
	int h = 480;
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

Image* Scene::render(){
	int w = this->camera->imageWidth;
	int h = this->camera->imageHeight;
	Image* image = new Image();
	image->imgCreate(w, h, 3);

	/*For each pixel on the screen*/
	int x,y;
	for (y=0;y<h;y++){
		for (x=0;x<w;x++) {

			/*Create a ray*/
			Ray* ray = new Ray();
			this->camera->getRay(x, y, ray);

			/*For each object on the screen*/
			Vec3d* min = new Vec3d(DBL_MAX,DBL_MAX,DBL_MAX);
			Object* obj = NULL;
			for(unsigned int i = 0; i < this->objects.size() ; i++){
				/*Calculate the ray's intersection with the object*/
				Vec3d* aux = this->objects[i].computeIntersection(ray);
				if(aux==NULL){
					continue;
				}
				/*Save the shortest intersection*/
				if(aux->getDistance(*new Vec3d(0,0,0), *aux)  < min->getDistance(*new Vec3d(0,0,0), *min)){
					min = aux;
					obj = &this->objects[i];
				}
			}

			if(obj!=NULL){
				//TO-DO: compute color of pixel
			}
			else{
				if(this->texture == NULL){
					image->imgSetPixel3fv(x,y,this->backGroundColor->getColor());
				}
				else{
					float color[3];
					int w2 = this->texture->image->imgGetWidth(), h2 = this->texture->image->imgGetHeight();
					this->texture->image->imgGetPixel3fv(x%w2, y%h2, color);
					image->imgSetPixel3fv(x,y,color);
				}
			}
		}
	}

	return image;
}

char* Scene::removeGarbage(char *str) {
	char* temp = (char*)malloc(sizeof(char)*40);
	int i;
	for(i = 0; i<40 && str[i]!='\n' && str[i]!='\t' && str[i]!='\v' && str[i]!='\t' && str[i]!='\r' && str[i]!='\f' && str[i]!='\0' && str[i]!=' '; i++){
		temp[i] = str[i];
	}
	temp[i] = '\0';

	return temp;
}
