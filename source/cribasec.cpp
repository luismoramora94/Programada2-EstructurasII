#include <bits/stdc++.h>
#include <vector>

using namespace std;

int CribaEratostenes(long double n){
	static bool prime[100000000];
	memset(prime, true, sizeof(prime));

	double number_of_primes = 0;

    for (int p=2; p*p<=n; p++){
        if (prime[p] == true){

    		for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

	for(int i = 2; i< n+1; i++){
		if(prime[i] == true){
			// std::cout << i << std::endl;
			number_of_primes ++;
		}
	}
	return number_of_primes;
}

int main(){

	long double n = 3*(10000000/4)*0.9825045;
	clock_t tStart = clock();

    int number_of_primes = CribaEratostenes(n);
	double t1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;

	std::cout << "**************************" << std::endl;
	std::cout << "Probando Criba Secuencial" << std::endl;
	std::cout << "**************************" << std::endl;

	std::cout << "Debajo de " << n << " hay " << number_of_primes << " numeros primos " << std::endl;
	std::cout << "Tiempo de ejecución: " << t1  << " s" << std::endl;

	return 0;
}
