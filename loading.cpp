#include <iostream>
#include <thread>      // For std::this_thread::sleep_for
#include <chrono>      // For std::chrono::milliseconds
#include "loading.h"   // Include the header file

// Function to show a loading spinner with Braille characters
void ShowLoading(const std::string& message, int durationInSeconds) {
    // Braille characters for the spinner
    const std::string frames[] = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    int frameCount = sizeof(frames) / sizeof(frames[0]); // Number of frames
    int sleepDuration = 100; // Time per frame in milliseconds

    // Hide the cursor
    std::cout << "\033[?25l";

    std::cout << message << " ";

    for (int i = 0; i < (durationInSeconds * 1000) / sleepDuration; ++i) {
        // Print the spinner frame
        std::cout << "\r" << message << " " << frames[i % frameCount] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
    }

    // Show the cursor again
    std::cout << "\033[?25h";

    // Clear the spinner and indicate completion
    std::cout << "\r" << message << " Done!         \n";
}