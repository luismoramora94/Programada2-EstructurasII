#include <bits/stdc++.h>
#include <vector>

using namespace std;

int CribaEratostenes(long double n)
{

	bool prime[int(n) + 1];
	memset(prime, true, sizeof(prime)); 

	double number_of_primes = 0;


    for (int p=2; p*p<=n; p++){
        if (prime[p] == true){

    		for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

	for(int i = 2; i< n+1; i++){
		if(prime[i] == true)
			number_of_primes ++;
	}
	return number_of_primes;
}
