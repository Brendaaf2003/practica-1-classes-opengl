#include "../include/WindowUtil.h"

/**
 * Constructor de la clase WindowUtil.
 * @param ancho Ancho de la ventana.
 * @param alto Alto de la ventana.
 * @param titulo Título de la ventana.
 */
WindowUtil::WindowUtil(int ancho, int alto, const char* titulo) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
    }

    //Configuración de la versión de OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(ancho, alto, titulo, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
    }
    glfwMakeContextCurrent(window);
    //Inicialización de GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
    }
}

/** Renderiza una escena utilizando el shader proporcionado. */
void WindowUtil::renderizar(const ShaderUtil& shader, const float* vertices, const float* colors, int numVertices) {
    GLuint VAO, VBO, VBOcolor;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VBOcolor);

    glBindVertexArray(VAO);

    //Vértices
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    //Colores
    glBindBuffer(GL_ARRAY_BUFFER, VBOcolor);
    glBufferData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(float), colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    //Bucle de renderizado
    while (!glfwWindowShouldClose(window)) {
        //procesar entrada
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        //Renderizado
        glClearColor(0.0f, 0.3f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Uso del shader
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, numVertices);
        glBindVertexArray(0);

        //Intercambio de buffers y eventos
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Liberar recursos
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &VBOcolor);
    glfwTerminate();
}

//Obtiene la ventana
GLFWwindow* WindowUtil::getWindow() {
    return window;
}