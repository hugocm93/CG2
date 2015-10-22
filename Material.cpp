/*
 * Material.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Material.h"

Material::Material(string name, ColorRGB* kd, ColorRGB*ks, float especular, float reflexCoeficient, float refractionIndex, float opacity, Texture* texture){
	this->name = name;
	this->kd = kd;
	this->ks = ks;
	this->especular = especular;
	this->reflexCoeficient = reflexCoeficient;
	this->refractionIndex = refractionIndex;
	this->opacity = opacity;
	this->texture = texture;

}

Material::~Material() {
	// TODO Auto-generated destructor stub
}

