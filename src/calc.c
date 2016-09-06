#include <stdio.h>
#include <stdlib.h>

int newLine = 0;
int attribution = 0;
int addition = 0;
int subtraction = 0;
int multiplication = 0;
int division = 0;
int exponentiation = 0;

void printTokens() {
  printf("%d new lines\n", newLine);
  printf("%d attribution tokens\n", attribution);
  printf("%d addition tokens\n", addition);
  printf("%d subtraction tokens\n", subtraction);
  printf("%d multiplication tokens\n", multiplication);
  printf("%d division tokens\n", division);
  printf("%d exponentiation tokens\n", exponentiation);
}

void checkCharacter(char character) {
  switch (character) {
    case '\n':
      newLine++;
      break;
    case '=':
      attribution++;
      break;
    case '+':
      addition++;
      break;
    case '-':
      subtraction++;
      break;
    case '*':
      multiplication++;
      break;
    case '/':
      division++;
      break;
    case '^':
      exponentiation++;
      break;
  }
}

int readFile(FILE* fp) {

  fp = fopen("src/file.txt", "r");
  if(!fp) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  int c; // note: int, not char, required to handle EOF
  while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
    // putchar(c);
    checkCharacter(c);
  }

  // printf("%d New lines\n", newLine);
  printTokens();

  if (ferror(fp))
  puts("I/O error when reading");
  else if (feof(fp))
  puts("End of file reached successfully");

  fclose(&fp);
  return 0;
}

int main(int argc, char const *argv[]) {
  FILE *fp;
  if(!readFile(&fp)) {
    return 1;
  }
  printf("%d New lines\n", newLine);

  return 0;
}
