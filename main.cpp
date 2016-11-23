#include <iostream>
#include "cribasec.h"

int main()
{
    int n = 30;
    std::cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << std::endl;
    CribaEratostenes(n);
    return 0;
}
