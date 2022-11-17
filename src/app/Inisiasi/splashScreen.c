#include <stdio.h>
#include <stdlib.h>
#include "../../../config/config.h"

#include "../simulator/simulator.c"

// Render splash screen
void display_ascii()
{
  FILE *fptr;
  fptr = fopen(splashScreenConfig, "r");

  system("cls");
  char splash[128];
  while (fgets(splash, sizeof(splash), fptr) != NULL)
  {
    printf("%s", splash);
  }

  fclose(fptr);
}

// Command Parser
void mainMenuCommandParser(char query[])
{
  // Available commands
  char startCommand[] = "START";
  char exitCommand[] = "EXIT";

  int isMenuCommandValid = 0;
  while (!isMenuCommandValid)
  {
    char command[10];
    printf("%s: ", query);
    scanf("%s", &command);

    if (compareString(command, startCommand))
    {
      // Call simulator app
      system("cls");
      fflush(stdin);
      printf("Masukkan nama Anda: ");
      scanf("%s", &simName);
      system("cls");
      loadSimulator();
      isMenuCommandValid = 1;
    }
    else if (compareString(command, exitCommand))
    {
      // Call exit app
      exit(0);
    }
    else
    {
      printf("Perintah tidak tersedia.\n");
    }
  }
}

// Main App
int mainMenu()
{
  // Render splash screen
  display_ascii();

  printf("\n");
  printf("\n");

  // User input
  printf("Selamat datang di Dinner Dash. Ketik 'START' untuk memulai atau 'EXIT' untuk keluar.\n");
  mainMenuCommandParser("Ketik (START/EXIT)");
}