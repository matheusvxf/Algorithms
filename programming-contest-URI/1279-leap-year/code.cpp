#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <bitset>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()

bool Div3(vector< int > &A)
{
    int sum = 0;
    int i = 0;

    while (i < A.size())
        sum += A[i++];
    
    return sum % 3 == 0;
}

bool Div4(vector< int > &A)
{
    int i = A.size() - 1;
    int B = A[i] + A[i - 1] * 10;

    return B % 4 == 0;
}

bool Div5(vector< int > &A)
{
    return A.back() % 5 == 0;
}

bool Div11(vector< int > &A)
{
    int sum = 0;
    int i = 0;

    while (i < A.size())
    {
        sum += (i % 2 == 0 ? A[i] : -A[i]);
        i++;
    }

    return sum % 11 == 0;
}

bool Div100(vector< int > &A)
{
    int i = A.size() - 1;
    int B = A[i] + A[i - 1] * 10;

    return B == 0;
}

static bool Div10000(vector< int > &A);

bool Div400(vector< int > &A)
{
    int i = A.size() - 1;
    int B;

    B = A[i] + A[i - 1] * 10 + A[i - 2] * 100 + A[i - 3] * 1000;

    return B % 400 == 0;
}

int main() {
    char c;
    bool first = true;

    while (scanf("%c", &c) != EOF) 
    {
        vector< int > A;
        bool leap, huluculu, bulukulu;

        if (!first)
            printf("\n");
        first = false;

        A.push_back(c - '0');
        while (scanf("%c", &c) && c != '\n')
            A.push_back(c - '0');

        leap = Div4(A) && (!Div100(A) || Div400(A));
        huluculu = Div3(A) && Div5(A);
        bulukulu = leap && (Div5(A) && Div11(A));

        if (leap)
            printf("This is leap year.\n");
        if (huluculu)
            printf("This is huluculu festival year.\n");
        if (bulukulu)
            printf("This is bulukulu festival year.\n");
        if (!leap && !huluculu && !bulukulu)
            printf("This is an ordinary year.\n");
    }
}
