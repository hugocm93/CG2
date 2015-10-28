/*
 * Box.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Box.h"
#include "Ray.h"
#include "Scene.h"
#include <cmath>

Box::Box(Material* mat, Vec3d* leftBottomCorner, Vec3d* rightTopCorner){
	this->material = mat;
	this->leftBottomCorner = leftBottomCorner;
	this->rightTopCorner = rightTopCorner;
}

Box::~Box() {

}

double Box::computeIntersection(Ray* ray){
	double Xmin, Xmax;
	double Ymin, Ymax;
	double Zmin, Zmax;

	Xmin = this->leftBottomCorner->getX();
	Ymin = this->leftBottomCorner->getY();
	Zmin = this->leftBottomCorner->getZ();

	Xmax = this->rightTopCorner->getX();
	Ymax = this->rightTopCorner->getY();
	Zmax = this->rightTopCorner->getZ();

	double x = -FLT_MAX, y = -FLT_MAX, z = -FLT_MAX;

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
	else if(ray->d->getZ() < 0){
		z = Zmax;
	}

	if(x!=-FLT_MAX){
		double t = (((double)x - ray->o->getX())/ray->d->getX());
		if(t>0){

			if((ray->o->getY() + ray->d->getY()*t >= Ymin && ray->o->getY() + ray->d->getY()*t <= Ymax)  &&  (ray->o->getZ() + ray->d->getZ()*t >= Zmin && ray->o->getZ() + ray->d->getZ()*t <= Zmax)){
				return t;
			}
		}
	}

	if(y!=-FLT_MAX){
		double t = (((double)y - ray->o->getY())/ray->d->getY());
		if(t>0){
			if((ray->o->getX() + ray->d->getX()*t >= Xmin && ray->o->getX() + ray->d->getX()*t <= Xmax)   &&  (ray->o->getZ() + ray->d->getZ()*t >= Zmin && ray->o->getZ() + ray->d->getZ()*t <= Zmax)){
				return t;
			}
		}
	}

	if(z!=-FLT_MAX){
		double t =  (((double)z - ray->o->getZ())/ray->d->getZ());
		if(t>0){
			if((ray->o->getX() + ray->d->getX()*t >= Xmin && ray->o->getX() + ray->d->getX()*t <= Xmax)  &&  (ray->o->getY() + ray->d->getY()*t >= Ymin && ray->o->getY() + ray->d->getY()*t <= Ymax)){
				return t;
			}
		}
	}



	return 0;
}
Vec3d*  Box::computeNormal(Vec3d* position){
	double Xmin, Xmax;
	double Ymin, Ymax;
	double Zmin, Zmax;

	Xmin = this->leftBottomCorner->getX();
	Ymin = this->leftBottomCorner->getY();
	Zmin = this->leftBottomCorner->getZ();

	Xmax = this->rightTopCorner->getX();
	Ymax = this->rightTopCorner->getY();
	Zmax = this->rightTopCorner->getZ();


#define DELTA 1
	if(abs(position->getY() - Ymin) < DELTA){
		return new Vec3d(0,-1,0);
	}
	else if(abs(position->getY() - Ymax) < DELTA){
		return new Vec3d(0,1,0);
	}

	if(abs(position->getZ() - Zmin) < DELTA){
		return new Vec3d(0,0,-1);
	}
	else if(abs(position->getZ() - Zmax) < DELTA){
		return new Vec3d(0,0,1);
	}

	if(abs(position->getX() - Xmin) <DELTA){
		return new Vec3d(-1,0,0);
	}
	else if(abs(position->getX() == Xmax) < DELTA){
		return new Vec3d(1,0,0);
	}
	else return new Vec3d(0,0,0);
}

Vec3d Box::getSpecificPoint(Ray* ray){
	Vec3d P = *ray->o + ((*ray->d)*(ray->t));
	return P;
}
