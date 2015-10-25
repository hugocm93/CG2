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
	virtual Vec3d* computeIntersection(Ray* ray);
	virtual Vec3d* computeNormal(Vec3d* position);
	virtual ColorRGB* getColor();
};

#endif /* OBJECT_H_ */
