#pragma once

#include "anvil/renderer/GraphicsContext.h"

// Forward declaration of GLFWwindow
struct GLFWwindow;

namespace Anvil
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* window);

        // Inherited via GraphicsContext
        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* m_WindowHandle;
    };
}
