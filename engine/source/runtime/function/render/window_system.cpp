#include "runtime/function/render/window_system.h"

#include "runtime/core/base/macro.h"

INNO_NAMESPACE_BEGIN

WindowSystem::~WindowSystem()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void WindowSystem::initialize(WindowCreateInfo create_info)
{
    if (!glfwInit())
    {
        LOG_FATAL("failed to initialize glfw");
        return;
    }
    m_width = create_info.width;
    m_height = create_info.height;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_window = glfwCreateWindow(
        create_info.width, 
        create_info.height,
        create_info.title,
        nullptr,
        nullptr 
    );
    if (!m_window)
    {
        LOG_FATAL("failed to initialize window");
        glfwTerminate();
        return;
    }

    // Setup input callbacks
    glfwSetWindowUserPointer(m_window, this);
    glfwSetKeyCallback(m_window, keyCallback);
    glfwSetWindowSizeCallback(m_window, windowSizeCallback);
}

void WindowSystem::pollEvents() const { glfwPollEvents(); }

bool WindowSystem::shouldClose() const { return glfwWindowShouldClose(m_window); }

void WindowSystem::setTitle(const char* title) { } // glfwSetWindowTitle(m_window, title); }

GLFWwindow* WindowSystem::getWindow() const { return m_window; }

std::array<int, 2> WindowSystem::getWindowSize() const { return std::array<int, 2>({m_width, m_height}); }


INNO_NAMESPACE_END
