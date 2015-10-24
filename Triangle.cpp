/*
 * Triangle.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Triangle.h"

Triangle::Triangle(Material* mat, Vec3d* vertex1, Vec3d* vertex2, Vec3d* vertex3, Vec3d* textureVertex1, Vec3d* textureVertex2, Vec3d* textureVertex3){
	this->material = mat;
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->vertex3 = vertex3;

	this->textureVertex1 = textureVertex1;
	this->textureVertex2 = textureVertex2;
	this->textureVertex3 = textureVertex3;

}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

