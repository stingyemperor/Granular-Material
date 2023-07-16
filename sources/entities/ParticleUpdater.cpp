// #include "ParticleUpdater.hpp"
// #include "entities/ParticleData.hpp"
// #include "utils/CompactNSearch.h"
// #include "utils/PointSet.h"
// #include <glm/common.hpp>
// #include <glm/exponential.hpp>
// #include <vector>

// void EulerUpdater::update(double dt, ParticleData *p){
//   const glm:: vec4 globalA{dt * m_globalAcceleration.x , dt * m_globalAcceleration.y,
//     dt * m_globalAcceleration.z, 0.0f};

//   const float localDT = (float)dt;
//   const unsigned int endId = p->m_count;
//   int n = 4;
//   float sdt = localDT/n;

//   for(size_t i = 0; i < endId; ++i){
//     for(int j = 0 ;j < n; ++j){
//       p->m_acc[i] += globalA;
//       p->m_vel[i] += sdt* p->m_acc[i];
//       p->m_pos[i] += sdt* p->m_vel[i];
//     }

//     std::array<float,3> temp = {p->m_pos[i].x,p->m_pos[i].y, p->m_pos[i].z};  
//     p->positions[i] = temp; 

//   }
// }

// void FloorUpdater::update(double dt, ParticleData *p){
//   const size_t endId = p->m_count;

//   for(size_t i = 0; i < endId; ++i){
//     if(p->m_pos[i].y < m_floorY){
//       glm::vec4 force = p->m_acc[i];
//       float normalFactor = glm::dot(force, glm::vec4(0.0f, 1.0f, 0.0f,0.0f));
//       if(normalFactor < 0.0f){
//         force -= glm::vec4(0.0f, 1.0f,0.0f, 0.0f) * normalFactor;
//       }
//       float velFactor = glm::dot(p->m_vel[i], glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
//       p->m_vel[i] -= glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * (1.0f + m_bounceFactor) * velFactor;
//       p->m_acc[i] = force;
//     }
//   }
// }

// void WindUpdater::update(double dt, ParticleData *p){
//   for (size_t i = 0; i < p->m_count; ++i){
//     p->m_vel[i] += wind;
//   }
// }

// float vectorMag(glm::vec4 &v){
//   
//   float result = 0;
//   result = v.x*v.x + v.y*v.y + v.z*v.z;
//   result = glm::sqrt(result);
//   return result;
// }

// void Constraints::resetNeighbors(CompactNSearch::NeighborhoodSearch &nsearch){
//   nsearch.find_neighbors();
// }

// void Constraints::setPointSet(CompactNSearch::NeighborhoodSearch &nsearch, ParticleData *p){
//   pointId = nsearch.add_point_set(p->positions.front().data(), p->positions.size());
// }

// std::vector<unsigned int> Constraints::getNeighbors(CompactNSearch::NeighborhoodSearch &nsearch, ParticleData *p ,int n){
//   resetNeighbors(nsearch); 
//   CompactNSearch::PointSet const& ps_1 = nsearch.point_set(pointId);
//   std::vector<unsigned int> result;
//   for(size_t i =0; i < ps_1.n_neighbors(pointId, n); ++i){
//     result.push_back(ps_1.neighbor(pointId, n, i));
//   }
//   return result;
// }

// void Constraints::frictionConstraint(glm::vec4 &x_i, glm::vec4 &x_j){
//   glm::vec4 x_ij = x_j - x_i;
//   float x_ij_mag = vectorMag(x_ij);
//   glm::vec4 delta_x_i = -0.5f * (2 * 0.1f -x_ij_mag) * (x_ij/x_ij_mag);
//   glm::vec4 delta_x_j = -0.5f * (2 * 0.1f -x_ij_mag) * (x_ij/x_ij_mag);
//   
//   glm::vec4 x_i_temp = x_i + delta_x_i;
//   glm::vec4 x_j_temp = x_j + delta_x_j;

//   x_i = x_i_temp;
//   x_j = x_j_temp;

//   // glm::vec4 delta_x_ij = delta_x_i - delta_x_j; 
//   // glm::vec4 delta_x_ij_tan = delta_x_ij - (glm::dot(delta_x_ij, x_ij)) * (x_ij/(x_ij_mag * x_ij_mag));
//   // 
//   // float temp = (2 * 0.1f * 0.3)/vectorMag(delta_x_ij_tan);
//   // float min_fric = glm::min(temp,1.0f);
// }

// void Constraints::simulate(ParticleData *p, float dt, CompactNSearch::NeighborhoodSearch &nsearch){  

//   for(size_t i = 0; i < p->m_count; ++i){
//     p->m_vel[i] +=  1.0 * dt;
//     glm::vec4 x_i_temp = p->m_vel[i] * dt;
//     std::vector<unsigned int> neighbors = getNeighbors(nsearch, p, i);
//     
//   }
// }

// void Constraints::update(double dt, ParticleData *p){

// }

