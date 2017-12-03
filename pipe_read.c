#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd, read_result;
    char buffer[512];

    fd = open("test_file", O_RDONLY);

    if(fd < 0){
        perror("Error opening file\n");
        return 0;
    }

    while((read_result = read(fd, buffer, 512)) > 0) {
        write(STDOUT_FILENO, buffer, read_result);
    }

    close(fd);
}
