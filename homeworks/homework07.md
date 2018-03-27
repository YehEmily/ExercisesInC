## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

The flow of execution jumps to another location in the program, as specified by the new value.

2) What is the fundamental problem caches are meant to solve?

The "memory bottleneck" - it takes a CPU a very short amount of time to execute an instruction, but a very long time to transfer data to and from memory. With caching, when a CPU loads a value from memory, it stores a copy in a cache, and if the same value is loaded again later, the CPU can get the cached copy instead of waiting for memory.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

With 50% hit rate: `0.5(1) + 0.5(10) = 5.5 ns`

With 90% hit rate: `0.9(1) + 0.1(10) = 1.9 ns`

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

Recursive functions would probably increase (temporal) locality, since such functions just call themselves over and over and pass the results up to past calls.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

No, because cache-aware algorithms are hardware-specific, whereas this program is not. It can infer the size of the cache and the blocks, but it doesn't actually know anything about the hardware it's being run on, so it doesn't qualify as a cache-aware program.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

Based on the numbers in the reading, I think a memory cache would cost about $0.02. Comparing a DRAM to an SSD: The access time of a DRAM is 1000 times faster than that of an SSD, and the cost is about 10 times more as well. Using this proportion, I can find that when comparing a cache to a DRAM, the access time of a cache is 10 times faster than that of a DRAM, so the cost should be about 0.1 times more. This translates to about $11 per GiB for a cache, and for a device that is typically 2 MiB in size, this translates to about 11 / 2^9, or about $0.02.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

Because there is more time to make decisions at the bottom, so it is possible and helpful to use more complicated policies.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

I think operating systems should just block or kill processes when thrashing occurs, as the reading suggested. Do operating systems already cache processes before switching? If not, maybe caching would be another viable strategy.

