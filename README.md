
<h1 align="center">🚦 Smart Traffic Control System</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Course-Data%20Structures-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"/>
</p>

<p align="center">
A C++ console-based Smart Traffic Control System developed as a semester project for the Data Structures course. The project demonstrates the implementation of Circular Queue, Circular Linked List, Stack, Binary Search Tree (BST), and Arrays in a traffic management simulation.
</p>

---

# 📌 Overview

The **Smart Traffic Control System** simulates traffic signal management at a four-way intersection.

The system automatically rotates traffic signals, simulates vehicle movement, allows manual traffic updates for each lane, stores recent system events using a Stack, and manages registered vehicle records using a Binary Search Tree (BST).

This project demonstrates how multiple data structures work together to solve a real-world traffic management problem.

---

# 🎯 Project Objectives

- Demonstrate practical implementation of Data Structures.
- Simulate traffic signal rotation.
- Manage vehicle counts efficiently.
- Implement Binary Search Tree operations.
- Record recent system events using Stack.
- Perform O(1) lane updates using Arrays.
- Develop a menu-driven simulation.

---

# ✨ Features

| Feature | Description |
|---------|-------------|
| 🚦 Traffic Signal Simulation | Simulates traffic light rotation |
| 🚗 Vehicle Count Monitoring | Maintains vehicle count for each lane |
| ⚡ Manual Lane Update | Update lane traffic using O(1) Array lookup |
| 📚 System Logs | Store recent system events using Stack |
| 🌳 Vehicle Registry | Store vehicle records using BST |
| ➕ Add Vehicle | Insert vehicle into BST |
| 🔍 Search Vehicle | Search vehicle using Plate ID |
| ❌ Delete Vehicle | Remove vehicle from BST |
| 📋 Display Registry | Display all registered vehicles using Inorder Traversal |
| 🖥️ Menu Driven | Interactive console application |

---

# ✅ Core DSA Requirements

| Requirement | Status |
|------------|--------|
| Arrays | ✅ |
| Linked List | ✅ Circular Linked List |
| Queue | ✅ Circular Queue |
| Stack | ✅ |
| Binary Search Tree | ✅ |
| BST Insert | ✅ |
| BST Search | ✅ |
| BST Delete | ✅ |
| Menu Driven System | ✅ |

---

# 🧠 Data Structures Used

| Data Structure | Purpose |
|---------------|---------|
| Circular Linked List | Connects all traffic lanes |
| Circular Queue | Rotates traffic signals |
| Array | Provides O(1) lane lookup |
| Stack | Stores recent system logs |
| Binary Search Tree | Stores vehicle records |

---

# 🔗 How Each Data Structure Is Used

| Data Structure | Usage |
|---------------|-------|
| Circular Queue | Controls traffic signal rotation |
| Circular Linked List | Connects traffic lanes in circular order |
| Array | Direct lane lookup for manual updates |
| Stack | Stores recent traffic events |
| BST | Stores registered vehicle records |

---

# 🌳 Binary Search Tree Operations

| Operation | Status |
|----------|--------|
| Insert | ✅ |
| Search | ✅ |
| Delete | ✅ |
| Inorder Traversal | ✅ |

---

# 🌟 Project Highlights

- Real-Time Traffic Signal Simulation
- Hybrid Data Structure Design
- Dynamic Memory Allocation
- O(1) Lane Lookup
- Menu-Driven Console Application
- BST Vehicle Registry
- Modular Code Structure

---

# 🔄 System Workflow

```text
Start
   │
   ▼
Initialize Traffic Lanes
   │
   ▼
Initialize Vehicle Registry
   │
   ▼
Start Traffic Signal
   │
   ▼
Display Dashboard
   │
   ▼
Display Menu
   │
   ▼
Select Operation
   │
   ├── Simulate One Second
   ├── Update Lane Traffic
   ├── View System Logs
   ├── Add Vehicle
   ├── Search Vehicle
   ├── Delete Vehicle
   ├── Display Vehicle Registry
   └── Exit
```

---

# 📋 Main Menu

```text
================ SYSTEM MENU ================

1. Simulate One Second
2. Update Lane Traffic (O(1) Array Lookup)
3. View System Logs (Stack)
4. Add Vehicle to Registry (BST Insert)
5. Search Vehicle (BST Search)
6. Delete Vehicle (BST Delete)
7. Display Vehicle Registry (Inorder Traversal)
8. Exit
```

---

# ⚙️ Algorithms Used

| Algorithm | Purpose |
|-----------|---------|
| Circular Queue Rotation | Traffic Signal Scheduling |
| BST Insert | Register Vehicle |
| BST Search | Search Vehicle |
| BST Delete | Delete Vehicle |
| Inorder Traversal | Display Vehicles in Sorted Order |
| Stack Push | Store System Events |
| Stack Pop | Remove Recent Events |

---

# ⏱️ Time Complexity

| Operation | Complexity |
|-----------|------------|
| Lane Lookup (Array) | O(1) |
| Stack Push | O(1) |
| Stack Pop | O(1) |
| Traffic Signal Rotation | O(1) |
| BST Insert | O(log n)* |
| BST Search | O(log n)* |
| BST Delete | O(log n)* |
| BST Inorder Traversal | O(n) |

> *Average case.*

---

# 📂 Project Structure

```text
Smart-Traffic-Control-System/
│
├── LaneNode.h
├── LogStack.h
├── TrafficQueue.h
├── VehicleBST.h
├── main.cpp
│
├── README.md
├── LICENSE
└── .gitignore
```

---

# ▶️ How to Run

## Visual Studio

1. Open Visual Studio.
2. Create an Empty C++ Project.
3. Add all project files.
4. Build the project.
5. Press **Ctrl + F5** to run.

---

## VS Code

```bash
g++ *.cpp -o TrafficSystem
./TrafficSystem
```

---

# 🎯 Learning Outcomes

This project demonstrates practical implementation of:

- Arrays
- Circular Linked Lists
- Circular Queue
- Stack
- Binary Search Tree (BST)
- Dynamic Memory Allocation
- Menu-Driven Programming
- Traffic Signal Simulation
- Data Structure Integration
- Time Complexity Analysis

---

# 🚀 Future Enhancements

- Emergency Vehicle Priority
- Adaptive Traffic Signal Timing
- File Handling
- AVL Tree Integration
- Multi-Intersection Traffic Management
- Graph-Based Road Network
- Graphical User Interface (GUI)

---

# 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Programming Language |
| Visual Studio | IDE |
| Console | User Interface |

---

# 🎓 Academic Information

| Field | Details |
|-------|---------|
| **University** | University of Central Punjab (UCP) |
| **Course** | Data Structures |
| **Project Type** | Semester Project |

---

# 👨‍💻 Developer

**Name:** Irfan

**Registration No:** L1F24BSCS0580

---

# 📄 License

This project is licensed under the **MIT License**.

See the **LICENSE** file for details.

---

<h3 align="center">⭐ If you found this project helpful, don't forget to star the repository! ⭐</h3>
