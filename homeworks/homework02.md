## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/YehEmily/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

In the massively popular and well-loved mobile game of Pokemon Go, walking around causes Pokemon to appear on-screen, making the player feel like they are discovering Pokemon in the real world. They have to physically be in a certain location to catch a Pokemon (unless they're massive cheaters who spoof, of course).

It's abstractly true that Pokemon appear randomly and at any point, the player might discover a Dragonite outside their house. However, Pokemon actually spawn according to a complicated formula and it's possible to predict spawns if you know the formula (but, of course, only Niantic employees do).

2. What is the difference between a program and a process?

A process represents a running program. It's possible for a process to run one program or load and run a new program, but each process can only run one program at a time. On the other hand, a program can be run on multiple processes, where each process shares the same program text but has different data and hardware states.

3. What is the primary purpose of the process abstraction? 

To allow users and engineers to use complicated systems without needing to know details about their implementation.

4. What illusion does the process abstraction create?

Process abstraction creates the illusion that there are many CPUs running many processes at once, when in reality, there is a limited number of CPUs, each running one process at a time (then terminating that process and immediately starting another, creating the illusion that this one CPU is just running a large number of processes by itself).

5. What is the kernel?

The part of the operating system responsible for core capabilities like creating threads.

6. What is a daemon?

Processes that run in the background and provide operating system services.
