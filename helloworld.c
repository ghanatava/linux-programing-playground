#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void main(){
    int fd;
    if ((fd = open("foo", O_WRONLY | O_CREAT,0644))<0){ //0644 is file permision rw-r-r
        printf("error no %d\n",errno);
        perror("foo");
        exit(1);
    }
    write(fd, "Hello World!", 12);
    close(fd);
}