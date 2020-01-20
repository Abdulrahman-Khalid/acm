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

// namespace my
// {
// template <class InIt, class T>
// auto count(InIt first, InIt last, const T &val)
// {
//     return std::reduce(first, last, 0, [val](auto i, auto e) { return i + (val == e); });
// }
// } // namespace my

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* sort & stable_sort, binary_search & lower_bound & upper_bound, reverse & rotate */
    {
        cout << endl
             << "sort & stable_sort, binary_search & lower_bound & upper_bound, reverse & rotate" << endl;
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

        /*rotate(v.begin(), v.begin() + 2, v.end());*/
        rotate_copy(v.begin(), v.begin() + 2, v.end(), vCpy.begin());
        forEach(vCpy);
    }

    /* lambda function */
    {
        cout << endl
             << "lambda function" << endl;
        int capture = 4;
        auto lambda = [capture](int input) mutable {
            capture = 5;
            return capture + input; };
        // mutable because capute is captured by value and I assigned it inside the lambda function
        // [=] capture all by value, [&] capture all by refrence
        cout << "lambda output: " << lambda(2) << endl;
    }

    /* all_of, any_of, none_of*/
    {
        cout << endl
             << "all_of, any_of, none_of" << endl;
        VI v{1, 5, 5, 2, 10, 20};
        auto is_even = [](auto a) { return a % 2 == 0; };
        bool noneEven = none_of(v.begin(), v.end(), is_even);
        bool anyEven = any_of(v.begin(), v.end(), is_even);
        bool allEven = all_of(v.begin(), v.end(), is_even);
        cout << "All even: " << (allEven ? "True" : "False") << endl;   // true if all true
        cout << "Any even: " << (anyEven ? "True" : "False") << endl;   // true if any true
        cout << "None even: " << (noneEven ? "True" : "False") << endl; // true if none true (all false)
    }

    /*  std::partial_sum & std::iota */
    {
        cout << endl
             << "std::partial_sum & std::iota" << endl;
        VI a(5), b(5), c(5);
        iota(all(a), 2);                                // 1, 2, 3, 4 ,5 // fill vector starting from the value
        partial_sum(all(a), b.begin());                 //default plus<>() // current element in (a) plus the previous in (b)
        partial_sum(all(a), c.begin(), multiplies<>()); // current element in (a) * the previous in (c)
        forEach(a), forEach(b), forEach(c);
    }

    /* set_union, set_intersection, set_difference & set_symmetric_difference */
    {
        cout << endl
             << "set_union, set_intersection, set_difference & set_symmetric_difference" << endl;
        // need to be sorted, o(N)
        // set_symmetric_difference is the not intersection
        cout << endl
             << "set_union, set_intersection, set_difference & set_symmetric_difference" << endl;
        VI a = {0, 1, 2, 3, 4, 5}, b = {4, 5, 6, 7, 8, 9}, uni, inter, diff, symmDiff;
        set_union(all(a), all(b), back_inserter(uni));
        set_intersection(all(a), all(b), back_inserter(inter));
        set_difference(all(a), all(b), back_inserter(diff));
        set_symmetric_difference(all(a), all(b), back_inserter(symmDiff)); // inserter(set1,set1.end()) if there is insert function
        cout << "Union: ";
        forEach(uni);
        cout << "Intersection: ";
        forEach(inter);
        cout << "Difference: ";
        forEach(diff);
        cout << "Symmetric Difference: ";
        forEach(symmDiff);
    }

    /* std::adjacent_find */
    {
        cout << endl
             << "std::adjacent_find" << endl;
        auto adjCount = [](auto first, auto last) {
            auto c = 0;
            while (1)
            {
                first = adjacent_find(first, last); //equal
                if (first == last)
                    return c;
                c++, first++;
            }
            return 0;
        };
        VI a = {0, 5, 2, 2, 2, 3, 1, 4, 4};
        cout << "Count: " << adjCount(all(a)) << endl;
        auto first = adjacent_find(all(a), less<>()); //first number less than the next
        cout << "Less: " << *first << endl;
        first = adjacent_find(all(a), greater<>()); //first number greater than the next
        cout << "Greater: " << *first << endl;
    }

    /* std::count, std::count_if & my::count via std::reduce */
    {
        cout << endl
             << "std::count, std::count_if & my::count via std::reduce" << endl;
        VI a = {1, 2, 3, 1, 2};
        cout << "1's count: " << count(all(a), 1) << endl;
        // cout << "my count: " << my::count(all(a), 1) << endl;
        auto is_odd = [](auto e) { return e % 2 == 1; };
        cout << "Odd Count: " << count_if(all(a), is_odd) << endl;
    }

    /* std::partition, std::stable_partition & std::remove_if */
    {
        cout << endl
             << "std::partition, std::stable_partition & std::remove_if" << endl;
        VI a(10), b(10), c(10);
        iota(all(a), 1);
        iota(all(b), 1);
        iota(all(c), 1);
        auto is_even = [](auto e) { return e % 2 == 0; };
        auto is_odd = [](auto e) { return e % 2 == 1; };
        partition(all(a), is_even); // if true swap to the front of vector
        cout << "partition is even: ";
        forEach(a, print);
        stable_partition(all(b), is_even); // if true swap to the front of vector
        cout << "stable_partition is even: ";
        forEach(b, print);
        cout << "remove_if is odd: ";
        c.erase(remove_if(all(c), is_odd), c.end()); // remove_if => if false move it (not swap) to the front
        forEach(c, print);
    }

    /* std::generate & std::generate_n */
    {
        cout << endl
             << "std::generate & std::generate_n" << endl;
        auto generateABC = [](int size) {
            vector<string> v(size);
            generate(all(v), [s = ""s, c = 'a']() mutable { s+=c; c++; return s; });
            forEach(v, print);
        };
        auto generateABC_n = [](int size) {
            vector<string> v;
            generate_n(back_inserter(v), size, [s = ""s, c = 'a']() mutable { s+=c; c++; return s; });
            forEach(v, print);
        };
        auto enhanceGenerateABC_n = [](int size) {
            vector<string> v;
            //push back make it slower
            v.reserve(size); // change capacity
            v.resize(size);  // change size
            generate_n(v.begin(), size, [s = ""s, c = 'a']() mutable { s+=c; c++; return s; });
            forEach(v, print);
        };
        generateABC(5);
        generateABC_n(6);
        enhanceGenerateABC_n(7);
    }
    return 0;
}