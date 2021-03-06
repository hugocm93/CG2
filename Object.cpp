/*
 * Object.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Object.h"
#include "Ray.h"
#include "Scene.h"
#include <cmath>


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
	ColorRGB* ks = this->material->getKs();
	Vec3d P = *ray->o + ((*ray->d)*(ray->t));
	Vec3d* normal = this->computeNormal(&P);
	ColorRGB* aux = new ColorRGB(ambient->getColor()[0]*kd->getColor()[0], ambient->getColor()[1]*kd->getColor()[1], ambient->getColor()[2]*kd->getColor()[2]);
	double especular = this->material->getEspecular();

	for(unsigned int i = 0; i < s->lights.size() ; i++){
		Vec3d specificPoint = this->getSpecificPoint(ray);
		ColorRGB* l = s->lights[i]->getIntensity();
		Vec3d L =  *s->lights[i]->getPosition() - specificPoint;
		L.normalise();

		Vec3d* aux2 = s->camera->eyePosition;
		Vec3d v =  *aux2 - this->getSpecificPoint(ray);
		v.normalise();
		Vec3d r = (*normal)*(Vec3d::dotProduct(v, *normal)*2) - v;
		r.normalise();
		double rl = Vec3d::dotProduct(r, L);

		double nl = Vec3d::dotProduct(*normal, L);


		if(this->material->getTexture()==NULL){

			aux->increment(l->getColor()[0]*kd->getColor()[0]*nl + l->getColor()[0]*ks->getColor()[0]*pow(rl,especular) , l->getColor()[1]*kd->getColor()[1]*nl + l->getColor()[1]*ks->getColor()[1]*pow(rl,especular), l->getColor()[2]*kd->getColor()[2]*nl + l->getColor()[2]*ks->getColor()[2]*pow(rl,especular));
		}
		else{
			//cout << "texture" << endl;
			ColorRGB* aux2 = this->getTexturePixel(ray, this->material);
			aux->increment(l->getColor()[0]*aux2->getColor()[0]*nl + l->getColor()[0]*ks->getColor()[0]*pow(rl,especular) , l->getColor()[1]*aux2->getColor()[1]*nl + l->getColor()[1]*ks->getColor()[1]*pow(rl,especular), l->getColor()[2]*aux2->getColor()[2]*nl + l->getColor()[2]*ks->getColor()[2]*pow(rl,especular));
		}
	}

	return aux;
}

Vec3d Object::getSpecificPoint(Ray* ray){
	Vec3d aux;
	return aux;
}

ColorRGB* Object::getTexturePixel(Ray* ray, Material* mat){

	return new ColorRGB(0,0,0);
}


