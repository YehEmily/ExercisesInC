## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

I think `malloc` and `free` should take constant time, since `malloc` simply returns a pointer and `free` simply deallocates a chunk. `calloc` and `realloc` probably take time proportional to the size of the allocated chunks, since `calloc` needs to set all the bytes in the chunk to 0 and `realloc` needs to copy data from the old chunk to the new.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

The system might trigger a segfault and stop the program; however, it's more likely that the program will just read whatever value was stored at the location previously.

b) Writing to unallocated memory.

"After the bad value is written, a long time might pass before it is read and causes problems" - so I'm guessing that a value that is written to unallocated memory just stays there until a program tries to read from its address? At which point, the program would get an incorrect value.

Alternatively, if a program writes past the end of a chunk, it might mangle the data structures used to implement `malloc` and `free` which sounds like it would be very bad indeed.

c) Reading from a freed chunk.

I think that this would be like reading from unallocated memory, so the program will probably just read whatever value used to be stored at the location of the chunk.

d) Writing to a freed chunk.

I think that this would be kind of like writing to unallocated memory, so again, the value written to the chunk will probably just sit there and cause trouble later, or mangle some data structures.

e) Failing to free a chunk that is no longer needed.

This will result in a memory leak, which might in turn result in the system running out of physical memory, at which point `malloc` will start returning `null` instead of a pointer to a newly allocated block.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

Here's my output:

```
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
emily     2546  0.0  4.5 1459840 369348 tty2   Sl+  Mar10   0:33 /opt/google/chrome/chrome --typ
emily     2042  2.0  4.5 1616152 369540 tty2   SLl+ Mar10  57:52 /opt/google/chrome/chrome
emily     2493  0.3  4.6 1464888 370756 tty2   Sl+  Mar10   9:32 /opt/google/chrome/chrome --typ
emily     3321  0.4  6.0 1561732 484728 tty2   Sl+  Mar10  11:51 /opt/google/chrome/chrome --typ
emily     1575  1.5  6.7 4139264 542544 tty2   Rl+  Mar10  43:25 /usr/bin/gnome-shell
```

It looks like the shell of my desktop environment takes up the most memory (6.7%), followed by some of my Google Chrome windows/tabs.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

Allocating a lot of small chunks causes fragmentation, which wastes space and makes memory caches less effective. This problem can be fixed by allocating these small chunks in arrays, which reduces the space overhead required.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
