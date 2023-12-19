#include <stdio.h>
#include <stdlib.h>

#include "load.h"

void loadWindow()
{
   window = glfwCreateWindow(src_width, src_height, "Parallax Engine", NULL, NULL);

   if (!window)
   {
      fprintf(stderr, "ERROR::glfwCreateWindow()\n");
      exit(EXIT_FAILURE);
   }

   glfwSetKeyCallback(window, key_callback);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   glfwMakeContextCurrent(window);
   
   loadExtensions();

   glGenVertexArrays(1, &VAO);
   glGenBuffers(1, &VBO);
   glGenBuffers(1, &EBO);

   glBindVertexArray(VAO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

   // load vertices

   glBindBuffer(GL_ARRAY_BUFFER, 0);

   // load shaders

   glBindVertexArray(0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   glfwSwapInterval(1);
}

void eventLoop()
{
   while (!glfwWindowShouldClose(window))
   {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(window);
      glfwPollEvents();
   }
}

void unloadWindow()
{
   glfwDestroyWindow(window);

   glDeleteVertexArrays(1, &VAO);
   glDeleteBuffers(1, &VBO);
   glDeleteBuffers(1, &EBO);
}

static void loadExtensions()
{
   glViewport = (GL_VIEWPORT)glfwGetProcAddress("glViewport");
   glClearColor = (GL_CLEARCOLOR)glfwGetProcAddress("glClearColor");
   glClear = (GL_CLEAR)glfwGetProcAddress("glClear");
   glGenVertexArrays = (GL_GENVERTEXARRAYS)glfwGetProcAddress("glGenVertexArrays");
   glGenBuffers = (GL_GENBUFFERS)glfwGetProcAddress("glGenBuffers");
   glBindVertexArray = (GL_BINDVERTEXARRAY)glfwGetProcAddress("glBindVertexArray");
   glBindBuffer = (GL_BINDBUFFER)glfwGetProcAddress("glBindBuffer");
   glBufferData = (GL_BUFFERDATA)glfwGetProcAddress("glBufferData");
   glVertexAttribPointer = (GL_VERTEXATTRIBPOINTER)glfwGetProcAddress("glVertexAttribPointer");
   glEnableVertexAttribArray = (GL_ENABLEVERTEXATTRIBARRAY)glfwGetProcAddress("glEnableVertexAttribArray");
   glUniform1i = (GL_UNIFORM1i)glfwGetProcAddress("glUniform1i");
   glActiveTexture = (GL_ACTIVETEXTURE)glfwGetProcAddress("glActiveTexture");
   glUseProgram = (GL_USEPROGRAM)glfwGetProcAddress("glUseProgram");
   glDeleteVertexArrays = (GL_DELETEVERTEXARRAYS)glfwGetProcAddress("glDeleteVertexArrays");
   glDeleteBuffers = (GL_DELETEBUFFERS)glfwGetProcAddress("glDeleteBuffers");
   glDeleteProgram = (GL_DELETEPROGRAM)glfwGetProcAddress("glDeleteProgram");
   glGetShaderiv = (GL_GETSHADERIV)glfwGetProcAddress("glGetShaderiv");
   glGetShaderInfoLog = (GL_GETSHADERINFOLOG)glfwGetProcAddress("glGetShaderInfoLog");
   glGetProgramiv = (GL_GETPROGRAMIV)glfwGetProcAddress("glGetProgramiv");
   glGetProgramInfoLog = (GL_GETPROGRAMINFOLOG)glfwGetProcAddress("glGetProgramInfoLog");
   glUniform3f = (GL_UNIFORM3F)glfwGetProcAddress("glUniform3f");
   glGetUniformLocation = (GL_GETUNIFORMLOCATION)glfwGetProcAddress("glGetUniformLocation");
   glBufferSubData = (GL_BUFFERSUBDATA)glfwGetProcAddress("glBufferSubData");
   glCreateShader = (GL_CREATESHADER)glfwGetProcAddress("glCreateShader");
   glShaderSource = (GL_SHADERSOURCE)glfwGetProcAddress("glShaderSource");
   glCompileShader = (GL_COMPILESHADER)glfwGetProcAddress("glCompileShader");
   glCreateProgram = (GL_CREATEPROGRAM)glfwGetProcAddress("glCreateProgram");
   glAttachShader = (GL_ATTACHSHADER)glfwGetProcAddress("glAttachShader");
   glLinkProgram = (GL_LINKPROGRAM)glfwGetProcAddress("glLinkProgram");
   glDeleteShader = (GL_DELETESHADER)glfwGetProcAddress("glDeleteShader");
   glGenerateMipmap = (GL_GENERATEMIPMAP)glfwGetProcAddress("glGenerateMipmap");
   glUniformMatrix4fv = (GL_UNIFORMMATRIX4FV)glfwGetProcAddress("glUniformMatrix4fv");
   glDrawArrays = (GL_DRAWARRAYS)glfwGetProcAddress("glDrawArrays");
   glDrawElements = (GL_DRAWELEMENTS)glfwGetProcAddress("glDrawElements");
   glPolygonMode = (GL_POLYGONMODE)glfwGetProcAddress("glPolygonMode");
   glLineWidth = (GL_LINEWIDTH)glfwGetProcAddress("glLineWidth");
   glPointSize = (GL_POINTSIZE)glfwGetProcAddress("glPointSize");
   glGenTextures = (GL_GENTEXTURES)glfwGetProcAddress("glGenTextures");
   glBindTexture = (GL_BINDTEXTURE)glfwGetProcAddress("glBindTexture");
   glTexParameteri = (GL_TEXPARAMETERI)glfwGetProcAddress("glTexParameteri");
   glTexImage2D = (GL_TEXIMAGE2D)glfwGetProcAddress("glTexImage2D");
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void framebuffer_size_callback(GLFWwindow *window, int src_width, int src_height)
{
   glViewport(0, 0, src_width, src_height);
}
/*
int loadWindow()
{
   GLFWwindow *window = glfwCreateWindow(src_width, src_height, "Parallax Engine", NULL, NULL);

   if (!window)
   {
      fprintf(stderr, "ERROR::glfwCreateWindow()\n");
      exit(EXIT_FAILURE);
   }

   glfwSetKeyCallback(window, key_callback);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   glfwMakeContextCurrent(window);
   
   loadExtensions();

   glGenVertexArrays(1, &VAO);
   glGenBuffers(1, &VBO);
   glGenBuffers(1, &EBO);

   glBindVertexArray(VAO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);

   loadGrid();

   //unsigned int texture1 = loadTexture("db/container.bmp");

   glBindBuffer(GL_ARRAY_BUFFER, 0);

   unsigned int program = loadProgram("gl/1.test.vs", "gl/1.test.fs", "gl/1.test.gs");
   //unsigned int program = loadProgram("gl/2.texture.vs", "gl/2.texture.fs", "gl/2.texture.gs");

   //glUseProgram(program);
   //glUniform1i(glGetUniformLocation(program, "texture1"), 0);
   //glUniform1i(glGetUniformLocation(program, "texture2"), 1);

   glBindVertexArray(0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

   glLineWidth(2);
   //glPointSize(4);

   glfwSwapInterval(1);

   printf("%s", "loadWindow()\n");

   while (!glfwWindowShouldClose(window))
   {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      //glActiveTexture(GL_TEXTURE0);
      //glBindTexture(GL_TEXTURE_2D, texture1);
      //glActiveTexture(GL_TEXTURE1);
      //glBindTexture(GL_TEXTURE_2D, texture2);

      glUseProgram(program);
      glBindVertexArray(VAO);

      //glDrawArrays(GL_TRIANGLES, 0, 6);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

      //glBindVertexArray(0);

      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glfwDestroyWindow(window);

   glDeleteVertexArrays(1, &VAO);
   glDeleteBuffers(1, &VBO);
   glDeleteBuffers(1, &EBO);

   glDeleteProgram(program);

   return 0;
}

void loadGrid()
{
   GLfloat vertices[] = {
      0.5f,  0.5f, 0.0f,// top right
      0.5f, -0.5f, 0.0f,// bottom right
      -0.5f, -0.5f, 0.0f,// bottom left
      -0.5f,  0.5f, 0.0f// top left 
   };

   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

   GLuint indices[] = {
      0, 1, 3,// first triangle
      1, 2, 3// second triangle
   };

   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
   glEnableVertexAttribArray(0);
}

static unsigned int loadTexture(const char *filename)
{
   float vertices[] = {
      // positions                // colors                 // texture coords
      0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,// top right
      0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,// bottom right
      -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,// bottom left
      -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f // top left 
   };

   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

   unsigned int indices[] = {
      0, 1, 3,// first triangle
      1, 2, 3 // second triangle
   };

   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   // position attribute
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
   glEnableVertexAttribArray(0);
   // color attribute
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
   glEnableVertexAttribArray(1);
   // texture coord attribute
   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
   glEnableVertexAttribArray(2);

   unsigned int texture;

   // texture 1
   glGenTextures(1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture); 

   //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

   // set the texture wrapping parameters
   //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// set texture wrapping to GL_REPEAT (default wrapping method)
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   // set texture filtering parameters
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   FILE *file = fopen(filename, "rb");
   if (file == NULL)
   {
      fprintf(stderr, "ERROR::texturefile\n");
      exit(EXIT_FAILURE);
   }

   int width = 512;
   int height = 512;

   unsigned char *data = (unsigned char*)malloc(width * height * 3);
   //int size = fseek(file,);
   fread(data, 54, 1, file);// strip bmp buffer
   fread(data, width * height * 3, 1, file);

   fclose(file);

   for(int i = 0; i < width * height ; ++i)
   {
      int index = i * 3;
      unsigned char B, R;
      B = data[index];
      R = data[index + 2];

      data[index] = R;
      data[index + 2] = B;
   }

   if (data)
   {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
   }
   else
   {
      fprintf(stderr, "ERROR::texturedata\n");
      exit(EXIT_FAILURE);
   }

   free(data);
   return texture;
}

static unsigned int loadProgram(const char *vShader, const char *fShader, const char *gShader)
{
   char line[MAX_SIZE], vDest[MAX_SIZE], fDest[MAX_SIZE], gDest[MAX_SIZE];

   FILE *vShaderFile = fopen(vShader, "r");
   if (vShaderFile == NULL) 
   {
      fprintf(stderr, "ERROR::vertexfile\n");
      exit(EXIT_FAILURE);
   }

   while (fgets(line, MAX_SIZE + 1, vShaderFile) != NULL) strcat(vDest, line);
   fclose(vShaderFile);
   const char *vShaderCode = vDest;

   FILE *fShaderFile = fopen(fShader, "r");

   if (fShaderFile == NULL)
   {
      fprintf(stderr, "ERROR::fragmentfile\n");
      exit(EXIT_FAILURE);
   }

   while (fgets(line, MAX_SIZE + 1, fShaderFile) != NULL) strcat(fDest, line);
   fclose(fShaderFile);
   const char *fShaderCode = fDest;

   FILE *gShaderFile = fopen(gShader, "r");

   if (gShaderFile == NULL)
   {
      fprintf(stderr, "ERROR::geometryfile\n");
      exit(EXIT_FAILURE);
   }

   while (fgets(line, MAX_SIZE + 1, gShaderFile) != NULL) strcat(gDest, line);
   fclose(gShaderFile);
   const char *gShaderCode = gDest;

   unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

   glShaderSource(vertexShader, 1, &vShaderCode, NULL);
   glCompileShader(vertexShader);
   shaderError(vertexShader, "vshader");

   unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

   glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
   glCompileShader(fragmentShader);
   shaderError(fragmentShader, "fshader");

   unsigned int geometryShader = glCreateShader(GL_GEOMETRY_SHADER);

   glShaderSource(geometryShader, 1, &gShaderCode, NULL);
   glCompileShader(geometryShader);
   shaderError(geometryShader, "gshader");

   unsigned int ID = glCreateProgram();

   glAttachShader(ID, vertexShader);
   glAttachShader(ID, fragmentShader);
   //glAttachShader(ID, geometryShader);

   glLinkProgram(ID);
   shaderError(ID, "PROGRAM");

   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);
   glDeleteShader(geometryShader);

   return ID;
}

static void shaderError(unsigned int shader, char const* type)
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
         exit(EXIT_FAILURE);
      }
   }
   else
   {
      glGetProgramiv(shader, GL_LINK_STATUS, &success);

      if (!success)
      {
         glGetProgramInfoLog(shader, 1024, NULL, infoLog);
         printf("%s%s\n%s", "ERROR::", type, infoLog);
         exit(EXIT_FAILURE);
      }
   }
}
*/