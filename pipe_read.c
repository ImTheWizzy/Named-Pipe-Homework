#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

int main() {
    int fd, read_result = 1;
    char buffer[512];

    fd = open("pipe", O_RDONLY);

    if(fd < 0) {
        perror("Error opening file\n");
        return 0;
    }

    while(1) {
        read(fd, buffer, 512);
        
        if(read_result < 0) {
            perror("Error reading\n");
            return 0;
        }

        write(STDOUT_FILENO, buffer, strlen(buffer));
    }

    close(fd);

    return 0;
}
