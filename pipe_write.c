#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd, read_result;
    char buffer[512];

    mkfifo("test_file", 0666);

    fd = open("test_file", O_WRONLY);

    if(fd < 0){
        perror("Error opening file\n");
        return 0;
    }

    while((read_result = read(STDIN_FILENO, buffer, 512)) > 0) {
        write(fd, buffer, strlen(buffer));
    }

    close(fd);
}
