/*
 * Sphere.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Sphere.h"

Sphere::Sphere(Material* mat, float radius, Vec3d* position){
	this->material = mat;
	this->radius = radius;
	this->position = position;

}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

