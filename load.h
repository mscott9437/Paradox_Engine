#pragma once

#define GLFW_INCLUDE_NONE
#include <glfw3.h>
#include <glext.h>

void loadWindow();
void eventLoop();
void unloadWindow();

static void loadExtensions();
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
static void framebuffer_size_callback(GLFWwindow *window, int src_width, int src_height);

const int src_width = 1024;
const int src_height = 768;

GLFWwindow *window;

unsigned int VBO, VAO, EBO;

GL_VIEWPORT glViewport;
GL_CLEARCOLOR glClearColor;
GL_CLEAR glClear;
GL_CREATESHADER glCreateShader;
GL_CREATEPROGRAM glCreateProgram;
GL_GETUNIFORMLOCATION glGetUniformLocation;
GL_SHADERSOURCE glShaderSource;
GL_COMPILESHADER glCompileShader;
GL_ATTACHSHADER glAttachShader;
GL_LINKPROGRAM glLinkProgram;
GL_USEPROGRAM glUseProgram;
GL_DELETESHADER glDeleteShader;
GL_GENBUFFERS glGenBuffers;
GL_GENVERTEXARRAYS glGenVertexArrays;
GL_BINDVERTEXARRAY glBindVertexArray;
GL_BINDBUFFER glBindBuffer;
GL_BUFFERDATA glBufferData;
GL_VERTEXATTRIBPOINTER glVertexAttribPointer;
GL_ENABLEVERTEXATTRIBARRAY glEnableVertexAttribArray;
GL_DELETEVERTEXARRAYS glDeleteVertexArrays;
GL_DELETEBUFFERS glDeleteBuffers;
GL_DELETEPROGRAM glDeleteProgram;
GL_GETSHADERIV glGetShaderiv;
GL_GETSHADERINFOLOG glGetShaderInfoLog;
GL_GETPROGRAMIV glGetProgramiv;
GL_GETPROGRAMINFOLOG glGetProgramInfoLog;
GL_GENERATEMIPMAP glGenerateMipmap;
GL_UNIFORM1i glUniform1i;
GL_ACTIVETEXTURE glActiveTexture;
GL_UNIFORMMATRIX4FV glUniformMatrix4fv;
GL_UNIFORM3F glUniform3f;
GL_BUFFERSUBDATA glBufferSubData;
GL_DRAWARRAYS glDrawArrays;
GL_DRAWELEMENTS glDrawElements;
GL_POLYGONMODE glPolygonMode;
GL_LINEWIDTH glLineWidth;
GL_POINTSIZE glPointSize;
GL_GENTEXTURES glGenTextures;
GL_BINDTEXTURE glBindTexture;
GL_TEXPARAMETERI glTexParameteri;
GL_TEXIMAGE2D glTexImage2D;
