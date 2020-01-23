#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define sz(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> VI;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return abs(a * b) / gcd(a, b); }

ll gcdVec(VI v)
{
    ll res = v[0];
    for (int i = 1; i < sz(v); i++)
        res = gcd(res, v[i]);
    return res;
}

ll lcmVec(VI v)
{
    auto multi = abs(std::accumulate(begin(v), end(v), 1, std::multiplies<double>()));
    return multi / gcdVec(v);
}

int main()
{
    /*gcd*/
    cout << "GCD [ a = 20, b = 44 ] : " << gcd(20, 44) << endl;
    cout << "LCM [ a = 20, b = 44 ] : " << lcm(20, 44) << endl;
    VI vec = {40, 10, 15};
    cout << "Vector GCD [ 40, 10, 15 ] : " << gcdVec(vec) << endl;
    cout << "Vector LCM [ 40, 10, 15 ] : " << lcmVec(vec) << endl;
    return 0;
}