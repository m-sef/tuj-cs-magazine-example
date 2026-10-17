#!/usr/bin/bash

USE_FAST_SET_RUNS=10
USE_HASH_SET_RUNS=10

cmake -B build -DCMAKE_CXX_FLAGS="USE_FAST_SET"
make --directory=build/
./build/greedy-maximal-independent-set

for ((i = 0; i < $USE_FAST_SET_RUNS; i++)); do
    echo "Fast Set - Run #$i"
done

cmake -B build -DCMAKE_CXX_FLAGS="USE_HASH_SET"
make --directory=build/
./build/greedy-maximal-independent-set

for ((i = 0; i < $USE_HASH_SET_RUNS; i++)); do
    echo "Hash Set - Run #$i"
done

exit 0
