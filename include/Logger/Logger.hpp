#pragma once

#include <cassert>
#include <iostream>
#include <ostream>
#include <stdexcept>

namespace logger {

class Logger {
private:
    class LoggerProxy {
    public:
        explicit LoggerProxy(std::ostream& os) : os_(os) {
        }

        template <typename T>
        LoggerProxy& operator<<(const T& x) {
            os_ << x;
            return *this;
        }

    private:
        std::ostream& os_;
    };

public:
    enum class Severity {
        Debug,
        Info,
        Err,
        Warn,
    };

    explicit Logger(std::string name, std::ostream& os = std::cout)
        : name_(std::move(name)), os_(os) {
    }

    template <typename T>
    void operator<<(const T&) {
        static_assert(false, "Invalid type passed to Logger::operator<<");
    }

    constexpr LoggerProxy operator<<(Logger::Severity severity) {
        os_ << name_ << '/' << to_string(severity) << ": ";
        return LoggerProxy{os_};
    }

private:
    constexpr const char* to_string(Severity s) {
        switch (s) {
            case Severity::Debug:
                return "debug";
            case Severity::Info:
                return "info";
            case Severity::Err:
                return "error";
            case Severity::Warn:
                return "warning";
        }
        return "unknown";
    }

    std::string name_;
    std::ostream& os_;
};

inline constexpr Logger::Severity debug{Logger::Severity::Debug};
inline constexpr Logger::Severity info{Logger::Severity::Info};
inline constexpr Logger::Severity err{Logger::Severity::Err};
inline constexpr Logger::Severity warn{Logger::Severity::Warn};

} // namespace logger
