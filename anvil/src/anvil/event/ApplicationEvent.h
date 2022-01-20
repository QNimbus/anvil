#pragma once

#include "anvil/event/Event.h"

namespace Anvil::Events
{

    class AppTickEvent : public Event
    {
    public:
        // Constructor
        AppTickEvent() {};

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)

    protected:
    };

    class AppRenderEvent : public Event
    {
    public:
        // Constructor
        AppRenderEvent() {};

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)

    protected:
    };

    class AppUpdateEvent : public Event
    {
    public:
        using TimeStep = double;

        // Constructor
        AppUpdateEvent(TimeStep timeStep) : m_TimeStep(timeStep) {};

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)

    protected:
        TimeStep m_TimeStep;
    };

    class AppShutdownEvent : public Event
    {
    public:
        // Constructor
        AppShutdownEvent() {};

        EVENT_CLASS_TYPE(AppShutdown)
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)

    protected:
    };

}
