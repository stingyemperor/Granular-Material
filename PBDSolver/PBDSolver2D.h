#ifndef Magnum_Examples_PBDSimulation2D_Solver2D_h
#define Magnum_Examples_PBDSimulation2D_Solver2D_h


#include <Corrade/Containers/Pointer.h>
#include <tbb/parallel_for.h>
#include "PBDSolver/SolverData.h"


namespace Magnum { namespace Examples {

namespace TaskScheduler {

    template<class IndexType, class Function> void forEach(IndexType endIdx, Function&& func) {
        tbb::parallel_for(tbb::blocked_range<IndexType>(IndexType(0), endIdx),
            [&](const tbb::blocked_range<IndexType>& r) {
                for (IndexType i = r.begin(), iEnd = r.end(); i < iEnd; ++i) {
                    func(i);
                }
            });
    }
}

/* 2D PBD solver */
class PBDSolver2D {
public:
    explicit PBDSolver2D(const Vector2& origin, Float cellSize, Int Ni, Int Nj, SceneObjects* sceneObjs);

    void emitParticles(const Vector2& pos, Float size, SDFObject::ObjectType type);

    /* Manipulation */
    void reset() {
        _particles.reset();
        _particles.addParticles(_particles.positionsT0, 0);
    }
    
    void setIterations(unsigned int num) { _numConstraintIteration = num; }
    void advanceFrame(Float frameDuration, Int nstep=3);

    /* Properties */
    UnsignedInt numParticles() const { return _particles.size(); }
    unsigned int numConstraintIterations() const { return _numConstraintIteration; }
    Float particleRadius() const { return _particles.particleRadius; }

    const std::vector<Vector2>& particlePositions() const {
        return _particles.positions;
    }

    SDFObject::ObjectType getBoundaryType() { return _objects->boundary.type; }
    void updateBoundary(SceneObjects* sceneObjs) { delete _objects;  _objects = sceneObjs; }
    void orientBoundary(Float orient) { _objects->boundary.setOrient(orient); _orient = orient;  }

    // friction
    void multFriction(Float mult) {
        _friction = Math::clamp(_friction*mult, 1e-4f, 0.25f); 
        _boundaryFriction = Math::clamp(_boundaryFriction * mult, 1e-4f, 0.25f);
    }
    Float getFriction() const { return _friction; }
    Float getBoundaryFriction() const { return _boundaryFriction; }

private:
    /* Initialization */
    void generateParticles(const SDFObject& sdfObj, Float initialVelocity_y);

    /* Simulation */
    void findNeighbors(const std::vector<Vector2>& pos, std::vector<std::vector<int>>& nbors) const;
    void solveBoundaryConstraints(std::vector<Vector2> &new_pos, Float friction) const;
    void solveParticleConstraints(std::vector<Vector2> &new_pos, const std::vector<std::vector<int>>& nbors, Float friction) const;

    SceneObjects *_objects;
    ParticleData _particles;
    Vector2 _origin;
    Float _cellSize;
    Int _ni, _nj;
    Float gravity = 20.0f;
    Float _boundaryFriction = 0.05f;
    Float _friction = 0.1f;
    Float _orient = 0;
    unsigned int _numConstraintIteration = 2;
};

}}

#endif
