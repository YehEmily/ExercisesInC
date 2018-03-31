## Homework 8

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

To handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The program counter.

3) What is the difference between an interrupt and a context switch?

After an interrupt, the kernel can resume the interrupted process, or in the case of a context switch, the kernel can switch to another process.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

When a process executes a disk request, which is a system call that cannot complete immediately; later, when the disk request completes, an interrupt occurs and the interrupt handler identifies which process was waiting for the request and switches that process's state from blocked to ready.

5) Why might a scheduler want to give higher priority to an I/O bound process?

An I/O bound process usually makes a request and blocks before its time slice is complete. As a result, 1) it might take some time to complete, so it should start as soon as possible, and 2) it is better for a long-running process to wait for a short one, so an I/O bound process should run before any long-running processes.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

(Is this a question I'm supposed to answer??) Put 8 slices on the griddle and let them cook on both sides, then put the remaining 4 on and do the same. It takes a total of 20 minutes. Actually, Allen, why not make batches of 16 slices? Then you can bring some to work and share them with your colleagues and students!
