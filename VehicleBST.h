#pragma once

#include <iostream>
#include <string>

// Node of the Binary Search Tree used to store vehicle records
struct BSTNode {

    // Unique vehicle registration number (BST key)
    int plateId;

    // Registered vehicle owner's name
    std::string ownerName;

    // Current vehicle status (e.g., Clear, Speeding Ticket, Stolen Record)
    std::string trackingStatus;

    // Left and right child pointers
    BSTNode* left;
    BSTNode* right;

    // Constructor
    BSTNode(int id, std::string owner, std::string status)
        : plateId(id),
        ownerName(owner),
        trackingStatus(status),
        left(nullptr),
        right(nullptr) {
    }
};

// Binary Search Tree used to manage registered vehicle records
class VehicleBST {

private:

    // Root node of the Binary Search Tree
    BSTNode* root;

    // Insert a new vehicle record into the BST
    BSTNode* insertHelper(BSTNode* node, int id, std::string owner, std::string status) {

        // Create a new node if the current position is empty
        if (node == nullptr)
            return new BSTNode(id, owner, status);

        // Insert into the left subtree
        if (id < node->plateId)
            node->left = insertHelper(node->left, id, owner, status);

        // Insert into the right subtree
        else if (id > node->plateId)
            node->right = insertHelper(node->right, id, owner, status);

        return node;
    }

    // Search for a vehicle using its registration number
    BSTNode* searchHelper(BSTNode* node, int id) {

        // Vehicle found or tree is empty
        if (node == nullptr || node->plateId == id)
            return node;

        // Search in the left subtree
        if (id < node->plateId)
            return searchHelper(node->left, id);

        // Search in the right subtree
        return searchHelper(node->right, id);
    }

    // Find the node with the smallest key in a subtree
    BSTNode* findMin(BSTNode* node) {

        while (node && node->left != nullptr)
            node = node->left;

        return node;
    }


        // Delete a vehicle record from the BST
    BSTNode* deleteHelper(BSTNode* node, int id, bool& flag) {

        // Vehicle not found
        if (node == nullptr)
            return node;

        // Continue searching in the left subtree
        if (id < node->plateId) {
            node->left = deleteHelper(node->left, id, flag);
        }

        // Continue searching in the right subtree
        else if (id > node->plateId) {
            node->right = deleteHelper(node->right, id, flag);
        }

        // Vehicle found
        else {

            // Mark successful deletion
            flag = true;

            // Case 1: Node has no left child
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Node has no right child
            else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Node has two children
            // Replace with the inorder successor
            BSTNode* temp = findMin(node->right);

            node->plateId = temp->plateId;
            node->ownerName = temp->ownerName;
            node->trackingStatus = temp->trackingStatus;

            // Delete the inorder successor
            node->right = deleteHelper(node->right, temp->plateId, flag);
        }

        return node;
    }

    // Display vehicle records using inorder traversal
    void inorderHelper(BSTNode* node) {

        // Base case
        if (node == nullptr)
            return;

        // Visit left subtree
        inorderHelper(node->left);

        // Display current vehicle information
        std::cout << "  Plate ID: " << node->plateId
            << " | Owner: " << node->ownerName
            << " | Status: [" << node->trackingStatus << "]\n";

        // Visit right subtree
        inorderHelper(node->right);
    }

    // Release all nodes in the BST
    void destroyTree(BSTNode* node) {

        // Base case
        if (node == nullptr)
            return;

        // Delete left subtree
        destroyTree(node->left);

        // Delete right subtree
        destroyTree(node->right);

        // Delete current node
        delete node;
    }

public:

    // Constructor
    VehicleBST() : root(nullptr) {}

    // Insert a new vehicle into the BST
    void insertVehicle(int id, std::string owner, std::string status) {
        root = insertHelper(root, id, owner, status);
    }

    // Search for a vehicle by its registration number
    void searchVehicle(int id) {

        BSTNode* result = searchHelper(root, id);

        if (result == nullptr) {

            std::cout << "\n[ALERT] Vehicle ID "
                << id
                << " not detected in current local registry.\n";
        }
        else {

            std::cout << "\n--- Vehicle Database Record Found ---\n";
            std::cout << "  Plate ID: " << result->plateId << "\n";
            std::cout << "  Owner Name: " << result->ownerName << "\n";
            std::cout << "  Enforcement Status: " << result->trackingStatus << "\n";
        }
    }

    // Remove a vehicle from the BST
    void deleteVehicle(int id) {

        bool success = false;

        root = deleteHelper(root, id, success);

        if (success) {
            std::cout << "\n[SUCCESS] Vehicle ID "
                << id
                << " removed from the registry.\n";
        }
        else {
            std::cout << "\n[ERROR] Vehicle ID "
                << id
                << " could not be found.\n";
        }
    }

    // Display all registered vehicles
    void displayAllVehicles() {

        if (root == nullptr) {
            std::cout << "  (Vehicle Registry Empty)\n";
            return;
        }

        inorderHelper(root);
    }

    // Destructor: Release all dynamically allocated BST nodes
    ~VehicleBST() {
        destroyTree(root);
    }
};