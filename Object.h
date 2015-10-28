/*
 * Object.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Material.h"
#include "Vec3.hpp"
#include "Ray.h"

typedef Vec3<double> Vec3d;

class Object {

protected:
	Material* material;

public:
	Object();
	virtual ~Object();

	/*Given a ray, this method calculates the intersection with the object and returns the position of the intersection*/
	virtual double computeIntersection(Ray* ray);

	/*Given a position, this method calculates de normal vector at that point*/
	virtual Vec3d* computeNormal(Vec3d* position);

	/*Calculates the color according to a point*/
	virtual ColorRGB* getColorP(void* scene, Ray* ray);

	virtual Vec3d getSpecificPoint(Ray* ray);

	virtual ColorRGB* getTexturePixel(Ray* ray, Material* mat);
};

#endif /* OBJECT_H_ */
