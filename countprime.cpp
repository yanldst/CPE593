
#include <iostream>
#include <vector>
#include <cmath>


//First, use Eratosthenes' sieve to find all prime from 2 to sqrt(N).
std::vector<int64_t> populateMyPrimes(int64_t N)
{
    int64_t cnt = std::sqrt(N);
    std::vector<bool> isPrime(cnt + 1, true);

    for (int64_t p = 2; p <= floor(sqrt((double)cnt)); p++)
    {
        if (isPrime[p])
        {
            int64_t m = 1;
            for (int64_t i = p * p; i <= cnt; i = pow((double)p, 2) + m*p, m++)
            {
                isPrime[i] = false;
            }
            //set composite p^2, p^2+p, p^2+2p... as false
        }
    }

    std::vector<int64_t> MyPrimes; //store prime numbers in MyPrimes vector
    for (int64_t i = 2; i <= cnt; i++)
    {
        if (isPrime[i])
            MyPrimes.push_back(i);
    }

    return MyPrimes;
}

int main()
{
    int64_t M;
    int64_t N;
    std::cout << "the left value M: " << std::endl;
    std::cin >> M;
    std::cout << "the right value N: " << std::endl;
    std::cin >> N;

    if (N > M && M > 0)
    {
        std::vector<bool> isPrime(N - M + 1, true);
        std::vector<int64_t> prime = populateMyPrimes(N);
        int64_t q=0; //q is used to store the amount of prime numbers in the range M to N

        // Then use segmented sieve to find primes between M and N
        for (int64_t i = 0; i < prime.size(); i++)
        {
            int64_t p = prime[i];
            int64_t c = M / p;
            c = c * p; // c is the closest number smaller than M that is a composite number for this prime p

            for (int64_t j = c; j <= N; j = j + p)
            {
                if (j < M) continue;
                isPrime[j - M] = false;
            }
        }

        // when M is smaller than sqrt(N), first prime numbers will also be set to false
        // hence we need count their amount in advance
        for (int64_t i = 0; i < prime.size(); i++)
        {
            if (prime[i] >= M && prime[i] <= N)
                q++;
        }

        for (int64_t i = 0; i < isPrime.size(); i++)
        {
            if (isPrime[i] && (i + M) != 1)
            {
                q++;
            }
        }
        std::cout << q << std::endl; // print out amount of prime numbers in the range M to N
    }
    else
        std::cout << "illegal input" << std::endl;


    return 0;
}
