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

