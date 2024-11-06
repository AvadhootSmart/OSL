Here are five viva questions and answers for an assignment on a C program involving `fork()`, sorting, and demonstrating zombie and orphan states:

### 1. **What is the purpose of the `fork()` system call in this program, and how does it work?**
   - **Answer:** The `fork()` system call is used to create a new process, known as the child process. When `fork()` is called, it creates an exact duplicate of the calling process (the parent), except for the process ID (PID). The `fork()` function returns a value of `0` to the child process and the child's PID to the parent process. This allows the program to differentiate between the parent and child and perform different tasks in each.

### 2. **How does the `wait()` system call function in this program, and why is it necessary?**
   - **Answer:** The `wait()` system call is used by the parent process to pause its execution until the child process has finished executing. This synchronization is necessary to ensure that the parent does not proceed with further operations that depend on the child’s execution. In this program, `wait()` is used after the parent sorts the integers, allowing it to wait until the child has also completed sorting.

### 3. **Explain how you would implement sorting in both the parent and child processes.**
   - **Answer:** In the parent process, after `fork()`, we can use any sorting algorithm, like bubble sort or quicksort, to sort the list of integers provided by the user. In the child process, after confirming that it is the child using `if (pid == 0)`, we can use another sorting algorithm, such as selection sort or insertion sort. This separation ensures each process sorts independently:
     ```c
     if (pid > 0) { /* Parent process */
         // Perform sorting algorithm, e.g., bubble sort
         wait(NULL); // Wait for child
     } else if (pid == 0) { /* Child process */
         // Perform another sorting algorithm, e.g., selection sort
     }
     ```

### 4. **What is a zombie process, and how can it be demonstrated in this program?**
   - **Answer:** A zombie process is a child process that has completed execution but still has an entry in the process table because the parent has not yet called `wait()` to retrieve its exit status. This can be demonstrated by having the child process exit before the parent calls `wait()`, leaving the child’s process entry as a "zombie" until `wait()` is called. To observe this, you can insert a sleep delay in the parent after the child exits:
     ```c
     if (pid > 0) { /* Parent process */
         sleep(10); // Delay to keep child in zombie state
         wait(NULL);
     }
     ```

### 5. **What is an orphan process, and how would it occur in this program?**
   - **Answer:** An orphan process is a child process that continues to execute after its parent has terminated. In this program, this can happen if the parent process terminates without calling `wait()` while the child is still executing. When the parent process terminates, the child process is adopted by the `init` process (PID 1), allowing it to complete execution. This can be demonstrated by terminating the parent immediately after `fork()`:
     ```c
     if (pid > 0) { /* Parent process */
         exit(0); // Exit without waiting
     } else if (pid == 0) { /* Child process */
         sleep(10); // Delay to show orphan state
     }
     ```
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


Here are five viva questions with answers for an assignment on a C program that involves `fork()`, `execve()`, sorting, and passing arrays through command line arguments:

### 1. **How does the `fork()` system call function in this program, and what is its role?**
   - **Answer:** The `fork()` system call is used to create a new process, called the child process, from the main (parent) process. In this program, `fork()` allows the parent to create a child process that will execute a separate program using `execve()`. After `fork()`, the parent sorts the array and then passes the sorted array to the child. The child process receives the sorted array and, using `execve()`, loads a new program to display the array in reverse order.

### 2. **What is the purpose of `execve()` in this program, and how is it used?**
   - **Answer:** The `execve()` system call replaces the current process image with a new program. In this program, `execve()` is used by the child process to load a new program that takes the sorted array (passed as command-line arguments) and displays it in reverse order. `execve()` requires the program name, an array of arguments (which will be the sorted array), and an environment pointer. Here’s a basic usage example:
     ```c
     char *args[] = {"./display_reverse", "1", "2", "3", NULL}; // Example array
     execve("./display_reverse", args, NULL);
     ```

### 3. **How would you pass a sorted array from the parent process to the child process using `execve()`?**
   - **Answer:** After sorting the array in the parent process, each element of the array can be converted to a string and stored as a command-line argument in an array of strings (char pointers). This array of strings is then passed as arguments to `execve()`. For example:
     ```c
     char *args[ARRAY_SIZE + 2]; // +2 for program name and NULL terminator
     args[0] = "./display_reverse";
     for (int i = 0; i < ARRAY_SIZE; i++) {
         snprintf(buffer, sizeof(buffer), "%d", sorted_array[i]);
         args[i + 1] = strdup(buffer); // Convert integer to string
     }
     args[ARRAY_SIZE + 1] = NULL; // Null-terminate the arguments
     execve("./display_reverse", args, NULL);
     ```

### 4. **What would happen if `execve()` fails in the child process, and how would you handle it?**
   - **Answer:** If `execve()` fails, it usually returns `-1` and sets `errno` to indicate the error. Common reasons for failure include incorrect file paths or insufficient permissions. To handle this, the child process should check the return value of `execve()`, and if it fails, print an error message and exit. Example:
     ```c
     if (execve("./display_reverse", args, NULL) == -1) {
         perror("execve failed");
         exit(1);
     }
     ```

### 5. **How does the child process display the array in reverse order, and why does it need a separate program?**
   - **Answer:** The child process, after receiving the sorted array as command-line arguments, can use a loop to print the elements in reverse order by iterating backward through the arguments. The need for a separate program loaded by `execve()` demonstrates the capability to run a new executable with passed arguments. The reverse order display code would look like this:
     ```c
     int main(int argc, char *argv[]) {
         for (int i = argc - 1; i > 0; i--) { // Start from argc-1 to 1 to reverse print
             printf("%s ", argv[i]);
         }
         printf("\n");
         return 0;
     }
     ```
     This program reads the arguments, interprets them as elements of the array, and displays them in reverse order.

