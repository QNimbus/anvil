#pragma once

#include "anvil/event/Event.h"

namespace Anvil::Events
{

    class KeyEvent : public Event
    {
    public:

        Key GetKey() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryInput | EventCategory::EventCategoryKeyboard)

    protected:
        // Disable direct instantiation
        KeyEvent(const Key key) : m_KeyCode(key) {};

    protected:
        Key m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        // Constructor
        KeyPressedEvent(const Key key, uint32_t repeatCount = 0) : KeyEvent(key), m_RepeatCount(repeatCount) {};

        EVENT_CLASS_TYPE(KeyPressed)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " ( " << m_RepeatCount <<  " repeats)";
            return ss.str();
        }

    private:
        uint32_t m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        // Constructor
        KeyReleasedEvent(const Key key) : KeyEvent(key) {};

        EVENT_CLASS_TYPE(KeyReleased)

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

    private:

    };

    class KeyTypedEvent : public KeyEvent
    {
    public:
        // Constructor
        KeyTypedEvent(const Key key) : KeyEvent(key) {};

        EVENT_CLASS_TYPE(KeyTyped)

       std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }
    private:

    };
}
