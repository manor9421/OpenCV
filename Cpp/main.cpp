#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>



using namespace cv;

// create windows
void displayGraphics();
void processImage();


// images
Mat image;
Mat processedImage; 

int main(int argc, char** argv)
{
    // create window
    namedWindow("Image");
    namedWindow("Processed Image");
    
    // load the image
    if(argc > 1)
        image = imread(argv[1]);
    else
        image = imread("IMG_59554.jpg");

    if(image.empty())
        exit(1);
    
    
    processImage();
    displayGraphics();

    imwrite("IMG.jpg", processedImage);
    
    
    return 0;
}


void displayGraphics()
{
    imshow("Image", image);
    imshow("Processed Image", processedImage);
}

void processImage()
{
    int x, y;
    Vec3b pixel;
    unsigned char R, G, B;
    processedImage = image.clone();
    
    for(y=0; y < processedImage.rows; y++)
    {// #for_1 start
        for(x=0; x < processedImage.cols; x++)
        {
            // get the pixel at(x,y)
            pixel = processedImage.at<Vec3b>(y,x);
            
            // get the separate colors
            B = pixel[0];
            G = pixel[1];
            R = pixel[2];
            
            // assign the complement to each color
            pixel[0] = 255 - B;
            pixel[1] = 255 - G;
            pixel[2] = 255 - R;
            
            // write the pixel back to the image
            processedImage.at<Vec3b>(y,x) = pixel;
            
        }
    }// #for_1 end
}


/*

create CMakeLists.txt
cmake .
make
./cv

*/
