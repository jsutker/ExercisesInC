## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic types

2) Name two advantages of static typing over dynamic typing.

It helps with checking for whether you're giving the right type of data to a function, and it saves space.

3) Give an example of a static semantic error.

int x = "seven"

4) What are two reasons you might want to turn off code optimization?

It might overoptimize and give you an unwanted side effect, or it might take away a wanted side effect. 

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Because it would be either x64 or x86 assembly code.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

Spelling a function name wrong would make you miss running a whole section of code, and would thus probably throw you a bunch of different errors, while misspelling a variable name would probably just tell you that it's an undefined reference.

7) What is a segmentation fault?

It's when you try to read/write to a bad memory location.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

Calling 911 gives you a line to the dispatch, and (given the right situation) an ambulance is sent to your location. You don't decide which ambulance or which route they take to get to you, you just call, give a location, and medical professionals appear in a few minutes.

2) What is the difference between a program and a process?

The program is the running code, while the process is an abstraction of the isolation process keeping the program from affecting other programs that it's not meant to affect.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

To coordinate multiple processes accessing the same section of memory (but not all at once, hence coordination). It makes it seem as if they can all access it at once.

4) What is the kernel?

The OS section responsible for "core capabilities".

5) What is a daemon?

A background process that provides OS services.
 

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 (i.e. 4294967296)

3) What is the difference between "memory" and "storage" as defined in Think OS?

Memory loses its data when the computer shuts down, storage does not.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

1 GiB = 2^30 B
1 GB = 10^9 B

They're about the same, but one uses base 2 while the other uses base 10. It's approximately a 7.374% difference (1,073,741,824 B vs. 1,000,000,000 B)

5) How does the virtual memory system help isolate processes from each other?

It assigns completely separate physical memory spaces to each process, even if it gives each the same virtual memory space.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

It's so that they don't overlap as easily (you'd have to use more space together than your memory allows, as opposed to trying to layer the two from the same side)

7) What Python data structure would you use to represent a sparse array?

A hash, probably

8) What is a context switch?

It's when the OS has to save the state of one process so that it canexit it and enter another process, while being able to start up the previous process at a later time like nothing ever happened.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

Mine was:
```
Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7ffd0120a694
Address of p is 0x2033010
```
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).

New call was `p`, results are:
```
Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7ffdb3499d5c
Address of p is 0x17ec010
Address of q is 0x17ec0a0
```
(i.e., yes, goes towards larger addresses)

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

New local variable was `local2`, results are:
```
Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7ffc0ea2f47c
Address of local2 is 0x7ffc0ea2f47b
Address of p is 0xdf9010
Address of q is 0xdf90a0
```
(i.e., yes, goes towards smaller addresses)

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

There is a difference of 32 between the addresses (fancy that).


## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

It abstracts away the blocks of memory (and other things about memory like sectors and tracks), and instead makes files the user accessed

2) What information do you imagine is stored in an `OpenFileTableEntry`?

It keeps track of what file is open and where in the file you are

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Block transfers, prefetching, buffering, and caching

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

It may have been put into the buffer and not put into persistent storage yet

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

inodes seem to contain actual information about the file, where as FATs seem not to

6) What is overhead?  What is fragmentation?

Overhead is the space used by allocator, and fragmentation is a term for the unused blocks in memory

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It makes things easier to work with for developers and makes pipes work easier. It might make it difficult for certain niche things, but I can't really think of those right now.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
