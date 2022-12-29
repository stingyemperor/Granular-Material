#ifndef Magnum_Examples_DrawableObjects_FlatShadeObject2D_h
#define Magnum_Examples_DrawableObjects_FlatShadeObject2D_h

#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/Flat.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/MatrixTransformation2D.h>

namespace Magnum { namespace Examples {

using Object2D = SceneGraph::Object<SceneGraph::MatrixTransformation2D>;

class FlatShadeObject2D: public SceneGraph::Drawable2D {
    public:
        explicit FlatShadeObject2D(Object2D& object, Shaders::Flat2D& shader, const Color3& color, GL::Mesh& mesh, SceneGraph::DrawableGroup2D* const drawables):
            SceneGraph::Drawable2D{object, drawables}, _shader(shader), _color(color), _mesh(mesh) {}

        void draw(const Matrix3& transformation, SceneGraph::Camera2D& camera) override {
            if(!_bEnabled) return;

            _shader
                .setColor(_color)
                .setTransformationProjectionMatrix(camera.projectionMatrix()*transformation)
                .draw(_mesh);
        }

        FlatShadeObject2D& setColor(const Color3& color) {
            _color = color;
            return *this;
        }
        FlatShadeObject2D& setEnabled(bool bEnabled) {
            _bEnabled = bEnabled;
            return *this;
        }

    private:
        Shaders::Flat2D& _shader;
        Color3 _color;
        GL::Mesh& _mesh;
        bool _bEnabled = true;
};

}}

#endif
