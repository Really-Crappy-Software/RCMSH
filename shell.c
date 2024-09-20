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
    if (startmsg==true) {
      printf("Welcome to the Really Crappy Microshell\n");
      printf("type help to start\n");
    } else {

    }
   while (shell==true) {
    host = fopen("/etc/hostname", "r");
    char hostname[15];
    char location[30];
    char brazillianmiku[250];
    char input[10];
    char input2[100] = "EOF";
    char currentdir[100];
    fgets(hostname, 15, host);
    hostname[strcspn(hostname, "\n")] = 0;
    printf("%s:", hostname);
    scanf("%s %s", input, input2);
    // Somehow this fucked up one worded commands (well I kinda know)
     input[strcspn(input, "\n")] = 0;
     input2[strcspn(input2, "\n")] = 0;
    // why wont strcmp work?
    if (strcmp(input, "help") == 0) {
    printf("help: displays this \n print: prints something\n create: creates files\n cd: changes the directory\n version: check the version\n ls: displays the files in current location\n exit: stops this\n mkdir: creates a directory\n");
  } 
    else if (strcmp(input, "print") == 0) {
      printf("%s\n", input2);
  } else if (strcmp(input, "exit") == 0) {
      return 0;
    } else if (strcmp(input, "create") == 0) {
     fptr = fopen(input2, "w");
    } else if (strcmp(input, "version") == 0) {
      printf("Really Crap Micro Shell ver 0.2\n");
    } else if (strcmp(input, "ls") == 0) {
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
    } else if (strcmp(input, "cd") == 0) {
     strcpy(brazillianmiku, input2);
      printf("The current directory is %s\n", brazillianmiku);
    } else if (strcmp(input, "mkdir") == 0) {
            int ret = mkdir(input2, S_IRWXU);
      if (ret == -1) {
        printf("didn't work\n");
      }
    }
    else {
      printf("rcsh: '%s' command not found, maybe use help?\n", input);
      }
  }
}
