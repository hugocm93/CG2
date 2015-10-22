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

class Sphere: public Object {
private:
	Material* material;
	float ray;
	Vec3d position;
public:
	Sphere();
	virtual ~Sphere();
};

#endif /* SPHERE_H_ */
