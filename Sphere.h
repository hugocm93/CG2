/*
 * Sphere.h
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Vec3.hpp"
#include "Object.h"
#include "Ray.h"
#include "Scene.h"

class Sphere: public Object {
private:
	double radius;
	Vec3d* position;
public:
	Sphere(Material* mat, double radius, Vec3d* position);
	virtual ~Sphere();
	virtual double computeIntersection(Ray* ray);
	virtual Vec3d* computeNormal(Vec3d* position);
	virtual Vec3d getSpecificPoint(Ray* ray);
	//virtual ColorRGB* getColorP(void* scene, Ray* ray);
};

#endif /* SPHERE_H_ */
