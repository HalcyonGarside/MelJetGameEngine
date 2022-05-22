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
#include "GL/glew.h"
#include "GL/gl.h"
#include "GLFW/glfw3.h"

//Utilities
#include "utils/util_files.h"

GLFWwindow* mainWindow;
GLuint vShaderID;
GLuint fShaderID;



static char* VertexShader = "./src/vshader.vs";
static char* FragmentShader = "./src/fshader.fs";

void keypress_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        if(key == GLFW_KEY_W)
        {
            
        }
        if(key == GLFW_KEY_ESCAPE)
        {
            glfwSetWindowShouldClose(mainWindow, GLFW_TRUE);
            return;
        }
        printf("%s\n", glfwGetKeyName(key, scancode));
    }
}

int compileShaders(char* vShaderLoc, char* fShaderLoc)
{
    GLint status = GL_FALSE;
    int log_len;

    char* vShader = getFileAsString(vShaderLoc);

    if(vShader == NULL)
    {
        return -1;
    }

    char* fShader = getFileAsString(fShaderLoc);

    if(fShader == NULL)
    {
        return -1;
    }

    vShaderID = glCreateShader(GL_VERTEX_SHADER);
    fShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShaderID, 1, (const char**)&vShader, NULL);
    glCompileShader(vShaderID);

    glGetShaderiv(vShaderID, GL_COMPILE_STATUS, &status);
    glGetShaderiv(vShaderID, GL_INFO_LOG_LENGTH, &log_len);
    if(log_len > 0)
    {
        char* msg = (char*)malloc(log_len * sizeof(char));
        glGetShaderInfoLog(vShaderID, log_len, NULL, msg);
        printf("%s\n", msg);
        return -1;
    }

    glShaderSource(fShaderID, 1, (const char**)&fShader, NULL);
    glCompileShader(fShaderID);

    glGetShaderiv(fShaderID, GL_COMPILE_STATUS, &status);
    glGetShaderiv(fShaderID, GL_INFO_LOG_LENGTH, &log_len);
    if(log_len > 0)
    {
        char* msg = (char*)malloc(log_len * sizeof(char));
        glGetShaderInfoLog(fShaderID, log_len, NULL, msg);
        printf("%s\n", msg);
        return -1;
    }

    GLuint pID = glCreateProgram();
    glAttachShader(pID, vShaderID);
    glAttachShader(pID, fShaderID);

    glLinkProgram(pID);

    glGetProgramiv(pID, GL_COMPILE_STATUS, &status);
    glGetProgramiv(pID, GL_INFO_LOG_LENGTH, &log_len);
    if(log_len > 0)
    {
        char* msg = (char*)malloc(log_len * sizeof(char));
        glGetProgramInfoLog(pID, log_len, NULL, msg);
        printf("%s\n", msg);
        return -1;
    }

    glDetachShader(pID, vShaderID);
    glDetachShader(pID, fShaderID);

    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);

    return pID;
}

void cleanup_ogl()
{

}

int main()
{
    printf("Hello, Kay\n");

    if(!glfwInit())
        return -1;

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mainWindow = glfwCreateWindow(640, 480, "Balls", NULL, NULL);
    
    if(!mainWindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(mainWindow);
    glewExperimental = GL_TRUE;

    int err = glewInit();
    if(err != GLEW_OK)
    {
        printf("GLEW Init Error: %s\n", glewGetErrorString(err));
        return -1;
    }

    static const GLfloat posArray[] = 
    {
        -1.0f, -1.0f,  0.0f,
         1.0f, -1.0f,  0.0f,
         0.0f,  1.0f,  0.0f
    };

    GLuint varrayid;
    glGenVertexArrays(1, &varrayid);
    glBindVertexArray(varrayid);

    GLuint vbuf;

    glGenBuffers(1, &vbuf);
    glBindBuffer(GL_ARRAY_BUFFER, vbuf);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), posArray, GL_STATIC_DRAW);

    glfwSetKeyCallback(mainWindow, keypress_callback);

    GLuint pID = compileShaders(VertexShader, FragmentShader);

    if(pID < 0)
    {
        return -1;
    }

    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

    while(!glfwWindowShouldClose(mainWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(pID);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vbuf);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            3 * sizeof(float),
            (void*)0
        );

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);

        //Double-buffering
        glfwSwapBuffers(mainWindow);

        //How we check for any input events -- Task Numero Uno
        glfwPollEvents();
    }



    glfwTerminate();
    return 0;
}