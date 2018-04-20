## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

**1) Why is is a bad idea to pass a `sem_t` as a parameter?**

A `sem_t` behaves like a structure, so if you assign it to a variable (and pass it as a parameter) you are making a copy of the contents, and in POSIX, the behavior of the copy is undefined!

**2) When you use a Semaphore as a mutex, what should its initial value be?**

1 because 1 means the mutex is unlocked and one thread can pass the semaphore without blocking!!!

**3) Can you think of another use for a Semaphore where you might use a different initial value?**

I might use 0 to indicate that the mutex is locked in the case where one thread is doing all the work... Then this one thread can just lock and unlock the mutex as needed.

**4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?**

`queue->spaces` is the number of empty spaces in the queue, which is the number of producer threads that can execute `queue_push` without blocking. So, there must be `3` empty spaces in the queue and space for `3` more producer threads!

**5) What does it mean if `queue->space` is `-3`?**

This must mean that there are too many producer threads - if any of the 3 extra threads try to execute `queue_push`, they will be blocked.

**6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?**

The semaphore just keeps track of how many items are in the queue, and blocks if there are none.

**7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?**

A semaphore can be implemented using mutexes and condition variables, so one way to prove that that’s true is to implement
a semaphore using condition variables and mutexes.

**8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf).**

Property 3: if there are threads waiting on a semaphore when a thread executes `signal`, then one of the waiting threads has to be woken. This is the weakest assumption that makes it possible to avoid thread starvation.
