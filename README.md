# Logger
**Logger** is a lightweight and user-friendly logging library designed
to simplify logging in your applications.
It supports essential log levels such as Error, Info, Debug, and Warning,
enabling clear and organized tracking of application events.

---

## Features
- Easy integration with any project.
- Configurable log levels. (Debug, Info, Warning, Error)
- Clean and readable output for debugging and monitoring.

---

## Usage

```cpp
#include "Logger/Logger.hpp"

Log::Logger logger{"example"};

int main() {
    logger << debug << "Debug message.";
    logger << info << "Some info message.";
    logger << wrn << "Warning message.";
    logger << err << "Error message.";

    // log to file
    std::ofstream output_file{"log.txt"};
    Log::Logger logger_file{"example_file", output_file};
    logger_file << info << "Some info message";

    return 0;
}
```

## Future improvements

- Support for multi-threaded environment.
- Logging Filtering.
