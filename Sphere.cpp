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

	//cout << "SphereComputeIntersection"<< endl;
	double a = Vec3d::dotProduct(*ray->d, *ray->d);
	Vec3d temp1 = (*ray->d)*2;
	Vec3d temp2 = *ray->o - *this->position;
	double b = Vec3d::dotProduct(temp1, temp2);
	double c = Vec3d::dotProduct(temp2, temp2) - this->radius*this->radius;

	//cout << "a" << a << endl;
	//cout << "b" << b << endl;
	//cout << "c" << c << endl;
	//temp2.display();
	double delta = b*b - 4*a*c;


	if(delta < 0){
		return 0;
	}
	//cout << "delta  " << delta << endl;
	if(delta == 0){
		double t1 = (-b)/(2*a);
		//cout << t1 << endl;
		return t1;
	}
	else{
		double t1 = (-b + sqrt(delta))/(2*a);
		double t2 = (-b - sqrt(delta))/(2*a);

		if(t1 > 0 && (t1 < t2)){
			cout << t1 << endl;

			Vec3d P = *ray->o + ((*ray->d)*(ray->t));
			double dist = Vec3d::getDistance(P, *this->position);
			//cout << dist <<  endl;

			return t1;
		}
		else if(t2 > 0){


			Vec3d P = *ray->o + ((*ray->d)*(ray->t));
			double dist = Vec3d::getDistance(P, *this->position);
			//cout << dist <<  endl;
			//cout << t2 << endl;
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

ColorRGB* Sphere::getColorP(void* scene, Ray* ray){
	Scene* s =  (Scene*)scene;

	ColorRGB* ambient = s->ambientLightIntensity;
	ColorRGB* kd = this->material->getKd();

	Vec3d P = *ray->o + ((*ray->d)*(ray->t));
	Vec3d* normal = this->computeNormal(&P);
	ColorRGB* aux = new ColorRGB(ambient->getColor()[0]*kd->getColor()[0], ambient->getColor()[1]*kd->getColor()[1], ambient->getColor()[2]*kd->getColor()[2]);
	for(unsigned int i = 0; i < s->lights.size() ; i++){
		ColorRGB LL = *s->lights[i]->getIntensity();
		ColorRGB* l = &LL;
		Vec3d L =  *s->lights[i]->getPosition() - *this->position;
		L.normalise();

		double nl = Vec3d::dotProduct(*normal, L);

		aux->increment(l->getColor()[0]*kd->getColor()[0]*nl, l->getColor()[1]*kd->getColor()[1]*nl, l->getColor()[2]*kd->getColor()[2]*nl);
	}
	return aux;
	return aux;
}

