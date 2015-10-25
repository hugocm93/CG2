/*
 * Sphere.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Sphere.h"
#include "Ray.h"


Sphere::Sphere(Material* mat, float radius, Vec3d* position){
	this->material = mat;
	this->radius = radius;
	this->position = position;

}

Sphere::~Sphere(){

}

Vec3d* Sphere::computeIntersection(Ray* ray){
	return NULL;
}
Vec3d* Sphere::computeNormal(Vec3d* position){
	return NULL;
}
ColorRGB* Sphere::getColor(){
	return NULL;
}

