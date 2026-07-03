#include <iostream>
#include <string>
#include "TrafficQueue.h"
#include "LogStack.h"
#include "VehicleBST.h"

using namespace std;

// Display the main menu of the Smart Traffic Control System
void displayMenu() {

    cout << "\n================ SYSTEM MENU ================\n";
    cout << "1. [S] Simulate One Second\n";
    cout << "2. [M] Update Lane Traffic (O(1) Array Lookup)\n";
    cout << "3. [V] View System Logs (Stack)\n";
    cout << "4. [A] Add Vehicle to Registry (BST Insert)\n";
    cout << "5. [F] Search Vehicle (BST Search)\n";
    cout << "6. [D] Delete Vehicle (BST Delete)\n";
    cout << "7. [P] Display Vehicle Registry (Inorder Traversal)\n";
    cout << "8. [Q] Exit\n";
    cout << "Select an option: ";
}

// Program entry point
int main() {

    // Create system components
    IntersectionCircularQueue trafficSystem;
    LogStack systemLogs;
    VehicleBST enforcementDB;

    // Create traffic lanes using a Circular Queue
    trafficSystem.addLane("Northbound ", 12);
    trafficSystem.addLane("Southbound ", 7);
    trafficSystem.addLane("Eastbound ", 20);
    trafficSystem.addLane("Westbound ", 4);

    // Add sample vehicle records into the Binary Search Tree
    enforcementDB.insertVehicle(4521, "Alice Miller", "Clear");
    enforcementDB.insertVehicle(1089, "John Doe", "Speeding Ticket");
    enforcementDB.insertVehicle(8843, "Bruce Wayne", "Stolen Record");
    enforcementDB.insertVehicle(2331, "Sarah Connor", "Clear");

    // Start the traffic signal simulation
    trafficSystem.advanceTrafficCycle(systemLogs);

    bool systemRunning = true;
    char menuOption;

    // Continue until the user chooses to exit
    while (systemRunning) {

        // Display current system status and menu
        trafficSystem.printDashboard();
        displayMenu();

        cin >> menuOption;

        // Execute the selected operation
        switch (menuOption) {

        case '1':
        case 's':
        case 'S':

            // Simulate one second of traffic flow
            trafficSystem.stepSimulatedSecond(systemLogs);
            break;

        case '2':
        case 'm':
        case 'M': {

            int laneId, targetCount;

            cout << "Enter Lane ID (1-4): ";
            cin >> laneId;

            cout << "Enter New Vehicle Count: ";
            cin >> targetCount;

            trafficSystem.updateSensorDataDirect(laneId, targetCount, systemLogs);
            break;
        }

        case '3':
        case 'v':
        case 'V':

            // Display recent traffic system logs
            systemLogs.displayLogs();
            break;

        case '4':
        case 'a':
        case 'A': {

            int id;
            string owner, status;

            cout << "Enter Vehicle Plate ID: ";
            cin >> id;

            cout << "Enter Owner Name: ";
            cin.ignore();
            getline(cin, owner);

            cout << "Enter Vehicle Status (Clear / Speeding Ticket / Stolen Record): ";
            getline(cin, status);

            enforcementDB.insertVehicle(id, owner, status);

            systemLogs.push("BST Record Added: Plate ID " + to_string(id) + " registered.");

            cout << "\n[SUCCESS] Vehicle added successfully.\n";
            break;
        }

        case '5':
        case 'f':
        case 'F': {

            int searchId;

            cout << "Enter Vehicle Plate ID: ";
            cin >> searchId;

            enforcementDB.searchVehicle(searchId);
            break;
        }

        case '6':
        case 'd':
        case 'D': {

            int deleteId;

            cout << "Enter Vehicle Plate ID to Delete: ";
            cin >> deleteId;

            enforcementDB.deleteVehicle(deleteId);

            systemLogs.push("BST Record Deleted: Plate ID " + to_string(deleteId) + " dropped.");
            break;
        }

        case '7':
        case 'p':
        case 'P':

            cout << "\n================ VEHICLE REGISTRY (BST INORDER) ================\n";

            enforcementDB.displayAllVehicles();

            cout << "================================================================\n";
            break;

        case '8':
        case 'q':
        case 'Q':

            systemRunning = false;
            break;

        default:

            cout << "\n[WARNING] Invalid option. Please try again.\n";
            break;
        }
    }

    cout << "\n=== System terminated successfully. Thank you for using Smart Traffic Control System. ===\n";

    return 0;
}