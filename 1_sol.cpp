#include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)
#define loop0(i, n) for (int i = 0; i < n; i++)
#define rloop(i, a, n) for (int i = n - 1; i >= a; i--)
#define rloop0(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef vector<vector<int>> VIV;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
typedef pair<ll, ll> PLL;

/* Solution of question (1) [Distinct Primes] link: (http://www.spoj.com/problems/AMR11E/) */
VI distinctPrimes()
{
    const int max = 1e4; // For sure the 1000th number the limit is lees than 1e4
    VI countPrimes(max); // Contains Count of distinct primes number factors of the index
    //first count the number of
    for (int i = 2; i <= max; i++) //should start with 2 as the first prime number
    {
        if (countPrimes[i] == 0)              // Is prime?
            for (int j = i; j <= max; j += i) // Could start from i*2 as countPrimes[i] will be atmost 1 as it's a prime number
                countPrimes[j]++;             // Add 1 to every number as it's divisable by this (i) prime number
    }

    VI res;
    res.push_back(0); // put 0 is res[0] doesn't matter instead of cout << res[x-1] << endl; in main
    for (int i = 2; i <= max; i++)
        if (countPrimes[i] >= 3) // if more than or equal to 3 distinct primes add to res
            res.push_back(i);
    return res;
}

/* Solution of question (2) [Noldbach problem] link: (http://codeforces.com/problemset/problem/17/A?locale=en) */
string noldbach(int n, int k)
{
    bitset<1001> was;
    was.set();
    was[0] = was[1] = 0;
    VI primes;
    for (int i = 2; i <= n; i++)
    {
        if (was[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                was[j] = 0;
        }
    }
    int max = primes.size() - 1;
    for (int i = 0; i < max; i++)
    {
        int sum = primes[i] + primes[i + 1] + 1;
        if (was[sum] && sum <= n)
            k--;
    }
    if (k > 0)
        return "NO";
    return "YES";
}

/*Solution of quesion (3) [Medium Factorization] link: (http://www.spoj.com/problems/FACTCG2/)*/
VI primes;
void sieve(int n)
{
    int max = (int)sqrt(n);
    vector<bool> was(max, true);
    was[0] = was[1] = false;
    for (int i = 2; i <= max; i++)
    {
        if (was[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= max; j += i)
                was[j] = false;
        }
    }
}

vector<ll> primeFact(ll num)
{
    int i = 0;
    vector<ll> res;
    res.push_back(1);
    while (num != 1)
    {
        while (num % primes[i] == 0)
        {
            res.push_back(primes[i]);
            num /= primes[i];
        }
        i++;
    }
    return res;
}

/* Solution of question (4) [Power of Large Numbers](https://www.hackerrank.com/challenges/power-of-large-numbers) */
ll powerOfLargeNum(string a, string b)
{
    /**
     * To reduce a: 
        1-(a^b) % m = ((a % m)^b) % m
        2- a = a % m
     * To reduce b: 
        1- given a^(p-1) % p = 1, When p is prime.
        2- a^b % m = (a^(m-1) * a^(m-1) * ....... * a^(m-1) * a^(x)) % m, where a^(m-1) is b/(m-1) times and x = b%(m-1)
        3- From (1) a^(m-1) % m = 1
        4- From (2) and (3) (a^b) % m = (a^x)%m as a^b % m = (1 * 1 * ....... * 1 * a^(x)) % m
        5- Hence b = x = b%(m-1)
    */
    a.length();
    ll aMod = a[0] - '0', bMod = b[0] - '0';
    loop(i, 1, a.length())
        aMod = (aMod * 10 + a[i] - '0') % mod;
    loop(i, 1, b.length())
        bMod = (bMod * 10 + b[i] - '0') % (mod - 1);
    return powmod(aMod, bMod);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*Question (1)*/
    // {
    //     int n;
    //     cin >> n;
    //     VI res = distinctPrimes();
    //     while (n--)
    //     {
    //         int x;
    //         cin >> x;
    //         cout << res[x] << endl;
    //     }
    // }

    /*Question (2)*/
    // {
    //     int n, k;
    //     cin >> n >> k;
    //     cout << noldbach(n, k) << endl;
    // }

    /*Question (3)*/
    // {
    //     int n;
    //     vector<ll> inputs;
    //     cin >> n;
    //     inputs.push_back(n);
    //     ll max = n;
    //     while (cin >> n)
    //     {
    //         if (n > max)
    //             max = n;
    //         inputs.push_back(n);
    //     }
    //     sieve(max);
    //     loop(i, 0, inputs.size())
    //     {
    //         vector<ll> ans = primeFact(inputs[i]);
    //         int sz = SZ(ans) - 1;
    //         loop(j, 0, sz)
    //         {
    //             cout << ans[j] << " x ";
    //         }
    //         cout << ans[sz] << endl;
    //     }
    // }

    {
        string a, b;
        int n;
        cin >> n;
        while (n--)
        {
            cin >> a >> b;
            cout << powerOfLargeNum(a, b) << endl;
        }
    }
    return 0;
}