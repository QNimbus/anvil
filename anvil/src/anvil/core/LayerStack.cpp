#include "avpch.h"
#include "LayerStack.h"

namespace Anvil
{
  LayerStack::~LayerStack()
  {
    for (auto layer : m_Stack) {
      delete layer;
    }
  }

  void LayerStack::PushLayer(Layer* layer)
  {
    m_Stack.emplace(m_Stack.begin() + m_LayerIndex++, layer);

    // Call layer onAttach event handler
    layer->onAttach();
  }

  bool LayerStack::PopLayer(Layer* layer)
  {
    // Try to find layer in stack
    auto it = std::find(m_Stack.begin(), m_Stack.begin() + m_LayerIndex, layer);

    // If iterator not equal to end() then layer was found
    if (it != m_Stack.begin() + m_LayerIndex) {
      --m_LayerIndex;
      m_Stack.erase(it);

      // Call layer onDetach event handler
      layer->onDetach();
      return true;
    }
    else {
      return false;
    }
  }

  void LayerStack::PushOverlay(Layer* overlay)
  {
    m_Stack.emplace_back(overlay);

    // Call layer onAttach event handler
    overlay->onAttach();
  }

  bool LayerStack::PopOverlay(Layer* overlay)
  {
    // Try to find layer in stack
    auto it = std::find(m_Stack.begin(), m_Stack.end(), overlay);

    // If iterator not equal to end() then layer was found
    if (it != m_Stack.end()) {
      m_Stack.erase(it);

      // Call layer onDetach event handler
      overlay->onDetach();
      return true;
    }
    else {
      return false;
    }
  }
}
