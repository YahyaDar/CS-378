# Project - Frequent Itemset Mining Engine Architecture

  
  

## **CS-378 :: Systems Implementation of Frequent Itemset Mining (Spring 2026)**

  
  

## Overview

  

During the semester, you will build a high-performance engine in C++ that implements and compares the classical Apriori algorithm against the state-of-the-art dEclat algorithm. Frequent itemset mining (FIM) is a foundational task in data mining concerned with identifying sets of items that co-occur frequently across transactional datasets. It serves as the backbone for generating association rules in various applications such as retail analytics, healthcare informatics, and fraud detection.

  

Despite its utility, FIM is computationally intensive due to the exponential number of potential itemsets and the cost of counting support across millions of transactions. The engine you build will be evaluated on its modularity, resource management (RAII), and execution speed.

  

This is a group project that allows up to 3 members.

  

-  **Due Date:** May 11, 2026.

  

---

  

## Project Specification

  

You will need to implement the following modules and components in your engine:

  

### Task #1 - Apriori Module

  

The Apriori algorithm operates on a breadth-first search (BFS) strategy combined with a generate-and-test paradigm. You will implement the core Apriori algorithm in `src/apriori.cpp`. Your implementation must include:

  

-  **Candidate Generation:** Generate candidate itemsets of size `k+1` by joining pairs of frequent itemsets of size `k` that share a common prefix. Use `std::vector` for candidate generation.

-  **Pruning via Apriori Property:** Exploit the anti-monotonicity property to prune candidates. If any subset of a candidate itemset is infrequent, the candidate must be immediately pruned. You must use `std::vector` for anti-monotonicity pruning.

-  **Support Counting:** Scan the transaction database to count the support of each candidate itemset.

  

### Task #2 - dEclat Module

  

dEclat utilizes a depth-first search (DFS) along with a vertical data format called "diffsets". You will implement dEclat in `src/declat.cpp`.

  

-  **Diffset Operations:** Instead of tracking full transaction ID sets, compute the differences between sets using efficient bit-level operations.

-  **Depth-First Search:** Recursively execute DFS to explore the search space.

  

### Task #3 - Optimization Strategies

  

Each group must propose and implement at least two optimization strategies targeting either the Apriori algorithm or the selected state-of-the-art algorithm. Possible directions include:

  

-  **Algorithmic Optimizations:** Reducing database scans using sampling or partition-based approaches, or improving candidate pruning with lookahead/constraint-based filtering.

-  **Data Structure Enhancements:** Replacing naive hash-table support counting with compact trie or bitmap structures.

-  **Parallel & Distributed Processing:** Implementing multi-threaded or GPU-accelerated support counting, or partitioning the dataset across threads to enable concurrent candidate evaluation.

  

Each optimization must be justified theoretically and validated empirically in your report.

  

### Task #4 - Testing & Benchmarking

  

You must validate your engine using the provided Google Test (`gtest`) framework.

  

-  **Functional Unit Tests (`tests/test_functional.cpp`):** Validate that both algorithms produce the exact same frequent itemsets.

-  **Performance Tests (`tests/test_performance.cpp`):** Benchmark the execution time. The dEclat implementation is expected to be faster than Apriori on dense datasets.

  

---

  

## Instructions

  

### Setting Up Your Environment

  

Ensure you have CMake (minimum version 3.14) and a compiler that supports C++17. The provided `CMakeLists.txt` is already configured to fetch Google Test automatically.

  

### Building the Project

  

You can compile the project from the command-line by creating a build directory:

  

  

```Bash
$ mkdir build

$ cd build

$ cmake ..

$ make
```

  

### Running the Engine

  

After compiling, you can run the main executable by providing a dataset file, a minimum support threshold (as a float), and the chosen algorithm (`apriori` or `declat`):

  


  

```Bash
$ ./cs378_engine <dataset.txt> <min_sup> <algo: apriori|declat>
```

  

### Running the Tests

  

You can execute the functional and performance test suites individually:

  


```Bash
$ ./cs378_tests_functional

$ ./cs378_tests_performance
```

  

### Benchmark Datasets

  

All experiments should be conducted using standard benchmark datasets. Recommended datasets include **Connect**, **Chess**, and **Accident**. These files can be found at the FIMI Repository or SPMF Datasets.

  

---

  

## Deliverables & Performance Metrics

  

Your evaluation will be grounded in quantitative metrics. You are encouraged to report results under multiple minimum support thresholds to demonstrate how algorithm performance scales with varying levels of itemset frequency. You must report the following for all algorithms and datasets:

  

- Execution time (wall-clock time in milliseconds/seconds) at varying `min_sup` thresholds.

- Memory consumption (peak RAM usage in MB).

- Number of frequent itemsets discovered.

- Number of candidates generated (for Apriori).

- Speedup ratio of the optimized algorithm over the baseline (Apriori).

- Scalability curves: performance as dataset size or `min_sup` changes.

  

All experiments should be run at least three times and results averaged to reduce variance.

  

---

  

## Evaluation & Grading Rubric

  

The project evaluation consists of two parts:

  

### 1. Final Report Writing (60%)

  

The final report must strictly adhere to the IEEE double-column conference format.

  

- **10%** - Introduction and problem motivation.

- **10%** - Literature review quality and depth.

- **15%** - Algorithm description, pseudocode, and complexity analysis.

- **10%** - Optimization strategies and justification.

- **10%** - Experimental setup, results, and discussion.

- **5%** - Conclusion, references, and IEEE format compliance.

  

### 2. Viva / Oral Defense (40%)

  

- **10%** - Conceptual understanding of Apriori algorithm.

- **10%** - Knowledge of selected state-of-the-art algorithm.

- **10%** - Articulation of optimization strategies and their empirical impact.

- **10%** - Ability to respond to follow-up and clarification questions.

  

---

  

## Submission Guidelines

  

- **Hard Copy:** The report must be submitted in hard copy (printed, bound) by 11th May, 2026.

- **Soft Copy:** A PDF must also be submitted via the designated google classroom by the same deadline.

- **Source Code:** The submitted code must be included as a zipped attachment or a shared repository link.

- **Viva Attendance:** All group members must be present during the viva; absent members will receive a zero for that component.

  

*Late submissions will be penalized at the instructor’s discretion.*

  

---

  

## Academic Integrity

  

All work submitted must be original. You may reference existing implementations for understanding, but the code you submit must be written independently by your group.

  

- All external sources — papers, datasets, code snippets — must be properly cited.

- Collaboration across groups is not permitted beyond general discussion.
