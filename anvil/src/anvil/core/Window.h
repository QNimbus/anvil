#pragma once

#include "avpch.h"

#include "anvil/event/Event.h"

namespace Anvil
{

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Events::Event&)>; 

        struct WindowProperties
        {
            uint32_t width, height;
            std::string title;

            bool vSync;
            bool fullScreen;

            WindowProperties(std::string title, uint32_t width, uint32_t height, bool vSync = true, bool fullScreen = false)
                : title(title), width(width), height(height), vSync(vSync), fullScreen(fullScreen) {
            };
        };

    public:
        static Ref<Window> Create(const WindowProperties& properties);

        virtual void Close() const = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual void* GetNativeWindow() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        // Event hooks
        virtual void onUpdate() const = 0;

    private:
    };

}
