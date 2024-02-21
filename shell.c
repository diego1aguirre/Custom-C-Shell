#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_ARGS 10
#define MAX_LENGTH 1000

// Function prototypes
void chgDir(char* path, char* currDir);
void showpid(int idList[]);

// Main function
int main() {
    char str[MAX_LENGTH], *tokenArr, *command, *argumentList[MAX_ARGS + 1];
    char currDir[MAX_LENGTH];
    int idList[5] = {0}; // Assuming you want to store 5 PIDs
    int i, pid, status, execStatus, a = 0;

    // Initialize the current directory
    if (getcwd(currDir, sizeof(currDir)) == NULL) {
        perror("getcwd() error");
        return 1;
    }

    while (1) {
        printf("\033[0;31m%s$ ", currDir); // Print the prompt in red
        printf("\033[0m"); // Reset color

        // Get user input using fgets
        if (fgets(str, sizeof(str), stdin) == NULL) {
            // Handle error or end of file
            break;
        }

        // Exit condition
        if (strncmp(str, "exit", 4) == 0) {
            printf("EXITING! \n");
            break;
        }

        // Tokenize the input
        tokenArr = strtok(str, " \n");
        i = 0;
        while (tokenArr != NULL) {
            argumentList[i] = strdup(tokenArr);
            tokenArr = strtok(NULL, " \n");
            i++;
            if (i >= MAX_ARGS) break; // Prevent buffer overflow
        }
        argumentList[i] = NULL; // NULL-terminate the argument list
        command = argumentList[0]; // The first token is the command

        // Check for built-in commands
        if (command == NULL) {
            // No command entered
            continue;
        } else if (strcmp(command, "cd") == 0) {
            chgDir(argumentList[1], currDir);
        } else if (strcmp(command, "showpid") == 0) {
            showpid(idList);
        } else {
            // External command
            pid = fork();
            if (pid == 0) {
                // Child process
                execStatus = execvp(command, argumentList);
                if (execStatus == -1) {
                    printf("Error: Command could not be executed\n");
                    exit(1);
                }
            } else if (pid > 0) {
                // Parent process
                waitpid(pid, &status, 0);
                if (a < 5) {
                    idList[a++] = pid; // Store PID and increment 'a'
                } else {
                    a = 0; // Reset 'a' if it exceeds the list size
                }
            } else {
                // Fork failed
                perror("fork");
            }
        }

        // Free the duplicated strings
        for (int j = 0; j < i; j++) {
            free(argumentList[j]);
        }
    }
    return 0;
}

// Function definitions
void chgDir(char* path, char* currDir) {
    if (chdir(path) == -1) {
        printf("Error: cannot change directory\n");
        return;
    }
    if (getcwd(currDir, MAX_LENGTH) == NULL) {
        perror("getcwd() error");
    }
    setenv("PWD", currDir, 1);
}

void showpid(int idList[]) {
    for (int i = 0; i < 5; i++) {
        printf("%d\n", idList[i]);
    }
}
