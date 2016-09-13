#include "wavefrontobjfacevertex.h"

WaveFrontObjFaceVertex::WaveFrontObjFaceVertex()
{
}
int WaveFrontObjFaceVertex::textureCoordPosition() const
{
    return _textureCoordPosition;
}

void WaveFrontObjFaceVertex::setTextureCoordPosition(int textureCoordPosition)
{
    _textureCoordPosition = textureCoordPosition;
}
int WaveFrontObjFaceVertex::vertexPosition() const
{
    return _vertexPosition;
}

void WaveFrontObjFaceVertex::setVertexPosition(int vertexPosition)
{
    _vertexPosition = vertexPosition;
}


