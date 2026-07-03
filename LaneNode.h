#pragma once

#include <string>

// Represents a single traffic lane in the circular queue
struct LaneNode {
    std::string laneName;
    int vehicleCount;

    // Traffic signal state: GREEN, YELLOW, or RED
    std::string signalState;

    // Remaining time for the current signal
    int greenDuration;

    // Tracks how long the lane has stayed GREEN
    int secondsElapsedInGreen;

    // Pointer to the next lane (Circular Linked List)
    LaneNode* next;

    // Constructor
    LaneNode(std::string name, int count) {
        laneName = name;
        vehicleCount = count;
        signalState = "[  RED  ]";
        greenDuration = 0;
        secondsElapsedInGreen = 0;
        next = nullptr;
    }
};