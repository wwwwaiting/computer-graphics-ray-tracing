#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double t_min = std::numeric_limits<double>::infinity();
  double hit = false;

  // loop through every object
  for(int i = 0; i < objects.size(); i++){
    Eigen::Vector3d n_temp;
    double t_temp;
    // check if the object is intersecting with the ray
    if(objects[i] -> intersect(ray, min_t, t_temp, n_temp)){
      hit = true;
      // update t_min, hit_id and n
      if(t_temp < t_min){
        t_min = t_temp;
        hit_id = i;
        n = n_temp;
      }
    }
  }
  t = t_min;
  return hit;
  ////////////////////////////////////////////////////////////////////////////
}
