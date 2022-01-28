#include "avpch.h"
#include "GraphicsContext.h"

#include "platform/OpenGL/OpenGLContext.h"

// Forward declaration of GLFWwindow
struct GLFWwindow;

namespace Anvil
{
    Scope<GraphicsContext> GraphicsContext::Create(void* window) {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:
                {
                    AV_CORE_ASSERT(false, "RendererAPI::None is currently not supported)");
                    return nullptr;
                    break;
                }
            case RendererAPI::API::OpenGL:
                {
                    return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
                    break;
                }
            default:
                {
                    return nullptr;
                    break;
                }
        }
    }
}
