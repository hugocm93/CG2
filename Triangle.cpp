/*
 * Triangle.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Triangle.h"
#include "Ray.h"

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

double Triangle::computeIntersection(Ray* ray){

	return NULL;
}
Vec3d* Triangle::computeNormal(Vec3d* position){
	return NULL;
}

float Triangle::calcArea(Vec3d* p1, Vec3d* p2, Vec3d* p3){
	Vec3d aux1 = *p2 - *p1;
	Vec3d aux2 = *p3 - *p1;
	Vec3d temp = Vec3d::crossProduct(aux1, aux2);
	Vec3d* zero = new Vec3d(0,0,0);

	return Vec3d::getDistance(*zero, temp)/2.0;
}

Vec3d Triangle::getSpecificPoint(Ray* ray){
	Vec3d aux;
	return aux;
}


