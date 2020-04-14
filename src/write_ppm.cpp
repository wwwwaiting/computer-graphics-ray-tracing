#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream image(filename, std::ios::binary);
  
  // error checking
  if (!image){
     return false;  
  }

  // write header information to the image
  // Assume binary data, using P6 for rgb image, P5 for grayscale image. reference: https://en.wikipedia.org/wiki/Netpbm_format#File_format_description
  if (num_channels == 3){
     image << "P6" << "\n"; 
  } else if (num_channels == 1){
  	  image << "P5" << "\n";
  }
  
  image << width << " " << height << "\n";
	image << 255 << "\n";

  // write every pixel color information to the image
  for (int idx = 0; idx < width * height * num_channels; idx++){
     image << data[idx]; 
  }
  
  //close the image file
  image.close();
  
  // error checking
  if(!image){
     return false;  
  }
  
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
