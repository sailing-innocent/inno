#pragma once

#define GLFW_INCLUDE_VULKAN
#include <glfw/glfw3.h>

#include <array>
#include <functional>
#include <vector>

#include <common.h>

INNO_NAMESPACE_BEGIN

struct WindowCreateInfo
{
    int width {1200};
    int height {720};
    const char* title{"INNO"};
    bool is_fullscreen {false};
};

class WindowSystem
{
public:
    WindowSystem() = default;
    ~WindowSystem();
    void initialize(WindowCreateInfo createInfo);
    void pollEvents() const;
    bool shouldClose() const;
    void setTitle(const char* title);
    GLFWwindow* getWindow() const;
    std::array<int, 2> getWindowSize() const;

    typedef std::function<void()> onResetFunc;
    typedef std::function<void(int, int, int, int)> onKeyFunc;

    typedef std::function<void(int, int)> onWindowSizeFunc;
    typedef std::function<void()> onWindowCloseFunc;

    void registerOnKeyFunc(onKeyFunc func) { m_onKeyFunc.push_back(func); }
protected:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app)
        {
            app->onKey(key, scancode, action, mods);
        }
    }
    static void windowSizeCallback(GLFWwindow* window, int width, int height)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app)
        {
            app->m_width = width;
            app->m_height = height;
        }
    }
    void onKey(int key, int scancode, int action, int mods)
    {
        for (auto& func: m_onKeyFunc)
            func(key, scancode, action, mods);
    }
    void onWindowSize(int width, int height)
    {
        for (auto& func: m_onWindowSizeFunc)
            func(width, height);
    }
private:
    GLFWwindow* m_window { nullptr };
    int m_width {0};
    int m_height {0};

    bool m_is_focus_mode {false};

    std::vector<onKeyFunc> m_onKeyFunc;
    std::vector<onWindowSizeFunc> m_onWindowSizeFunc;
};

INNO_NAMESPACE_END
