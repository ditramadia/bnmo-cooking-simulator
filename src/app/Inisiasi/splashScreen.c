#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 128

void print_ascii(FILE *fptr){
  char read_string[MAX_LEN];
  while(fgets(read_string,sizeof(read_string),fptr) != NULL)
    printf("%s",read_string);
}
void Start(){
  char *filename;
  FILE *fptr;
  
  filename = "welcome.txt";
  fptr = fopen(filename,"r");
  system("cls");
  print_ascii(fptr);
  fclose(fptr);
  printf("\n");
  printf("");
}

int main(){
  Start();
}