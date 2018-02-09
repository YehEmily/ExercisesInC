## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits (2^5 = 32, so I need 2^6).

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 = 4294967296 characters.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

Memory is voltaile, while files stored in storage are not. If your computer shuts down, anything stored in memory will be lost, whereas anything stored in storage (which refers to hard disk drives HSS or solid state drives SSD) won't.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

Gibibyte vs. gigabyte = 2^30 bytes vs. 10^9 bytes = 7.37% difference.

5) How does the virtual memory system help isolate processes from each other?

A process can't access data belonging to another process because there is no virtual address that it can generate that maps to the physical memory allocated to another process.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

Because the heap can grow dynamically, whereas space is allocated to the stack, it makes sense for the stack and heap to be as far apart as possible to allow the heap to grow. I think.

7) What Python data structure would you use to represent a sparse array?

A hashmap? If the array is sparse, it's unlikely there will be collisions, so a hashmap should work just fine.

8) What is a context switch?

When an operating system interrupts a running process, saves its state, and then runs another process.
