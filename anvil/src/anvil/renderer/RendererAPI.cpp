#include "avpch.h"
#include "RendererAPI.h"

namespace Anvil
{
    // Statically define API to 'OpenGL' for now
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
}
