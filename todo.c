#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of tasks and the maximum length of each task
#define MAX_TASKS 100
#define TASK_LENGTH 256

// Function prototypes for adding, viewing, and deleting tasks
void add_task();
void view_tasks();
void delete_task();

// Global variables to store tasks and the current count of tasks
char tasks[MAX_TASKS][TASK_LENGTH];
int task_count = 0;

int main() {
    int choice;

    // Infinite loop to continuously show the menu until the user exits
    while (1) {
        // Displaying the menu options to the user
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Getting user's choice

        // Switch case to handle user's choice
        switch (choice) {
            case 1:
                add_task(); // Call function to add a task
                break;
            case 2:
                view_tasks(); // Call function to view all tasks
                break;
            case 3:
                delete_task(); // Call function to delete a task
                break;
            case 4:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    }

    return 0;
}

// Function to add a task to the list
void add_task() {
    if (task_count < MAX_TASKS) { // Check if the task list is not full
        printf("Enter the task: ");
        getchar(); // Consume the newline character left by the previous scanf
        fgets(tasks[task_count], TASK_LENGTH, stdin); // Get the task from the user
        tasks[task_count][strcspn(tasks[task_count], "\n")] = '\0'; // Remove the newline character
        task_count++; // Increment the task count
        printf("Task added successfully.\n");
    } else {
        printf("Task list is full.\n"); // Inform the user if the task list is full
    }
}

// Function to view all tasks in the list
void view_tasks() {
    if (task_count == 0) { // Check if there are any tasks to display
        printf("No tasks available.\n");
    } else {
        printf("\nYour Tasks:\n");
        for (int i = 0; i < task_count; i++) { // Loop through and display each task
            printf("%d. %s\n", i + 1, tasks[i]); // Display task number and task description
        }
    }
}

// Function to delete a specific task from the list
void delete_task() {
    int task_number;
    if (task_count == 0) { // Check if there are any tasks to delete
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter the task number to delete: ");
    scanf("%d", &task_number); // Get the task number to delete from the user

    // Check if the entered task number is valid
    if (task_number > 0 && task_number <= task_count) {
        // Shift tasks up to fill the gap left by the deleted task
        for (int i = task_number - 1; i < task_count - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        task_count--; // Decrease the task count
        printf("Task deleted successfully.\n");
    } else {
        printf("Invalid task number.\n"); // Inform the user if the task number is invalid
    }
}
