# TextureBuilder

Working OpenGL textures on OSX based on [LoadTextures](https://github.com/mlutfib/pacman-glut-3d/blob/master/TextureBuilder.h)

### How to Use

1. Add "TextureBuilder.h" and "TextureBuilder.cpp" to your directory
2. Add ``` include "TextureBuilder.h"``` to the begining of your `main.cpp`
3. Use it as usual

    ```
    loadBMP(&texID, "textures/metal.bmp", true);
    loadBMP(&texID, "textures/metal.bmp", 900, 900, true);
    loadPPM(&texID, "textures/clouds.ppm", 200, 200, true);
    ```
