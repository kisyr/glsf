#include <GL/glfw.h>
#include "../glsf.hpp"

#define PRELOAD "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        printf("Usage: hello <font>\n");
        return EXIT_FAILURE;
    }

    glfwInit();
    glfwOpenWindow(500,500, 0,0,0,0,0,0, GLFW_WINDOW);

    glsf::Font font(argv[1], 18, PRELOAD);
    
    glsf::Rect top(0, 0, 500, 0);
    glsf::Rect mid(0, 250, 500, 0);
    glsf::Rect bottom(0, 500-font.size(), 500, 0);
    glsf::Color white(1, 1, 1, 1);
    glsf::Color yellow(1, 1, 0, 1);
    
    std::vector<glsf::String> strings = {
        glsf::String(top, white, "Lorem ipsum dolor sit amet..."),
        glsf::String(mid, white, "...consectetuer adipiscing elit.") };
    
    while( glfwGetWindowParam(GLFW_OPENED) && !glfwGetKey(GLFW_KEY_ESC) ) {
        glClearColor(0.5,0.5,0.5,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        font.draw(strings);
        font.draw(bottom, yellow, "Waffles");

        glfwSwapBuffers();
        glfwSleep(0.01);
    }
    
    return EXIT_SUCCESS;
}
