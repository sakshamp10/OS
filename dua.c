#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libgen.h>
void cd(char **args) {
    int ct = 0;
    for (int i = 1; args[i] != NULL; i++) {
        ct++;
    }
    if (ct > 1) {
        printf("too many arguments\n");
        return;
    } else {
        if (ct == 1) {
            if (strcmp(args[1], "/") == 0) {
                chdir("/");
            } else if (strcmp(args[1], "~") == 0 || strcmp(args[1], "root") == 0) {
                chdir("~");
            } else {
                char *path;
                path = (char *) malloc(256 * sizeof(char));
                int f = 0;
                for (int i = 0; parentcwd[i] != '\0'; i++) {
                    path[f++] = parentcwd[i];
                }
                path[f++] = '/';
                for (int i = 0; args[1][i] != '\0'; i++) {
                    path[f++] = args[1][i];
                }
                int suc = chdir(path);
                if (suc == -1) {
                    printf("No such file or directory");
                }
            }
        } else if (ct == 0) {
            chdir("~");
        }
    }
}