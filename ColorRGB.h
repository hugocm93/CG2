/*
 * ColorRGB.h
 *
 *  Created on: Oct 21, 2015
 *      Author: hugocm93
 */

#ifndef COLORRGB_H_
#define COLORRGB_H_

class ColorRGB {

public:
	float vector[3];
public:
	ColorRGB(float r, float g, float b);
	virtual ~ColorRGB();
	float* getColor();
};

#endif /* COLORRGB_H_ */
