/*
 * Scene.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "Image.h"

class Scene {
public:
	Scene(char* fileName);
	virtual ~Scene();
	Image* render();
};

#endif /* SCENE_H_ */
