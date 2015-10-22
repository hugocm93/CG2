/*
 * Triangle.h
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Object.h"

class Triangle: public Object {
private:
	Material* material;
	Vec3d vertex1;
	Vec3d vertex2;
	Vec3d vertex3;

	/*Following vec3s are used as vec2s*/
	Vec3d textureVertex1;
	Vec3d textureVertex2;
	Vec3d textureVertex3;
public:
	Triangle();
	virtual ~Triangle();
};

#endif /* TRIANGLE_H_ */