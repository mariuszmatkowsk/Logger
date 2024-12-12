#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "Logger/Logger.hpp"

TEST(LoggerTest, canCreateLoggerWithGivenName) {
    logger::Logger logger{"Test"};
}

TEST(LoggerTest, canCreateLoggerWithStringStream) {
    std::stringstream ss;
    logger::Logger logger{"Test", ss};
}

TEST(LoggerTest, canCreateLoggerWithFileStream) {
    std::ofstream file{};
    logger::Logger logger{"Test", file};
}

TEST(LoggerTest, canLogInfo) {
    std::stringstream ss;
    logger::Logger logger{"Test", ss};

    logger << logger::info << "info";

    EXPECT_EQ(ss.str(), "Test/info: info");
}

TEST(LoggerTest, canLogWarning) {
    std::stringstream ss;
    logger::Logger logger{"Test", ss};

    logger << logger::warn << "warning";

    EXPECT_EQ(ss.str(), "Test/warning: warning");
}

TEST(LoggerTest, canLogDebug) {
    std::stringstream ss;
    logger::Logger logger{"Test", ss};

    logger << logger::debug << "debug";
    EXPECT_EQ(ss.str(), "Test/debug: debug");
}

TEST(LoggerTest, canLogError) {
    std::stringstream ss;
    logger::Logger logger{"Test", ss};

    logger << logger::err << "error";

    EXPECT_EQ(ss.str(), "Test/error: error");
}

// TEST(LoggerTest, ssss) {
//     std::stringstream ss;
//     logger::Logger logger{"Test", ss};
//
//     logger << 1;
// }
