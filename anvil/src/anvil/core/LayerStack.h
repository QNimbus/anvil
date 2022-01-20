#pragma once

#include "anvil/core/Layer.h"

namespace Anvil
{
  class LayerStack
  {
  public:
    LayerStack() = default;
    ~LayerStack();

    bool PopLayer(Layer* layer);
    void PushLayer(Layer* layer);
    bool PopOverlay(Layer* layer);
    void PushOverlay(Layer* layer);

    // Expose iterators of underlying layer stack
    std::vector<Layer*>::iterator begin()                       { return m_Stack.begin(); }
    std::vector<Layer*>::iterator end()                         { return m_Stack.end(); }
    std::vector<Layer*>::reverse_iterator rbegin()              { return m_Stack.rbegin(); }
    std::vector<Layer*>::reverse_iterator rend()                { return m_Stack.rend(); }

    std::vector<Layer*>::const_iterator cbegin() const          { return m_Stack.cbegin(); }
    std::vector<Layer*>::const_iterator cend() const            { return m_Stack.cend(); }
    std::vector<Layer*>::const_reverse_iterator crbegin() const { return m_Stack.crbegin(); }
    std::vector<Layer*>::const_reverse_iterator crend() const   { return m_Stack.crend(); }

  private:
    std::vector<Layer*> m_Stack;

    uint32_t m_LayerIndex = 0;
  };
}


