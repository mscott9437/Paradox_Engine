#pragma once

#include <sqlite3.h>
#define GLFW_INCLUDE_NONE
#include <glfw3.h>

#define PATH_SIZE 256
#define LINE_SIZE 65536

void sqlExec(char *sql);
void sqlInit(char *file);
void loadRepl();

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
static void error_callback(int error, const char* description);

sqlite3 *db;
