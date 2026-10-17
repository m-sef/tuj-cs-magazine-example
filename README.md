# TUJ CS Magazine - "Why Hash Maps Suck" MIS Implementation

The program was ran twice using the following bash command:

```bash
for (( i=0; i < 20; i++ )) do; ./build/greedy-maximal-independent-set >> data.txt; done
```

To change the Set implementation, modify the final flag in the following line of [CMakeList.txt](CMakeLists.txt):

```CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Wextra -Werror -DUSE_HASH_SET")
```

To either `-DUSE_FAST_SET` or `-DUSE_HASH_SET`.

The Greedy Maximal Indepdent Set algorithm implementation can be found in [greedy_maximal_independent_set.cpp](src/greedy_maximal_independent_set.cpp).
