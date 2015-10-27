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

float Sphere::computeIntersection(Ray* ray){

	//cout << "SphereComputeIntersection"<< endl;
	float a = Vec3d::dotProduct(*ray->d, *ray->d);
	Vec3d temp1 = (*ray->d)*2;
	Vec3d temp2 = *ray->o - *this->position;
	float b = Vec3d::dotProduct(temp1, temp2);
	float c = Vec3d::dotProduct(temp2, temp2) - this->radius*this->radius;

	//cout << "a" << a << endl;
	//cout << "b" << b << endl;
	//cout << "c" << c << endl;
	double delta = b*b - 4*a*c;


	if(delta < 0){
		return 0;
	}
	//cout << "delta  " << delta << endl;
	if(delta == 0){
		double t1 = (-b + sqrt(delta))/2*a;
		return t1;
	}
	else{
		double t1 = (-b + sqrt(delta))/2*a;
		double t2 = (-b - sqrt(delta))/2*a;

		if(t1 > 0 && (t1 < t2)){
			return t1;
		}
		else{
			return t2;
		}

	}
}
Vec3d* Sphere::computeNormal(Vec3d* position){
	return NULL;
}
ColorRGB* Sphere::getColor(){
	return this->material->getKd();
}

