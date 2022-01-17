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
    layer->OnAttach();
  }

  bool LayerStack::PopLayer(Layer* layer)
  {
    // Try to find layer in stack
    auto it = std::find(m_Stack.begin(), m_Stack.begin() + m_LayerIndex, layer);

    // If iterator not equal to end() then layer was found
    if (it != m_Stack.begin() + m_LayerIndex) {
      --m_LayerIndex;
      m_Stack.erase(it);
      layer->OnDetach();
      return true;
    }
    else {
      return false;
    }
  }

  void LayerStack::PushOverlay(Layer* overlay)
  {
    m_Stack.emplace_back(overlay);
    overlay->OnAttach();
  }

  bool LayerStack::PopOverlay(Layer* overlay)
  {
    // Try to find layer in stack
    auto it = std::find(m_Stack.begin(), m_Stack.end(), overlay);

    // If iterator not equal to end() then layer was found
    if (it != m_Stack.end()) {
      m_Stack.erase(it);
      overlay->OnDetach();
      return true;
    }
    else {
      return false;
    }
  }
}
