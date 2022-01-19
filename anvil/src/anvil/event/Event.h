#pragma once

#include "avpch.h"
#include "anvil/core/Core.h"

/*
* EVENT_CLASS_TYPE macro expands into 3 member functions (of which 1 is static)
* GetName()             - returns std::string with EventType name
* GetEventType()        - returns EventType enum for instance
* GetEventTypeStatic()  - returns EventType enum for class
*/
#define EVENT_CLASS_TYPE(type)  std::string GetName() const override { return #type; }; \
                                static EventType GetEventTypeStatic() { return EventType::type; }; \
                                EventType GetEventType() const override { return GetEventTypeStatic(); };

/*
* EVENT_CLASS_CATEGORY macro expands into a single member function
* GetCategoryFlags()    - returns uint32_t (category type flags)
*/
#define EVENT_CLASS_CATEGORY(category)  uint32_t GetCategoryFlags() const override { return static_cast<uint32_t>(category); };

/*
An event can be stringified
An event has a type (EventType)
An event belongs to one or more categories (EventCategory)
*/

namespace Anvil::Events
{

    class Event
    {
    public:
        /*
        * An event has one or more categories.
        * This is done using flags and a bitwise-OR operation.
        */
        enum class EventCategory : uint32_t
        {
            None = 0,

            EventCategoryApplication    = BIT(0),   // bit0 = 1
            EventCategoryWindow         = BIT(1),   // bit1 = 2
            EventCategoryInput          = BIT(2),   // bit2 = 4
            EventCategoryKeyboard       = BIT(3),   // bit3 = 8
            EventCategoryMouse          = BIT(4),   // bit4 = 16
            EventCategoryMouseButton    = BIT(5)    // bit5 = 32
        };

        /*
        * An event is one EventType.
        */
        enum class EventType : uint32_t
        {
            None = 0,
            WindowClose, WindowResize, WindowFocus, WindowFocusLost, WindowMove,
            AppTick, AppUpdate, AppRender, AppShutdown,
            KeyPressed, KeyReleased, KeyTyped,
            MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
        };

    public:
        // Flag to signal whether an event is done (handled)
        mutable bool handled = false;

    public:
        virtual ~Event() = default;

        // Pure virtual member function(s) need to be implemented by derived class
        virtual std::string GetName()       const = 0;
        virtual EventType GetEventType()    const = 0;
        virtual uint32_t GetCategoryFlags() const = 0;

        // Virtual member function(s) can be overriden by derived class
        virtual bool InCategory(EventCategory category) { return GetCategoryFlags() & static_cast<uint32_t>(category); }
        virtual bool InCategory(uint32_t categories)    { return GetCategoryFlags() & categories; }
        virtual std::string ToString() const { return GetName(); }

        // Operators
        friend std::ostream& operator<<(std::ostream& os, const Event& event);

    private:
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event) {
        return os << event.ToString();
    }

    inline uint32_t operator| (Event::EventCategory lhs, Event::EventCategory rhs) {
        return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
    };

    inline uint32_t operator| (uint32_t lhs, Event::EventCategory rhs) {
        return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
    };
}
