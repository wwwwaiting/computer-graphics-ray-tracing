#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d c = center;
  
  double r = radius;

  double A, B, C;
  A = d.dot(d);
  B = 2 * d.dot(e-c);
  C = (e-c).dot(e-c) - r * r;

  double delta = B * B - 4 * A * C;

  // no result when smaller than 0
  if (delta < 0){
    return false;
  }
  // result is (-b+-2delta)/2A
  double t1 = (-B-sqrt(delta))/(2*A);
  double t2 = (-B+sqrt(delta))/(2*A);

  double max = std::max(t1, t2);

  // check if both t1 and t2 are smaller than min_t
  if(max < min_t){
    return false;
  }

  // there is at least one t is valid
  double min = std::min(t1, t2);
  // take the smallest if both t1 and t2 are both valid
  if(min >= min_t){
    t = min;
  }else{ // take the max if only one t is valid
    t = max;
  }

  n = (e + t*d - c)/r;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

