#include <iostream>
#include <thread>      // For std::this_thread::sleep_for
#include <chrono>      // For std::chrono::milliseconds
#include "loading.h"   // Include the header file

int main() {
    // Activate UTF-8 encoding on Windows (chcp 65001)
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    // Display the loading spinner for 5 seconds
    ShowLoading("Processing", 5);

    return 0;
}