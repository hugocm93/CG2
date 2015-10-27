/*
 * Box.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Box.h"
#include "Ray.h"
#include "Scene.h"

Box::Box(Material* mat, Vec3d* leftBottomCorner, Vec3d* rightTopCorner){
	this->material = mat;
	this->leftBottomCorner = leftBottomCorner;
	this->rightTopCorner = rightTopCorner;
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

float Box::computeIntersection(Ray* ray){
	float Xmin, Xmax;
	float Ymin, Ymax;
	float Zmin, Zmax;

	Xmin = this->leftBottomCorner->getX();
	Ymin = this->leftBottomCorner->getY();
	Zmin = this->leftBottomCorner->getZ();

	Xmax = this->rightTopCorner->getX();
	Ymax = this->rightTopCorner->getY();
	Zmax = this->rightTopCorner->getZ();



	float x = -1, y = -1, z = -1;

	if(ray->d->getY() > 0){
		y = Ymin ;
	}
	else if(ray->d->getY() < 0){
		y = Ymax;
	}

	if(ray->d->getX() > 0){
		x = Xmin;
	}
	else if(ray->d->getX() < 0){
		x = Xmax;
	}

	if(ray->d->getZ() > 0){
		z = Zmin;
	}
	else if(ray->d->getY() < 0){
		z = Zmax;
	}

	if(x!=-1){
		float t = (double)x/ray->d->getX();
		if(t>0){

			if((ray->d->getY()*t >= Ymin && ray->d->getY()*t <= Ymax)  &&  (ray->d->getZ()*t >= Zmin && ray->d->getZ()*t <= Zmax)){
				//std::cout << t << std::endl;
				return t;
			}
		}
	}

	if(y!=-1){
		float t = (double)y/ray->d->getY();
		if(t>0){
			if((ray->d->getX()*t >= Xmin && ray->d->getX()*t <= Xmax)  &&  (ray->d->getZ()*t >= Zmin && ray->d->getZ()*t <= Zmax)){
				//std::cout << t << std::endl;
				return t;
			}
		}
	}

	if(z!=-1){
		float t =  (double)z/ray->d->getZ();
		if(t>0){
			if((ray->d->getX()*t >= Xmin && ray->d->getX()*t <= Xmax)  &&  (ray->d->getY()*t >= Ymin && ray->d->getY()*t <= Ymax)){
				//std::cout << t << std::endl;
				return t;
			}
		}
	}

	//std::cout << 0 << std::endl;
	return 0;
}
Vec3d*  Box::computeNormal(Vec3d* position){
	return NULL;
}
