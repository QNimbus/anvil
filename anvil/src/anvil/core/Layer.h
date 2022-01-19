#pragma once

#include "anvil/event/Event.h"

namespace Anvil
{
    using namespace Events;

    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void onAttach();
        virtual void onDetach();
        virtual void onUpdate();
        virtual void onEvent(const Event& event) = 0;

        #ifdef AV_DEBUG
        const std::string& GetName() const { return m_Name; }
        #endif

    public:
        #ifdef AV_DEBUG
        std::string m_Name;
        #endif
    };

}
