#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
  FILE *fptr;
bool shell = true;
  while (shell = true) {
    char location[30];
    char input[10];
    fgets(input, 10, stdin);
     input[strcspn(input, "\n")] = 0;
    // why wont strcmp work?
    if (strcmp(input, "help") == 0) {
    printf("help: displays this \n print: prints something(only input print)\n create: creates files\n version: check the version\n exit: stops this\n");
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
      fptr = fopen(location, "w");
    } else if (strcmp(input, "version") == 0) {
      printf("Really Crap SHell ver 0.1\n");
    }

    else {
      printf("rcsh: '%s' command not found, maybe use help?\n");
      }
  }
}
