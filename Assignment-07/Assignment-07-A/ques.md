Here are five possible viva questions and answers for an assignment on **Full-Duplex Communication Between Two Independent Processes** using **FIFOs** (named pipes) in a C program.

### 1. **What is FIFO (First-In, First-Out) in the context of inter-process communication (IPC), and how does it work?**
   - **Answer:** **FIFO** (First-In, First-Out) is a type of **named pipe** used for communication between processes in Unix-like operating systems. It provides a way for processes to send and receive data in a sequential, orderly manner. Data written to the FIFO by one process can be read by another process in the same order it was written. FIFOs are persistent and can be used by unrelated processes to communicate by referring to the same FIFO file in the filesystem. One process writes data to the FIFO, and another reads from it, allowing full-duplex communication.

### 2. **What is full-duplex communication, and how is it achieved using FIFOs in this assignment?**
   - **Answer:** **Full-duplex communication** allows two processes to communicate simultaneously in both directions. In this assignment, full-duplex communication is achieved by using two FIFOs:
     - The first FIFO is used by the **first process** to send sentences to the second process.
     - The second FIFO is used by the **second process** to send the output (number of characters, words, and lines) back to the first process.
     This setup enables the two processes to exchange data in both directions concurrently, with the first process writing to the first FIFO and reading from the second FIFO, and vice versa for the second process.

### 3. **How does the first process interact with the second process in this implementation using FIFOs?**
   - **Answer:** The **first process** interacts with the **second process** in two stages:
     1. It **writes** sentences to the **first FIFO**, which the second process reads.
     2. After the second process counts the number of characters, words, and lines, it writes the results to a text file and then writes the contents of this file to the **second FIFO**.
     3. The **first process** then **reads** from the second FIFO, displaying the results (the file content) on the standard output.

### 4. **How does the second process count the number of characters, words, and lines, and how are these results stored and communicated back to the first process?**
   - **Answer:** The **second process** performs the following tasks:
     1. It reads the sentence from the **first FIFO**.
     2. It then processes the sentence to count:
        - **Characters**: This can be done by iterating through each character in the sentence.
        - **Words**: This can be done by splitting the sentence based on spaces or other delimiters.
        - **Lines**: This can be counted by detecting newline characters (`\n`).
     3. The results (counts of characters, words, and lines) are written to a **text file** (e.g., using `fprintf` in C).
     4. After the file is updated, the **second process** writes the contents of the file to the **second FIFO** for the **first process** to read.

### 5. **What are some challenges in implementing full-duplex communication using FIFOs, and how can they be addressed?**
   - **Answer:** Some challenges in implementing full-duplex communication with FIFOs include:
     - **Synchronization**: Both processes must be synchronized to avoid race conditions. For instance, the second process must not attempt to read from the first FIFO before the first process writes to it, and vice versa. This can be managed by proper ordering of `read` and `write` operations and by using synchronization techniques like **blocking** reads or **select** to wait for data.
     - **Error Handling**: Handling cases like **EOF** (End of File) or errors while reading or writing to FIFOs is crucial. This can be done by checking the return values of `read()` and `write()` functions and handling cases where data might not be available or the pipe is closed.
     - **Buffer Management**: Ensuring that the buffer size of the FIFO is adequate to handle the data being passed between processes. If the buffer is full, the writing process might block until there is space, so this needs to be handled efficiently.

