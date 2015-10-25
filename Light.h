/*
 * Light.h
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Vec3.hpp"
#include "ColorRGB.h"

typedef Vec3<double> Vec3d;

class Light {
private:
	Vec3d* position;
	ColorRGB* intensity;

public:
	Light(Vec3d* position, ColorRGB* intensity);
	virtual ~Light();

	Vec3d* getPosition();
	ColorRGB* getIntensity();
};

#endif /* LIGHT_H_ */
