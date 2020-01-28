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

ll mulmod(ll a, ll b, ll m = mod)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

ll powmodWithMulmod(ll a, ll b, ll m = mod)
{
    ll res = 1; // not 1 as it's + not *
    while (b)
    {
        if (b & 1)
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }
    return res;
}

ll powmod(ll a, ll b, ll m = mod)
{
    ll res = 1;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = ((__int128)res * a) % m;
        a = ((__int128)a * a) % m;
    }
    return res;
}

typedef pair<ll, ll> PLL;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcdVec(VI v)
{
    ll res = v[0];
    for (int i = 1; i < SZ(v); i++)
        res = gcd(res, v[i]);
    return res;
}

string extraLongMultiplication(string str1, string str2)
{

    string res = "";
    if (str1[0] == '-' ^ str2[0] == '-') //xor
        res.push_back('-');

    if (str1[0] == '-')
        str1.erase(str1.begin());

    if (str2[0] == '-')
        str2.erase(str2.begin());

    int maxLen = str1.size() + str2.size() - 1;
    int num1[str1.size()], num2[str2.size()], mul[maxLen];

    memset(mul, 0, sizeof(mul));

    for (int i = 0; i < str1.size(); ++i)
        num1[i] = str1[i] - '0';
    for (int i = 0; i < str2.size(); ++i)
        num2[i] = str2[i] - '0';

    loop0(i, SZ(str2))
        loop0(j, SZ(str1))
            mul[i + j] += num2[i] * num1[j];

    rloop(i, 1, maxLen)
    {
        mul[i - 1] += mul[i] / 10;
        mul[i] %= 10;
    }
    loop0(i, maxLen)
        res += to_string(mul[i]);
    return res;
}
string extraLongFactorial(int n)
{
    string res = "1";
    while (n > 1)
    {
        res = extraLongMultiplication(res, to_string(n));
        n--;
    }
    return res;
}

void modGCD()
{
    ll a, b, n;
    cin >> a >> b >> n;
    if (a == b)
    {
        cout << (powmod(a, n) + powmod(b, n)) % mod << '\n';
    }
    else
    {
        ll d = (powmod(a, n, a - b) + powmod(b, n, a - b)) % (a - b);
        cout << gcd(d, a - b) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*[Sherlock and GCD](https://www.hackerrank.com/challenges/sherlock-and-gcd?h_r=internal-search)*/
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            VI v(n);
            loop0(i, n)
            {
                int x;
                cin >> x;
                v[i] = x;
            }
            // if gcd(a,b) is 1 so gcd(a,b,c,d,e) is also 1
            cout << (gcdVec(v) == 1 ? "YES\n" : "NO\n");
        }
    }

    /*- [Complicated GCD](http://codeforces.com/contest/664/problem/A)*/
    {
        string a, b;
        cin >> a >> b;
        cout << (a == b ? a : "1"); // because there is no gcd(a, a+1) always be 1 and gcd(a,a) is a
    }

    /*[Extra Long Factorials](https://www.hackerrank.com/challenges/extra-long-factorials?h_r=internal-search)*/
    {
        int n;
        int carry = 0;
        cin >> n;
        VI arr;
        arr.push_back(1); //Initial product = 1
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < SZ(arr); j++)
            {
                arr[j] = arr[j] * i + carry;
                carry = arr[j] / 10;
                arr[j] %= 10;
            }
            while (carry)
            { //Propogate the remaining carry to higher order digits
                arr.push_back(0);
                arr[SZ(arr) - 1] = carry % 10;
                carry /= 10;
            }
        }
        for (int i = SZ(arr) - 1; i >= 0; i--) // k
            cout << arr[i];
        cout << endl;

        /*another solution (much slower)*/
        cout << extraLongFactorial(n) << endl;
    }

    /*- [GCD of Large Number](https://www.codechef.com/problems/GCD2) 
    - [Editorial](https://www.geeksforgeeks.org/gcd-of-two-numbers-when-one-of-them-can-be-very-large-2/)*/
    {
        int n;
        cin >> n;
        while (n--)
        {
            ll a, bMod = 0;
            string b;
            cin >> a >> b;
            loop0(i, SZ(b))
                bMod = (bMod * 10 + b[i] - '0') % a;
            cout << gcd(a, bMod) << endl;
        }
    }

    /*- [Modular GCD](https://www.codechef.com/AUG18B/problems/GCDMOD)*/
    {
        int t, a, b, n;
        cin >> t;
        while (t--)
            modGCD();
    }
    return 0;
}