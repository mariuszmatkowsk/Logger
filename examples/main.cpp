#include "Logger/Logger.hpp"

Log::Logger logger{"Example"};

int main(int argc, char** argv) {

    logger << Log::info << "Some information to print.";
    logger << Log::err << "Error message.";
    logger << Log::debug << "Debug message.";
    logger << Log::warn << "Warning message.";

    return 0;
}
