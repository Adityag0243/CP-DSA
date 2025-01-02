#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>  // For sleep() function to simulate time in critical section

#define n 5  // Number of processes (for example, 5 processes)

// Shared variables for mutual exclusion
bool waiting[n];  // Array to track if process i is waiting
bool key = false;  // Key flag for mutual exclusion
bool lock = false;  // Lock flag to indicate critical section status

// Simulate the test_and_set operation (atomic)
bool test_and_set(bool *lock_var) {
    bool old_value = *lock_var;
    *lock_var = true;
    return old_value;
}

// Simulate the critical section code
void critical_section(int i) {
    printf("Process %d is in the critical section.\n", i);
    sleep(1);  // Simulate time spent in the critical section
}

// Entry section: Process i tries to acquire the lock and enter the critical section
void entry_section(int i) {
    int j = (i + 1) % n;  // The next process (circular array)

    waiting[i] = true;  // Indicate that process i wants to enter the critical section
    key = true;          // Indicate that process i is attempting to enter

    // Busy-wait until the process can acquire the lock
    while (waiting[i] && key) {
        key = test_and_set(&lock);  // Atomically acquire the lock
    }
}

// Exit section: Process i leaves the critical section and updates the waiting array
void exit_section(int i) {
    waiting[i] = false;  // Process i is done, so it is no longer waiting

    int j = (i + 1) % n;  // The next process (circular array)

    // Check if any other process is waiting; if not, release the lock
    while (j != i && !waiting[j]) {
        j = (j + 1) % n;  // Move to the next process in the array
    }

    if (i == j) {
        lock = false;  // If process i is the only one left waiting, release the lock
    } else {
        waiting[i] = false;  // Otherwise, set waiting[i] to false and move on
    }
}

int main() {
    // Initialize waiting array to false (no process is initially waiting)
    for (int i = 0; i < n; i++) {
        waiting[i] = false;
    }

    // Simulate processes
    for (int i = 0; i < n; i++) {
        if (fork() == 0) {
            // In child process (simulating process i)
            for (int j = 0; j < 5; j++) {  // Each process attempts to enter 5 times
                entry_section(i);   // Enter section
                critical_section(i);  // Critical section code
                exit_section(i);    // Exit section
            }
            return 0;
        }
    }

    // Parent process waits for child processes to complete
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}