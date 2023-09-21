# Creating Processes on Linux with C++ 🐧

Processes are the fundamental units for executing programs in computer systems. They consist of code and data, loaded into main memory and linked with a data structure called a process control block or process described block. It is through this structure that the operating system is able to perform all the management functions that are necessary for the efficient execution of a given program or application. 🚀

Processes are created from other processes, establishing a "parent process" and "child process" relationship, which underlies a process tree maintained by the system. The creation of processes is a prerogative of operating systems. They do so through system calls, the specification of which depends on the type of application programming interface (API) compatible with the system. For example, in the case of Linux, and other operating systems that have a derivative of Unix, the API used is POSIX. 🌐

The POSIX system call for creating a child process is `fork()`. This function creates an image of the parent process in another memory address space, and with another process descriptor. Therefore, these are two different processes. 🔄

The value returned by the `fork()` function has different values ​​for the creator and created processes. For the parent process, the function returns the identifier of the child process. For the child process, the function returns the value zero. This allows you to create code that, through decision structures (`if-else`, for example), decides whether the person executing is a parent process or a child process.

Finally, for synchronization reasons, the parent process must execute the `wait()` system call, which is a function that will block the parent process until the child process ends its execution. ⏳

## Problem to be solved 🤔

Create a program, in C/C++ language, for Linux systems, in which a process receives a positive integer (total terms in the Fibonacci series), creates a child process and blocks itself using the `wait()` function. The created child process must then, based on the total number of terms in the Fibonacci series, generate and display these terms, thus completing its execution. 💡

## Run ▶️

```bash
gcc main.c -o main.out && ./a.out
```

### Running example 🚀

```bash
gcc main.c -o main && ./main

# .:: Starting main process... <PID#797>
# .:: Create child process.. 
# .:: Waiting for child process to finish.. 

#     .:: Starting child process.. <PID#798>

#         .:: Enter the number of terms to display in the Fibonacci series: 5
#         .:: Fibonacci series for 5 numbers: { 0  1  1  2  3 }

#     .:: Child process closed! <PID#798>

# .:: Returning to the main process.. 
# .:: Main process closed! <PID#797> 
```

---

<div align="center">
  📚 DCA0108 - Operating Systems (2023.1) 🎓 <br/>
  Federal University of Rio Grande do Norte - Department of Computer and Automation Engineering (DCA). 🏛️
</div>