## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

**1) Why does each thread have its own stack?**

So that each thread can call functions without interfering with other threads.

**2) What does the gcc flag `-lpthread` do?**

It compiles a source file with the Pthread library.

**3) What does the argument of `pthread_exit` do?**

The argument is a value that can be passed to the thread (the parent) that joins the current thread (the child).

**4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?**

I think this is okay, maybe? I imagine that if thread A is joining thread B, which A did not create, then A would just wait for thread B and once thread B is done, thread A would continue.

**5) What goes wrong if several threads try to increment a shared integer at the same time?**

Several threads can read the shared integer before any threads increment it.

**6) What does it mean to "lock a mutex"?**

Prevent all other threads from accessing the block of code (the mutex), so only one thread gets to execute the code.
