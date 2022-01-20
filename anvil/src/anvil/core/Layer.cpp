#include "avpch.h"
#include "Layer.h"

namespace Anvil
{
  Layer::Layer(const std::string& name)
    : m_Name(name)
  {
    AV_CORE_TRACE("Constructing layer: {0}", m_Name);
  }

  Layer::~Layer()
  {
    AV_CORE_TRACE("Destructing layer: {0}", m_Name);
  }

  void Layer::onAttach()
  {
    AV_CORE_TRACE("Attaching layer: {0}", m_Name);
  }

  void Layer::onDetach()
  {
      AV_CORE_TRACE("Detaching layer: {0}", m_Name);
  }

  void Layer::onUpdate()
  {
  }
}
