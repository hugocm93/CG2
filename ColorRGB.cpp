/*
 * ColorRGB.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "ColorRGB.h"

ColorRGB::ColorRGB(float r, float g, float b) {
	vector[0] = r;
	vector[1] = g;
	vector[2] = b;
}

ColorRGB::~ColorRGB() {

}

float* ColorRGB::getColor(){
	return &vector[0];
}

void ColorRGB::increment(double r, double g, double b){
	this->vector[0]+=r;
	this->vector[1]+=g;
	this->vector[2]+=b;
}

