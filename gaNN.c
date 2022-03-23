#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "const.h"
#include "entity.h"

/*************************
 *  GA CNN v2
 *  
 *  Author: Luigi Di Biasi, 
 *
 *
 * */


int test_openmp() {
	int omp_th;
	omp_th =0;
	#pragma omp parallel num_threads(MAX_THREADS)
	{
		#pragma omp atomic
		omp_th = omp_th +1;
	}	
	return omp_th;	
}



int main() {

	// Initialize nrand with predefined value (for reproducibility)
	srand(8885);

	// Prepare initial population memory space
	NN** POPULATION;	
	POPULATION =  malloc(sizeof(NN)*POPULATION_SIZE);

	printf("Initizializing Population...\n");
	printf("\tPopulation size: %d\n",POPULATION_SIZE);
	
	// Test OpenMP
	int omp_th;
	omp_th = test_openmp();
	if (omp_th<=1) {
		printf("\tOPENMP test failed\n");
		return -1;
	}
	else {
		printf("\tOPENMP test success:%d\n",omp_th);
	}

	// Fill the first Population set
	for (int i=0;i<POPULATION_SIZE;i++) {
		POPULATION[i]=makeEntity(NULL);
	}
	
	// Call all the entities via OPENMP (preliminary test)
	#pragma omp parallel for num_threads(MAX_THREADS)
	for (int i=0;i<POPULATION_SIZE;i++) {
		printf("\tThread %d handled entity %ld\n",omp_get_thread_num(),POPULATION[i]->entity_id);	
	}
	

}

