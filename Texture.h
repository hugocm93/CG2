/*
 * Texture.h
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Image.h"

class Texture {

private:
	Image* image;
public:
	Texture();
	virtual ~Texture();
	//get color for pixel x y
};

#endif /* TEXTURE_H_ */
