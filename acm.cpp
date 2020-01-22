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

int winningHands(int m, int x, vector<int> a)
{
    int state = 0;
    VIV dp(2, VI(m));
    loop0(i, a.size())
    {
        loop0(j, m)
            dp[state][(ll)j * a[i] % m] += dp[state ^ 1][j];
        dp[state][a[i] % m]++;
        dp[state ^ 1] = dp[state];
        state ^= 1;
    }
    return dp[state][x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;
    int x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++)
    {
        cin >> a[a_i];
    }
    int result = winningHands(m, x, a);
    cout << result << endl;
    return 0;
}