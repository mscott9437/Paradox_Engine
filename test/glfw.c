#include <stdio.h>
#include <string.h>

#include <ft2build.h>
#include FT_FREETYPE_H
//#include FT_GLYPH_H

#include <GLFW/glfw3.h>
#include <sqlite3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define CGLM_ALL_UNALIGNED
#include <cglm/cglm.h>

#define MAX_SIZE 65536

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

typedef char GLchar;
typedef signed long long int GLsizeiptr;
typedef signed long long int GLintptr;

typedef GLuint (*GL_CREATESHADER) (GLenum);
GL_CREATESHADER glCreateShader  = NULL;
typedef GLuint (*GL_CREATEPROGRAM) (void);
GL_CREATEPROGRAM glCreateProgram  = NULL;
typedef GLint (*GL_GETUNIFORMLOCATION) (GLuint, const GLchar*);
GL_GETUNIFORMLOCATION glGetUniformLocation  = NULL;
typedef void (*GL_SHADERSOURCE) (GLuint, GLsizei, const GLchar**, const GLint*);
GL_SHADERSOURCE glShaderSource  = NULL;
typedef void (*GL_COMPILESHADER) (GLuint);
GL_COMPILESHADER glCompileShader  = NULL;
typedef void (*GL_ATTACHSHADER) (GLuint, GLuint);
GL_ATTACHSHADER glAttachShader  = NULL;
typedef void (*GL_LINKPROGRAM) (GLuint);
GL_LINKPROGRAM glLinkProgram  = NULL;
typedef void (*GL_USEPROGRAM) (GLuint);
GL_USEPROGRAM glUseProgram  = NULL;
typedef void (*GL_DELETESHADER) (GLuint);
GL_DELETESHADER glDeleteShader  = NULL;
typedef void (*GL_GENBUFFERS) (GLsizei, GLuint*);
GL_GENBUFFERS glGenBuffers  = NULL;
typedef void (*GL_GENVERTEXARRAYS) (GLsizei, GLuint*);
GL_GENVERTEXARRAYS glGenVertexArrays = NULL;
typedef void (*GL_BINDVERTEXARRAY) (GLuint);
GL_BINDVERTEXARRAY glBindVertexArray  = NULL;
typedef void (*GL_BINDBUFFER) (GLenum, GLuint);
GL_BINDBUFFER glBindBuffer  = NULL;
typedef void (*GL_BUFFERDATA) (GLenum, GLsizeiptr, const void*, GLenum);
GL_BUFFERDATA glBufferData  = NULL;
typedef void (*GL_VERTEXATTRIBPOINTER) (GLuint, GLint, GLenum, GLboolean, GLsizei, const void*);
GL_VERTEXATTRIBPOINTER glVertexAttribPointer  = NULL;
typedef void (*GL_ENABLEVERTEXATTRIBARRAY) (GLuint);
GL_ENABLEVERTEXATTRIBARRAY glEnableVertexAttribArray  = NULL;
typedef void (*GL_DELETEVERTEXARRAYS) (GLsizei, const GLuint*);
GL_DELETEVERTEXARRAYS glDeleteVertexArrays  = NULL;
typedef void (*GL_DELETEBUFFERS) (GLsizei, const GLuint*);
GL_DELETEBUFFERS glDeleteBuffers  = NULL;
typedef void (*GL_DELETEPROGRAM) (GLuint);
GL_DELETEPROGRAM glDeleteProgram  = NULL;
typedef void (*GL_GETSHADERIV) (GLuint, GLenum, GLint*);
GL_GETSHADERIV glGetShaderiv  = NULL;
typedef void (*GL_GETSHADERINFOLOG) (GLuint, GLsizei, GLsizei*, GLchar*);
GL_GETSHADERINFOLOG glGetShaderInfoLog  = NULL;
typedef void (*GL_GETPROGRAMIV) (GLuint, GLenum, GLint*);
GL_GETPROGRAMIV glGetProgramiv = NULL;
typedef void (*GL_GETPROGRAMINFOLOG) (GLuint, GLsizei, GLsizei*, GLchar*);
GL_GETPROGRAMINFOLOG glGetProgramInfoLog = NULL;
typedef void (*GL_GENERATEMIPMAP) (GLenum);
GL_GENERATEMIPMAP glGenerateMipmap  = NULL;
typedef void (*GL_UNIFORM1i) (GLint, GLint);
GL_UNIFORM1i glUniform1i  = NULL;
typedef void (*GL_ACTIVETEXTURE) (GLenum);
GL_ACTIVETEXTURE glActiveTexture  = NULL;
typedef void (*GL_UNIFORMMATRIX4FV) (GLint, GLsizei, GLboolean, const GLfloat*);
GL_UNIFORMMATRIX4FV glUniformMatrix4fv = NULL;
typedef void (*GL_UNIFORM3F) (GLint, GLfloat, GLfloat, GLfloat);
GL_UNIFORM3F glUniform3f  = NULL;
typedef void (*GL_BUFFERSUBDATA) (GLenum, GLintptr, GLsizeiptr, const void*);
GL_BUFFERSUBDATA glBufferSubData  = NULL;

static int callback(void*, int, char**, char**);

void loadRepl(sqlite3*, char*, int);

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);

void checkCompileErrors(unsigned int, char const*);

unsigned int loadShaders(char[], char[], char[]);
unsigned int loadTexture(unsigned int, char[], int, int);

void loadFont(unsigned int);
void RenderText(unsigned int, char[], float, float, float, vec3);

void loadDriver();

const unsigned int width = 800;
const unsigned int height = 600;

struct Character {
   unsigned int TextureID;
   int SizeX;
   int SizeY;
   int BearingX;
   int BearingY;
   unsigned int Advance;
};

unsigned int VBO, VAO;
unsigned int EBO;

struct Character character;

int main()
{
   char cmd[MAX_SIZE];
   sqlite3 *db;
   char *zErrMsg = 0;

   int rc = sqlite3_open("db/test.db", &db);

   FILE *fp = fopen("db/init.sql" , "r");
   while (fgets(cmd, MAX_SIZE, fp) != NULL) rc = sqlite3_exec(db, cmd, NULL, NULL, NULL);
   fclose(fp);

   //loadRepl(db, zErrMsg, rc);

   char *sql = "select * from users";
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   sqlite3_close(db);

   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   GLFWwindow *window = glfwCreateWindow(width, height, "Parallax Engine", NULL, NULL);
   glfwMakeContextCurrent(window);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   loadDriver();

   glGenVertexArrays(1, &VAO);
   glGenBuffers(1, &VBO);
   glGenBuffers(1, &EBO);

   glBindVertexArray(VAO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);

   //float vertices[] = { -0.5f, -0.5f, 0.0f,   0.5f, -0.5f, 0.0f,   0.0f,  0.5f, 0.0f };
   //float vertices[] = { 0.5f,  0.5f, 0.0f,   0.5f, -0.5f, 0.0f,   -0.5f, -0.5f, 0.0f,   -0.5f,  0.5f, 0.0f  };
   //float vertices[] = { 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f };

   //float vertices[] = { 0.5f,  0.5f, 0.0f,   0.5f, -0.5f, 0.0f,   -0.5f,  0.5f, 0.0f,   0.5f, -0.5f, 0.0f,   -0.5f, -0.5f, 0.0f,   -0.5f,  0.5f, 0.0f };

   float vertices[] = { 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,   -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f };

   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
   //glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

   unsigned int indices[] = { 0, 1, 3,   1, 2, 3 };
   //unsigned int indices[] = { 0, 1, 3,   1, 2, 3 };

   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
   //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
   //glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

   glEnableVertexAttribArray(0);

   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
   //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
   glEnableVertexAttribArray(1);

   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
   glEnableVertexAttribArray(2);

   glBindBuffer(GL_ARRAY_BUFFER, 0);

   //unsigned int program = loadShaders("db/test.vs", "db/test.fs", "");
   //unsigned int program = loadShaders("db/colors.vs", "db/colors.fs", "");
   unsigned int program = loadShaders("db/texture.vs", "db/texture.fs", "");
   //unsigned int program = loadShaders("db/freetype.vs", "db/freetype.fs", "");

   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

   //glLineWidth(1);
   //glPointSize(1);

   unsigned int texture1 = loadTexture(program, "db/container.bmp", GLFW_FALSE, GLFW_FALSE);
   //unsigned int texture2 = loadTexture(program, "db/awesomeface.png", GLFW_TRUE, GLFW_TRUE);

   glUseProgram(program);

   glUniform1i(glGetUniformLocation(program, "texture1"), 0);
   //glUniform1i(glGetUniformLocation(program, "texture2"), 1);

   //GLuint texture;
   //texture= LoadTexture( "your_image_name.bmp" );
   //glBindTexture (GL_TEXTURE_2D, texture);

   //
   //fread(data, 54, 1, file)

   //glEnable(GL_CULL_FACE);
   //glEnable(GL_BLEND);
   //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   //loadFont(program);

   glBindVertexArray(0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   while (!glfwWindowShouldClose(window))
   {
      processInput(window);

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, texture1);
      //glActiveTexture(GL_TEXTURE1);
      //glBindTexture(GL_TEXTURE_2D, texture2);

      glUseProgram(program);
      glBindVertexArray(VAO);

      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

      //glDrawArrays(GL_TRIANGLES, 0, 3);
      //glDrawArrays(GL_TRIANGLES, 0, 6);

      //RenderText(program, "@", 25.0f, 25.0f, 1.0f, (vec3){0.5, 0.8f, 0.2f});
      //RenderText(program, "@", 540.0f, 570.0f, 0.5f, (vec3){0.3, 0.7f, 0.9f});

      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glDeleteVertexArrays(1, &VAO);

   glDeleteBuffers(1, &VBO);
   glDeleteBuffers(1, &EBO);
   glDeleteProgram(program);

   glfwTerminate();

   return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   for(int i = 0; i<argc; i++) printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   printf("%s", "\n");

   return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
   glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void checkCompileErrors(unsigned int shader, char const* type)
{
   int success;
   char infoLog[1024];

   if (strcmp(type, "PROGRAM") != 0)
   {
      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

      if (!success)
      {
         glGetShaderInfoLog(shader, 1024, NULL, infoLog);
         printf("%s%s\n%s", "ERROR::", type, infoLog);
      }
   }
   else
   {
      glGetProgramiv(shader, GL_LINK_STATUS, &success);

      if (!success)
      {
         glGetProgramInfoLog(shader, 1024, NULL, infoLog);
         printf("%s%s\n%s", "ERROR::", type, infoLog);
      }
   }
}

void RenderText(unsigned int shader, char text[], float x, float y, float scale, vec3 color)
{
   struct Character ch = character;
   float xpos = x + ch.BearingX * scale;
   float ypos = y - (ch.SizeY - ch.BearingY) * scale;
   float w = ch.SizeX * scale;
   float h = ch.SizeY * scale;

   float vertices[6][4] = {
      {xpos, ypos + h, 0.0f, 0.0f},
      {xpos, ypos, 0.0f, 1.0f},
      {xpos + w, ypos, 1.0f, 1.0f},

      {xpos, ypos + h, 0.0f, 0.0f},
      {xpos + w, ypos, 1.0f, 1.0f},
      {xpos + w, ypos + h, 1.0f, 0.0f}
   };

   glUseProgram(shader);
   glUniform3f(glGetUniformLocation(shader, "textColor"), color[0], color[1], color[2]);
   glActiveTexture(GL_TEXTURE0);

   glBindVertexArray(VAO);
   glBindTexture(GL_TEXTURE_2D, ch.TextureID);

   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   glDrawArrays(GL_TRIANGLES, 0, 6);

   // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
   x += (ch.Advance >> 6) * scale;

   glBindVertexArray(0);
   glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int loadShaders(char vShader[], char fShader[], char gShader[])
{
   char line[MAX_SIZE], vDest[MAX_SIZE], fDest[MAX_SIZE];
   //char gDest[MAX_SIZE];

   FILE *vShaderFile = fopen(vShader, "r");
   while (fgets(line, MAX_SIZE, vShaderFile) != NULL) strcat(vDest, line);
   fclose(vShaderFile);
   const char *vShaderCode = vDest;

   FILE *fShaderFile = fopen(fShader, "r");
   while (fgets(line, MAX_SIZE, fShaderFile) != NULL) strcat(fDest, line);
   fclose(fShaderFile);
   const char *fShaderCode = fDest;

   //FILE *gShaderFile = fopen(gShader, "r");
   //while (fgets(line, MAX_SIZE, gShaderFile) != NULL) strcat(gDest, line);
   //fclose(gShaderFile);
   //const char *gShaderCode = gDest;

   unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
   unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   //unsigned int geometryShader = glCreateShader(GL_GEOMETRY_SHADER);

   glShaderSource(vertexShader, 1, &vShaderCode, NULL);
   glCompileShader(vertexShader);
   checkCompileErrors(vertexShader, "VERTEX");

   glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
   glCompileShader(fragmentShader);
   checkCompileErrors(fragmentShader, "FRAGMENT");

   //glShaderSource(geometryShader, 1, &gShaderCode, NULL);
   //glCompileShader(geometryShader);

   //checkCompileErrors(geometryShader, "GEOMETRY");

   unsigned int ID = glCreateProgram();

   glAttachShader(ID, vertexShader);
   glAttachShader(ID, fragmentShader);
   //glAttachShader(ID, geometryShader);

   glLinkProgram(ID);
   checkCompileErrors(ID, "PROGRAM");

   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);
   //glDeleteShader(geometryShader);

   return ID;
}

//GLuint LoadTexture(const char * filename)
unsigned int loadTexture(unsigned int program, char path[], int alpha, int flip)
{
   //unsigned int texture;
   GLuint texture;

   int width = 512;
   int height = 512;

   FILE * file;
   file = fopen(path, "rb");

   if (file == NULL) return 0;

   unsigned char *data = (unsigned char *)malloc(width * height * 3);

   //
   //int size = fseek(file,);

   fread(data, width * height * 3, 1, file);
   fclose(file);

   for(int i = 0; i < width * height; ++i)
   {
      int index = i * 3;
      unsigned char B,R;
      B = data[index];
      R = data[index + 2];

      data[index] = R;
      data[index + 2] = B;
   }

   //glGenTextures(1, &texture);
   //glBindTexture(GL_TEXTURE_2D, texture);
  //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

   //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   //gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

   //free(data);

   //return texture;

   glGenTextures(1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture); 

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   //int tWidth, tHeight, nrChannels;

   //if (flip) stbi_set_flip_vertically_on_load(GLFW_TRUE); else stbi_set_flip_vertically_on_load(GLFW_FALSE);

   //unsigned char *data = stbi_load(path, &tWidth, &tHeight, &nrChannels, 0);

   if (!alpha)
   {
      //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tWidth, tHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
   }
   else
   {
      //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tWidth, tHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
   }

   glGenerateMipmap(GL_TEXTURE_2D);

   //stbi_image_free(data);

   //glBindTexture(GL_TEXTURE_2D, 0);

   return texture;
}

void loadRepl(sqlite3 *db, char *zErrMsg, int rc)
{
   int i;
   char str[MAX_SIZE + 3];

   while (1)
   {
      fgets(str, sizeof(str), stdin);
      i = 0;
      while (str[i] != '\0')
      {
         if (i > MAX_SIZE)
         {
            puts("error: StreamTooLong");
            //return 1;
         }
         i++;
      }
      printf("INPUT::%s%", str);
      rc = sqlite3_exec(db, str, callback, 0, &zErrMsg);
   }
}

void loadFont(unsigned int ID)
{
   mat4 projection;
   glm_ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f, projection);

   glUseProgram(ID);

   glUniformMatrix4fv(glGetUniformLocation(ID, "projection"), 1, GL_FALSE, *projection);

   FT_Library ft;
   FT_Face face;

   FT_Init_FreeType(&ft);
   FT_New_Face(ft, "db/FiraMono-Regular.ttf", 0, &face);

   FT_Set_Pixel_Sizes(face, 0, 48);
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   unsigned char c = 64;

   FT_Load_Char(face, c, FT_LOAD_RENDER);
   
   unsigned int texture;

   glGenTextures(1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture);

   glTexImage2D(
      GL_TEXTURE_2D,
      0,
      GL_RED,
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      0,
      GL_RED,
      GL_UNSIGNED_BYTE,
      face->glyph->bitmap.buffer
   );

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   character.TextureID = texture,
   character.SizeX = face -> glyph -> bitmap.width;
   character.SizeY = face -> glyph -> bitmap.rows;
   character.BearingX = face -> glyph -> bitmap_left;
   character.BearingY = face -> glyph -> bitmap_top;
   character.Advance = face -> glyph -> advance.x;

   glBindTexture(GL_TEXTURE_2D, 0);

   FT_Done_Face (face);
   FT_Done_FreeType(ft);
}

void loadDriver()
{
   glGenVertexArrays  = (GL_GENVERTEXARRAYS)glfwGetProcAddress("glGenVertexArrays");
   glGenBuffers  = (GL_GENBUFFERS)glfwGetProcAddress("glGenBuffers");
   glBindVertexArray  = (GL_BINDVERTEXARRAY)glfwGetProcAddress("glBindVertexArray");
   glBindBuffer  = (GL_BINDBUFFER)glfwGetProcAddress("glBindBuffer");
   glBufferData  = (GL_BUFFERDATA)glfwGetProcAddress("glBufferData");
   glVertexAttribPointer  = (GL_VERTEXATTRIBPOINTER)glfwGetProcAddress("glVertexAttribPointer");
   glEnableVertexAttribArray  = (GL_ENABLEVERTEXATTRIBARRAY)glfwGetProcAddress("glEnableVertexAttribArray");
   glUniform1i  = (GL_UNIFORM1i)glfwGetProcAddress("glUniform1i");
   glActiveTexture  = (GL_ACTIVETEXTURE)glfwGetProcAddress("glActiveTexture");
   glUseProgram  = (GL_USEPROGRAM)glfwGetProcAddress("glUseProgram");
   glDeleteVertexArrays  = (GL_DELETEVERTEXARRAYS)glfwGetProcAddress("glDeleteVertexArrays");
   glDeleteBuffers  = (GL_DELETEBUFFERS)glfwGetProcAddress("glDeleteBuffers");
   glDeleteProgram  = (GL_DELETEPROGRAM)glfwGetProcAddress("glDeleteProgram");
   glGetShaderiv  = (GL_GETSHADERIV)glfwGetProcAddress("glGetShaderiv");
   glGetShaderInfoLog  = (GL_GETSHADERINFOLOG)glfwGetProcAddress("glGetShaderInfoLog");
   glGetProgramiv = (GL_GETPROGRAMIV)glfwGetProcAddress("glGetProgramiv");
   glGetProgramInfoLog = (GL_GETPROGRAMINFOLOG)glfwGetProcAddress("glGetProgramInfoLog");
   glUniform3f  = (GL_UNIFORM3F)glfwGetProcAddress("glUniform3f");
   glGetUniformLocation  = (GL_GETUNIFORMLOCATION)glfwGetProcAddress("glGetUniformLocation");
   glBufferSubData  = (GL_BUFFERSUBDATA)glfwGetProcAddress("glBufferSubData");
   glCreateShader  = (GL_CREATESHADER)glfwGetProcAddress("glCreateShader");
   glShaderSource  = (GL_SHADERSOURCE)glfwGetProcAddress("glShaderSource");
   glCompileShader  = (GL_COMPILESHADER)glfwGetProcAddress("glCompileShader");
   glCreateProgram  = (GL_CREATEPROGRAM)glfwGetProcAddress("glCreateProgram");
   glAttachShader  = (GL_ATTACHSHADER)glfwGetProcAddress("glAttachShader");
   glLinkProgram  = (GL_LINKPROGRAM)glfwGetProcAddress("glLinkProgram");
   glDeleteShader  = (GL_DELETESHADER)glfwGetProcAddress("glDeleteShader");
   glGenerateMipmap  = (GL_GENERATEMIPMAP)glfwGetProcAddress("glGenerateMipmap");
   glUniformMatrix4fv = (GL_UNIFORMMATRIX4FV)glfwGetProcAddress("glUniformMatrix4fv");
}
