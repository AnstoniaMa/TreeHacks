#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <stdlib.h>
#include <stdio.h>

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 4;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

using namespace cv;
Mat load(string filename) {
  return imread(filename, CV_LOAD_IMAGE_COLOR );
}
Mat blackandwhite(Mat src) {
  Mat src_gray;
  Mat grad;
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  
  GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
  /// Convert it to gray
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// Generate grad_x and grad_y
  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;

  /// Gradient X
  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_x, abs_grad_x );

  /// Gradient Y
  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_y, abs_grad_y );

  /// Total Gradient (approximate)
  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
  return grad;
}
//inverting every single pixel in the target image
void invert(Mat src) {
  Size s = src.size();
  height = s.height;
  width = s.width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < ) {
    }
  }
}
/** @function main */
int main( int argc, char** argv )
{
  const char* window_name = "Microexpressions";

  // Load an image
  Mat src = load(argv[1]);
  if( !src.data )
  { return -1; }

  Mat result = blackandwhite(src);
  // invert(result);
  /// Create window
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  namedWindow("Display window", CV_WINDOW_AUTOSIZE);

  imshow( "Display window", result);

  waitKey(0);

  return 0;

}