#include "WindowUtil.h"
#include "ShaderUtil.h"

int main() {
    //Crea un objeto de la clase WindowUtil y ShaderUtil
    WindowUtil ventana(800, 600, "OpenGL con Clases");
    ShaderUtil shader("../shaders/shader.vert", "../shaders/shader.frag");

    //Configuración de los datos de los vértices y colores
    float vertices[] = {
        //Triángulo equilátero
        -0.9f,  0.9f, 0.0f,
        -0.7f,  0.9f, 0.0f,
        -0.8f,  0.7f, 0.0f,

        //Cuadrado (2 triángulos)
        -0.5f,  0.9f, 0.0f,
        -0.3f,  0.9f, 0.0f,
        -0.3f,  0.7f, 0.0f,

        -0.5f,  0.9f, 0.0f,
        -0.3f,  0.7f, 0.0f,
        -0.5f,  0.7f, 0.0f,

        //Rectángulo (2 triángulos)
        0.0f,  0.9f, 0.0f,
        0.3f,  0.9f, 0.0f,
        0.3f,  0.7f, 0.0f,

        0.0f,  0.9f, 0.0f,
        0.3f,  0.7f, 0.0f,
        0.0f,  0.7f, 0.0f,

        //Rombo (2 triángulos)
        //Triángulo superior
        -0.2f, -0.2f, 0.0f,
        0.0f,  0.0f, 0.0f,
        0.2f, -0.2f, 0.0f,

        //Triángulo inferior
        -0.2f, -0.2f, 0.0f,
        0.0f, -0.4f, 0.0f,
        0.2f, -0.2f, 0.0f,
    };

    float colors[] = {
        //Triángulo equilátero
        1.0f, 0.7f, 0.8f,
        1.0f, 0.7f, 0.8f,
        1.0f, 0.7f, 0.8f,

        //Cuadrado
        1.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f,

        //Rectángulo
        0.5f, 0.5f, 0.0f,
        0.5f, 0.0f, 0.5f,
        0.0f, 0.5f, 0.5f,

        0.5f, 0.5f, 0.0f,
        0.0f, 0.5f, 0.5f,
        0.5f, 0.0f, 0.5f,

        //Rombo
        //Colores para el triángulo superior
        0.9f, 0.9f, 0.9f,
        0.9f, 0.9f, 0.9f,
        0.9f, 0.9f, 0.9f,

        //Colores para el triángulo inferior
        0.9f, 0.9f, 0.9f,
        0.9f, 0.9f, 0.9f,
        0.9f, 0.9f, 0.9f,
    };

    //renderiza las formas
    ventana.renderizar(shader, vertices, colors, 21);

    return 0;
}