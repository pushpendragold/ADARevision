#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long subMod(long a,long b,long m)
{
    // works
    return (a % m - b % m + m) % m;
}

long addMod(long a, long b, long m) 
{
    if (a + b < 0)
        return (a - m) + b;
    else if (a + b >= m)
        return a + b - m;
    else
        return a + b;
}

long multiplyMod(long a, long b, long m) 
{
    if (b == 0 || a <= 1000000000000 / b)
        return a * b % m;
    long result = 0;
    if (a > b) {
        long c = b;
        b = a;
        a = c;
    }
    while (a > 0) 
    {
        if ((a & 1) != 0) {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)
            b += m;
    }
    return result;
}

long PowMod(long x, long e, long mod)
{
    long res;
    if (e == 0)
    {
        res = 1;
    }
    else if (e == 1)
    {
        res = x;
    }
    else
    {
        res = PowMod(x, e / 2, mod);
        res = res * res % mod;
        if (e % 2)
            res = res * x % mod;
    }
    return res;
}

int main()
{
    printf("%ld\n",PowMod(2,10000,1000000007));
    printf("%ld\n",multiplyMod(2,3,4));
    return 0;
}
