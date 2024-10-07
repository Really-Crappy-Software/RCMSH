#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include </etc/shell.cfg>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

void panic(char reason[]) {
  printf("PANIC: %s", reason);
  return;
}

int main() {
  FILE *fptr;
  FILE *host;
  DIR *folder;
bool shell = true;
    if (startmsg==true) {
      printf("Welcome to the Really Crappy Microshell\n");
      printf("type help to start\n");
    } else {

    }
   while (shell==true) {
    host = fopen("/etc/hostname", "r");
    int errorclp = 0;
    char hostname[15];
    char location[30];
    char brazillianmiku[250];
    char input[2][100];
    char currentdir[100];
    fgets(hostname, 15, host);
    hostname[strcspn(hostname, "\n")] = 0;
    printf("%s:", hostname);
    scanf("%s %s", input[0], &input[1]);
     input[0][strcspn(input[0], "\n")] = 0;
     input[1][strcspn(input[1], "\n")] = 0;
    if (strcmp(input[0], "help") == 0) {
    printf("help: displays this \n print: prints something\n create: creates files\n cd: changes the directory\n version: check the version\n ls: displays the files in current location\n exit: stops this\n mkdir: creates a directory\n exec: executes a file with no argument (must use an absolute path)\n");
  } 
    else if (strcmp(input[0], "print") == 0) {
      printf("%s\n", input[1]);
  } else if (strcmp(input[0], "exit") == 0) {
      return 0;
    } else if (strcmp(input[0], "create") == 0) {
     fptr = fopen(input[1], "w");
    } else if (strcmp(input[0], "version") == 0) {
      printf("Really Crap Micro Shell ver 0.3\n");
    } else if (strcmp(input[0], "ls") == 0) {
      struct dirent *entry;
      int files = 0;
      char fname[40];
      folder = opendir(brazillianmiku);
      if(folder == NULL) {
        panic("How are you in a directory that does not exist?");
      }

      while( (entry=readdir(folder)) ) {
        files++;
        printf("FILE %3d: %s\n", files, entry->d_name);
      }
      closedir(folder);
    } else if (strcmp(input[0], "cd") == 0) {
     strcpy(brazillianmiku, input[1]);
      printf("The current directory is %s\n", brazillianmiku);
    } else if (strcmp(input[0], "mkdir") == 0) {
            int ret = mkdir(input[1], S_IRWXU);
      if (ret == -1) {
        printf("didn't work\n");
      }
    } else if (strcmp(input[0], "exec") == 0) {
      system(input[1]);
    }
    else {
      pid_t winblows = fork();
      if (winblows==0) {
      execlp(input[0], input[1], NULL);
      }
      wait(NULL);
      printf("%s:", hostname);
      printf("rcsh: '%s' command not found, maybe use help?\n", input);
  }
}
}
