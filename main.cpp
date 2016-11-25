#include <iostream>
#include <time.h>

#include "cribasec.h"
#include "cribapar.h"
#include "mpi.h"


int main( int argc, char* argv[])
{
	/* Parametros MPI */

	int         my_rank;       /* rank of process      */
    int         p;             /* number of processes  */
    int         source;        /* rank of sender       */
    int         dest;          /* rank of receiver     */
    int         tag = 0;       /* tag for messages     */
    char        message[100];  /* storage for message  */
    MPI_Status  status;        /* return status for  receive  */

    MPI_Init(&argc, &argv);

    long double n = 3*(10000000/4)*0.9825045;

	clock_t tStart = clock();

    int number_of_primes = CribaEratostenes(n);
	double t1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;

	std::cout << "**************************" << std::endl;
	std::cout << "Probando Criba Secuencial" << std::endl;
	std::cout << "**************************" << std::endl;

	std::cout << "Debajo de " << n << " hay " << number_of_primes << " numeros primos " << std::endl;
	std::cout << "Tiempo de ejecución: " << t1  << " s" << std::endl;

	std::cout << "**************************" << std::endl;
	std::cout << "Probando Criba MPI" << std::endl;
	std::cout << "**************************" << std::endl;

	clock_t tStart2 = clock();

	int number_of_primes_par = CribaEratostenesPar(n);

	double t2 = (double)(clock() - tStart2)/CLOCKS_PER_SEC;

	std::cout << "Debajo de " << n << " hay " << number_of_primes_par << " numeros primos " << std::endl;
	std::cout << "Tiempo de ejecución: " << t2 << " s" << std::endl;

	std::cout << "**************************" << std::endl;
	double pd = (t1 - t2)/t2 * 100 ;
	double veces = t1/t2;
	std::cout << "Porcentaje de diferencia: " << pd << std::endl;
	std::cout << "El proceso en paralelo es " << veces << " más rápido que el secuencial" << std::endl;
	std::cout << "**************************" << std::endl;

	MPI_Finalize();
	return 0;
}
