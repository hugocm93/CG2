/*
 * Camera.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vec3.hpp"
#include "Ray.h"
#include <math.h>

typedef Vec3<double> Vec3d;
#define PI 3.141592

class Camera {
public:
	int imageWidth;
	int imageHeight;
	Vec3d* eyePosition;
	Vec3d* centerPosition;
	Vec3d* upVector;
	float apertureAngle;
	float nearPlane;
	float farPlane;

	float df;
	float height;
	float base;
	Vec3d* Xe;
	Vec3d* Ye;
	Vec3d* Ze;

public:
	Camera(Vec3d *eyePosition, Vec3d *refPosition, Vec3d *upVector, float apertureAngle, float nearPlane, float farPlane, float imgWidth, float imgHeight);
	virtual ~Camera();

	/*Returns a ray that passes through a certain point p(x,y) (by reference)*/
	void getRay(int x, int y, Ray* ray);
};

#endif /* CAMERA_H_ */
