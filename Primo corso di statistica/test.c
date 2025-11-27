#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 7;
    int result = add(x, y);

    printf("Hello, VSCode!\n");
    printf("%d + %d = %d\n", x, y, result);

    // Ciclo per test del debug
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    return 0;
}
