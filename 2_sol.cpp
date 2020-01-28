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
#define rall(x) (x).rbe gin(), (x).rend()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
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
typedef pair<ll, ll> PLL;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcdVec(VI v)
{
    ll res = v[0];
    for (int i = 1; i < sz(v); i++)
        res = gcd(res, v[i]);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*[Sherlock and GCD](https://www.hackerrank.com/challenges/sherlock-and-gcd?h_r=internal-search)*/
    // {
    //     int t;
    //     cin >> t;
    //     while (t--)
    //     {
    //         int n;
    //         cin >> n;
    //         VI v(n);
    //         loop0(i, n)
    //         {
    //             int x;
    //             cin >> x;
    //             v[i] = x;
    //         }
    //         // if gcd(a,b) is 1 so gcd(a,b,c,d,e) is also 1
    //         cout << (gcdVec(v) == 1 ? "YES\n" : "NO\n");
    //     }
    // }
    /*- [Complicated GCD](http://codeforces.com/contest/664/problem/A)*/
    // {
    //     string a, b;
    //     cin >> a >> b;
    //     cout << (a == b ? a : "1"); // because there is no gcd(a, a+1) always be 1 and gcd(a,a) is a
    // }
    {
    }
    return 0;
}