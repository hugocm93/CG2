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
	delete kd;
	delete ks;
	delete texture;
}

string Material::getName(){
	return this->name;
}


float Material::getEspecular(){
	return especular;
}

ColorRGB* Material::getKd(){
	return kd;
}

ColorRGB* Material::getKs(){
	return ks;
}

float Material::getOpacity(){
	return opacity;
}

float Material::getReflexCoeficient(){
	return reflexCoeficient;
}

float Material::getRefractionIndex(){
	return refractionIndex;
}

Texture* Material::getTexture(){
	return texture;
}



