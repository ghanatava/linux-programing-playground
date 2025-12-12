#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 16384

void main(){
    int fin,fout;
    char buf[BUFSIZE];
    int count;

    if ((fin=open("foo", O_RDONLY)) < 0){
        perror("foo");
        exit(1);
    }
    if ((fout=open("bar", O_WRONLY | O_CREAT,0644)) < 0){
        perror("bar");
        exit(2);
    }
    while ((count=read(fin,buf,BUFSIZE)) > 0)
        write(fout,buf,count);
    close(fin);
    close(fout);
}