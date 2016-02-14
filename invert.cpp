#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables
Mat src, dst;
int morph_elem = 0;
int morph_size = 0;
int morph_operator = 4;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

const char* window_name = "Morphology Transformations Demo";

/** Function Headers */
void Morphology_Operations( int, void* );

/** @function main */
int main( int argc, char** argv )
{
  /// Load an image
  src = imread( argv[1] );

  if( !src.data )
  { return -1; }

 /// Create window
 namedWindow( window_name, CV_WINDOW_AUTOSIZE );


 /// Default start
 Morphology_Operations( 6, 0 );

 waitKey(0);
 return 0;
 }

 /**
  * @function Morphology_Operations
  */
void Morphology_Operations(int, void* )
{
  // Since MORPH_X : 2,3,4,5 and 6
  int operation = morph_operator + 2;

  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );

  /// Apply the specified morphology operation
  morphologyEx( src, dst, 6, element );
  imshow( window_name, dst );
  }