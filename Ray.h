/*
 * Ray.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef RAY_H_
#define RAY_H_

#include "Vec3.hpp"
typedef Vec3<double> Vec3d;

class Ray {
private:
	Vec3d* o;
	Vec3d* d;
	float t;
public:
	Ray();
	virtual ~Ray();
};

#endif /* RAY_H_ */
