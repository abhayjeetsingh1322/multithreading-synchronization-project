# Multithreading and Synchronization Project

## Overview

This project focuses on understanding how to create threads and use locks in C. It includes several experiments to explore multithreading, synchronization, and optimizing performance in parallel computations. The project consists of fixing a faulty thread creation program and implementing three parallelized solutions to calculate the sum of random integers.

## Goals

1. Fix thread creation issues using dynamic memory allocation.
2. Implement parallel computation with threads.
3. Add synchronization to ensure correctness.
4. Optimize thread execution to reduce overhead from locks.

## Features

### 1. **Thread Creation**
- Fixes the provided `createThreads.c` using the `malloc` approach to dynamically allocate memory for thread arguments.
- Ensures threads are created correctly without unexpected behavior.

### 2. **Parallel Computation**
- Implements parallel summation of one million random integers using threads.
- Includes three versions:
  - **Parallel1**: Basic multithreading without synchronization.
  - **Parallel2**: Multithreading with proper synchronization using locks.
  - **Parallel3**: Optimized solution with minimized lock usage.

## Experiments

### **Experiment 1: Basic Multithreading**
- **File**: `parallel1.c`
- Splits the work among 10 threads, each summing 100,000 integers from its own array.
- **Goal**: Observe if the result matches the sequential version and check for consistency across multiple runs.
- **Expected Outcome**: Inconsistent results due to lack of synchronization.

### **Experiment 2: Synchronization with Locks**
- **File**: `parallel2.c`
- Adds proper synchronization using locks to ensure threads access shared resources safely.
- Each thread performs:
  ```c
  lock();
  sum += array[i];
  unlock();
