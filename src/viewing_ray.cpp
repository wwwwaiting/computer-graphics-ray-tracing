#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ray.origin = camera.e;

  // Note that i-> row index is corresponding to height, j -> column index is corresponding to width 
  double u = camera.width * (j+0.5)/width - camera.width/2;
  double v = (-1) * (camera.height * (i+0.5)/height - camera.height/2);

  ray.direction = camera.u * u + camera.v * v - camera.d * camera.w;
  ////////////////////////////////////////////////////////////////////////////
}
