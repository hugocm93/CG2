/*
 * Camera.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vec3.hpp"

typedef Vec3<double> Vec3d;

class Camera {
private:
	Vec3d eyePosition;
	Vec3d refPosition;
	Vec3d upVector;
	float apertureAngle;
	float nearPlane;
	float farPlane;
	int imageWidth;
	int imageHeight;
public:
	Camera();
	virtual ~Camera();
};

#endif /* CAMERA_H_ */
