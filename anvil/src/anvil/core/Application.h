#pragma once

namespace Anvil {

  class Application {
  public:
    Application(std::string_view name = "Anvil application");

    void         Run();
    void         Close();
    Application* Get() const { return s_Instance; }

  private:
    virtual ~Application() = default;

  private:
    // TODO: Should we use a smart pointer?
    static Application* s_Instance;

    std::string_view m_Name;
  };

} // namespace Anvil
