/*
 * Image.cpp
 *
 *  Modified on: Oct 16, 2015
 *      Author: hugocm93
 *       *
 *   @file image.c TAD: digital image (implementation).
 *   @author Marcelo Gattass and others
 *
 *   @date
 *         Last version:     08/2011.
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

#include "Image.h"

Image::Image() {
	this->dcs = 0;        /* define a dim do espaco de cor (dimension of the color space): 3=RGB, 1=luminancia */
	this->width = 0;      /* numero de pixels na direcao horizontal da imagem */
	this->height = 0;     /* numero de pixels na direcao vertical da imagem   */
	this->buf = NULL;

	this->originalDcs = 0;
	this->originalWidth = 0;
	this->originalHeight = 0;
	this->originalBuf = NULL;
}

Image::~Image() {
	delete [] buf;
	delete [] originalBuf;
}

void Image::imgCreate(int w, int h, int dcs)
{
	this->width  = w;
	this->height = h;
	this->dcs = dcs;
	this->buf = (float*)calloc (w * h * dcs , sizeof(float));

	this->originalWidth  = w;
	this->originalHeight = h;
	this->originalDcs = dcs;
	this->originalBuf = (float*)calloc (w * h * dcs , sizeof(float));

}

void Image::imgDestroy()
{
	if (this)
	{
		if (this->buf) free (this->buf);
		if (this->originalBuf) free (this->originalBuf);
	}
}

Image* Image::imgCopy()
{
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	int dcs = this->imgGetDimColorSpace();
	Image* img1 = new Image();
	img1->imgCreate(w,h,dcs);
	int x,y;
	float rgb[3];

	for (y=0;y<h;y++){
		for (x=0;x<w;x++) {
			this->imgGetPixel3fv(x,y,rgb);
			img1->imgSetPixel3fv(x,y,rgb);
		}
	}

	return img1;
}


void Image::imgGrey()
{
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	Image* img1 = new Image();
	img1->imgCreate(w,h,1);
	int x,y;
	float cor[3];

	for (y=0;y<h;y++){
		for (x=0;x<w;x++) {
			this->imgGetPixel3fv(x,y,cor);
			img1->imgSetPixel3fv(x, y, cor);  /* por img1 so ter um canal a funcao coloca a luminancia*/
		}
	}

	this->dcs = img1->dcs;
	this->width = img1->width;
	this->height = img1->height;
	this->buf = img1->buf;

}

void Image::imgResize(int w1, int h1)
{
	Image* img1 = new Image();
	img1->imgCreate(w1,h1,this->dcs);
	float w0 = (float) this->width;  /* passa para float para fazer contas */
	float h0 = (float) this->height;

	int x0,y0,x1,y1;
	float color[3];

	for (y1=0;y1<h1;y1++)
		for (x1=0;x1<w1;x1++)
		{
			x0=ROUND(w0*x1/w1);   /* pega a cor do pixel mais proxima */
			y0=ROUND(h0*y1/h1);
			this->imgGetPixel3fv(x0,y0,color);
			img1->imgGetPixel3fv(x1,y1,color);
		}
}


int Image::imgGetWidth()
{
	return this->width;
}

int Image::imgGetHeight()
{
	return this->height;
}

int Image::imgGetDimColorSpace()
{
	return this->dcs;
}

float* Image::imgGetData()
{
	return this->buf;
}

void Image::imgSetPixel3fv(int x, int y, float*  color)
{
	int pos = (y*this->width*this->dcs) + (x*this->dcs);
	switch (this->dcs) {
	case 3:
		this->buf[pos  ] = color[0];
		this->buf[pos+1] = color[1];
		this->buf[pos+2] = color[2];
		break;
	case 1:
		this->buf[pos  ] = luminance(color[0],color[1],color[2]);
		break;
	default:
		break;
	}
}

void Image::imgSetPixel3f(int x, int y, float R, float G, float B)
{
	int pos = (y*this->width*this->dcs) + (x*this->dcs);
	switch (this->dcs) {
	case 3:
		this->buf[pos  ] = R;
		this->buf[pos+1] = G;
		this->buf[pos+2] = B;
		break;
	case 1:
		this->buf[pos  ] = luminance(R,G,B);
		break;
	default:
		break;
	}
}

int Image::imgGetPixel3fv(int x, int y, float* color)
{
	int pos = (y*this->width*this->dcs) + (x*this->dcs);
	switch (this->dcs) {
	case 3:
		color[0] = this->buf[pos  ];
		color[1] = this->buf[pos+1];
		color[2] = this->buf[pos+2];
		break;
	case 1:
		color[0] = this->buf[pos  ];
		color[1] = color[0];
		color[2] = color[0];
		break;
	default:
		break;
	}

	return 1;
}


void Image::imgGetPixel3f(int x, int y, float* R, float* G, float* B)
{
	int pos = (y*this->width*this->dcs) + (x*this->dcs);
	switch (this->dcs) {
	case 3:
		*R = this->buf[pos  ];
		*G = this->buf[pos+1];
		*B = this->buf[pos+2];
		break;
	case 1:
		*R = this->buf[pos  ];
		*G = *R;
		*B = *R;
		break;
	default:
		break;
	}
}

void Image::imgSetPixel3ubv(int x, int y, unsigned char * color)
{
	int pos = (y*this->width*this->dcs) + (x*this->dcs);
	switch (this->dcs) {
	case 3:
		this->buf[pos  ] = (float)(color[0]/255.);
		this->buf[pos+1] = (float)(color[1]/255.);
		this->buf[pos+2] = (float)(color[2]/255.);
		break;
	case 1:
		this->buf[pos  ] = luminance((float)(color[0]/255.),(float)(color[1]/255.),(float)(color[2]/255.));
		break;
	default:
		break;
	}
}

void Image::imgGetPixel3ubv(int x, int y, unsigned char *color)
{
	int pos = (y*this->width*this->dcs) + (x*this->dcs);
	int r,g,b;
	switch (this->dcs) {
	case 3:
		r= ROUND(255*this->buf[pos]);
		g= ROUND (255*this->buf[pos+1]);
		b= ROUND (255*this->buf[pos+2]);
		color[0] = (unsigned char)(r<256) ? r : 255 ;
		color[1] = (unsigned char)(g<256) ? g : 255 ;
		color[2] = (unsigned char)(b<256) ? b : 255 ;
		break;
	case 1:
		r=g=b= ROUND(255*this->buf[pos]);
		color[0] = (unsigned char)(r<256) ? r : 255 ;
		color[1] = (unsigned char)(g<256) ? g : 255 ;
		color[2] = (unsigned char)(b<256) ? b : 255 ;
		break;
	default:
		break;
	}
}


/* Compiler dependent definitions */
typedef unsigned char BYTE;
typedef unsigned short int USHORT;
typedef unsigned short int WORD;
typedef long int LONG;
typedef unsigned long int DWORD;


void Image::imgReadBMP(char *filename)
{
	FILE  *filePtr;            /* ponteiro do arquivo */

	BYTE *linedata;

	USHORT  bfType;             /* "BM" = 19788           */
	LONG    biWidth;            /* image width in pixels  */
	LONG    biHeight;           /* image height in pixels */
	WORD    biBitCount;         /* bitmap color depth     */
	DWORD   bfSize;

	USHORT  ushortSkip;         /* dado lixo USHORT */
	DWORD   dwordSkip;         /* dado lixo DWORD  */
	LONG    longSkip;         /* dado lixo LONG   */
	WORD    wordSkip;         /* dado lixo WORD   */

	LONG i, j, k, l, linesize, got;

	/* abre o arquivo com a imagem BMP */
	filePtr = fopen(filename, "rb");
	std::cout << filename << std::endl;
	assert(filePtr);

	/* verifica se eh uma imagem bmp */
	getuint(&bfType, filePtr);
	assert(bfType == 19778);

	/* pula os 12 bytes correspondentes a bfSize, Reserved1 e Reserved2 */
	getdword(filePtr, &bfSize);
	getuint(&ushortSkip, filePtr);  /* Reserved1, deve ter valor 0 */
	assert(ushortSkip == 0);
	getuint(&ushortSkip, filePtr);  /* Reserved2, deve ter valor 0 */
	assert(ushortSkip == 0);

	/* pula os 4 bytes correspondentes a bfOffBits, que deve ter valor 54 */
	getdword(filePtr, &dwordSkip);
	assert(dwordSkip == 54);

	/* pula os 4 bytes correspondentes a biSize, que deve ter valor 40 */
	getdword(filePtr, &dwordSkip);
	assert(dwordSkip == 40);

	/* pega largura e altura da imagem */
	getlong(filePtr, &biWidth);
	getlong(filePtr, &biHeight);

	/* verifica que o numero de quadros eh igual a 1 */
	getword(filePtr, &wordSkip);
	assert(wordSkip == 1);

	/* Verifica se a imagem eh de 24 bits */
	getword(filePtr, &biBitCount);
	if(biBitCount != 24)
	{
		fprintf(stderr, "imgReadBMP: Not a bitmap 24 bits file.\n");
		fclose(filePtr);
		return ;
	}

	/* pula os demais bytes do infoheader */
	getdword(filePtr, &dwordSkip);
	assert(dwordSkip == 0);
	getdword(filePtr, &dwordSkip);
	getlong(filePtr, &longSkip);
	getlong(filePtr, &longSkip);
	getdword(filePtr, &dwordSkip);
	getdword(filePtr, &dwordSkip);

	this->imgCreate(biWidth, biHeight,3);

	/* a linha deve terminar em uma fronteira de dword */
	linesize = 3*this->width;
	if (linesize & 3) {
		linesize |= 3;
		linesize++;
	}

	/* aloca espaco para a area de trabalho */
	linedata = (BYTE *) malloc(linesize);
	if (linedata == NULL) {
		fprintf(stderr, "get24bits: Not enough memory.\n");
		return ;
	}

	/* pega as componentes de cada pixel */
	for (k=0, i=0; i<this->height; i++) {
		got = (unsigned long int)fread(linedata, linesize, 1, filePtr);
		if (got != 1) {
			free(linedata);
			fprintf(stderr, "get24bits: Unexpected end of file.\n");
		}
		for (l=1, j=0; j<this->width; j++, l=l+3) {
			this->buf[k++] = (float)(linedata[l+1]/255.);
			this->buf[k++] = (float)(linedata[l  ]/255.);
			this->buf[k++] = (float)(linedata[l-1]/255.);
		}
	}

	for(int i = 0; i < this->dcs*this->width*this->height; i++){
		this->originalBuf[i] = this->buf[i];
	}

	free(linedata);
	fclose(filePtr);

	std::cout << "asdasa"<< std::endl;

}

int Image::imgWriteBMP(char *filename)
{
	FILE          *filePtr;         /* ponteiro do arquivo */
	unsigned char *filedata;
	DWORD bfSize;
	int i, k, l;

	int linesize, put;

	/* cria um novo arquivo binario */
	filePtr = fopen(filename, "wb");
	assert(filePtr);

	/* a linha deve terminar em uma double word boundary */
	linesize = this->width * 3;
	if (linesize & 3) {
		linesize |= 3;
		linesize ++;
	}

	/* calcula o tamanho do arquivo em bytes */
	bfSize = 14 +                     /* file header size */
			40 +                     /* info header size */
			this->height * linesize;       /* image data  size */

	/* Preenche o cabe�alho -> FileHeader e InfoHeader */
	putuint(19778, filePtr);              /* type = "BM" = 19788                             */
	putdword(filePtr, bfSize);            /* bfSize -> file size in bytes                    */
	putuint(0, filePtr);                  /* bfReserved1, must be zero                       */
	putuint(0, filePtr);                  /* bfReserved2, must be zero                       */
	putdword(filePtr, 54);                /* bfOffBits -> offset in bits to data             */

	putdword(filePtr, 40);                /* biSize -> structure size in bytes                 */
	putlong(filePtr, this->width);         /* biWidth -> image width in pixels                  */
	putlong(filePtr, this->height);        /* biHeight -> image height in pixels                */
	putword(filePtr, 1);                  /* biPlanes, must be 1                               */
	putword(filePtr, 24);                 /* biBitCount, 24 para 24 bits -> bitmap color depth */
	putdword(filePtr, 0);                 /* biCompression, compression type -> no compression */
	putdword(filePtr, 0);                 /* biSizeImage, nao eh usado sem compressao          */
	putlong(filePtr, 0);                  /* biXPelsPerMeter                                   */
	putlong(filePtr, 0);                  /* biYPelsPerMeter                                   */
	putdword(filePtr, 0);                 /* biClrUsed, numero de cores na palheta             */
	putdword(filePtr, 0);                 /* biClrImportant, 0 pq todas sao importantes        */

	/* aloca espacco para a area de trabalho */
	filedata = (unsigned char *) malloc(linesize);
	assert(filedata);

	/* a linha deve ser zero padded */
	for (i=0; i<(linesize-(3*this->width)); i++)
		filedata[linesize-1-i] = 0;

	for (k=0; k<this->height;k++)
	{
		l = 1;
		/* coloca as componentes BGR no buffer */
		for (i=0; i<this->width; i++) {
			unsigned char color[3];
			int r,g,b;
			this->imgGetPixel3ubv(i,k,color);
			r= color[0];
			g= color[1];
			b= color[2];
			filedata[l-1] = (unsigned char)(b<256) ? b : 255 ;
			filedata[l  ] = (unsigned char)(g<256) ? g : 255 ;
			filedata[l+1] = (unsigned char)(r<256) ? r : 255 ;
			l+=3;
		}

		/* joga para o arquivo */
		put = (int)fwrite(filedata, linesize, 1, filePtr);
		if (put != 1) {
			fprintf(stderr, "put24bits: Disk full.");
			free(filedata);
			return 0;
		}
	}

	/* operacao executada com sucesso */
	fprintf(stdout,"imgWriteBMP: %s successfuly generated\n",filename);
	free(filedata);
	fclose(filePtr);
	return 1;
}


/*- PFM Interface Functions  ---------------------------------------*/

void Image::imgReadPFM(char *filename)
{
	FILE *fp;
	Image* img;
	float scale;
	int w,h;

	char line[256];

	fp = fopen(filename, "rb");
	if (fp == NULL) {  printf("%s nao pode ser aberto\n",filename); return ;}

	fgets(line,256,fp);

	if(strcmp(line,"PF\n"))
	{
		return ;
	}

	while (fscanf( fp, " %d ", &w ) != 1)
		fgets(line, 256, fp);
	while (fscanf( fp, " %d ", &h ) != 1)
		fgets(line, 256, fp);
	while (fscanf( fp, " %f", &scale ) != 1)
		fgets(line, 256, fp);

	fgetc(fp);
	img = new Image();
	img->imgCreate(w,h,3);
	fread( img->buf, 3*w*h, sizeof(float), fp );

	fprintf(stdout,"imgReadPFM: %s successfuly loaded\n",filename);
	fclose(fp);

	this->dcs = img->dcs;        /* define a dim do espaco de cor (dimension of the color space): 3=RGB, 1=luminancia */
	this->width = img->width;      /* numero de pixels na direcao horizontal da imagem */
	this->height = img->height;     /* numero de pixels na direcao vertical da imagem   */
	this->buf = img->buf;

	this->originalDcs = img->originalDcs;
	this->originalWidth = img->originalWidth;
	this->originalHeight = img->originalHeight;
	this->originalBuf = (float*)calloc (img->width * img->height * img->dcs , sizeof(float));

	for(int i = 0; i < this->dcs*this->width*this->height; i++){
		this->originalBuf[i] = this->buf[i];
	}

	this->originalBuf = img->originalBuf;
}



int Image::imgWritePFM(char * filename)
{
	FILE * fp;
	float  scale=1.f;

	if ((fp = fopen(filename, "wb")) == NULL) {
		printf("\nN�o foi possivel abrir o arquivo %s\n",filename);
		return 0;
	}

	/* the ppm file header */
	fprintf(fp,"PF\n%d %d\n%f\n", this->width, this->height, scale);

	fwrite( this->buf, 3*this->width*this->height, sizeof(float), fp );

	fprintf(stdout,"imgWritePFM: %s successfuly created\n",filename);
	fclose(fp);
	return 1;
}

int comparaCor3(const void * p1, const void * p2)
{
	int *c1 = (int *) p1;  /* aponta para o vermelho quantizado da cor 1 */
	int *c2 = (int *) p2;  /* aponta para o vermelho quantizado da cor 2 */

	/* compara o canal vermelho */
	if (*c1 < *c2) return -1;
	if (*c1 > *c2) return  1;

	/* compara  o canal verde, uma vez que o vermelho e' igual */
	c1++; c2++;
	if (*c1 < *c2) return -1;
	if (*c1 > *c2) return  1;

	/* compara o canal azul, uma vez que o vermelho e o azul sao iguais */
	c1++; c2++;
	if (*c1 < *c2) return -1;
	if (*c1 > *c2) return  1;

	/* sao iguais */
	return 0;
}

int comparaCor1(const void * p1, const void * p2)
{
	int *c1 = (int *) p1;  /* aponta para a luminosidade quantizada da cor 1 */
	int *c2 = (int *) p2;  /* aponta para a luminosidade quantizada da cor 2 */

	/* compara o canal de luminosidade */
	if (*c1 < *c2) return -1;
	if (*c1 > *c2) return  1;

	/* sao iguais */
	return 0;
}

int Image::imgCountColor(float tol)
{
	int numCor = 1;
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	int dcs = this->imgGetDimColorSpace();
	float* buf=this->imgGetData();
	int *vet=(int*) malloc(3*w*h*sizeof(int));
	int i;


	/* copia o buffer da imagem no vetor de floats fazendo
    uma quantizacao para (1/tol) tons de cada componente de cor */
	for (i=0;i<dcs*w*h;i++)
		vet[i]  = (int)(buf[i]/tol+0.5);

	/* ordena o vetor */
	if (dcs==3)
		std::qsort(vet,w*h,3*sizeof(int),comparaCor3);
	else
		std::qsort(vet,w*h,sizeof(int),comparaCor1);

	/* conta o numero de cores diferentes */
	if (dcs==3) {
		int freq=1;
		printf("%d %d %d ",vet[0],vet[1],vet[2]);
		for (i=3; i<3*w*h; i+=3){
			freq++;
			if (comparaCor3(&vet[i-3],&vet[i])!=0) {
				printf("%d\n %d %d %d ",freq,vet[i],vet[i+1],vet[i+2]);
				freq=1;
				numCor++;
			}
		}
		printf("%d\n",freq);
	} else {
		for (i=1; i<w*h; i+=1)
			if (comparaCor1(&vet[i-1],&vet[i])!=0) numCor++;
	}


	free(vet);
	return numCor;
}

float Image::apply(float c[9], float v[9])
{
	return c[0]*v[0]+c[1]*v[1]+c[2]*v[2]+c[3]*v[3]+c[4]*v[4]+c[5]*v[5]+c[6]*v[6]+c[7]*v[7]+c[8]*v[8];
}

/*
 * The following routines have been built from knowledge gathered
 * around the Web. I am not aware of any copyright problem with
 * them, so use it as you want.
 * N. Devillard - 1998
 */
typedef float pixelvalue ;
#define PIX_SORT(a,b) { if ((a)>(b)) PIX_SWAP((a),(b)); }
#define PIX_SWAP(a,b) { pixelvalue temp=(a);(a)=(b);(b)=temp; }

/*----------------------------------------------------------------------------
Function : opt_med9()
In : pointer to an array of 9 pixelvalues
Out : a pixelvalue
Job : optimized search of the median of 9 pixelvalues
Notice : in theory, cannot go faster without assumptions on the
signal.
Formula from:
XILINX XCELL magazine, vol. 23 by John L. Smith
The input array is modified in the process
The result array is guaranteed to contain the median
value
in middle position, but other elements are NOT sorted.
---------------------------------------------------------------------------*/
pixelvalue opt_med9(pixelvalue * p)
{
	PIX_SORT(p[1], p[2]) ; PIX_SORT(p[4], p[5]) ; PIX_SORT(p[7], p[8]) ;
	PIX_SORT(p[0], p[1]) ; PIX_SORT(p[3], p[4]) ; PIX_SORT(p[6], p[7]) ;
	PIX_SORT(p[1], p[2]) ; PIX_SORT(p[4], p[5]) ; PIX_SORT(p[7], p[8]) ;
	PIX_SORT(p[0], p[3]) ; PIX_SORT(p[5], p[8]) ; PIX_SORT(p[4], p[7]) ;
	PIX_SORT(p[3], p[6]) ; PIX_SORT(p[1], p[4]) ; PIX_SORT(p[2], p[5]) ;
	PIX_SORT(p[4], p[7]) ; PIX_SORT(p[4], p[2]) ; PIX_SORT(p[6], p[4]) ;
	PIX_SORT(p[4], p[2]) ; return(p[4]) ;
}


#undef PIX_SORT
#undef PIX_SWAP


void Image::imgMedian()
{
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();

	int dcs = this->imgGetDimColorSpace();
	Image* img = this->imgCopy();
	float* image_buf = this->imgGetData();
	float* img_buf = this->imgGetData();
	int x,y;

	if (dcs==1) {
		for (y=1;y<h-1;y++){
			for (x=1;x<w-1;x++) {
				int k = y*w+x;
				float v[9] = {img_buf[k+w-1], img_buf[k+w],img_buf[k+w+1],
						img_buf[k-1],img_buf[k],img_buf[k+1],
						img_buf[k-w-1],img_buf[k-w],img_buf[k-w+1]};
				image_buf[k]= opt_med9(v);
			}
		}
	} else {
		for (y=1;y<h-1;y+=1){
			for (x=1;x<w-1;x+=1) {
				int k0 = y*w*3+x*3;
				int k1 = k0+1;
				int k2 = k0+2;
				float r[9] = {img_buf[k0+3*w-3],img_buf[k0+3*w],img_buf[k0+3*w+3],
						img_buf[k0-3]    ,img_buf[k0]    ,img_buf[k0+3],
						img_buf[k0-3*w-3],img_buf[k0-3*w],img_buf[k0-3*w+3]};
				float g[9] = {img_buf[k1+3*w-3],img_buf[k1+3*w],img_buf[k1+3*w+3],
						img_buf[k1-3]    ,img_buf[k1]    ,img_buf[k1+3],
						img_buf[k1-3*w-3],img_buf[k1-3*w],img_buf[k1-3*w+3]};
				float b[9] = {img_buf[k2+3*w-3],img_buf[k2+3*w],img_buf[k2+3*w+3],
						img_buf[k2-3]    ,img_buf[k2]    ,img_buf[k2+3],
						img_buf[k2-3*w-3],img_buf[k2-3*w],img_buf[k2-3*w+3]};
				image_buf[k0] = opt_med9(r);
				image_buf[k1] = opt_med9(g);
				image_buf[k2] = opt_med9(b);
			}
		}
	}
	img->imgDestroy();
}

void Image::imgBinary()
{
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	float  white[3] = { 1, 1, 1 };
	float  black[3] = { 0, 0, 0 };
	float  cor[3];
	int    x, y;

	for (y = 0; y < h; y++)	{
		for (x = 0; x < w; x++) {
			this->imgGetPixel3fv( x, y, cor);
			if (cor[0] >= 0.5f)
				this->imgSetPixel3fv( x, y, white);
			else
				this->imgSetPixel3fv(x, y, black);
		}
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//The following functions were added by Hugo

void Image::imgDilated()
{
	printf("Dilatation\n");
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	Image* temp = NULL;
	float  white[3] = { 1, 1, 1 };
	float  cor[3];
	float  corCenter[3];
	int structuringElement[3][3];
	int x, y, i, j;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			structuringElement[i][j] = 1;
		}
	}

	temp = this->imgCopy();

	for (y = 1; y < h-1; y++)	{
		for (x = 1; x < w-1; x++) {

			this->imgGetPixel3fv(x, y, corCenter);
			if(corCenter[0] == WHITE){
				continue;
			}

			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					this->imgGetPixel3fv(x+i-1, y+j-1, cor);
					if(structuringElement[i][j] == 1 && cor[0] == WHITE){
						temp->imgSetPixel3fv(x, y, white);
						i = 3;
						j = 3;
					}
				}
			}
		}
	}
}

void Image::imgEroded()
{
	printf("Erosion\n");

	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	Image* temp = NULL;
	float  black[3] = { 0, 0, 0 };
	float  cor[3];
	float  corCenter[3];
	int structuringElement[3][3];
	int x, y, i, j;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			structuringElement[i][j] = 1;
		}
	}

	temp = this->imgCopy();

	for (y = 1; y < h-1; y++)	{
		for (x = 1; x < w-1; x++) {

			this->imgGetPixel3fv(x, y, corCenter);
			if(corCenter[0] == BLACK){
				continue;
			}

			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					this->imgGetPixel3fv(x+i-1, y+j-1, cor);
					if(structuringElement[i][j] == 1 && cor[0] == BLACK){
						temp->imgSetPixel3fv(x, y, black);
						i = 3;
						j = 3;
					}
				}
			}
		}
	}
}

int Image::count(){

	//do processing

	//count
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	int i, j, x, y ;
	int n;
	int *label = (int *)malloc(h * w * sizeof(int));
	float  cor[3];
	int labels[4];
	float aux1[3];
	float aux2[3];
	float aux3[3];
	float aux4[3];
	int var = 0;
	int numbers[4000];
	int index = 0;

	//set Label matrix
	for(i=0;i<w;i++){
		for(j=0; j<h;j++){
			n =  i * h + j;
			label[n] = 0;
		}
	}

	//label the entire matrix
	for (y = 1; y < h-1; y++)	{
		for (x = 1; x < w-1; x++) {

			this->imgGetPixel3fv(x, y, cor);
			if(cor[0] == BLACK){
				continue;
			}

			n =  (x-1) * h + (y);
			labels[0] = label[n];
			this->imgGetPixel3fv(x-1, y, aux1);

			n =  (x-1) * h + (y-1);
			labels[1] = label[n];
			this->imgGetPixel3fv(x-1, y-1, aux2);

			n =  (x) * h + (y-1);
			labels[2] = label[n];
			this->imgGetPixel3fv(x, y-1, aux3);

			n =  (x+1) * h + (y-1);
			labels[3] = label[n];
			this->imgGetPixel3fv(x+1, y-1, aux4);

			if(aux1[0] == BLACK && aux2[0] == BLACK && aux3[0] == BLACK && aux4[0] == BLACK){
				n =  (x) * h + (y);
				label[n] = ++var;
			}

			else{
				if(aux1[0] == WHITE && aux2[0] == WHITE && aux3[0] == WHITE && aux4[0] == WHITE){
					n =  (x) * h + (y);
					label[n] = labels[0];
				}
				else{
					if(aux4[0] == WHITE){
						n =  (x) * h + (y);
						label[n] = labels[3];

					}
					if(aux3[0] == WHITE){
						n =  (x) * h + (y);
						label[n] = labels[2];
					}
					if(aux2[0] == WHITE){
						n =  (x) * h + (y);
						label[n] = labels[1];
					}
					if(aux1[0] == WHITE){
						n =  (x) * h + (y);
						label[n] = labels[0];
					}
				}
			}
		}

	}

	//Set equivalences
	for (x = 1; x < w-1; x++) {
		for (y = 1; y < h-1; y++)	{

			this->imgGetPixel3fv(x, y, cor);
			if(cor[0] == WHITE){

				int auxLabel = 0;
				n = (x) * h + (y);
				auxLabel = label[n];

				for(j=0;j<3;j++){
					for(i=0;i<3;i++){

						this->imgGetPixel3fv(x+i-1, y+j-1, aux1);
						if(aux1[0] == WHITE){
							n =  (x+i-1) * h + (y+j-1);
							label[n] = auxLabel;
						}

					}
				}
			}
		}
	}

	//count connected components
	for (y = 0; y < h; y++)	{
		for (x = 0; x < w; x++) {
			this->imgGetPixel3fv(x, y, cor);
			if(cor[0] == BLACK){
				continue;
			}

			int l;
			int flag = 0;
			n =  (x)* h  + (y);

			for(l=0;l<=index;l++){
				if(numbers[l]==label[n]){
					flag = 1;
					break;
				}

			}
			if(flag==0){
				numbers[++index] = label[n];
			}

		}
	}

	//print
	//	for (y = 0; y < h; y++)	{
	//		printf("\n");
	//		for (x = 0; x < w; x++) {
	//			n =  (x)* h  + (y);
	//			printf("%d ", label[n]);
	//
	//		}
	//	}

	free(label);
	return index;
}

int Image::count2(void){
	int max = 0;
	int current = 2;
	this->imgGrey();
	this->imgBinary();

	while(current>1){
		this->imgEroded();
		this->imgMedian();
		this->imgMedian();
		this->imgMedian();
		this->imgMedian();
		current = this->count();
		if(current>max){
			max = current;
		}
	}
	return max;
}

void Image::imgInvert()
{
	int w = this->imgGetWidth();
	int h = this->imgGetHeight();
	float  white[3] = { 1, 1, 1 };
	float  black[3] = { 0, 0, 0 };
	float  cor[3];
	int    x, y;

	for (y = 0; y < h; y++)	{
		for (x = 0; x < w; x++) {
			this->imgGetPixel3fv(x, y, cor);
			if (cor[0] == WHITE)
				this->imgSetPixel3fv(x, y, black);
			else
				this->imgSetPixel3fv(x, y, white);
		}
	}

}

void Image::imgReset(){
	this->dcs = this->originalDcs;
	this->width = this->originalWidth;
	this->height = this->originalHeight;
	this->buf = this->originalBuf;

	int n = this->dcs*this->width*this->height;
	this->originalBuf = (float*)calloc (n , sizeof(float));

}


/************************************************************************/
/* Definicao das Funcoes Privadas                                       */
/************************************************************************/

/*  getuint e putuint:
 * Funcoes auxiliares para ler e escrever inteiros na ordem (lo-hi)
 * Note  que  no Windows as variaveis tipo "unsigned short int" sao
 * armazenadas  no disco em dois bytes na ordem inversa. Ou seja, o
 * numero  400, por exemplo, que  pode ser escrito como 0x190, fica
 * armazenado  em dois bytes consecutivos 0x90 e 0x01. Nos sistemas
 * UNIX e Mac este mesmo inteiro seria armazenado  na  ordem 0x01 e
 * 0x90. O armazenamento do Windows e' chamado  de  "little endian"
 * (i.e., lowest-order byte stored first), e  no  sitemas  Unix sao
 * "big-endian" (i.e., highest-order byte stored first).
 */

/***************************************************************************
 * Reads an unsigned integer from input                                     *
 ***************************************************************************/
int Image::getuint(unsigned short *uint, FILE *input)
{
	int got;
	unsigned char temp[2];
	unsigned short tempuint;

	got = (int) fread(&temp, 1, 2, input);
	if (got != 2) return 0;

	tempuint = ((unsigned short)(temp[1])<<8) | ((unsigned short)(temp[0]));

	*uint = tempuint;

	return 1;
}

/***************************************************************************
 * Writes an unsigned integer in output                                     *
 ***************************************************************************/
int Image::putuint(unsigned short uint, FILE *output)
{
	int put;
	unsigned char temp[2];

	temp[0] = uint & 0xff;
	temp[1] = (uint >> 8) & 0xff;

	put = (int) fwrite(&temp, 1, 2, output);
	if (put != 2) return 0;

	return 1;
}

/***************************************************************************
 * Reads a long integer from input                                          *
 ***************************************************************************/
int Image::getlong(FILE *input, long int *longint)
{
	int got;
	unsigned char temp[4];
	long int templongint;

	got = (int)fread(&temp, 1, 4, input);
	if (got != 4) return 0;

	templongint = ((long int)(temp[3])<<24) | ((long int)(temp[2])<<16)
    																																																																																																																																																														  | ((long int)(temp[1])<<8) | ((long int)(temp[0]));

	*longint = templongint;

	return 1;
}

/***************************************************************************
 * Writes a long integer in output                                          *
 ***************************************************************************/
int Image::putlong(FILE *output, long int longint)
{
	int put;
	unsigned char temp[4];

	temp[0] = (unsigned char)longint & 0xff;
	temp[1] = (unsigned char)(longint >> 8) & 0xff;
	temp[2] = (unsigned char)(longint >> 16) & 0xff;
	temp[3] = (unsigned char)(longint >> 24) & 0xff;

	put = (int)fwrite(&temp, 1, 4, output);

	if (put != 4) return 0;

	return 1;
}

/***************************************************************************
 * Reads a word from input                                                  *
 ***************************************************************************/
int Image::getword(FILE *input, unsigned short int *word)
{
	int got;
	unsigned char temp[2];
	unsigned short int tempword;

	got = (int)fread(&temp, 1, 2, input);
	if (got != 2) return 0;

	tempword = ((unsigned short int)(temp[1])<<8) | ((unsigned short int)(temp[0]));

	*word = tempword;

	return 1;
}

/***************************************************************************
 * Writes a word in output                                                  *
 ***************************************************************************/
int Image::putword(FILE *output, unsigned short int word)
{
	int put;
	unsigned char temp[2];

	temp[0] = word & 0xff;
	temp[1] = (word >> 8) & 0xff;

	put = (int)fwrite(&temp, 1, 2, output);
	if (put != 2) return 0;

	return 1;
}

/***************************************************************************
 * Reads a double word from input                                           *
 ***************************************************************************/
int Image::getdword(FILE *input, unsigned long int *dword)
{
	int got;
	unsigned char temp[4];
	unsigned long int tempdword;

	got = (int)fread(&temp, 1, 4, input);
	if (got != 4) return 0;

	tempdword = ((unsigned long int)(temp[3])<<24) | ((unsigned long int)(temp[2])<<16)
    																																																																																																																																																														  | ((unsigned long int)(temp[1])<<8) | ((unsigned long int)(temp[0]));

	*dword = tempdword;

	return 1;
}

/***************************************************************************
 * Writes a double word in output                                           *
 ***************************************************************************/
int Image::putdword(FILE *output, unsigned long int dword)
{
	int put;
	unsigned char temp[4];

	temp[0] = (unsigned char) (dword & 0xff);
	temp[1] = (unsigned char) ((dword >>  8) & 0xff);
	temp[2] = (unsigned char) ((dword >> 16) & 0xff);
	temp[3] = (unsigned char) ((dword >> 24) & 0xff);

	put = (int)fwrite(&temp, 1, 4, output);

	if (put != 4) return 0;

	return 1;
}

float Image::luminance(float red, float green, float blue)
{
	return 0.2126f*red +0.7152f*green+0.0722f*blue;
}


