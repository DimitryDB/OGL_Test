#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>

struct VertexData
{
    VertexData()
    {
    }
     VertexData(QVector3D p,  QVector2D t, QVector3D n) : position(p),
       texCoord(t), normal(n)
     {
     }

    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void initShaders();
    void initCube(float);

private:
    QMatrix4x4 m_projectionMatrix;
    QOpenGLShaderProgram m_program;
    QOpenGLTexture *m_texture;
    QOpenGLBuffer m_arrayBuffer;
    QOpenGLBuffer m_indexBuffer;

};

#endif // WIDGET_H
