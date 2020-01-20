#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
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

auto reverse_order = [](const auto &a, const auto &b) { return a > b; }; //lambda func

template <typename T>
void print(T &a)
{
    cout << a << " ";
}

template <typename T>
void forEach(vector<T> &vec, void (*func)(T &) = print) // to pass lambda const function<void(int)>& func
{
    for (auto &val : vec)
        func(val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //sort & stable_sort
    VI v{1, 5, 5, 2, 10, 20};
    sort(all(v));
    forEach(v, print);
    cout << endl;
    cout << (binary_search(all(v), 5) ? "Found" : "Not Found") << endl;
    stable_sort(all(v), reverse_order); // greater<int>() or lambda func
    forEach(v);
    cout << endl;
    cout << (binary_search(all(v), 5, greater<int>()) ? "Found" : "Not Found") << endl;
    //lambda function
    int capture = 4;
    auto lambda = [capture](int input) mutable { capture = 5; return capture + input; };
    // mutable because capute is captured by value and I assigned it inside the lambda function
    // [=] capture all by value, [&] capture all by refrence
    cout << "lambda output: " << lambda(2) << endl;
    return 0;
}