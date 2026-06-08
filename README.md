# Accelerating Matrices and Vectors with Parallel Programming using OpenMP in C

### 🎓 University Thesis Project | Grade: 10/10 by a 3 professor commitee
A high-performance parallel computing benchmark suite developed in pure C, utilizing the **OpenMP (Open Multi-Processing)** API to analyze multi-core scalability and profile load-balancing overheads across linear algebra operations and search algorithms.

---

## 📌 Advanced Benchmarking Methodology & Architecture
Unlike monolithic applications, this repository is designed as an **architectural testing suite**. The core testing matrix relies on a nested benchmarking loop pattern implemented inside the execution code to map out precise performance scaling curves:

1. **Exponential CPU Core Scaling:** An outer loop programmatically scales the execution workload across CPU cores exponentially ($1 \rightarrow 2 \rightarrow 4 \rightarrow 8$ threads) using `omp_set_num_threads()`.
2. **Scheduler Chunk Size Tuning:** An inner loop evaluates the OpenMP scheduling sub-parameters, dynamically altering the **chunk size** configuration per test run. 

This dual-axis execution matrix allows for precise profiling of the hardware's threshold, measuring exactly when the parallel processing benefits are eclipsed by thread synchronization and cache-miss overheads.

---

## 🛠️ Technical Features & Directory Structure

The codebase is modularly organized inside the `code/` directory, containing the following standalone executable packages:

```text
code/
├── Scalar Multiplication/    # Concurrent scalar-vector operations
├── graphical tranformations/ # 2D/3D transformations (rotation, scaling, translation) applied directly to matrices
├── inverse_matrix/          # Optimized matrix inversion and determinant parsing (Cofactors/Parallel methods)
├── kronecker Product/       # Tensor products utilizing multi-threaded heavily nested loops
├── linear equations/        # Concurrent solvers for systems of linear equations
├── matrix_addition/         # Cached-aligned dynamic matrix arrays accumulation
├── matrix_multiplication/   # Cache-unrolled multi-core row/column matrix multiplication


# How to use it

1. Navigate to the specific module directory
cd "code/inverse_matrix"

2. Compile the C file with OpenMP support enabled
gcc inverse_matrix_par.c -o inverse_matrix_par -fopenmp -O3

3. Run the benchmark suite (the internal loops will auto-scale threads and chunks)
./inverse_matrix_par

├── search/                  # Parallel Sequential vs. Parallel Binary search validation
├── transpose/               # Thread-safe matrix transposition strategies
└── not in use code/         # Sandboxed environment for memory allocation (malloc) and CLI argument (argc) tests
