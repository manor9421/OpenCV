#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>

void processImage();
void displayGraphics();

IplImage *image = NULL;
IplImage *processedImage=NULL;


int main(int argc, char** argv) {

cvNamedWindow("Image");
cvNamedWindow("Processed Image");

if(argc > 1)
	image = cvLoadImage(argv[1]);
else
	image = cvLoadImage("anime_wp.jpg");

if(!image)
	exit(1);

processImage();
displayGraphics();

cvWaitKey(0);

if(image)
	cvReleaseImage(&image);
if(processedImage)
	cvReleaseImage(&processedImage);

cvDestroyAllWindows();

return (EXIT_SUCCESS);
}

void displayGraphics()
{
	// display images
	cvShowImage("Image", image);
	cvShowImage("Image", processedImage);
}

void processImage()
{
	int x,y;
	unsigned char R, G, B;
	processedImage = cvCloneImage(image);

	for(y=0; y < processedImage->height; y++)
		for(x=0; x < processedImage->width; x++)
		{
			B = ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 0];

			((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 0] = 255 - B;

			G = ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 2];

			((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 2] = 255 - G;

			R = ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 2];

			((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 2] = 255 - R;
		}

}

/*
for compiling: g++ main.c `pkg-config --libs --cflags opencv` -o main
*/
