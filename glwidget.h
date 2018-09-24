#ifndef QLWIDGET_H
#define QLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QWidget>

class GLwidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLwidget(QWidget *parent = nullptr);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:
};

#endif // GLWIDGET_H
