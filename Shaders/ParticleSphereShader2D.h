#ifndef Magnum_Examples_ParticleSphereFlatShader_h
#define Magnum_Examples_ParticleSphereFlatShader_h

#include <Magnum/GL/AbstractShaderProgram.h>

namespace Magnum { namespace Examples {

class ParticleSphereShader2D: public GL::AbstractShaderProgram {
    public:
        enum ColorMode {
            UniformDiffuseColor = 0,
            RampColorById
        };

        explicit ParticleSphereShader2D();

        ParticleSphereShader2D& setNumParticles(Int numParticles);
        ParticleSphereShader2D& setParticleRadius(Float radius);

        ParticleSphereShader2D& setColorMode(Int colorMode);
        ParticleSphereShader2D& setColor(const Color3& color);

        ParticleSphereShader2D& setViewport(const Vector2i& viewport);
        ParticleSphereShader2D& setViewProjectionMatrix(const Matrix3& matrix);
        ParticleSphereShader2D& setScreenHeight(Int height);
        ParticleSphereShader2D& setDomainHeight(Int height);

    private:
        Int _uNumParticles,
            _uParticleRadius,
            _uColorMode,
            _uColor,
            _uViewProjectionMatrix,
            _uScreenHeight,
            _uDomainHeight;
};

}}

#endif
