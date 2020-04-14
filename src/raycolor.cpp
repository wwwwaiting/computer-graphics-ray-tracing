#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  rgb = Eigen::Vector3d(0,0,0);
  
  if (num_recursive_calls > 10){
      return false;
  }

  int hit_id; 
  double t;
  Eigen::Vector3d n;
  if(first_hit(ray, min_t, objects, hit_id, t, n)){
    // ecaluate shading model
    rgb = blinn_phong_shading(ray, hit_id, t, n, objects, lights);

    // add ideal specular reflection
    Ray reflected_ray;
    Eigen::Vector3d reflected_rgb;
    reflected_ray.origin = ray.origin + t * ray.direction;;
    reflected_ray.direction = reflect(ray.direction.normalized(), n);
    if (raycolor(reflected_ray, 1.0e-6, objects, lights, num_recursive_calls+1, reflected_rgb)){
      rgb += (objects[hit_id]->material->km.array()*reflected_rgb.array()).matrix();
    }

    return true;
  }
  
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
