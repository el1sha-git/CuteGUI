#include <GLFW/glfw3.h>


int main(void)
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(680, 680, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    float theta = 0.0f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
            glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();
            // glRotatef(theta, 0.0f, 0.0f, 1.0f);
            glLineWidth(10);
            glBegin(GL_TRIANGLE_FAN);
                glColor3f(0,0,0);
                glVertex2f(-0.5f,-0.9f);
                glVertex2f(0.5f,-0.9f);
                glVertex2f(0.5f,0.2f);
                glColor3f(0,1,0);
                glVertex2f(-0.5f,0.2f);

            glEnd();

            glBegin(GL_TRIANGLES);
                glColor3f(1,0,0);
                glVertex2f(0.8f,0.2f);
                glVertex2f(-0.8f,0.2f);
                glColor3f(0,0.12f,0);
                glVertex2f(0,0.8f);
            glEnd();

            glPopMatrix();

            glfwSwapBuffers(window);

            // theta += 1.0f;

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}