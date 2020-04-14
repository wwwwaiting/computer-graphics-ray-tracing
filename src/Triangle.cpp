#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
#include <iostream>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d p1 = std::get<0>(corners);
  Eigen::Vector3d p2 = std::get<1>(corners);
  Eigen::Vector3d p3 = std::get<2>(corners);

  // formulas and variables see reference on textbook p78-79 carmer's rule.
  double a, b, c, d, e, f, g, h, i, j, k, l;  
  a = p1[0] - p2[0];
  b = p1[1] - p2[1];
  c = p1[2] - p2[2];
  d = p1[0] - p3[0]; 
  e = p1[1] - p3[1];
  f = p1[2] - p3[2];

  g = ray.direction[0];
  h = ray.direction[1];
  i = ray.direction[2];

  j = p1[0] - ray.origin[0]; 
  k = p1[1] - ray.origin[1];
  l = p1[2] - ray.origin[2]; 
  
  double M = a*(e*i - h*f) + b*(g*f - d*i) + c*(d*h - e*g);
  double beta = (j*(e*i - h*f) + k*(g*f - d*i) + l*(d*h - e*g)) / M; 
  double gamma = (i*(a*k - j*b) + h*(j*c - a*l) + g*(b*l - k*c)) / M;
  double temp_t = (-1) * ((f*(a*k - j*b) + e*(j*c - a*l) + d*(b*l - k*c)) / M);
  
  // constriants see reference on textbook p79.
  if (temp_t < min_t || gamma < 0 || gamma > 1 || beta < 0 || beta > (1-gamma)){
     return false;  
  } else {
     t = temp_t;  
     // two edge vectors of the triangle.   
     Eigen::Vector3d e1 = p1 - p2;
     Eigen::Vector3d e2 = p1 - p3;
     // normal vector is the cross product
     n = e1.cross(e2).normalized();
     return true;
  }
  ////////////////////////////////////////////////////////////////////////////
}


