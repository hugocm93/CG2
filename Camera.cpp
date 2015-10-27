/*
 * Camera.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#include "Camera.h"

Camera::Camera(Vec3d *eyePosition, Vec3d *centerPosition, Vec3d *upVector, float apertureAngle, float nearPlane, float farPlane, float imgWidth, float imgHeight){
	this->eyePosition = eyePosition;
	this->centerPosition = centerPosition;
	this->upVector = upVector;
	this->apertureAngle = apertureAngle;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	this->imageWidth = imgWidth;
	this->imageHeight = imgHeight;



	df = nearPlane;
	height = 2*df*tan(apertureAngle*(PI/180.0) * 0.5);
	base = ((float)imgWidth/(float)imgHeight)*height;

	Vec3d temp = (*(eyePosition) - *(centerPosition));
	Ze = new Vec3d(temp.getX(),temp.getY(),temp.getZ());
	Ze->normalise();

	Vec3d temp1 = Vec3d::crossProduct(*upVector, *Ze);
	Xe = new Vec3d(temp1.getX(),temp1.getY(),temp1.getZ());
	Xe->normalise();

	Vec3d temp3 = Vec3d::crossProduct(*Ze, *Xe);
	Ye = new Vec3d(temp3.getX(),temp3.getY(),temp3.getZ());
	Ye->normalise();

//	Xe->display();
//	Ye->display();
//	Ze->display();

}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::getRay(int x, int y, Ray* ray){
	ray->o = eyePosition;

	Vec3d temp1 = (*Ze)*(-df);
	Vec3d temp2 = (*Ye)*(height*(((double)y/(double)imageHeight) - 0.5));
	Vec3d temp3 = (*Xe)*(base*((double)x/(double)imageWidth - 0.5));
	Vec3d temp4 = temp1 + temp2 + temp3;
	ray->d  = new Vec3d(temp4.getX(),temp4.getY(),temp4.getZ());

//	ray->o->display();
	//std::cout << "Display "<< std::endl;
	//temp4.display();
}

