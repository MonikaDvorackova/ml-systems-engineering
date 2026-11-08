# ml-systems-engineering

C++ reference GEMM and microbenchmark.

## Scope

A small, inspectable, reproducible **v0.1 reference implementation**. The project is not presented as a production system or peer-reviewed research result.

## Requirements

C++17 compiler; CMake

## Setup

```bash
cmake -S . -B build && cmake --build build
```

## Run example / experiment

From the repository root:

```bash
g++ -std=c++17 -O2 benchmarks/matrix_bench.cpp -o /tmp/matrix_bench && /tmp/matrix_bench
```

## Test

```bash
ctest --test-dir build --output-on-failure
```

## Reproducibility

Experiments use deterministic inputs or explicitly seeded generators. See the experiment sources for assumptions and input sizes. CI exercises both tests and the example; check the Actions tab for actual run results. No empirical results are claimed without executed measurements.

## Limitations

The kernel is a straightforward O(mkn) reference implementation, not BLAS-competitive. Single timing is illustrative and is not a rigorous hardware benchmark.

## License

MIT. Contributions should include a focused regression test and an explanation of changed assumptions.

## Run without local setup

Run [CI](https://github.com/MonikaDvorackova/ml-systems-engineering/actions/workflows/ci.yml) → **Run workflow** on `main`. GitHub provides the compiler, dependencies, and test environment. Local commands must be run from a cloned repository root, not your home directory.
