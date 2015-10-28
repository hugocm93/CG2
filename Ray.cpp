/*
 * Ray.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Ray.h"

Ray::Ray() {
	this->o = new Vec3d(0,0,0);;
	this->d = new Vec3d(0,0,0);
	this->t = 0;
}

Ray::Ray(Vec3d* o, Vec3d* d, float t){
	this->o = o;
	this->d = d;
	this->t = t;

}
Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

