#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define DEBUG 0
#define FIND(Q, a) (Q.find(a) != Q.end())

int num_digits(long long int A)
{
    int div = 10;
    int digits = 1;

    while (A / div)
    {
        div *= 10;
        digits++;
    }
    return digits;
}

long long int calc_base(long long int n_digit)
{
    long long int base = 1;

    for (int i = 1; i < n_digit; ++i)
        base *= 10;

    return base;
}

long long int fac(long long int a)
{
    static unordered_map< long long int, long long int > cache{ { -1, 1 }, { 0, 1 }, { 1, 1 } };
    long long int res;

    if (FIND(cache, a))
        return cache[a];
    else
    {
        res = a * fac(a - 1);
        cache[a] = res;
    }
    
    return res;
}

inline long long int comb(long long int a, long long int n)
{
    if (a > n)
        return 1;
    return fac(n) / (fac(a) * fac(n - a));
}

inline long long int exp_9(long long int e)
{
    static unordered_map< long long int, long long int> cache{ { 0, 1 }, { 1, 9 } };
    long long int res = 1;

    if (FIND(cache, e))
        return cache[e];

    for (int i = 0; i < e; ++i)
        res *= 9;

    cache[e] = res;

    return res;
}

inline long long int make_9(int num_digit)
{
    long long int res = 0;

    if (num_digit == 0)
        return 0;

    res += 9;
    num_digit--;

    while (num_digit--)
    {
        res *= 10;
        res += 9;
    }
    
    return res;
}

long long int count_digits(long long int A, int p_digit, int extra, bool count_trailing_zero = false)
{
    int n_digit = num_digits(A);
    long long int base = calc_base(n_digit);
    long long int digit;
    long long int counter = 0;

    digit = A / base;

    if (base == 1)
    {
        if (p_digit <= digit)
            return 1 + extra + extra * (digit);
        else
            return extra * (digit + 1);
    }

    if (p_digit > digit)
    {
        long long int first_digit_comb = digit;

        for (int i = 0; i < n_digit; ++i)
            counter += (i + extra) * first_digit_comb * comb(i, n_digit - 1) * exp_9(n_digit - 1 - i);

        return counter + count_digits(A % base, p_digit, extra);
    }
    else if (p_digit == digit)
    {
        long long int first_digit_comb = digit;

        for (int i = 0; i < n_digit; ++i)
            counter += (i + extra) * first_digit_comb * comb(i, n_digit - 1) * exp_9(n_digit - 1 - i);

        return counter + count_digits(A % base, p_digit, extra + (digit == p_digit ? 1 : 0));
    }
    else
    {
        long long int first_digit_comb = digit - 1;

        for (int i = 0; i < n_digit; ++i)
            counter += (i + extra) * first_digit_comb * comb(i, n_digit - 1) * exp_9(n_digit - 1 - i);

        if (p_digit != 0)
        {
            for (int i = 0; i < n_digit; ++i)
                counter += (i + extra + 1) * comb(i, n_digit - 1) * exp_9(n_digit - 1 - i);
        }
        else
        {
            long long int next_number = A % base;

            if (count_trailing_zero)
                for (int i = 0; i < n_digit; ++i)
                    counter += (i + extra + 1) * comb(i, n_digit - 1) * exp_9(n_digit - 1 - i);
            else
                counter += count_digits(make_9(n_digit - 1), p_digit, extra, false);

            counter += count_digits(next_number, p_digit, extra + n_digit - num_digits(next_number) - 1, true);

            return counter;
        }

        counter += count_digits(A % base, p_digit, extra, false);
        return counter;
    }

}

long long int count_digits(long long int A, int digit)
{
    return count_digits(A, digit, 0, false);
}

int main() {
    long long int A, B;

    while (cin >> A >> B && A != 0)
    {
        long long int res_1, res_2;

        for (int i = 0; i < 9; ++i)
        {
            res_2 = count_digits(B, i);
            res_1 = count_digits(A - 1, i);

#if(DEBUG == 1)
            cout << res_2 - res_1 << " " << res_1 << " " << res_2 << endl;
#else
            cout << res_2 - res_1 << " ";
#endif

        }

        res_1 = count_digits(A - 1, 9);
        res_2 = count_digits(B, 9);
        cout << res_2 - res_1 << endl;
    }
}
