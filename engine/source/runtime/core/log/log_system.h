#pragma once

#include <spdlog/spdlog.h>
#include <cstdint>
#include <stdexcept>

#include <common.h>

INNO_NAMESPACE_BEGIN

class LogSystem final
{
public:
    enum class LogLevel: uint8_t
    {
        debug,
        info,
        warn,
        error,
        fatal
    };

public:
    LogSystem();
    ~LogSystem();

    template<typename... TARGS>
    void log(LogLevel level, TARGS&&... args)
    {
        switch (level)
        {
        case LogLevel::debug:
            m_logger->debug(std::forward<TARGS>(args)...);
            break;
        case LogLevel::info:
            m_logger->info(std::forward<TARGS>(args)...);
            break;
        default:
            break;
        }
    }

private:
    std::shared_ptr<spdlog::logger> m_logger;
};

INNO_NAMESPACE_END
