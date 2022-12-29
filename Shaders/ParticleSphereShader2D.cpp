#include "Shaders/ParticleSphereShader2D.h"

#include <Corrade/Containers/Reference.h>
#include <Corrade/Utility/Resource.h>
#include <Magnum/GL/Shader.h>
#include <Magnum/GL/Version.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Math/Matrix3.h>

namespace Magnum { namespace Examples {

ParticleSphereShader2D::ParticleSphereShader2D() {
    Utility::Resource rs("data");

    GL::Shader vertShader{ GL::Version::GL330, GL::Shader::Type::Vertex };
    GL::Shader fragShader{ GL::Version::GL330, GL::Shader::Type::Fragment };
    vertShader.addSource(rs.get("ParticleSphereShader2D.vert"));
    fragShader.addSource(rs.get("ParticleSphereShader2D.frag"));

    CORRADE_INTERNAL_ASSERT(GL::Shader::compile({ vertShader, fragShader }));
    attachShaders({vertShader, fragShader});
    CORRADE_INTERNAL_ASSERT(link());

    _uNumParticles = uniformLocation("numParticles");
    _uParticleRadius = uniformLocation("particleRadius");

    _uColorMode = uniformLocation("colorMode");
    _uColor = uniformLocation("uniformColor");

    _uViewProjectionMatrix = uniformLocation("viewProjectionMatrix");
    _uScreenHeight = uniformLocation("screenHeight");
    _uDomainHeight = uniformLocation("domainHeight");
}

ParticleSphereShader2D& ParticleSphereShader2D::setNumParticles(Int numParticles) {
    setUniform(_uNumParticles, numParticles);
    return *this;
}

ParticleSphereShader2D& ParticleSphereShader2D::setParticleRadius(Float radius) {
    setUniform(_uParticleRadius, radius);
    return *this;
}

ParticleSphereShader2D& ParticleSphereShader2D::setColorMode(Int colorMode) {
    setUniform(_uColorMode, colorMode);
    return *this;
}

ParticleSphereShader2D& ParticleSphereShader2D::setColor(const Color3& color) {
    setUniform(_uColor, color);
    return *this;
}

ParticleSphereShader2D& ParticleSphereShader2D::setViewProjectionMatrix(const Matrix3& matrix) {
    setUniform(_uViewProjectionMatrix, matrix);
    return *this;
}

ParticleSphereShader2D& ParticleSphereShader2D::setScreenHeight(Int height) {
    setUniform(_uScreenHeight, height);
    return *this;
}

ParticleSphereShader2D& ParticleSphereShader2D::setDomainHeight(Int height) {
    setUniform(_uDomainHeight, height);
    return *this;
}
} }
