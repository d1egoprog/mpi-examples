#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  printf("Hola Mundo cruel de MPI\n");
  MPI_Finalize();
}