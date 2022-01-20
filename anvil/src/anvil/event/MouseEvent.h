#pragma once

#include "anvil/event/Event.h"

namespace Anvil::Events
{

    class MouseScrolledEvent : public Event
    {
    public:
        // Constructor
        MouseScrolledEvent(double offsetX, double offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {};

        double GetOffsetX() const { return m_OffsetX; }
        double GetOffsetY() const { return m_OffsetY; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << std::setprecision(3) << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse)

    protected:
        double m_OffsetX, m_OffsetY;
    };

    class MouseMovedEvent : public Event
    {
    public:
        // Constructor
        MouseMovedEvent(double mouseX, double mouseY) : m_MouseX(mouseX), m_MouseY(mouseY) {};

        double GetX() const { return m_MouseX; }
        double GetY() const { return m_MouseY; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << std::setprecision(3) << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse)

    protected:
        double m_MouseX, m_MouseY;
    };

    class MouseButtonEvent : public Event
    {
    public:

        MouseButton GetMouseButton() const { return m_MouseButton; }

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse | EventCategory::EventCategoryMouseButton)

    protected:
        // Disable direct instantiation
        MouseButtonEvent(MouseButton mouseButton) : m_MouseButton(mouseButton) {};

    protected:
        MouseButton m_MouseButton;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        // Constructor
        MouseButtonPressedEvent(MouseButton mouseButton) : MouseButtonEvent(mouseButton) {};

        EVENT_CLASS_TYPE(MouseButtonPressed)

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_MouseButton;
            return ss.str();
        }

    protected:
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        // Constructor
        MouseButtonReleasedEvent(MouseButton mouseButton) : MouseButtonEvent(mouseButton) {};

        EVENT_CLASS_TYPE(MouseButtonReleased)

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_MouseButton;
            return ss.str();
        }
    protected:
    };
}
