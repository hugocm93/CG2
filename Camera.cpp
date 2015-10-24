/*
 * Camera.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Camera.h"

Camera::Camera(Vec3d *eyePosition, Vec3d *refPosition, Vec3d *upVector, float apertureAngle, float nearPlane, float farPlane, float imgWidth, float imgHeight){
	this->eyePosition = eyePosition;
	this->refPosition = refPosition;
	this->upVector = upVector;
	this->apertureAngle = apertureAngle;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	this->imageWidth = imgWidth;
	this->imageHeight = imgHeight;

}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

