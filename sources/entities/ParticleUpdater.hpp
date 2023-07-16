#pragma once
// #include "ParticleData.hpp"
// #include "../utils/CompactNSearch"
// #include "utils/CompactNSearch.h"
// #include <omp.h>

// class ParticleUpdater{
// public:
//   std::vector<std::array<float,3>> positions;
//   ParticleUpdater(){}
//   virtual ~ParticleUpdater(){}
//   virtual void update(double dt, ParticleData *p) = 0;
// };

#include "utils/CompactNSearch.h"
struct Constraints{
  unsigned point_id;
  void resetNeighbor(CompactNSearch::NeighborhoodSearch &nsearch);
  void setPointSet(CompactNSearch::NeighborhoodSearch &nsearch);

};
// class EulerUpdater : public ParticleUpdater{
// public:
//   glm::vec4 m_globalAcceleration{0.0f,-0.1f,0.0f,0.0f};
// public:
//   virtual void update(double dt, ParticleData *p) override;
// };

// class FloorUpdater : public ParticleUpdater{
// public:
//   float m_floorY{0.0f};
//   float m_bounceFactor{0.5f};
// public:
//   virtual void update(double dt, ParticleData *p) override;
// };

// class WindUpdater : public ParticleUpdater{
// public:
//   glm::vec4 wind = {0.01f, 0.0f,0.0f,0.0f};

// public:
//   virtual void update(double dt, ParticleData *p) override;
// };

// class Constraints : public ParticleUpdater{
// public:
//   unsigned int pointId;
//   // CompactNSearch::NeighborhoodSearch nsearch;
//   // void init(ParticleData *p);
//   void resetNeighbors(CompactNSearch::NeighborhoodSearch &nsearch);
//   void setPointSet(CompactNSearch::NeighborhoodSearch &nsearch, ParticleData *p);
//   std::vector<unsigned int> getNeighbors(CompactNSearch::NeighborhoodSearch &nsearch, ParticleData *p, int i);
//   void frictionConstraint(glm::vec4 &x_i, glm::vec4 &x_j);
//   void simulate(ParticleData *p, float dt, CompactNSearch::NeighborhoodSearch &nsearch);
//   virtual void update(double dt, ParticleData *p) override;
// };



