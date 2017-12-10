#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

int main() {
    int fd;
    char buffer[512];
    char line[] = "I come from a land down under";

    mkfifo("pipe", 0666);

    fd = open("pipe", O_WRONLY);

    if(fd < 0) {
        perror("Error opening file\n");
        return 0;
    }

    while(1) {
        write(fd, line, strlen(line));
        write(fd, "\n", strlen("\n"));
        sleep(5);
    }

    close(fd);

    return 0;
}
