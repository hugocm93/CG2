/*
 * Material.h
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <string>
#include "Texture.h"
#include "ColorRGB.h"

using namespace std;

class Material {
private:
	string name;
	ColorRGB* kd;
	ColorRGB* ks;
	float especular;
	float reflexCoeficient;
	float refractionIndex;
	float opacity;
	Texture* texture;

public:
	Material(string name, ColorRGB* kd, ColorRGB*ks, float especular, float reflexCoeficient, float refractionIndex, float opacity, Texture* texture);
	virtual ~Material();

	string getName();
	float getEspecular();
	ColorRGB* getKd();
	ColorRGB* getKs();
	float getOpacity();
	float getReflexCoeficient();
	float getRefractionIndex();
	Texture* getTexture();
};

#endif /* MATERIAL_H_ */
