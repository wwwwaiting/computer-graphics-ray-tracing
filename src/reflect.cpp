#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // see text 4.8 for formula reference
  Eigen::Vector3d r = in - 2*(in.dot(n))*n;
  return r.normalized();
  ////////////////////////////////////////////////////////////////////////////
}
