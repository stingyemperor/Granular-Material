
#include "DrawableObjects/ParticleGroup2D.h"

#include <Corrade/Utility/Assert.h>
#include <Corrade/Containers/ArrayView.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Functions.h>
#include <Magnum/Shaders/Generic.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/Trade/MeshData.h>

namespace Magnum { namespace Examples {

using namespace Math::Literals;

ParticleGroup2D::ParticleGroup2D(const std::vector<Vector2>& points, Float particleRadius):
    _points{points},
    _particleRadius{particleRadius},
    _meshParticles{GL::MeshPrimitive::Points}
{
    _meshParticles.addVertexBuffer(_bufferParticles, 0, Shaders::Generic2D::Position{});
    _particleShader.reset(new ParticleSphereShader2D);
}

ParticleGroup2D& ParticleGroup2D::draw(Containers::Pointer<SceneGraph::Camera2D>& camera, Int screenHeight, Int projectionHeight) {
    if(_points.empty()) return *this;

    if(_dirty) {
        Containers::ArrayView<const float> data(reinterpret_cast<const float*>(&_points[0]), _points.size() * 2);
        _bufferParticles.setData(data);
        _meshParticles.setCount(Int(_points.size()));
        _dirty = false;
    }

    (*_particleShader)
        /* particle data */
        .setNumParticles(Int(_points.size()))
        .setParticleRadius(_particleRadius)
        /* sphere render data */
        .setColorMode(_colorMode)
        .setColor(_color)
        /* view/prj matrices and size */
        .setViewProjectionMatrix(camera->projectionMatrix()*camera->cameraMatrix())
        .setScreenHeight(screenHeight)
        .setDomainHeight(projectionHeight)
        .draw(_meshParticles);

    return *this;
}
} }
