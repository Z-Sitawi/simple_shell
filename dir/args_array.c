#include <stdio.h>

int main(int argc, char **argv) {
    printf("av: %p\n", (void *)argv);
    printf("*av: %p\n", (void *)*argv);
    printf("**av: %c\n", **argv);

    for (int i = 0; argv[i] != NULL; i++) {
        printf("av[%d]: %s\n", i, argv[i]);
        printf("*av[%d]: %c\n", i, *argv[i]);
    }

    return 0;
}

