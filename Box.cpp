/*
 * Box.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Box.h"

Box::Box(Material* mat, Vec3d* leftBottomCorner, Vec3d* rightTopCorner){
	this->material = mat;
	this->leftBottomCorner = leftBottomCorner;
	this->rightTopCorner = rightTopCorner;
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

