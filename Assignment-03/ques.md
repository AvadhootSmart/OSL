Here are five viva questions with answers for an assignment on implementing CPU scheduling algorithms: Shortest Job First (SJF) (Preemptive) and Round Robin (with different arrival times).

### 1. **What is the difference between preemptive and non-preemptive scheduling in CPU scheduling algorithms?**
   - **Answer:** In **preemptive scheduling**, a running process can be interrupted if a higher-priority process (or one with a shorter burst time in SJF) arrives, and control of the CPU is given to this higher-priority process. In **non-preemptive scheduling**, once a process starts executing, it cannot be interrupted until it completes, regardless of other arriving processes.

### 2. **Explain how the Shortest Job First (SJF) Preemptive algorithm works with different arrival times.**
   - **Answer:** In the preemptive SJF algorithm (also known as Shortest Remaining Time First or SRTF), the CPU always selects the process with the shortest remaining time to execute. If a new process arrives with a burst time shorter than the remaining time of the currently executing process, the CPU preempts the current process and switches to the new process. This requires the scheduler to keep track of the remaining burst times and the arrival times of all processes to determine the next process to execute.

### 3. **How does the Round Robin scheduling algorithm work, and how do arrival times affect it?**
   - **Answer:** Round Robin scheduling assigns each process a fixed time slice or quantum. Processes are added to a ready queue, and each process is allowed to execute for a maximum of one time slice. If a process does not finish within this quantum, it is moved to the end of the queue, and the next process starts executing. With different arrival times, processes are only added to the queue when they arrive, so the algorithm must handle dynamic insertion into the queue based on arrival time. This makes Round Robin scheduling fair, as each process gets an equal share of CPU time.

### 4. **How would you calculate the average waiting time in both SJF (Preemptive) and Round Robin scheduling algorithms?**
   - **Answer:** For **SJF (Preemptive)**:
     - Track the waiting time for each process by recording the time intervals when a process is in the ready queue but not executing.
     - The average waiting time is calculated by summing the waiting times for all processes and dividing by the total number of processes.
  
     For **Round Robin**:
     - Track each time a process waits in the queue before resuming execution after each time quantum.
     - Sum the total waiting times of all processes and divide by the number of processes to get the average waiting time.

### 5. **What are the advantages and disadvantages of SJF (Preemptive) and Round Robin scheduling algorithms?**
   - **Answer:**
     - **SJF (Preemptive)**:
       - **Advantages:** Minimizes the average waiting time, making it optimal for shorter jobs.
       - **Disadvantages:** Difficult to implement as it requires knowledge of the future burst times of processes, and it can lead to **starvation** for longer processes if many short processes keep arriving.
     
     - **Round Robin**:
       - **Advantages:** Fair to all processes, as each process gets an equal opportunity to execute in its time quantum. It is simple and widely used for time-sharing systems.
       - **Disadvantages:** Can lead to higher average waiting time if the time quantum is too large or too small, leading to context switching overhead and inefficiency for short processes if quantum is large.
