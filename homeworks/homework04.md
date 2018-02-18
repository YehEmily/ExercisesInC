## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

File systems provide the abstraction that each file's name is mapped to its contents, so a file system is like a key-value database. It logically makes sense that files are byte-based, but in reality, persistent storage is block-based.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

`OpenFileTableEntry` stores information about open files, right? I think it probably stores information about the file position (how much of the file has been read) and the status of the file (open for reading, writing, etc.).

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Block transfers (reading large blocks every time the disk is accessed), prefetching (predicting what blocks a process might read), buffering (storing data in memory while you edit and writing to the disk later), and caching (keeping a copy of a block in memory for future requests).

4) Suppose your program writes a file and prints a message indicating that it is done writing. 
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

The file I wrote was probably in a cache and not yet on the disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

There is some overhead in using inodes, since inodes essentially store addresses in blocks that could be used for storing data. On the other hand, FAT can be error-prone because it basically behaves like a linked list of pointers to clusters. If something happens and one of the pointers is incorrect, it'll be impossible to access the next cluster that the pointer was supposed to point to.

6) What is overhead?  What is fragmentation?

Overhead is space used by data structures that are used by allocators (in other words, space that can't be used by data). Fragmentation is partially or completely unused blocks of space.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It's a good idea because reusing file abstraction principles allows programmers to only have to learn one API. However, it might be a bad idea because it's not really true; not everything really behaves like a file, but I guess it's usually good enough to believe they do.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



