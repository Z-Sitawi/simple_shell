#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void cd(const char *path) {
    if (path == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(path) != 0) {
            perror("cd");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: cd <directory>\n");
        return 1;
    }

    cd(argv[1]);

    return 0;
}
