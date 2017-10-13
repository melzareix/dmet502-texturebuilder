//
// Created by Mohamed El Zarei on 10/13/17.
//

#include <cstdio>
#include <cstdlib>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "glut.h"
#endif

void loadBMP(GLuint*, const char *, bool);
void loadPPM(GLuint*, const char *, bool);
void loadBMP(GLuint*, const char *,int, int, bool);
void loadPPM(GLuint*, const char *,int, int, bool);
