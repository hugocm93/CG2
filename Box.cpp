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
	// TODO Auto-generated destructor stub
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
				//std::cout << t << std::endl;
				return t;
			}
		}
	}

	if(y!=-FLT_MAX){
		double t = (((double)y - ray->o->getY())/ray->d->getY());
		if(t>0){
			if((ray->o->getX() + ray->d->getX()*t >= Xmin && ray->o->getX() + ray->d->getX()*t <= Xmax)   &&  (ray->o->getZ() + ray->d->getZ()*t >= Zmin && ray->o->getZ() + ray->d->getZ()*t <= Zmax)){
				//std::cout << t << std::endl;
				return t;
			}
		}
	}

	if(z!=-FLT_MAX){
		double t =  (((double)z - ray->o->getZ())/ray->d->getZ());
		if(t>0){
			if((ray->o->getX() + ray->d->getX()*t >= Xmin && ray->o->getX() + ray->d->getX()*t <= Xmax)  &&  (ray->o->getY() + ray->d->getY()*t >= Ymin && ray->o->getY() + ray->d->getY()*t <= Ymax)){
				//std::cout << t << std::endl;
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

	//position->display();


	if(abs(position->getY() - Ymin) < 1){
		return new Vec3d(0,-1,0);
	}
	else if(abs(position->getY() - Ymax) < 1){
		return new Vec3d(0,1,0);
	}

	if(abs(position->getZ() - Zmin) < 1){
		return new Vec3d(0,0,-1);
	}
	else if(abs(position->getZ() - Zmax) < 1){
		return new Vec3d(0,0,1);
	}

	if(abs(position->getX() - Xmin) <1){
		return new Vec3d(-1,0,0);
	}
	else if(abs(position->getX() == Xmax) < 1){
		return new Vec3d(1,0,0);
	}

}

ColorRGB* Box::getColorP(void* scene, Ray* ray){
	Scene* s =  (Scene*)scene;
	ColorRGB* ambient = s->ambientLightIntensity;
	ColorRGB* kd = this->material->getKd();

	Vec3d P = *ray->o + ((*ray->d)*(ray->t));
	Vec3d* normal = this->computeNormal(&P);
	//normal->display();
	ColorRGB* aux = new ColorRGB(ambient->getColor()[0]*kd->getColor()[0], ambient->getColor()[1]*kd->getColor()[1], ambient->getColor()[2]*kd->getColor()[2]);
	for(unsigned int i = 0; i < s->lights.size() ; i++){
		ColorRGB LL = *s->lights[i]->getIntensity();
		ColorRGB* l = &LL;
		Vec3d L =  *s->lights[i]->getPosition() - P;
		L.normalise();
		//normal->display();
		double nl = Vec3d::dotProduct(*normal,  L);

		aux->increment(l->getColor()[0]*kd->getColor()[0]*nl, l->getColor()[1]*kd->getColor()[1]*nl, l->getColor()[2]*kd->getColor()[2]*nl);
	}
	return aux;
}
