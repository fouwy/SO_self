#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 64

int main(int argc, char **argv) {
    char buffer[BUFFSIZE];
    int bytesREAD = BUFFSIZE;
    int count = 0;

    int file = open(argv[1], O_RDONLY);

    if(file < 0)    perror("open");

    while(bytesREAD == 64) {
        bytesREAD = read(file, buffer, BUFFSIZE);
        write(STDOUT_FILENO, buffer, bytesREAD);
        count += bytesREAD;
    }
    close(file);
    
    printf("\n");
    printf("Tamanho em bytes:%d\n", count);

    return 0;
}