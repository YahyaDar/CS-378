# CS-378: Systems Implementation of Frequent Itemset Mining
**Project: Apriori vs. dEclat Engine Architecture (C++ Edition)**

## 1. Objective
The objective of this project is to build a high-performance engine in C++ that implements and compares the classical Apriori algorithm against the state-of-the-art dEclat algorithm. You are expected to utilize C++ standard containers effectively, optimize for CPU cache locality, and utilize bitset structures to minimize the memory footprint.

## 2. System Architecture
Your engine will be evaluated on its modularity, resource management (RAII), and execution speed. The system is divided into two core modules:
* **Apriori Module:** Implements a breadth-first search (BFS). Use `std::vector` for candidate generation and anti-monotonicity pruning.
* **dEclat Module:** Implements a depth-first search (DFS) using vertical data formats. You must implement "diffsets" using efficient bit-level operations.

## 3. Testing and Benchmarking
You must validate your engine using the provided Google Test (`gtest`) framework.
* **Functional Unit Tests:** Validate that both algorithms produce the exact same frequent itemsets.
* **Performance Tests:** Benchmark the execution time.

## 4. Benchmark Datasets
* **FIMI Repository:** http://fimi.uantwerpen.be/data/
* **SPMF Datasets:** https://www.philippe-fournier-viger.com/spmf/index.php?link=datasets.php
