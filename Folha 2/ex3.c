#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 64

typedef char name[30]; 
typedef struct { 
	name st;
	int grades[3];
} test_t;

int main(int argc, char **argv) {
    
    int bytesREAD = BUFFSIZE;
    test_t teste;
    char notas[50];

    int fid = open(argv[1], O_RDWR|O_CREAT|O_APPEND);

    if(fid < 0)    perror("open");

    bytesREAD = read(STDOUT_FILENO, teste.st, sizeof(teste.st));
    write(fid, teste.st, bytesREAD);

    bytesREAD = read(STDOUT_FILENO, teste.st, sizeof(teste.grades));
    sprintf(notas, "%d", teste.grades[0]);
    write(fid, notas, bytesREAD);

    
    bytesREAD = read(STDOUT_FILENO, teste.st, sizeof(teste.grades));
    sprintf(notas, "%d", teste.grades[1]);
    write(fid, notas, bytesREAD);
    
    bytesREAD = read(STDOUT_FILENO, teste.st, sizeof(teste.grades));
    sprintf(notas, "%d", teste.grades[2]);
    write(fid, notas, bytesREAD);

    close(fid);
    
    return 0;
}
