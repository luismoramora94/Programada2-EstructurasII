#include "cribapar.h"
#include "mpi.h"
#include <iostream>
#include <time.h>

using namespace std;

int CribaEratostenesPar(long double n, int argc, char* argv[] ){

	/* Parametros MPI */

	int rank, size;

	int         p;             /* number of processes  */
	int         source = 0;        /* rank of sender       */
	int         dest = 0;          /* rank of receiver     */
	int         tag = 0;       /* tag for messages     */
	// int 		bool_size = int(n);
	static bool prime[100000000];
	static bool prime1[100000000];
	static bool prime5[100000000];
	static bool prime7[100000000];
	static bool prime11[100000000];


	MPI_Status  status;        /* return status for  receive  */

	prime[0] = 0;
	prime[1] = 0;
	prime[2] = 1;

	for(int i = 2; i< n; i++){
		if(i%12 == 0 || i%12 == 2 || i%12 == 3 || i%12 == 4 || i%12 == 6 || i%12 == 8 || i%12 == 9 || i%12 == 10 ){
		prime[i] = 0;
		prime1[i] = 0;
		prime5[i] = 0;
		prime7[i] = 0;
		prime11[i] = 0;
	}
		else{
			prime[i] = 1;
			prime1[i] = 1;
			prime5[i] = 1;
			prime7[i] = 1;
			prime11[i] = 1;
		}


	}

	/* Start up MPI */
	MPI_Init(&argc, &argv);
	 /* Find out process rank  */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	/* Find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &size);
    /* Find out how many processes are being used */
    MPI_Comm_size(MPI_COMM_WORLD, &p);

	int countg  = 0;

	if (rank == 0){ // Asignar al primer proceso los primos congruentes a 1 en modulo 12
				for (int p=2; p*p<=n; p++){
			        if ((prime1[p] == true && p%12 == 1)|| p%5 == 0 || p%7 == 0){
			    		for (int i=p*2; i<=n; i += p)
			                prime1[i] = false;
			        }
					else prime1[p] = false;
			    }
	}
		else if(rank == 1){ // Asignar al segundo proceso los primos congruentes a 5 en modulo 12
						for (int p=2; p*p<=n; p++){
					        if ((prime1[p] == true && p%12 == 5)|| p%5 == 0 || p%7 == 0){
					    		for (int i=p*2; i<=n; i += p)
					                prime5[i] = false;
					        }
					 		else prime5[p] = false;
					    }

		} else if(rank == 2){ // Asignar al tercer proceso los primos congruentes a 7 en modulo 12
						for (int p=2; p*p<=n; p++){
							if ((prime1[p] == true && p%12 == 7)|| p%5 == 0 || p%7 == 0){
								for (int i=p*2; i<=n; i += p)
									prime7[i] = false;
								}
							 else prime7[p] = false;
							}
					} else if(rank == 3){ // Asignar al cuarto proceso los primos congruentes a 11 en modulo 12

									for (int p=2; p*p<=n; p++){
										if ((prime1[p] == true && p%12 == 11)|| p%5 == 0 || p%7 == 0){
											for (int i=p*2; i<=n; i += p)
												prime11[i] = false;
											}
										else prime11[p] = false;
										}
								}
	 for(int i = 0; i< n; i++){ // Contar el numero de primos en todos los arreglos
	 	if(prime1[i] || prime5[i] || prime7[i] || prime11[i]) countg++;
	 }

  return countg;
}

int main( int argc, char* argv[])
{

	long double n = 3*(100000/4)*3.9485*5.066;


	clock_t tStart2 = clock();

	int number_of_primes_par = CribaEratostenesPar(n, argc, argv);

	double t2 = (double)(clock() - tStart2)/CLOCKS_PER_SEC;


	std::cout << "Numero de primos calculados: " << number_of_primes_par << std::endl;


	// std::cout << "Debajo de " << n << " hay " << number_of_primes_par << " numeros primos " << std::endl;
	std::cout << "Tiempo de ejecución: " << t2 << " s" << std::endl;

	return 0;

}
