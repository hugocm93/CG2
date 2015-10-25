/*
 * Light.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Light.h"

Light::Light(Vec3d* position, ColorRGB* intensity){
	this->position = position;
	this->intensity = intensity;

}

Light::~Light() {
	delete position;
	delete  intensity;
}

Vec3d* Light::getPosition(){
	return this->position;
}
ColorRGB* Light::getIntensity(){
	return this->intensity;
}

