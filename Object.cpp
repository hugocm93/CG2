/*
 * Object.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Object.h"
#include "Ray.h"
#include "Scene.h"


Object::Object() {
	this->material = NULL;

}

Object::~Object() {

}

double Object::computeIntersection(Ray* ray){
	return 0;
}
Vec3d* Object::computeNormal(Vec3d* position){
	return NULL;
}
ColorRGB* Object::getColorP(void* scene, Ray* ray){
	Scene* s =  (Scene*)scene;
	ColorRGB* ambient = s->ambientLightIntensity;
	ColorRGB* kd = this->material->getKd();
	Vec3d P = *ray->o + ((*ray->d)*(ray->t));
	Vec3d* normal = this->computeNormal(&P);
	ColorRGB* aux = new ColorRGB(ambient->getColor()[0]*kd->getColor()[0], ambient->getColor()[1]*kd->getColor()[1], ambient->getColor()[2]*kd->getColor()[2]);

	for(unsigned int i = 0; i < s->lights.size() ; i++){
		Vec3d specificPoint = this->getSpecificPoint(ray);
		ColorRGB* l = s->lights[i]->getIntensity();
		Vec3d L =  *s->lights[i]->getPosition() - specificPoint;
		L.normalise();
		double nl = Vec3d::dotProduct(*normal, L);
		aux->increment(l->getColor()[0]*kd->getColor()[0]*nl, l->getColor()[1]*kd->getColor()[1]*nl, l->getColor()[2]*kd->getColor()[2]*nl);
	}

	return aux;
}

Vec3d Object::getSpecificPoint(Ray* ray){
	Vec3d aux;
	return aux;
}


