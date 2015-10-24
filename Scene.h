/*
 * Scene.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include "Image.h"
#include "ColorRGB.h"
#include "Texture.h"
#include "Camera.h"
#include "Material.h"
#include "Light.h"
#include "Object.h"
#include "Vec3.hpp"

typedef Vec3<double> Vec3d;

using namespace std;

class Scene {

private:
	ColorRGB* backGroundColor;
	ColorRGB* ambientLightIntensity;
	Texture* texture;

	Camera* camera;
	vector<Material> materials;
	vector<Light> lights;
	vector<Object> objects;

public:
	Scene(char* fileName);
	virtual ~Scene();
	Image* render();

};

#endif /* SCENE_H_ */
