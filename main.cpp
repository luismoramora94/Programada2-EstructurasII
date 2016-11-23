#include <iostream>
#include <time.h>
#include "cribasec.h"


int main()
{
    long double n = 1000000;

	clock_t tStart = clock();

    int number_of_primes = CribaEratostenes(n);

	std::cout << "Debajo de " << n << " hay " << number_of_primes << " numeros primos " << std::endl;
	std::cout << "Tiempo de ejecución: " << (double)(clock() - tStart)/CLOCKS_PER_SEC <<  std::endl;

    return 0;
}
