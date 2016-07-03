#include <stdio.h>
int main() {
    char c;
    int d;
	printf("Enter a character: ");

    // Reads character input from the user
    scanf("%c", &c);  
    d=(int)c;
    // %d displays the integer value of a character
    // %c displays the actual character
    printf("ASCII value of %c = %d\n", c, c);
    printf("%d",d);
    return 0;
}
