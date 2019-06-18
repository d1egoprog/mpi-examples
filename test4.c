#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

void procesandoAlgo(int numero);

int main(int argc, char **argv) {
  int proceso; 
  int tamano;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &proceso); 
  MPI_Comm_size(MPI_COMM_WORLD, &tamano);
  procesandoAlgo(proceso);
  printf("Termine de Procesar en el proceso %i\n", proceso);
  MPI_Finalize();
}


void procesandoAlgo(int numero){
	for (int i=0;i<numero;i++)
		printf("Imprimiendo %i de %i\n",i, numero);
	printf("Termine de imprimir, ahora me toca esperar %i segundos\n", numero);
	sleep(numero);
	return;
}