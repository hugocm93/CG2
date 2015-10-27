/*
 * Sphere.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Sphere.h"
#include "Scene.h"
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
		ray->t = 0;
		return 0;
	}
	//cout << "delta  " << delta << endl;
	if(delta == 0){
		float t1 = (-b + sqrt(delta))/2*a;
		ray->t = t1;
		//cout << t1 << endl;
		return t1;
	}
	else{
		float t1 = (-b + sqrt(delta))/2*a;
		float t2 = (-b - sqrt(delta))/2*a;

		if(t1 > 0 && (t1 < t2)){
			ray->t = t1;
			//cout << t1 << endl;
			return t1;
		}
		else{
			ray->t = t2;
			//cout << t2 << endl;
			return t2;
		}

	}
}
Vec3d* Sphere::computeNormal(Vec3d* position){
	Vec3d normal = *position - *this->position;
	normal.normalise();
	return new Vec3d(normal.getX(), normal.getY(), normal.getZ());
}

ColorRGB* Sphere::getColorP(void* scene, Ray* ray){
	Scene* s =  (Scene*)scene;

	ColorRGB* l = s->ambientLightIntensity;
	ColorRGB* kd = this->material->getKd();

	Vec3d P = *ray->o + ((*ray->d)*(ray->t));
	//P.display();
	//cout << ray->t << endl;
	Vec3d* normal = this->computeNormal(&P);
	Vec3d L =  *this->position - *s->lights[0]->getPosition();
	L.normalise();
	//L.display();
	float nl = Vec3d::dotProduct(*normal, L);
	cout << "nl" << nl << endl;
	nl = 1-nl;;
	ColorRGB* aux = new ColorRGB(l->getColor()[0]*kd->getColor()[0]*nl, l->getColor()[1]*kd->getColor()[1]*nl, l->getColor()[2]*kd->getColor()[2]*nl);
	return aux;
}

