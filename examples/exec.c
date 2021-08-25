#include <unistd.h>
#include <stdio.h>

int main() {

    char *argv[] = { "/bin/ls", "-l", 0, 0 };
    execve("/bin/ls", argv, 0);
	printf("Esto es una prueba para ver si el programa continua");
	return(0);
	}


