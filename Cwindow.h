//
// Created by igoryan on 25.04.15.
//

#ifndef OPENGL_CWINDOW_H
#define OPENGL_CWINDOW_H

#include <stdio.h>
#include <unistd.h>
#include <GL/glew.h>
#include <GL/gl.h
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <thread>

class Cwindow {
private:
    GLFWwindow *mWindow;
public:
    Cwindow();
    void threadFunction();
};


#endif //OPENGL_CWINDOW_H
