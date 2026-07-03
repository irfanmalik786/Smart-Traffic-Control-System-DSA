#pragma once

#include "LaneNode.h"
#include "LogStack.h"
#include <iostream>
#include <string>

// Circular Queue implementation for managing traffic lanes
class IntersectionCircularQueue {
private:
    LaneNode* head;
    LaneNode* tail;
    LaneNode* activeLane;

    // Array used for direct O(1) lane access by lane ID
    LaneNode* laneLookUpMap[6];

    // Total number of lanes in the intersection
    int totalLanes;

    // Fixed green signal duration (in seconds)
    const int FIXED_GREEN_TIME = 12;

public:

    // Constructor: Initialize an empty circular queue
    IntersectionCircularQueue() {
        head = nullptr;
        tail = nullptr;
        activeLane = nullptr;
        totalLanes = 0;

        // Initialize lookup table
        for (int i = 0; i < 6; i++)
            laneLookUpMap[i] = nullptr;
    }

    // Add a new traffic lane into the circular queue
    void addLane(std::string name, int initialVehicles) {

        // Create a new lane node
        LaneNode* newLane = new LaneNode(name, initialVehicles);

        totalLanes++;

        // Store lane pointer for direct O(1) lookup
        if (totalLanes < 6) {
            laneLookUpMap[totalLanes] = newLane;
        }

        // Insert the first lane
        if (head == nullptr) {
            head = newLane;
            tail = newLane;

            // Make the queue circular
            newLane->next = head;

            // First lane becomes active
            activeLane = head;
        }
        else {

            // Insert lane at the rear of the circular queue
            tail->next = newLane;
            tail = newLane;

            // Maintain circular connection
            tail->next = head;
        }
    }


        // Change the traffic signal to the next lane in the circular queue
    void advanceTrafficCycle(LogStack& systemLogs) {

        // Return if no lane exists
        if (activeLane == nullptr)
            return;

        // If the current lane is GREEN, change it to YELLOW
        if (activeLane->signalState == "[ GREEN ]") {

            activeLane->signalState = "[ YELLOW ]";
            activeLane->greenDuration = 3;
            activeLane->secondsElapsedInGreen = 0;

            // Store the event in the system log
            systemLogs.push("Transition: " + activeLane->laneName + " turned YELLOW.");
        }

        // If the current lane is YELLOW, change it to RED
        // and activate the next lane
        else if (activeLane->signalState == "[ YELLOW ]") {

            activeLane->signalState = "[  RED  ]";
            activeLane->secondsElapsedInGreen = 0;

            // Store the event in the system log
            systemLogs.push("Transition: " + activeLane->laneName + " turned RED.");

            // Move to the next lane in the circular queue
            activeLane = activeLane->next;

            // Turn the next lane GREEN
            activeLane->signalState = "[ GREEN ]";
            activeLane->greenDuration = FIXED_GREEN_TIME;
            activeLane->secondsElapsedInGreen = 0;

            // Store the event in the system log
            systemLogs.push("Rotation: " + activeLane->laneName + " activated to GREEN.");
        }

        // Initialize the traffic system when it starts
        else {

            activeLane->signalState = "[ GREEN ]";
            activeLane->greenDuration = FIXED_GREEN_TIME;
            activeLane->secondsElapsedInGreen = 0;

            // Store the initialization event
            systemLogs.push("System Boot Init: " + activeLane->laneName + " set to GREEN.");
        }
    }



        // Simulate one second of traffic signal operation
    void stepSimulatedSecond(LogStack& systemLogs) {

        // Continue only if there is an active lane with remaining signal time
        if (activeLane != nullptr && activeLane->greenDuration > 0) {

            // Decrease the remaining signal timer by one second
            activeLane->greenDuration--;

            // Process vehicles only while the signal is GREEN
            if (activeLane->signalState == "[ GREEN ]") {

                // Count how long the signal has been GREEN
                activeLane->secondsElapsedInGreen++;

                // Allow one vehicle to pass every 2 simulated seconds
                if (activeLane->secondsElapsedInGreen % 2 == 0) {

                    // Prevent vehicle count from becoming negative
                    if (activeLane->vehicleCount > 0) {
                        activeLane->vehicleCount--;
                    }
                }
            }

            // Move to the next traffic phase when the timer expires
            if (activeLane->greenDuration == 0) {
                advanceTrafficCycle(systemLogs);
            }
        }
    }



        // Update the vehicle count of a specific lane using its lane ID
    void updateSensorDataDirect(int laneId, int newCount, LogStack& systemLogs) {

        // Validate the entered lane ID
        if (laneId < 1 || laneId > totalLanes || laneLookUpMap[laneId] == nullptr) {
            std::cout << "\n[ERROR] Invalid Lane ID provided!\n";
            return;
        }

        // Access the required lane in O(1) time using the lookup array
        LaneNode* targetLane = laneLookUpMap[laneId];

        // Prevent negative vehicle counts
        targetLane->vehicleCount = (newCount < 0) ? 0 : newCount;

        // Save this manual update in the system log
        systemLogs.push("Manual override: " + targetLane->laneName +
            " payload altered to " + std::to_string(targetLane->vehicleCount));
    }

    // Display the current status of all traffic lanes
    void printDashboard() {

        // Nothing to display if no lanes exist
        if (head == nullptr)
            return;

        std::cout << "\n==================================================================\n";
        std::cout << "             SMART TRAFFIC CONTROL SYSTEM DASHBOARD               \n";
        std::cout << "==================================================================\n";
        std::cout << "Lane ID | Lane Name              | Vehicles | State    | Timer    \n";
        std::cout << "------------------------------------------------------------------\n";

        // Traverse the circular queue and display each lane
        LaneNode* temp = head;
        int id = 1;

        do {

            std::cout << " [" << id << "]    | ";

            std::cout << temp->laneName;

            // Keep lane names aligned in the output table
            for (size_t i = temp->laneName.length(); i < 22; i++)
                std::cout << " ";

            std::cout << " | " << temp->vehicleCount;

            if (temp->vehicleCount < 10)
                std::cout << " ";

            std::cout << "        | " << temp->signalState << " | ";

            // Show the remaining timer only for GREEN and YELLOW signals
            if (temp->signalState != "[  RED  ]") {
                std::cout << temp->greenDuration << "s\n";
            }
            else {
                std::cout << "-\n";
            }

            temp = temp->next;
            id++;

        } while (temp != head);

        std::cout << "==================================================================\n";
    }

    // Destructor: Release all dynamically allocated lane nodes
    ~IntersectionCircularQueue() {

        // Nothing to delete if the queue is empty
        if (head == nullptr)
            return;

        // Break the circular link before deleting nodes
        tail->next = nullptr;

        LaneNode* current = head;

        // Delete each lane one by one
        while (current != nullptr) {

            LaneNode* nextNode = current->next;

            delete current;

            current = nextNode;
        }
    }
};