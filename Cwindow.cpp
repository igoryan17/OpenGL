//
// Created by igoryan on 25.04.15.
//

#include "Cwindow.h"

Cwindow::Cwindow() {
    if( !glfwInit() )
    {
        fprintf( stderr, "Ошибка при инициализации GLFWn" );
    }
    else
    {
        glfwWindowHint(GLFW_SAMPLES, 4); // 4x Сглаживание
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Мы хотим использовать OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL
        GLFWwindow *window;
        window = glfwCreateWindow( 800, 600, "Tutorial 01", nullptr, nullptr);
        if( window == NULL ) {
            fprintf( stderr, "Невозможно открыть окно GLFW. Если у вас Intel GPU, то он не поддерживает версию 3.3. Попробуйте версию уроков для OpenGL 2.1.n" );
            glfwTerminate();
        }
        else {
            mWindow  = window;
            glfwMakeContextCurrent(window);
            glewExperimental = true;
            if (glewInit() != GLEW_OK) {
                fprintf(stderr, "Невозможно инициализировать GLEWn");
            }
            std::thread thr(&Cwindow::threadFunction, this);
            thr.join();
            glfwTerminate();
        }
    }

}

void Cwindow::threadFunction()
{
    glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);
    do{
        // Пока что ничего не выводим. Это будет в уроке 2.

        // Сбрасываем буферы
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    } // Проверяем нажатие клавиши Escape или закрытие окна
    while( glfwGetKey(mWindow, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(mWindow) == 0 );
}