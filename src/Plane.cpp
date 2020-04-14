#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
 
  double denominator = d.dot(normal);
  // check for the denominator
  if(denominator == 0){
    return false;
  }
  double t_temp = (point.dot(normal) - e.dot(normal))/ denominator;
  // update only when the t value is not smaller than min_t
  if (t_temp >= min_t){
    t = t_temp;
    n = normal;
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

