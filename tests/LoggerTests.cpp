#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "Logger/Logger.hpp"

TEST(LoggerTest, canCreateLoggerWithGivenName) {
    Log::Logger logger{"Test"};
}

TEST(LoggerTest, canCreateLoggerWithStringStream) {
    std::stringstream ss;
    Log::Logger logger{"Test", ss};
}

TEST(LoggerTest, canCreateLoggerWithFileStream) {
    std::ofstream file{};
    Log::Logger logger{"Test", file};
}

TEST(LoggerTest, canLogInfo) {
    std::stringstream ss;
    Log::Logger logger{"Test", ss};

    logger << Log::info << "info";

    EXPECT_EQ(ss.str(), "Test/info: info\n");
}

TEST(LoggerTest, canLogWarning) {
    std::stringstream ss;
    Log::Logger logger{"Test", ss};

    logger << Log::warn << "warning";

    EXPECT_EQ(ss.str(), "Test/warning: warning\n");
}

TEST(LoggerTest, canLogDebug) {
    std::stringstream ss;
    Log::Logger logger{"Test", ss};

    logger << Log::debug << "debug";
    EXPECT_EQ(ss.str(), "Test/debug: debug\n");
}

TEST(LoggerTest, canLogError) {
    std::stringstream ss;
    Log::Logger logger{"Test", ss};

    logger << Log::err << "error";

    EXPECT_EQ(ss.str(), "Test/error: error\n");
}

TEST(LoggerTest, multipleLineLogging) {
    std::stringstream ss;
    Log::Logger logger{"Test", ss};

    logger << Log::err << "error";
    logger << Log::info << "info";

    EXPECT_EQ(ss.str(), "Test/error: error\nTest/info: info\n");
}
