#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 128

void print_image(FILE *fptr){
  char read_string[MAX_LEN];
  while(fgets(read_string,sizeof(read_string),fptr) != NULL)
    printf("%s",read_string);
}
void splashScreenWelcome(){
  char *filename;
  FILE *fptr;
  
  filename = "welcome.txt";
  fptr = fopen(filename,"r");
  system("cls");
  print_image(fptr);
  fclose(fptr);
  printf("\n");
  printf("");
}

int main(){
  splashScreenWelcome();
}