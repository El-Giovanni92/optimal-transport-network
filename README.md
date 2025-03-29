# Optimal Transport Network  

## Introduction  

The Optimal Transport Network project is developed in C++ and focuses on building an efficient transportation network connecting a set of cities. The implementation applies Kruskal’s algorithm to find the Minimum Spanning Tree (MST) of the network while differentiating between roads and railways based on distance constraints.  

## Features  

- Implementation of Kruskal’s algorithm to minimize transportation costs  
- Utilization of Union-Find data structure for optimized merging operations  
- Differentiation between roads and railways based on distance thresholds  
- Input from structured text files representing city coordinates  

## Installation  

The project can be installed and executed in two ways:  

### **Using CLion (Recommended)**  

1. Open CLion and load the project folder.  
2. Ensure that the correct C++ toolchain is installed.  
3. Build and run the project from the IDE.  

### **Manual Compilation**  

Alternatively, compile and execute the project manually using a terminal:  

```bash
g++ -o main main.cpp <other_files>.cpp
./main
```

## Usage
The program reads input from [cities.txt](optimal-transport-network/cmake-build-debug/cities.txt), where each line represents a city with its X and Y coordinates:
```cities.txt
4 20  
0 0  
40 30  
30 30  
10 10
```

To modify the dataset, edit [cities.txt](optimal-transport-network/cmake-build-debug/cities.txt), ensuring the correct format is maintained.

## Project Documentation
For an in-depth explanation of the project, please refer to the [Project Report](Project%20Report.pdf).

### Contributors
[madoverflow](https://github.com/madoverflow)
