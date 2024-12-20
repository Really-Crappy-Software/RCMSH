#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
int test;
int main() {
  FILE *fptr;
  FILE *host;
  DIR *folder;
bool shell = true;
   while (shell==true) {
    host = fopen("/etc/hostname", "r");
    char hostname[15];
    char location[30];
    char input[100];
    char array[100];
    char input2[100];
    char currentdir[100];
    fgets(hostname, 15, host);
    hostname[strcspn(hostname, "\n")] = 0;
    printf("%s:", hostname);
    fgets(input, 100, stdin);
    	int sargn = strcspn(input, " ");
    			strcpy(input2, input);
    			input[sargn] = 0;
    			int msargn = sargn + 1;
    			memmove(input2, input2 + msargn, 100 - sargn);
    			input[strcspn(input, "\n")] = 0;
    			input2[strcspn(input2, "\n")] = 0;
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
      folder = opendir(".");
      if(folder == NULL) {
        printf("How are you in a directory that does not exist?");
      }

      while( (entry=readdir(folder)) ) {
        files++;
        printf("FILE %3d: %s\n", files, entry->d_name);
      }
      closedir(folder);
    } else if (strcmp(input, "cd") == 0) {
     chdir(input2);
    } else if (strcmp(input, "mkdir") == 0) {
            int ret = mkdir(input2, S_IRWXU);
      if (ret == -1) {
        printf("didn't work\n");
      }
    } else if (strcmp(input, "exec") == 0) {
        system(input2);
      }
      else {
    	  strcat(array, input);
    	  strcat(array, " ");
    	  strcat(array, input2);
    	  pid_t winblows = fork();
        if (winblows==0) {
        test = system(array);
        return 0;
        }
        strcpy(array, "");
        wait(NULL);
        printf("%s\n", array);
        if (test < 0) {
        printf("rcsh: '%s' command not found, maybe use help?\n", input);
        }
    }
  }
}
