#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int proceso; 
  int tamano;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &proceso); 
  MPI_Comm_size(MPI_COMM_WORLD, &tamano);
  printf("Hola Mundo, me ejecuto en el procesador %d de un total de %d\n", proceso, tamano);
  MPI_Finalize();
}