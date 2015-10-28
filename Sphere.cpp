/*
 * Sphere.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Sphere.h"
#include "Scene.h"
#include "Ray.h"


Sphere::Sphere(Material* mat, double radius, Vec3d* position){
	this->material = mat;
	this->radius = radius;
	this->position = position;

}

Sphere::~Sphere(){

}

double Sphere::computeIntersection(Ray* ray){

	double a = Vec3d::dotProduct(*ray->d, *ray->d);
	Vec3d temp1 = (*ray->d)*2;
	Vec3d temp2 = *ray->o - *this->position;
	double b = Vec3d::dotProduct(temp1, temp2);
	double c = Vec3d::dotProduct(temp2, temp2) - this->radius*this->radius;

	double delta = b*b - 4*a*c;

	if(delta < 0){
		return 0;
	}

	if(delta == 0){
		double t1 = (-b)/(2*a);

		return t1;
	}
	else{
		double t1 = (-b + sqrt(delta))/(2*a);
		double t2 = (-b - sqrt(delta))/(2*a);

		if(t1 > 0 && (t1 < t2)){

			return t1;
		}
		else if(t2 > 0){

			return t2;
		}

	}
	return 0;
}
Vec3d* Sphere::computeNormal(Vec3d* position){
	Vec3d normal =  *position - *this->position;
	normal.normalise();
	return new Vec3d(normal.getX(), normal.getY(), normal.getZ());
}

Vec3d Sphere::getSpecificPoint(Ray* ray){
	return *this->position;
}
ColorRGB* Sphere::getTexturePixel(Ray* ray, Material* mat){
	Vec3d aux = *ray->o + ((*ray->d)*(ray->t));
	float theta = atan(aux.getY()/(aux.getX()+1));
	float phi = sqrt(pow(aux.getX(),2) + pow(aux.getY(),2)/aux.getZ());

	float u = 0.5*(1 + phi/3.14159);
	float v = theta/3.14159;

	float h = this->material->getTexture()->image->imgGetHeight();
	float w = this->material->getTexture()->image->imgGetWidth();

	float vec[3];
	this->material->getTexture()->image->imgGetPixel3fv((int)(u*w)%(int)w, (int)(v*h)%(int)h, vec);

	return new ColorRGB(vec[0],vec[1],vec[2]);
}

