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

typedef Vec3<double> Vec3d;

class Camera {
public:
	int imageWidth;
	int imageHeight;
private:
	Vec3d* eyePosition;
	Vec3d* refPosition;
	Vec3d* upVector;
	float apertureAngle;
	float nearPlane;
	float farPlane;
public:
	Camera(Vec3d *eyePosition, Vec3d *refPosition, Vec3d *upVector, float apertureAngle, float nearPlane, float farPlane, float imgWidth, float imgHeight);
	virtual ~Camera();
	Ray* getRay(int x, int y);
};

#endif /* CAMERA_H_ */
