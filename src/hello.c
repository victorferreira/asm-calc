#include <stdio.h>

void hello() {
  printf("hello world\n");
}

int main(int argc, char const *argv[]) {
  hello();
  // printf("Char %c\n", *argv[1]);

  int c;
  FILE *file;
  file = fopen("src/file.txt", "r");
  while ((c = getc(file)) != EOF){
    printf("%c",c);
  }
  fclose(file);

  return 0;
}
