#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    cout << endl;
}

template <typename ForwardIterator, typename T>
ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value)
{
    auto it = lower_bound(first, last, value);
    return it == first ? last : --it;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //sort & stable_sort
    VI v{1, 5, 5, 2, 10, 20};
    sort(all(v)); //complexity: o(nlogn)
    forEach(v, print);
    cout << endl;
    cout << "Binary Search: " << (binary_search(all(v), 5) ? "Found" : "Not Found") << endl;
    auto it = lower_bound(all(v), 5); //first equal to or greater than //complexity: o(logn)
    cout << "Lower Bound: " << (it != v.end() ? to_string(*it) : "Not Found") << endl;
    cout << "Lower Bound Distance: " << distance(v.begin(), it) << endl;
    it = upper_bound(all(v), 5); // first greater than //complexity: o(logn)
    cout << "Upper Bound: " << (it != v.end() ? to_string(*it) : "Not Found") << endl;
    it = first_less_than(all(v), 5); // first greater than //complexity: o(logn)
    cout << "first less than: " << (it != v.end() ? to_string(*it) : "Not Found") << endl;

    stable_sort(all(v), reverse_order); // greater<int>() or lambda func //complexity: o(nlogn)
    forEach(v);
    cout << "Binary Search: " << (binary_search(all(v), 5, reverse_order) ? "Found" : "Not Found") << endl; //complexity: o(logn)

    reverse(all(v));
    forEach(v);

    VI vCpy(6);
    reverse_copy(all(v), vCpy.begin());
    forEach(vCpy);

    //rotate(v.begin(), v.begin() + 2, v.end());
    rotate_copy(v.begin(), v.begin() + 2, v.end(), vCpy.begin());
    forEach(vCpy);

    /* lambda function */
    int capture = 4;
    auto lambda = [capture](int input) mutable {
        capture = 5;
        return capture + input; };
    // mutable because capute is captured by value and I assigned it inside the lambda function
    // [=] capture all by value, [&] capture all by refrence
    cout << "lambda output: " << lambda(2) << endl;

    /* scope */
    {
        int ad = 2;
    }

    /* all_of, any_of, none_of*/
    auto is_even = [](auto a) { return a % 2 == 0; };
    bool noneEven = none_of(v.begin(), v.end(), is_even);
    bool anyEven = any_of(v.begin(), v.end(), is_even);
    bool allEven = all_of(v.begin(), v.end(), is_even);
    cout << "All even: " << (allEven ? "True" : "False") << endl;   // true if all true
    cout << "Any even: " << (anyEven ? "True" : "False") << endl;   // true if any true
    cout << "None even: " << (noneEven ? "True" : "False") << endl; // true if none true (all false)

    /*  std::partial_sum & std::iota */
    VI a(5), b(5), c(5);
    iota(all(a), 1);                // 1, 2, 3, 4 ,5
    partial_sum(all(a), b.begin()); //default plus<>()
    partial_sum(all(a), c.begin(), multiplies<>());
    forEach(a), forEach(b), forEach(c);
    return 0;
}