#pragma once

namespace Anvil
{

  class Layer
  {
  public:
    Layer(const std::string& name = "Layer");
    virtual ~Layer();

    void OnAttach() const;
    void OnDetach() const;
    void OnUpdate() const;

  #ifdef AV_DEBUG
    const std::string& GetName() const { return m_Name; }
  #endif

  public:
  #ifdef AV_DEBUG
    std::string m_Name;
  #endif
  };

}
