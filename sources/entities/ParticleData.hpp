#pragma once
#include <eigen3/Eigen/Core>

#define max_count 1000

struct ParticleData{

  const float radius{0.2f};
  std::array<Eigen::Vector3f, max_count> position;
  std::array<Eigen::Vector3f, max_count> velocity;
  std::array<Eigen::Vector3f, max_count> mass;
};
