/*
 * Scene.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <list>
#include "Image.h"
#include "ColorRGB.h"
#include "Texture.h"
#include "Camera.h"
#include "Material.h"
#include "Light.h"
#include "Object.h"

using namespace std;

class Scene {

private:
	ColorRGB* backGroundColor;
	ColorRGB* ambientLightIntensity;
	Texture* texture;

	Camera* camera;
	list<Material> materials;
	list<Light> lights;
	list<Object> objects;

public:
	Scene(char* fileName);
	virtual ~Scene();
	Image* render();

};

#endif /* SCENE_H_ */
