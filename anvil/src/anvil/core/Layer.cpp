#include "avpch.h"
#include "Layer.h"

namespace Anvil
{
  Layer::Layer(const std::string& name)
    : m_Name(name)
  {
    AV_CORE_WARN("Constructing new layer '{0}'", m_Name);
  }

  Layer::~Layer()
  {
    AV_CORE_WARN("Destructing layer '{0}'", m_Name);
  }

  void Layer::OnAttach() const
  {
    AV_CORE_TRACE("Layer {0} :: OnAttach()", m_Name);
  }

  void Layer::OnDetach() const
  {
    AV_CORE_TRACE("Layer {0} :: OnDetach()", m_Name);
  }

  void Layer::OnUpdate() const
  {
    AV_CORE_TRACE("Layer {0} :: OnUpdate()", m_Name);
  }
}
