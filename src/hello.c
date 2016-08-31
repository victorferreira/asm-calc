#include <stdio.h>

void hello() {
  printf("hello world\n");
}

int main(int argc, char const *argv[]) {
  hello();
  printf("Char %c\n", *argv[1]);
  return 0;
}
