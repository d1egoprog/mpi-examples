#include <mpi.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int sumasParciales(int numInferior, int numSuperior);

int main(int argc, char **argv) {
	int proceso; 
	int tamano;
	int maestro;
	int totalSuma = 0, totalParcial;
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &proceso); 
	MPI_Comm_size(MPI_COMM_WORLD, &tamano);
	
	int rango = atoi(argv[1]) / (tamano-1);
	if (proceso == 0){
		double inicio=clock();
		for(int i=1;i<tamano;i++){
			MPI_Send ( &rango, 1, MPI_INT, i, 1, MPI_COMM_WORLD );
			MPI_Recv ( &totalParcial, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &estado);
			totalSuma += totalParcial;
		}
		double fin=clock();
		double total=(fin-inicio)/(double) CLOCKS_PER_SEC;
		printf("La suma paralela de %i procesos se demororo %f segundos y dio %i \n", tamano, total, totalSuma);
	}else{
		MPI_Recv(&rango,1, MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&estado);
		int numInferior = rango * (proceso-1);
		int numSuperior = rango * proceso;
		int resultado = sumasParciales(numInferior, numSuperior);
		MPI_Send ( &resultado, 1, MPI_INT, maestro, 1, MPI_COMM_WORLD );
	}
	MPI_Finalize();
}


int sumasParciales(int numInferior, int numSuperior){
	int suma = 0;
	for (int i=(numInferior+1);i<=numSuperior;i++){
		suma += i;
		sleep(1);
	}
	return suma;
}