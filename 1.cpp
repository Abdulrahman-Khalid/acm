#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector> // STL
#include <bitset> // STL
#include <math.h>
using namespace std;

template <class T>
void print(vector<T> v)
{
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
}

vector<int> sieve(int n)
{
    vector<int> primes;
    bitset<(long long)1e7 + 10> was;
    was.set();
    was[0] = was[1] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (was[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                was[j] = 0;
        }
    }
    return primes;
}

vector<int> primeFactors(int N)
{
    vector<int> primes;
    bitset<(long long)1e7 + 10> was;
    was.set();
    was[0] = was[1] = 0;
    // Get prime numbers between 1 and sqrt(N)
    int lastPossible = (int)sqrt(N);
    for (int i = 0; i <= lastPossible; i++)
    {
        if (was[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= lastPossible; j += i)
                was[j] = 0;
        }
    }

    // Get prime factors of N
    int k = 0;
    vector<int> res;
    while (N != 1)
    {
        while (N % primes[k] == 0)
        {
            res.push_back(primes[k]);
            N /= primes[k];
        }
        k++;
    }
    return res;
}

long long modExpo(int x, int y, int m)
{
    if (y == 0)
        return 1;
    long long res = 1;
    x %= m;
    while (y > 0)
    {
        if (y & 1) //y%2==1 // y&1==1
            res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int main()
{
    /*sieve*/
    {
        cout << "Sieve of Eratosthenes(prime numbers between 1 and the entered number), Enter a number: ";
        int n;
        cin >> n;
        vector<int> v = sieve(n);
        print(v);
    }

    /*prime factors*/
    {
        cout << "Prime factors, Enter a number: ";
        int n;
        cin >> n;
        vector<int> pF = primeFactors(n);
        print(pF);
    }

    /*Modular Exponentiation (Power in Modular Aritmetic) (x^y)*/
    {
        cout << "Modular Exponentiation (Power in Modular Aritmetic) (x^y)%m (enter x y m): ";
        long long int x, y, m, res = 1;
        cin >> x >> y >> m; // x^y%m
        cout << "(x^y)%m = " << modExpo(x, y, m) << endl;
    }
    return 0;
}
