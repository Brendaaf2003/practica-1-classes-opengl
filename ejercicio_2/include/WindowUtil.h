#ifndef WINDOWUTIL_H
#define WINDOWUTIL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderUtil.h"

class WindowUtil {
private:
    //Ventana
    GLFWwindow* window;

public:
    //Constructor que toma el tamaño de la ventana
    WindowUtil(int ancho, int alto, const char* titulo);
    //Método para controlar la renderización
    void renderizar(const ShaderUtil& shader, const float* vertices, const float* colors, int numVertices);
    //Con este método tenemos la ventana
    GLFWwindow* getWindow();
};

#endif