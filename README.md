# Teaching_Code
## NUMA
This code snippet should demonstrate the problem that can arise with NUMA architectures.
Likwid can be used to pin the program and ensure the expected results.
Be sure to adjust the core ids to the specific architecture the program is running on
```bash
make
likwid-pin -c 0,10 ./numa
```

If you run the numa program and pin it to different cores it should print out different runtimes for the two threads.
This results in the fact that both vectors are allocated on one thread.

```bash
make
likwid-pin -c 0,1 ./numa
```

However if you pin the program on the same socket you should see the same runtimes
