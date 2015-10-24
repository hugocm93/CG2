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

typedef Vec3<double> Vec3d;

class Object {

protected:
	Material* material;

public:
	Object();
	virtual ~Object();
};

#endif /* OBJECT_H_ */
