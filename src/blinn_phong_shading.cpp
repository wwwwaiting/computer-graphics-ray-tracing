#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d L(0,0,0);
  Eigen::Vector3d Ia(0.1,0.1,0.1);
  Eigen::Vector3d kd = objects[hit_id]->material->kd;
  Eigen::Vector3d ks = objects[hit_id]->material->ks;
  Eigen::Vector3d ka = objects[hit_id]->material->ka;
  double phong_exponent = objects[hit_id]->material->phong_exponent;

  Eigen::Vector3d p = ray.origin + t * ray.direction;

  for(int i = 0; i<lights.size(); i++){
    // compute l ie. direction for each light
    Eigen::Vector3d l;
    double max_t;
    lights[i] -> direction(p, l, max_t);

    //create a ray for shadow
    Ray shadow_ray;
    shadow_ray.origin = p;
    shadow_ray.direction = l;
     
    //check if the point is in shadow.
    int curr_id; 
    double curr_t;   
    Eigen::Vector3d curr_n;
    if (!first_hit(shadow_ray, 1e-6, objects, curr_id, curr_t, curr_n) || curr_t > max_t){
      // get the indensity I
      Eigen::Vector3d I = lights[i] -> I;
      // compute the half vector
      Eigen::Vector3d v = -ray.direction.normalized();
      l = l.normalized();
      Eigen::Vector3d h = (v + l).normalized();

      // computing the Blinn-Phong Shading for each light
      L += (kd.array() * I.array()).matrix() * fmax(0, n.dot(l));
      L += (ks.array() * I.array()).matrix() * pow(fmax(0, n.dot(h)), phong_exponent);
    }
  }

  L += (ka.array() * Ia.array()).matrix();

  return L;
  ////////////////////////////////////////////////////////////////////////////
}
