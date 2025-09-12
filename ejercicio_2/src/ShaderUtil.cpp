#include "../include/ShaderUtil.h"

/** Constructor
 * Lee, compila y enlaza los shaders desde los archivos proporcionados.
 * @param vertexPath Ruta al archivo del shader de vértices.
 * @param fragmentPath Ruta al archivo del shader de fragmentos.
 * @return Un objeto ShaderUtil con el programa de shaders listo para usar.
 */
ShaderUtil::ShaderUtil(const std::string& vertexPath, const std::string& fragmentPath) {
    //Lee el código fuente de los shaders
    std::string vertexCode = readShaderSource(vertexPath);
    std::string fragmentCode = readShaderSource(fragmentPath);

    //Compila los shaders
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

    //Enlaza los shaders en un programa
    programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    //Verifica errores en el enlace
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //Elimina los shaders ya enlazados al programa
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

/**
 * Activa el programa de shaders.
 */
void ShaderUtil::use() const {
    glUseProgram(programID);
}

/**
 * Obtener el ID del programa de shaders.
 * @return El ID del programa de shaders.
 */
GLuint ShaderUtil::getProgramID() const {
    return programID;
}

/**
 * Lee el código de un shader desde un archivo.
 * @param filePath Ruta al archivo del shader.
 * @return El código fuente del shader.
 */
std::string ShaderUtil::readShaderSource(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;

    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo de shader: " << filePath << std::endl;
        return "";
    }

    buffer << file.rdbuf();
    return buffer.str();
}

/**
 * Compila un shader.
 * @param type Tipo de shader (GL_VERTEX_SHADER o GL_FRAGMENT_SHADER).
 * @param source Código del shader.
 * @return El ID del shader compilado.
 */
GLuint ShaderUtil::compileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);
    const char* code = source.c_str();
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);

    //Verifica errores en la compilación
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}