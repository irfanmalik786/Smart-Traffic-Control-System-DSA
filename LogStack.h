#pragma once

#include <iostream>
#include <string>

// Node used in the linked-list implementation of the stack
struct StackNode {
    std::string logMessage;
    StackNode* next;

    // Constructor
    StackNode(std::string msg) : logMessage(msg), next(nullptr) {}
};

// Stack used to store recent traffic system events
class LogStack {
private:
    // Points to the top element of the stack
    StackNode* top;

public:

    // Constructor
    LogStack() : top(nullptr) {}

    // Push a new log entry onto the stack
    void push(std::string msg) {
        StackNode* newNode = new StackNode(msg);
        newNode->next = top;
        top = newNode;
    }

    // Remove the most recent log entry
    void pop() {
        if (top == nullptr)
            return;

        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    // Display the five most recent system logs
    void displayLogs() {

        if (top == nullptr) {
            std::cout << "\n--- No System Logs Available ---\n";
            return;
        }

        std::cout << "\n================ RECENT SYSTEM LOGS (STACK) ================\n";

        StackNode* current = top;
        int count = 1;

        // Display only the latest five log entries
        while (current != nullptr && count <= 5) {
            std::cout << " [" << count << "] " << current->logMessage << "\n";
            current = current->next;
            count++;
        }

        std::cout << "============================================================\n";
    }

    // Destructor: Release all dynamically allocated stack nodes
    ~LogStack() {

        while (top != nullptr) {
            pop();
        }
    }
};