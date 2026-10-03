# Terminal Benchmark

A lightweight CPU benchmarking tool written in C++ that uses numerical calculus workloads to measure computational performance.

The benchmark combines numerical integration and numerical differentiation into a CPU-intensive workload.

## Mathematical Workloads

### 1. Definite Integration

The benchmark approximates the definite integral

$$
\int_1^{50} \frac{\sin(x)\ln(x)}{1+x^2}\,dx
$$

using the Trapezoidal Rule.

The integration is divided into 150,000,000 subintervals.

The function used is:

$$
f(x)=\frac{\sin(x)\ln(x)}{1+x^2}
$$

The large number of iterations produces a floating-point intensive workload involving trigonometric functions, logarithms, multiplication, and division.

### 2. Numerical Differentiation

The benchmark approximates the derivative of

$$
f(x)=x\sin(x)\ln(x+1)
$$

using the Central Difference Formula:

$$
f'(x)\approx
\frac{f(x+h)-f(x-h)}{2h}
$$

where

$$
h=10^{-5}
$$

The derivative workload performs 50,000,000 evaluations.

## M-ints

The benchmark uses a custom throughput metric called **M-ints**.

M-ints represents the number of millions of benchmark steps completed per second.

$$
\text{M-ints}
=
\frac{\text{Total Steps}}
{\text{Execution Time}\times10^6}
$$

For example, if the benchmark performs 200,000,000 steps in 2 seconds:

$$
\text{M-ints}
=
\frac{200,000,000}
{2\times10^6}
$$

$$
\text{M-ints}=100
$$

Therefore, the benchmark would report:

```text
100 M-ints
```

This means that the program completed approximately 100 million benchmark steps per second.

M-ints is a project-specific metric and is not intended to represent a standardized CPU performance score or FLOPS measurement.

## Total Workload

The benchmark consists of:

```text
Definite Integration    150,000,000 steps
Numerical Differentiation 50,000,000 steps
------------------------------------------
Total                   200,000,000 steps
```

## Requirements

* C++11 or newer
* GCC, Clang, or MSVC
* A modern CPU

## Compilation

### Linux

```bash
g++ -O3 calculus_bench.cpp -o calculus_bench
./calculus_bench
```

### macOS

```bash
clang++ -O3 calculus_bench.cpp -o calculus_bench
./calculus_bench
```

### Windows

Using MinGW:

```cmd
g++ -O3 calculus_bench.cpp -o calculus_bench.exe
calculus_bench.exe
```

## Example Output

```text
========================================
      TERMINAL BENCHMARK WITH CALCULUS   
           by Patiphan Sittikan          
========================================
[*] Starting Calculus 1 benchmark...
[*] DEFINITE INTEGRAL (150000000 steps)... Done! Time: 0.1345s (Area: 1.1234)
[*] DERIVATIVE (50000000 steps)... Done! Time: 0.0412s
========================================
 BENCHMARK RESULTS:
 Total Cal 1 Operations: 200000000 steps
 Total Time Taken      : 0.1757 s
 ---------------------------------------
 SPEED SCORE           : 1138.30 M-ints
========================================

Created and maintained by
Patiphan Sittikan
```

The values shown above are examples. Actual results depend on the CPU, compiler, operating system, optimization settings, and system load.

## Optimization

The benchmark is recommended to be compiled with `-O3`.

For fair comparisons, use the same:

* Source code
* Compiler and compiler version
* Optimization flags
* Number of iterations
* Operating conditions

Multiple runs should be performed when collecting benchmark results.

## Limitations

This benchmark measures performance for a specific numerical workload. It should not be considered a general-purpose CPU benchmark.

Performance can be affected by:

* CPU architecture
* CPU clock speed
* Turbo/boost behavior
* Thermal throttling
* Compiler and math-library implementation
* Operating system
* Background processes
* Power-management settings

In particular, functions such as `sin()` and `log()` may have different implementations depending on the compiler and platform.

## Project Structure

```text
calculus-benchmark/
├── calculus_bench.cpp
├── README.md
├── LICENSE
└── results/
    └── benchmark_results.csv
```

## Future Improvements

* Multi-threaded benchmark
* SIMD implementations
* AVX2 / AVX-512 implementations
* Configurable iteration count
* Multiple benchmark runs
* Statistical result analysis
* CSV result export
* CPU information detection
* Additional numerical integration methods
* Simpson's Rule
* Higher-order numerical differentiation

## Author

Patiphan Sittikan

A project exploring the connection between calculus, numerical methods, C++, and computer hardware.
