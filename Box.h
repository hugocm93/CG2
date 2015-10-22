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
	Material* material;
	Vec3d leftBottomCorner;
	Vec3d rightTopCorner;
public:
	Box();
	virtual ~Box();
};

#endif /* BOX_H_ */