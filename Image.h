/*
 * Image.h

 *
 *  Modified on: Oct 16, 2015
 *      Author: hugocm93
 *
 *        Departamento de Informatica, PUC-Rio, INF1761 Computer Graphhics
 *
 *   @file image.h TAD: digital image (interface).
 *   @author Marcelo Gattass and others
 *
 *   @date
 *         Last version:     08/2015.
 *
 *   @version 3.1
 *
 *   @Copyright/License
 *   DI PUC-Rio Educational Software
 *   All the products under this license are free software: they can be used for both academic and commercial purposes at absolutely no cost.
 *   There are no paperwork, no royalties, no GNU-like "copyleft" restrictions, either. Just download and use it.
 *   They are licensed under the terms of the MIT license reproduced below, and so are compatible with GPL and also qualifies as Open Source software.
 *   They are not in the public domain, PUC-Rio keeps their copyright. The legal details are below.
 *
 *   The spirit of this license is that you are free to use the libraries for any purpose at no cost without having to ask us.
 *   The only requirement is that if you do use them, then you should give us credit by including the copyright notice below somewhere in your product or its documentation.
 *
 *   Copyright � 2010-2015 DI PUC-Rio Educational Software
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software
 *   without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sub license, and/or sell copies of the Software, and to permit
 *   persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all copies or suavlantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <cstdlib>
#include <string.h>
#include <cstdio>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <memory.h>
#include <iup/iup.h>

#define WHITE 1
#define BLACK 0

#define ROUND(_) (int)floor( (_) + 0.5 )
#define N_CORES   256
#define MAIOR_COR 255

class Image {

private:
	int dcs;        // define a dim do espaco de cor (dimension of the color space): 3=RGB, 1=luminancia */
	int width;      // numero de pixels na direcao horizontal da imagem */
	int height;     // numero de pixels na direcao vertical da imagem   */
	float *buf;     // vetor de dimensao dcs*width*height que armazena consecutivamente as componentes de cor de cada pixel a partir do canto inferior esquerdo da imagem. A posicao das componentes de cor do pixel (x,y) fica armazenada a partir da posicao: (y*width*dcs) + (x*dcs)

public:
	Image();
	virtual ~Image();

	/************************************************************************/
	/* Funcoes Exportadas                                                   */
	/************************************************************************/

	/**
	 *	Cria uma nova imagem com as dimensoes especificadas.
	 *
	 *	@param w Largura da imagem.
	 *	@param h Altura da imagem.
	 *	@param dcs Dimensao do espaco de cor de cada pixel (1=luminancia ou 3=RGB).
	 *
	 *	@return Handle da imagem criada.
	 */
	static Image  * imgCreate (int w, int h, int dcs);

	/**
	 *	Destroi a imagem.
	 *
	 *	@param image imagem a ser destruida.
	 */
	static void    imgDestroy (Image*image);

	/**
	 *	Cria uma nova nova copia imagem dada.
	 *
	 *	@param image imagem a ser copiada.
	 *
	 *	@return Handle da imagem criada.
	 */
	static Image* imgCopy(Image* image);

	/**
	 *	Cria uma nova nova copia imagem dada em tons de cinza.
	 *
	 *	@param image imagem a ser copiada em tons de cinza.
	 *
	 *	@return Handle da imagem criada.
	 */
	static Image* imgGrey(Image* image);

	/**
	 *	Obtem a largura (width) de uma imagem.
	 *
	 *	@param image Handle para uma imagem.
	 *	@return  a largura em pixels (width) da imagem.
	 */
	static int imgGetWidth(Image* image);

	/**
	 *	Obtem a altura (heigth) de uma imagem.
	 *
	 *	@param image Handle para uma imagem.
	 *	@return  a altura em pixels (height) da imagem.
	 */
	static int imgGetHeight(Image* image);

	/**
	 *	Obtem a dimensao do espaco de cor de cada pixel (1=lminancia ou 3=RGB).
	 *
	 *	@param image Handle para uma imagem.
	 *	@return  dimensao do espaco de cor de cada pixel (1=lminancia ou 3=RGB) da imagem.
	 */

	static int imgGetDimColorSpace(Image* image);
	/**
	 *	Obtem as dimensoes de uma imagem.
	 *
	 *	@param image Handle para uma imagem.
	 *	@param w [out]Retorna a largura da imagem.
	 *	@param h [out]Retorna a altura da imagem.
	 */
	static float*  imgGetData(Image* image);

	/**
	 *	Ajusta o pixel de uma imagem com a cor especificada.
	 *
	 *	@param image Handle para uma imagem.
	 *	@param x Posicao x na imagem.
	 *	@param y Posicao y na imagem.
	 *	@param color Cor do pixel(valor em float [0,1]).
	 */
	static void imgSetPixel3fv(Image* image, int x, int y, float*  color);
	static void imgSetPixel3f(Image* image, int x, int y, float R, float G, float B);

	/**
	 *	Ajusta o pixel de uma imagem com a cor especificada.
	 *
	 *	@param image Handle para uma imagem.
	 *	@param x Posicao x na imagem.
	 *	@param y Posicao y na imagem.
	 *	@param color Cor do pixel (valor em unsigend char[0,255]).
	 */
	static void imgSetPixel3ubv(Image* image, int x, int y, unsigned char * color);

	/**
	 *	Obtem o pixel de uma imagem na posicao especificada.
	 *
	 *	@param image Handle para uma imagem.
	 *	@param x Posicao x na imagem.
	 *	@param y Posicao y na imagem.
	 *	@param color [out] Pixel da posicao especificada(valor em float [0,1]).
	 */
	static int imgGetPixel3fv(Image* image, int x, int y, float* color);
	static void imgGetPixel3f(Image* image, int x, int y, float* R, float* G, float* B);

	/**
	 *	Obtem o pixel de uma imagem na posicao especificada.
	 *
	 *	@param image Handle para uma imagem.
	 *	@param x Posicao x na imagem.
	 *	@param y Posicao y na imagem.
	 *	@param color [out] Pixel da posicao especificada (valor em unsigend char[0,255]).
	 */
	static void imgGetPixel3ubv(Image* image, int x, int y, unsigned char *color);


	/**
	 *	Salva a imagem no arquivo especificado em formato BMP.
	 *
	 *	@param filename Nome do arquivo de imagem.
	 *	@param bmp Handle para uma imagem.
	 *
	 *	@return retorna 1 caso nao haja erros.
	 */
	static int imgWriteBMP(char *filename, Image* bmp);

	/**
	 *	Le a imagem a partir do arquivo especificado.
	 *
	 *	@param filename Nome do arquivo de imagem.
	 *
	 *	@return imagem criada.
	 */
	static Image* imgReadBMP (char *filename);


	/**
	 *	Le a imagem a partir do arquivo especificado.
	 *  A imagem e' armazenada como um arquivo binario
	 *  onde os tres campos da .
	 *
	 *	@param filename Nome do arquivo de imagem.
	 *
	 *	@return imagem criada.
	 */
	static Image* imgReadPFM(char *filename);

	/**
	 *	Salva a imagem no arquivo especificado .
	 *
	 *	@param filename Nome do arquivo de imagem.
	 *	@param image Handle para uma imagem.
	 *
	 *	@return retorna 1 caso nao haja erros.
	 */
	static int imgWritePFM(char *filename, Image* image);


	/**
	 *	Conta o numero de cores diferentes na imagem
	 *
	 *	@param image Handle para uma imagem.
	 *	@param w Nova largura da imagem.
	 *	@param h Nova altura da imagem.
	 */
	static int imgCountColor(Image* image, float);

	/**
	 *	 Aplica o filtro de Mediana para eliminar o ruido sal e pimenta
	 *  da imagem.
	 *
	 *	@param image Handle para uma imagem a ser filtrada.
	 *
	 */
	static void imgMedian(Image* image);


	/**
	 *	Reduz a imagem em tons de cinza para 2 tons (B&W ou Preto e Branco).
	 *
	 *
	 *	@param img_grey    Handle para uma imagem em tons de cinza.
	 *
	 *   @return Handle para a image de luminosidade com dois tons 0 e 1 (B&W).
	 **/
	static Image* imgBinary(Image* img_cgrey);

	static Image* imgResize(Image* img0, int w1, int h1);


	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//These functions were added by Hugo

	static Image* imgEroded(Image* img);
	static Image* imgDilated(Image* img);
	static int count(Image* img);
	static int count2(Image* img);
	static void imgInvert(Image *img);

private:
	static int getuint(unsigned short *uint, FILE *input);
	 static int putuint(unsigned short uint, FILE *output);
	 static  int getlong(FILE *input, long int *longint);
	 static  int putlong(FILE *output, long int longint);
	 static int getword(FILE *input, unsigned short int *word);
	 static int putword(FILE *output, unsigned short int word);
	 static  int getdword(FILE *input, unsigned long int *dword);
	 static int putdword(FILE *output, unsigned long int dword);
	 static float luminance(float red, float green, float blue);
	 static float apply(float c[9], float v[9]);
};

#endif /* IMAGE_H_ */
