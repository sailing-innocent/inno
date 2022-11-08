#pragma once

#include "runtime/core/log/log_system.h"
#include "runtime/function/global/global_context.h"

#include <chrono>
#include <thread>

#define LOG_HELPER(LOG_LEVEL, ...) \
    g_runtime_global_context.m_logger_system->log(LOG_LEVEL, "[" + std::string(__FUNCTION__) + "]" + __VA_ARGS__);

#define LOG_DEBUG(...) LOG_HELPER(LogSystem::LogLevel::debug, __VA_ARGS__);

#define LOG_INFO(...) LOG_HELPER(LogSystem::LogLevel::info, __VA_ARGS__);

#ifdef NDEBUG
#define ASSERT(statement)
#else
#define ASSERT(statement) assert(statement)
#endif
