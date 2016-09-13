#ifndef WAVEFRONTOBJVERTEX_H
#define WAVEFRONTOBJVERTEX_H

class WaveFrontObjFaceVertex
{
public:
    WaveFrontObjFaceVertex();

    int vertexPosition() const;
    void setVertexPosition(int vertexPosition);

    int textureCoordPosition() const;
    void setTextureCoordPosition(int textureCoordPosition);

private:
    int _vertexPosition;

    int _textureCoordPosition;

};

#endif // WAVEFRONTOBJVERTEX_H
