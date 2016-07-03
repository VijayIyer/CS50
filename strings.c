#include <stdio.h>
#define MAX 50
int main() {
  char array1[MAX];
  char *array2;
  char b[MAX];
  
  while(1)
  {
  printf("Now enter another string less than 50");
  printf(" characters with spaces: \n");
  gets(array1);

printf("\n%s",array1);

  printf("\nYou entered: ");
  puts(array1);

}
  return 0;
}
