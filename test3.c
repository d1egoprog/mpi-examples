#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int proceso; 
  int tamano;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &proceso); 
  MPI_Comm_size(MPI_COMM_WORLD, &tamano);
  printf("Hola Mundo, me ejecuto en el procesador %d de un total de %d\n", proceso, tamano);
  if (proceso == 0)
	printf("Se acabo\n");
  MPI_Finalize();
}


void procesandoAlgo(int numero){
	for (int i=0;i<numero;i++)
		printf("Imprimiendo %i de %i\n",i, numero);
	printf("Termine de imprimir, ahora me toca esperar %i segundos\n", numero);
	sleep(numero*1000);
	return;
}