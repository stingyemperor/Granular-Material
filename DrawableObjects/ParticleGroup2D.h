#ifndef Magnum_Examples_Particle2DGroup_h
#define Magnum_Examples_Particle2DGroup_h

#include <vector>
#include <Corrade/Containers/Pointer.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/SceneGraph/Camera.h>

#include "Shaders/ParticleSphereShader2D.h"

namespace Magnum { namespace Examples {

class ParticleGroup2D {
    public:
        explicit ParticleGroup2D(const std::vector<Vector2>& points, Float particleRadius);

        ParticleGroup2D& draw(Containers::Pointer<SceneGraph::Camera2D>& camera, Int screenHeight, Int projectionHeight);

        bool isDirty() const { return _dirty; }

        ParticleGroup2D& setDirty() {
            _dirty = true;
            return *this;
        }

        Float particleRadius() const { return _particleRadius; }

        ParticleGroup2D& setParticleRadius(Float radius) {
            _particleRadius = radius;
            return *this;
        }

        ParticleSphereShader2D::ColorMode colorMode() const { return _colorMode; }

        ParticleGroup2D& setColorMode(ParticleSphereShader2D::ColorMode colorMode) {
            _colorMode = colorMode;
            return *this;
        }

        const Color3& color() const { return _color; }

        ParticleGroup2D& setColor(const Color3& color) {
            _color = color;
            return *this;
        }

    private:
        const std::vector<Vector2>& _points;
        bool _dirty = false;

        Float _particleRadius = 1.0f;
        ParticleSphereShader2D::ColorMode _colorMode = ParticleSphereShader2D::ColorMode::RampColorById;
        Color3 _color{0.1f};

        GL::Buffer _bufferParticles;
        GL::Mesh   _meshParticles;
        Containers::Pointer<ParticleSphereShader2D> _particleShader;
};

}}

#endif
