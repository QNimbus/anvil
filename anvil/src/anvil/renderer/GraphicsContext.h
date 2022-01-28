#pragma once

#include "anvil/core/Core.h"
#include "anvil/renderer/RendererAPI.h"

namespace Anvil
{

    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;

        static Scope<GraphicsContext> Create(void* window);

    private:
    };
}
