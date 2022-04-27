/*
main.c
Main function of the MelJet game engine

Center of command.  As of now, it handles all operations, and that's the
way it will stay until things need to be abstracted.  We'll explore here
until we crack the surface into a world of possibility.
*/


//Standard Libraries
#include "stdlib.h"
#include "stdio.h"

//OpenGL
#include "GLFW/glfw3.h"

int main()
{
    printf("Hello, Kay\n");

    //Writing this is practically a copy-paste
    //Writing the makefile without prior knowledge...
    //That's a bit harder.
    GLFWwindow* mainWindow;

    if(!glfwInit())
        return -1;

    mainWindow = glfwCreateWindow(640, 480, "TestWindow", NULL, NULL);

    if(!mainWindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(mainWindow);

    while(!glfwWindowShouldClose(mainWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //Double-buffering
        glfwSwapBuffers(mainWindow);

        //How we check for any input events -- Task Numero Uno
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}