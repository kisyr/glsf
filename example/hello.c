#include <GL/glfw.h>
#include "../glsf.h"

#define PRELOAD "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        printf("Usage: hello <font>\n");
        return EXIT_FAILURE;
    }

    glfwInit();
    glfwOpenWindow(500,500, 0,0,0,0,0,0, GLFW_WINDOW);

    const float size = 18;
    GLSFfont* font = glsfCreateFont(argv[1], size, PRELOAD);
    if( font == NULL ) {
        return EXIT_FAILURE;
    }
    
    float top[4] = { 0,0,500,500 };
    float mid[4] = { 0,250,500,250 };
    float bottom[4] = { 0,500-size,500,size };
    float white[4] = { 1,1,1,1 };
    float yellow[4] = { 1,1,0,1 };
    
    while( glfwGetWindowParam(GLFW_OPENED) && !glfwGetKey(GLFW_KEY_ESC) ) {
        glClearColor(0.5,0.5,0.5,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glsfBegin(font);
        glsfString(top, white, "Lorem ipsum dolor sit amet...");
        glsfString(mid, white, "...consectetuer adipiscing elit.");
        glsfEnd();
        
        glsfDrawString(font, bottom, yellow, "Waffles");

        glfwSwapBuffers();
        glfwSleep(0.01);
    }
    
    glsfDestroyFont(font);
    
    return EXIT_SUCCESS;
}
