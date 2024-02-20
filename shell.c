#include <stdio.h> // Include the standard I/O header file


void chgDir(char* path, char* currDir){
   if(chdir(path) == -1){
      printf("Error: cannot change    directory\n");
     return;
   }
  if( (getcwd(currDir,1000)) == NULL){
     perror("getcwd() error");
  }
  setenv("pwd", currDir, 1);
}

void showpid(int idList[]){
  int i = 0;
  for(i=0; i<5; i++) {
   printf("%d\n", idList[i]);
  }
 return;
}

int main() { 

    if ( (getcwd(currDir, 1000)) == NULL){
    }

    while (1)
    {
        //Get user input using fgets

        printf("\033[0;31m%s$ ", currDir);
        printf ("\033 [0m"); // Reset from red

        if (fgets(str, 1000, stdin) != NULL){
        //Do coding as needed
        }

        if (strncmp(str, "exit", 4) == 0 )
        {
            printf("EXITING! \n");
            break;
        }
        //Do something with input
    }

    char* tokenArr; // token array
    char* argumentList[10];
    for(i=0; i<10; i++) // Malloc a char* pointer with length 81 and initialize it to null
    argumentList[i] = (char*)malloc(sizeof(char)*81) ;
    argumentList[i] = NULL;

    while(1) {
    //Get user input using fgets
    if ( fgets(str, 1000, stdin) != NULL){
    //Do coding as needed
    }
    //Using strtok to create tokens and count eac token as one word
    tokenArr = strtok(str, " ");
    i = 0;
    while(tokenArr != NULL)
    {
    if(i == 0)
        command = strdup (tokenArr);
    }
    argumentList [i] = strdup(tokenArr);
    tokenArr = strtok(NULL, " ");
    i++;
    }
    
    while(1) {
    // Get user input using fgets
    if(fgets(str, 1000, stdin) != NULL) {
        // Do coding as needed
    }

    // Using strtok to create tokens and count each token as one word
    tokenArr = strtok(str, " ");
    i = 0;
    while(tokenArr != NULL) {
        if(i == 0) {
            command = strdup(tokenArr);
        }
        argumentList[i] = strdup(tokenArr);
        tokenArr = strtok(NULL, " ");
        i++;
    }

    if ((pid = fork()) == 0) {
        execStatus = execvp(command, argumentList);

        if(execStatus == -1) {
            printf("Error: Command could not be executed\n");
            exit(1);
        }
        kill(pid, SIGTERM);
    } else {
        // Parent process (your shell program itself)
        waitpid(pid, &status, 0);
    }
}

while(1) {
    // Get user input using fgets
    if (fgets(str, 1000, stdin) != NULL) {
        // Do coding as needed
    }

    // Using strtok to create tokens and count each token as one word
    tokenArr = strtok(str, " ");
    i = 0;
    while (tokenArr != NULL) {
        if (i == 0) {
            command = strdup(tokenArr);
        }
        argumentList[i] = strdup(tokenArr);
        tokenArr = strtok(NULL, " ");
        i++;
    }
    
    // Handle the 'cd' and 'showpid' built-in commands
    if (strcmp(command, "cd") == 0) {
        chgDir(argumentList[1], currDir);
    } else if (strcmp(command, "showpid") == 0) {
        showpid(idList);
    } else {
        // Child process code goes here
        if ((pid = fork()) == 0) {
            // Child process
        } else {
            // Parent process code goes here
            if (a == 5) {
                a = 0;
            }
            idList[a] = pid;
            a++;
            waitpid(pid, status, 0);
        }
    }
}






        return 0;}
