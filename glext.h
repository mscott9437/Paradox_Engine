#pragma once

#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_CLAMP_TO_EDGE 0x812F 
#define GL_FLOAT 0x1406
#define GL_FALSE 0
#define GL_TRIANGLES 0x0004
#define GL_UNSIGNED_INT 0x1405
#define GL_FRONT_AND_BACK 0x0408
#define GL_LINE 0x1B01
#define GL_POINT 0x1B00
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_REPEAT 0x2901
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_LINEAR 0x2601
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_UNSIGNED_BYTE 0x1401

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF

typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLuint;
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef signed long long int GLsizeiptr;
typedef signed long long int GLintptr;
typedef char GLchar;
typedef unsigned char GLuchar;
typedef unsigned char GLboolean;
typedef float GLfloat;

typedef void (*GL_VIEWPORT)(GLint, GLint, GLsizei, GLsizei);
typedef void (*GL_CLEARCOLOR) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (*GL_CLEAR) (GLbitfield);
typedef void (*GL_SHADERSOURCE) (GLuint, GLsizei, const GLchar**, const GLint*);
typedef void (*GL_COMPILESHADER) (GLuint);
typedef void (*GL_ATTACHSHADER) (GLuint, GLuint);
typedef void (*GL_LINKPROGRAM) (GLuint);
typedef void (*GL_USEPROGRAM) (GLuint);
typedef void (*GL_DELETESHADER) (GLuint);
typedef void (*GL_GENBUFFERS) (GLsizei, GLuint*);
typedef void (*GL_GENVERTEXARRAYS) (GLsizei, GLuint*);
typedef void (*GL_BINDVERTEXARRAY) (GLuint);
typedef void (*GL_BINDBUFFER) (GLenum, GLuint);
typedef void (*GL_BUFFERDATA) (GLenum, GLsizeiptr, const void*, GLenum);
typedef void (*GL_VERTEXATTRIBPOINTER) (GLuint, GLint, GLenum, GLboolean, GLsizei, const void*);
typedef void (*GL_ENABLEVERTEXATTRIBARRAY) (GLuint);
typedef void (*GL_DELETEVERTEXARRAYS) (GLsizei, const GLuint*);
typedef void (*GL_DELETEBUFFERS) (GLsizei, const GLuint*);
typedef void (*GL_DELETEPROGRAM) (GLuint);
typedef void (*GL_GETSHADERIV) (GLuint, GLenum, GLint*);
typedef void (*GL_GETSHADERINFOLOG) (GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (*GL_GETPROGRAMIV) (GLuint, GLenum, GLint*);
typedef void (*GL_GETPROGRAMINFOLOG) (GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (*GL_GENERATEMIPMAP) (GLenum);
typedef void (*GL_UNIFORM1i) (GLint, GLint);
typedef void (*GL_ACTIVETEXTURE) (GLenum);
typedef void (*GL_UNIFORMMATRIX4FV) (GLint, GLsizei, GLboolean, const GLfloat*);
typedef void (*GL_UNIFORM3F) (GLint, GLfloat, GLfloat, GLfloat);
typedef void (*GL_BUFFERSUBDATA) (GLenum, GLintptr, GLsizeiptr, const void*);
typedef void (*GL_DRAWARRAYS) (GLenum, GLint, GLsizei);
typedef void (*GL_DRAWELEMENTS) (GLenum, GLsizei, GLenum, const void*);
typedef void (*GL_POLYGONMODE) (GLenum, GLenum);
typedef void (*GL_LINEWIDTH) (GLfloat);
typedef void (*GL_POINTSIZE) (GLfloat);
typedef void (*GL_GENTEXTURES) (GLsizei, GLuint*);
typedef void (*GL_BINDTEXTURE) (GLenum, GLuint);
typedef void (*GL_TEXPARAMETERI) (GLenum, GLenum, GLint);
typedef void (*GL_TEXIMAGE2D) (GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*);
typedef GLint (*GL_GETUNIFORMLOCATION) (GLuint, const GLchar*);
typedef GLuint (*GL_CREATESHADER) (GLenum);
typedef GLuint (*GL_CREATEPROGRAM) (void);
