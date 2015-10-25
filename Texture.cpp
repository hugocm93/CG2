/*
 * Texture.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: hugocm93
 */

#include "Texture.h"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

Texture::Texture(char* name) {

	char cCurrentPath[FILENAME_MAX];
	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){
			return ;
		}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '/0'; /* not really required */
	strcat(cCurrentPath, "/cenasSimplesRT4/Textures/");
	strcat(cCurrentPath, name);
	std::cout << cCurrentPath << std::endl;
	this->image = new Image();
	this->image->imgReadBMP(cCurrentPath);


}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}

