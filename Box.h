/*
 * Box.h
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#ifndef BOX_H_
#define BOX_H_

#include "Object.h"

class Box: public Object {
private:
	Vec3d* leftBottomCorner;
	Vec3d* rightTopCorner;
public:
	Box(Material* mat, Vec3d* leftBottomCorner, Vec3d* rightTopCorner);
	virtual ~Box();

	virtual double computeIntersection(Ray* ray);
	virtual Vec3d* computeNormal(Vec3d* position);
	virtual ColorRGB* getColorP(void* scene, Ray* ray);
	static float calcSquareArea(Vec3d* p1, Vec3d* p2, Vec3d* p3);
};

#endif /* BOX_H_ */
