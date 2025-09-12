//Header el cual su proposito es es declarar interfaces, clases, funciones, constantes, etc. 
//Vamos a hacer la implementacion de los métodos en otro archivo (ShaderUtil.cpp)
#ifndef SHADERUTIL_H
#define SHADERUTIL_H

//Importamos librerias 
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h> //libreria de OpenGL Extension Wrangler para manejar las extensiones de OpenGL

//Esta clase cargara, compilara y enlazara shaders de OpenGL
class ShaderUtil {
private:
    // ID del programa de shader
    GLuint programID;

    //Vamos a lleer el código de un shader desde un archivo y se devuleve con un string
    std::string readShaderSource(const std::string& filePath);
    //compileShader va a compilar el código de un shader y devuelve su ID
    GLuint compileShader(GLenum type, const std::string& source);

public:
//Para nuestros métodos públicos 
    //Constructor de la clase ShaderUtil
    ShaderUtil(const std::string& vertexPath, const std::string& fragmentPath);
    void use() const;
    //Se nos devuelve el identificador del programa de shaders
    GLuint getProgramID() const;
};

#endif