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

public:
	ColorRGB* backGroundColor;
	ColorRGB* ambientLightIntensity;
	Texture* texture;
	Camera* camera;
	vector<Material*> materials;
	vector<Light*> lights;
	vector<Object*> objects;

public:
	/*Loads scene from a file*/
	Scene(char* fileName);

	/*Deletes scene*/
	virtual ~Scene();

	/*Renders the scene into and Image*/
	Image* render();

	/*Produces a blank image file to initialize the canvas when the scene is loaded*/
	Image* blank();

private:
	/*Remove spaces when reading strings*/
	char* removeGarbage(char *str);

};

#endif /* SCENE_H_ */
