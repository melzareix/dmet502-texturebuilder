#include "TextureBuilder.h"

void loadBMP(GLuint *texture, const char *filename, int width = 1024, int height = 512, bool wrap = true) {
  unsigned char *data;
  FILE *file;

  file = fopen(filename, "rb");
  if (file == NULL) return;
  data = (unsigned char *) malloc(width*height*3);
  fread(data, width*height*3, 1, file);
  fclose(file);

  for (int i = 0; i < width*height; ++i) {
    int index = i*3;
    unsigned char B, R;
    B = data[index];
    R = data[index + 2];

    data[index] = R;
    data[index + 2] = B;
  }
  glGenTextures(1, texture);
  glBindTexture(GL_TEXTURE_2D, *texture);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
  free(data);
}
void loadBMP(GLuint *texture, const char *filename, bool wrap) {
  loadBMP(texture, filename, 1024, 512, wrap);
}

void loadPPM(GLuint *texture, const char *filename, int width = 1024, int height = 512, bool wrap = true) {
  loadBMP(texture, filename, width, height, wrap);
}
void loadPPM(GLuint *texture, const char *filename, bool wrap){
  loadBMP(texture, filename, wrap);
}