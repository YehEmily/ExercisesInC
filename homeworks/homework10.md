## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

**1) What does it mean to say that a data structure is thread safe?**

If the data structure is accessed and modified by threads in a way that does not cause synchronization errors, then it is thread safe.

**2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?**

Because adding an element at the end of the queue makes it seem like the queue is empty; when the index gets to the end of the array, it wraps around to 0, and so, if while adding elements to the queue, we see that `next_in == next_out`, it looks like the queue is empty..

**3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.**

Different threads could acess `array`, `next_in`, and `next_out` at the same time. So if, for example, there is a thread that tries to edit a particular element from `array` and another thread that tries to pop the same element from `array`, both threads might perform their actions at the same time and the thread trying to edit the element will edit the wrong one or the thread trying to pop the element might pop the element out might pop and return the wrong value.

**4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?**

Because if it didn't unlock the mutex before blocking, no other thread would be able to access the queue, no more items could be added, and the queue would always be empty.

**5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?**

Definitely true: there is at least one item in the queue and the mutex is locked, so it's safe to access the queue. Probably true: the queue is not full.

**6) What happens if you signal a condition variable when there are no waiting threads?**

The signal has no effect.

**7) Do you have to lock the mutex to signal a condition variable?**

You don't have to, but you really should, I think. If you do not lock the mutex to signal a condition variable, you can lose important information, like wakeups ([I found this information here](https://stackoverflow.com/questions/4544234/calling-pthread-cond-signal-without-locking-mutex)).

**8) Does the condition have to be true when you signal a condition variable?**

It doesn't have to be, but signalling a sondition variable implies that it is or might be true.


