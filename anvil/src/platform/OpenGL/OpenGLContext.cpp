#include "avpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Anvil
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) { AV_CORE_ASSERT(m_WindowHandle, "Window handle is null"); };

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);

        // Load GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            AV_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD");

        AV_CORE_INFO("OpenGL info");
        AV_CORE_INFO("  Vendor: {0}",   glGetString(GL_VENDOR));
        AV_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        AV_CORE_INFO("  Version: {0}",  glGetString(GL_VERSION));

        #ifdef AV_ENABLE_ASSERTS
        int versionMajor;
        int versionMinor;
        glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
        glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

        AV_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Anvil requires at least OpenGL version 4.5");
        #endif
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_WindowHandle);
    }
}
