#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv) {
	int suma = 0;
	int numSuperior = atoi(argv[1]);
	double inicio=clock();
	for (int i=1;i<=numSuperior;i++){
		suma += i;
		sleep(1);
	}
	double fin=clock();
	double total=(fin-inicio)/(double) CLOCKS_PER_SEC;
	printf("La suma se demororo %f segundos y dio %i \n",  total, suma);
	return 0;
}
