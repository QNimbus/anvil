#pragma once

#include "anvil/event/Event.h"

namespace Anvil::Events
{

    class WindowCloseEvent : public Event
    {
    public:
        // Constructor
        WindowCloseEvent() {};

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryWindow)

    protected:
    };

    class WindowMoveEvent : public Event
    {
    public:
        // Constructor
        WindowMoveEvent(uint32_t posX, uint32_t posY) : m_PosX(posX), m_PosY(posY) {};

        EVENT_CLASS_TYPE(WindowMove)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryWindow)

    protected:
        uint32_t m_PosX, m_PosY;
    };

    class WindowFocusLostEvent : public Event
    {
    public:
        // Constructor
        WindowFocusLostEvent() {};

        EVENT_CLASS_TYPE(WindowFocusLost)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryWindow | EventCategory::EventCategoryApplication)

    protected:
    };

    class WindowFocusEvent : public Event
    {
    public:
        // Constructor
        WindowFocusEvent() {};

        EVENT_CLASS_TYPE(WindowFocus)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryWindow)

    protected:
    };

    class WindowResizeEvent : public Event
    {
    public:
        // Constructor
        WindowResizeEvent(uint32_t width, uint32_t height) : m_Width(width), m_Height(height) {};

        uint32_t GetWidth()     { return m_Width; }
        uint32_t GetHeight()    { return m_Height; }

        std::string ToString() const {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryWindow)

    protected:
        uint32_t m_Width, m_Height;
    };

}
