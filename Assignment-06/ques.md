Here are five possible viva questions and answers for an assignment on implementing **Page Replacement Algorithms**: **FCFS (First-Come, First-Served)**, **LRU (Least Recently Used)**, and **Optimal** for a frame size of at least three.

### 1. **What is the purpose of page replacement algorithms, and why are they needed in an operating system?**
   - **Answer:** Page replacement algorithms are used in an operating system to manage memory more efficiently when the number of processes exceeds the available physical memory. When a process needs a page that is not currently in memory (a **page fault**), the operating system must decide which page to replace. This decision ensures that the system can continue operating without running out of memory. These algorithms aim to minimize the number of page faults and improve system performance.

### 2. **How does the **First-Come, First-Served (FCFS)** page replacement algorithm work, and what are its advantages and disadvantages?**
   - **Answer:** In **FCFS**, pages are replaced in the order in which they arrived. When a page fault occurs and there is no space in memory, the oldest page in memory (i.e., the one that has been in memory the longest) is replaced with the new page.
   
   - **Advantages**:
     - Simple to implement and understand.
     - Works well when the memory access patterns are predictable.
   
   - **Disadvantages**:
     - It can lead to **poor performance** when the page access patterns are not predictable, as it doesn't consider the frequency of use or recency of use. This can cause a high number of page faults and inefficient memory usage.

### 3. **Explain how the **Least Recently Used (LRU)** page replacement algorithm works and why it is considered more efficient than FCFS.**
   - **Answer:** **LRU** replaces the page that has not been used for the longest period of time. It assumes that recently accessed pages are more likely to be accessed again soon. The algorithm maintains a record of the order in which pages are used, and when a page fault occurs, it replaces the page that was least recently accessed.
   
   - **Advantages**:
     - More efficient than FCFS in terms of minimizing page faults, as it takes into account the recency of use.
   
   - **Disadvantages**:
     - Requires additional hardware or software overhead to track the access history of pages, making it more complex to implement compared to FCFS.

### 4. **What is the **Optimal Page Replacement Algorithm**, and how does it differ from LRU and FCFS?**
   - **Answer:** The **Optimal Page Replacement Algorithm** (also known as **OPT**) replaces the page that will not be used for the longest period of time in the future. This algorithm requires knowledge of future memory references, which makes it impractical for real systems but is used for comparison purposes because it gives the minimum number of page faults possible for a given sequence of memory references.
   
   - **Differences from LRU and FCFS**:
     - **FCFS** replaces pages based on the arrival time, without considering how frequently or recently they were used.
     - **LRU** replaces the least recently used page, considering the recent access history.
     - **Optimal** selects the page that will be used farthest in the future, providing the theoretical best performance but is impractical since it needs future knowledge.

### 5. **How do you calculate the number of page faults in the given page replacement algorithms, and what is the significance of the frame size?**
   - **Answer:** The **number of page faults** is calculated by counting how many times a page is requested that is not currently in memory. Each time a page fault occurs, the page is brought into memory and may cause the replacement of an existing page.
   
   - **Significance of frame size**:
     - The **frame size** determines how many pages can be held in memory at any given time. A larger frame size allows more pages to be kept in memory, reducing the chance of page faults. However, a smaller frame size can increase the page fault rate, as fewer pages are available in memory.
     - The algorithms (FCFS, LRU, and Optimal) are affected by the frame size, as the number of available frames directly impacts the likelihood of page replacement and the overall performance of the system. With a minimum frame size of three, you are ensuring that the system can handle more than one page at a time, but the efficiency of the algorithms will still depend on how well the system can predict future page references or manage the memory usage effectively.
