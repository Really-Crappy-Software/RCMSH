#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include </etc/shell.cfg>
void panic(char reason[]) {
  printf("PANIC: %s", reason);
  return;
}

int main() {
  FILE *fptr;
  FILE *host;
  DIR *folder;
bool shell = true;
  while (shell = true) {
    if (startmsg==true) {
      printf("Welcome to the Really Crappy Microshell\n");
      printf("type help to start\n");
    }
    host = fopen("/etc/hostname", "r");
    char brazillianmiku[250];
    char hostname[15];
    char location[30];
    char input[10];
    char currentdir[100];
    fgets(hostname, 15, host);
    hostname[strcspn(hostname, "\n")] = 0;
    printf("%s:", hostname);
    fgets(input, 10, stdin);
     input[strcspn(input, "\n")] = 0;
    // why wont strcmp work?
    if (strcmp(input, "help") == 0) {
    printf("help: displays this \n print: prints something(only input print)\n create: creates files\n cd: changes the directory\n version: check the version\n ls: displays the files in current location\n exit: stops this\n mkdir: creates a directory\n");
  } 
    else if (strcmp(input, "print") == 0) {
    char print[30];
    printf("What would you like to print?(btw character limit is 30):\n");
      fgets(print, 30, stdin);
      printf("%s\n", print);
  } else if (strcmp(input, "exit") == 0) {
      return 0;
    } else if (strcmp(input, "create") == 0) {
      printf("Please input the location of this file (make sure to include the file name and extension at the end)\n");
      fgets(location, 30, stdin);
      location[strcspn(location, "\n")] = 0;
      fptr = fopen(location, "w");
    } else if (strcmp(input, "version") == 0) {
      printf("Really Crap Micro Shell ver 0.2\n");
    } else if (strcmp(input, "ls") == 0) {
      struct dirent *entry;
      int files = 0;
      char fname[40];
      folder = opendir(currentdir);
      if(folder == NULL) {
        panic("How are you in a directory that does not exist?");
      }

      while( (entry=readdir(folder)) ) {
        files++;
        printf("FILE %3d: %s\n", files, entry->d_name);
      }
      closedir(folder);
    } else if (strcmp(input, "cd") == 0) {
      printf("input the Directory\n");
      fgets(currentdir, 100, stdin);
      currentdir[strcspn(currentdir, "\n")] = 0;
      printf("The current directory is %s\n", currentdir);
    } else if (strcmp(input, "mkdir") == 0) {
          printf("input the location including name at the end:\n");
            fgets(brazillianmiku, 250, stdin);
      brazillianmiku[strcspn(brazillianmiku, "\n")] = 0;
            int ret = mkdir(brazillianmiku, S_IRWXU);
      if (ret == -1) {
        printf("didn't work\n");
      }
    }
    else {
      printf("rcsh: '%s' command not found, maybe use help?\n", input);
      }
  }
}
