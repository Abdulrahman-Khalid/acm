#include <bits/stdc++.h>
#include <vector>
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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return abs(a * b) / gcd(a, b); }

ll gcdVec(VI v)
{
    ll res = v[0];
    for (int i = 1; i < SZ(v); i++)
        res = gcd(res, v[i]);
    return res;
}

ll lcmVec(VI v)
{
    auto multi = abs(std::accumulate(begin(v), end(v), 1, std::multiplies<double>()));
    return multi / gcdVec(v);
}

string extraLongSum(string num1, string num2)
{
    // Before proceeding further, make sure length
    // of b is larger.
    if (SZ(num1) < SZ(num2))
        swap(num1, num2);

    // Take an empty string for storing result
    string res = "";

    // Calculate length of both string
    int diff = SZ(num1) - SZ(num2);

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    rloop0(i, SZ(num2))
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = num2[i] - '0' + num1[i + diff] - '0' + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    // Add remaining digits of b[]
    rloop0(i, diff)
    {
        int sum = ((num1[i] - '0') + carry);
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    // Add remaining carry
    if (carry)
        res.push_back(carry + '0');
    // reverse resultant string
    reverse(all(res));
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

bool isNum1Smaller(const string &num1, const string &num2)
{
    if (SZ(num2) > SZ(num1))
        return true;
    if (SZ(num1) < SZ(num2))
        return false;

    // if size of num1 & num2 are equal
    for (int i = 0; i < SZ(num2); i++)
    {
        if (num1[i] > num2[i])
            return false;
        else if (num1[i] < num2[i])
            return true;
    }
    return false;
}

string extraLongSubtraction(string num1, string num2)
{
    bool isSmaller = isNum1Smaller(num1, num2);
    if (isSmaller)
        swap(num1, num2);
    string res = "";
    int diff = SZ(num1) - SZ(num2);
    rloop0(i, SZ(num2))
    {
        int j = i + diff;
        if (num1[j] < num2[i])
        {
            //take a carry from the bigger number
            num1[j - 1]--;
            num1[j] += 10;
        }
        // because (num1[j]-'0')+(num2[i]-'0')+'0', char to num => -'0', num to char => +'0'
        res.push_back(num1[j] - num2[i] + '0');
    }
    res += num1.substr(0, diff);

    // remove extra '0's
    // eg: 200 - 153 = (740) de hya (047) bs reversed => after remove right '0's = (74) hya (47) reversed
    rloop(i, 1, SZ(num1)) // > not >= to not remove last zero
    {
        if (res[i] == '0')
            res.pop_back();
        else
            break;
    }

    if (isSmaller)
        res += '-';
    reverse(all(res));
    return res;
}
int main()
{
    /*gcd*/
    cout << "GCD [ a = 20, b = 44 ] : " << gcd(20, 44) << endl;
    cout << "LCM [ a = 20, b = 44 ] : " << lcm(20, 44) << endl;
    VI vec = {40, 10, 15};
    cout << "Vector GCD [ 40, 10, 15 ] : " << gcdVec(vec) << endl;
    cout << "Vector LCM [ 40, 10, 15 ] : " << lcmVec(vec) << endl;
    cout << "Long Sum: 98675+113 = " << extraLongSum("98675", "113") << endl;
    cout << "Long Sub: 200-240 = " << extraLongSubtraction("200", "240") << endl;
    cout << "Long Sub: 200-150 = " << extraLongSubtraction("200", "150") << endl;
    cout << "Long Sub: 200-200 = " << extraLongSubtraction("200", "200") << endl;
    cout << "Long Mult: 89014*516125161 = " << extraLongMultiplication("89014", "516125161") << endl;
    cout << "Long Mult: -2*5 = " << extraLongMultiplication("-2", "5") << endl;
    cout << "Long Mult: 2*-5 = " << extraLongMultiplication("2", "-5") << endl;
    cout << "Long Mult: -3*-2 = " << extraLongMultiplication("-3", "-2") << endl;
    cout << "Long Mult: 9*9 = " << extraLongMultiplication("9", "9") << endl;

    return 0;
}