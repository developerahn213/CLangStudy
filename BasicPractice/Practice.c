#include <stdio.h>

int main(){
    printf("Hello World\n");
    int a = 21; // 0001 0101(binary)
    a = a | (1<<3);
    int b = (1<<2); // print 4(decimal), 100(binary)
    int c = b<<1; // It means multiple 2
    c <<= 1;
    printf("The value of a is %d\n", a);
    printf("The value of b is %d\n", b);
    printf("The value of c is %d\n", c);

    return 0;
}