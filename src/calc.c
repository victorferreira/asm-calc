#include <stdio.h>
#include <stdlib.h>

int newLine = 0;

void checkCharcter(char character) {
  if (character == '\n')
    newLine++;
  putchar(character);
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
    checkCharcter(c);
  }

  printf("%d New lines\n", newLine);

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
