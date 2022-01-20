#pragma once

#include "avpch.h"
#include "anvil/event/Event.h"

/*
* Basic event bus implementation
*
* To listen for a specific event:
*
* - Create an event handler method on your class: i.e. MyClass::onKeyPressed(const Events::KeyPressedEvent& event) {}
* - Subscribe to the event bus: eventBus.Subscribe(this, &MyClass::onKeyPressed)
* - The onKeyPressed() event handler will be invoked every time a KeyPressedEvent is published on the event bus
*
* To publish a specific event:
*
* - Create an event: i.e. Events::KeyPressedEvent myEvent = { Key::Space }
* - Publish the event: eventBus.Publish(myEvent);
*
* TODO:
*
* - Make this class thread-safe (concurrent usage), for example see: https://github.com/DeveloperPaul123/eventbus
*/

namespace Anvil::Events
{
    // Forward declaration for typedef
    class EventHandlerBase;
    // Typedef
    using EventHandlerList = std::list<EventHandlerBase*>;

      /*
      * Abstract base class for event handler
      */
    class EventHandlerBase
    {
    public:
        void exec(const Event& event) { call(event); };

    private:
        virtual void call(const Event& event) = 0;

    };

    /*
    * Templated derived class (EventHandlerBase) for actual event handler functions
    */
    template<typename T, typename EventType>
    class EventHandlerFunction : public EventHandlerBase
    {
    public:
        // Typedef
        using MemberMethod = void (T::*)(const EventType&);

        // Constructor
        EventHandlerFunction(T* instance, MemberMethod method) : m_Instance(instance), m_Method(method) {};

    private:
      /*
      * The combination of m_Instance and m_Method points to the specific event handler.
      * e.g. ((*m_Instance).(*m_Method))(event) or (m_Instance->*m_Member)(event)
      */
        void call(const Event& event) override { return (m_Instance->*m_Method)(static_cast<const EventType&>(event)); };

    private:

      // Pointer to class instance
        T* m_Instance;

        // Pointer to class instance member method
        MemberMethod m_Method;
    };

    class EventBus
    {
    public:
        // Disable copy & move constructors
        EventBus(EventBus&&) = delete;
        EventBus(const EventBus&) = delete;
        EventBus& operator=(const EventBus&) = delete;
        EventBus& operator=(EventBus&&) = delete;

        // Singleton instance()
        static auto& instance() {
            static EventBus eventBus;
            return eventBus;
        }

        /*
        * Custom destructor which deletes all heap allocated
        * event handler functions for every registered EventType
        *
        * m_EventSubscriptions is a std::map<std::type_index, std::list>
        */
        ~EventBus() {
            for (auto const& [_, eventHandlers] : m_EventSubscribers) {
                if (eventHandlers) {
                    for (auto const& list : *eventHandlers) {
                        delete list;
                    }
                    delete eventHandlers;
                }
            }
        };

        /*
        * Publish calls subscribed event handlers for a given event type in order with the event as argument.
        */
        template<typename EventType>
        void Publish(const EventType& event) {
            // When accessing non-existing key in std::map it will create an empty entry for key
            auto eventHandlers = m_EventSubscribers[typeid(EventType)];

            // No event handlers found, return
            if (!eventHandlers)
                return;

              // Call subscribed event handlers in order (FIFO)
            for (auto& eventHandler : *eventHandlers) {
                eventHandler->exec(event);
            }

        }

        template<typename T, typename EventType>
        void Subscribe(T* instance, void (T::* method)(const EventType&)) {
          // Get event handlers for current EventType
            EventHandlerList* eventHandlers = m_EventSubscribers[typeid(EventType)];

            // First time initialization (no previous event handlers)
            if (eventHandlers == nullptr) {
                eventHandlers = new EventHandlerList();
                m_EventSubscribers[typeid(EventType)] = eventHandlers;
            }

            // Append event handler function to (the back of) the list
            eventHandlers->push_back(new EventHandlerFunction<T, EventType>(instance, method));
        }

    private:
        EventBus() = default;

    private:
        std::map<std::type_index, EventHandlerList*> m_EventSubscribers;
    };
}
