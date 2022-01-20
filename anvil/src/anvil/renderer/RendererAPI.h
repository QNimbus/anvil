#pragma once

namespace Anvil
{

    class RendererAPI
    {
    public:
        enum class API
        {
            None = 0,
            OpenGL
        };

        static API GetAPI() { return s_API; }
        
    private:
        static API s_API;
    };
}
