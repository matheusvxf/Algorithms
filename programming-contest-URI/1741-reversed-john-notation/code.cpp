#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Atribute
{
public:
    virtual void dummy() {}
};

class Number : public Atribute
{
public:
    long long int num;

    Number() : Number('0') {}
    Number(char c) : num(c - '0') {}
};

class Operator : public Atribute
{
public:
    char op;
    static bool ERROR;
    static bool DIVISION_BY_ZERO;

    enum Op
    {
        plus = '+',
        minus = '-',
        multiply = '*',
        divide = '/'
    };

    Operator(char c) : op(c) {}

    long long int operator()(const Number* a, const Number* b)
    {
        switch (op)
        {
        case plus:
            return a->num + b->num;
        case minus:
            return a->num - b->num;
        case multiply:
            return a->num * b->num;
        case divide:
            if (b->num == 0)
            {
                DIVISION_BY_ZERO = 1;
                return 0;
            }
            else
                return a->num / b->num;
        }
    }

    inline bool error() { return ERROR; }
};

bool Operator::ERROR = false;
bool Operator::DIVISION_BY_ZERO = false;

bool IsOperator(char c)
{
    switch (c)
    {
    case Operator::plus:
    case Operator::minus:
    case Operator::multiply:
    case Operator::divide:
        return true;
    default:
        return false;
    }
}

int main() {
    char c;

    while (scanf("%c", &c) != EOF)
    {
        stack< Atribute* > S;
        Number *operand_1 = nullptr, *operand_2 = nullptr;
        Operator* op = nullptr;
        long long int result;
        bool flag = true;

        Operator::ERROR = false;
        Operator::DIVISION_BY_ZERO = false;

        if (IsOperator(c))
            S.push(new Operator(c));
        else
            S.push(new Number(c));
            

        while (scanf("%c", &c) && c != '\n')
        {
            if (c != ' ')
            {
                if (IsOperator(c))
                {
                    S.push(new Operator(c));
                }
                else
                {
                    S.push(new Number(c));
                }
            }
        }

        if (S.size() == 1)
        {
            operand_1 = dynamic_cast<Number*>(S.top()); S.pop();
            result = operand_1->num;
            flag = false;
        }
        else if (S.size() >= 3)
        {
            operand_2 = dynamic_cast<Number*>(S.top()); S.pop();
            operand_1 = dynamic_cast<Number*>(S.top()); S.pop();
            op = dynamic_cast<Operator*>(S.top()); S.pop();
        }
        else
        {
            Operator::ERROR = true;
        }

        if (flag)
        {
            if (operand_1 == nullptr || operand_2 == nullptr || op == nullptr)
            {
                printf("Invalid expression.\n");
                Operator::ERROR = true;
            }
            else
            {
                result = (*op)(operand_2, operand_1);
                operand_2->num = result;

                while (!S.empty())
                {
                    if (S.size() >= 2)
                    {
                        operand_1 = dynamic_cast<Number*>(S.top()); S.pop();
                        op = dynamic_cast<Operator*>(S.top()); S.pop();
                    }
                    else
                    {
                        Operator::ERROR = true;
                    }

                    if (Operator::ERROR || operand_1 == nullptr || op == nullptr)
                    {
                        printf("Invalid expression.\n");
                        Operator::ERROR = true;
                        break;
                    }

                    result = (*op)(operand_2, operand_1);
                    operand_2->num = result;
                }
            }
        }

        if (!Operator::ERROR)
        {
            if (Operator::DIVISION_BY_ZERO)
                printf("Division by zero.\n");
            else
                printf("The answer is %lld.\n", result);
        }
    }
}
