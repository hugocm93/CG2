/*
 * Object.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Object.h"
#include "Ray.h"


Object::Object() {
	this->material = NULL;

}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

float Object::computeIntersection(Ray* ray){
	//cout << "ObjectComputeIntersection"<< endl;
	return NULL;
}
Vec3d* Object::computeNormal(Vec3d* position){
	return NULL;
}
ColorRGB* Object::getColorP(void* scene, Ray* ray){
	return this->material->getKd();
}

