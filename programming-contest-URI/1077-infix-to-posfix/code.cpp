#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <deque>
#include <unordered_map>
#include <stack>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()
#define FIND(Q, a) Q.find(a) != Q.end()

class Operator
{
public:
    char c;
    short priority;

    Operator() {}
    Operator(char c, short priority) : c(c), priority(priority) {}
};

static unordered_map< char, Operator > K_operator = {
    { '^', Operator('^', 6) },
    { '*', Operator('*', 5) },
    { '/', Operator('/', 5) },
    { '+', Operator('+', 4) },
    { '-', Operator('-', 4) },
    { '<', Operator('<', 3) },
    { '>', Operator('>', 3) },
    { '=', Operator('=', 3) },
    { '#', Operator('#', 3) },
    { '.', Operator('.', 2) },
    { '|', Operator('|', 1) }
};

inline short Priority(char c)
{
    return K_operator[c].priority;
}

inline bool IsOperator(char c)
{
    return FIND(K_operator, c);
}

inline bool IsOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

inline bool IsBracket(char c)
{
    return c == '(' || c == ')';
}

bool LexicalCheck(char c)
{
    return IsOperand(c) || IsOperator(c) || IsBracket(c);
}

enum State
{
    OPERAND,
    OPERATOR
};

bool PopBracket(stack< char >& S, deque< char >& exp_posfix)
{
    bool found = false;
    char c;

    while (!S.empty() && !found)
    {
        c = S.top();
        S.pop();

        if (c == '(')
            found = true;
        else
            exp_posfix.push_back(c);
    }

    return found;
}

pair< bool, deque< char > > SintaxCheck(deque< char >& exp)
{
    stack< char > S;
    deque< char > exp_posfix;
    State state = OPERAND;
    
    while (!exp.empty())
    {
        char c = exp.back(); exp.pop_back();

        switch (state)
        {
        case (OPERAND) :
            if (c == '(')
                S.push(c);
            else if (c == ')')
            {
                if (!PopBracket(S, exp_posfix))
                    return make_pair(false, exp_posfix);
            }
            else if (IsOperand(c))
            {
                exp_posfix.push_back(c);
                state = OPERATOR;
            }
            else
                return make_pair(false, exp_posfix);
            break;
        case (OPERATOR) :
            if (IsOperator(c))
            {
                while (!S.empty() && IsOperator(S.top()))
                {
                    char op = S.top();
                    if (Priority(c) <= Priority(op))
                    {
                        exp_posfix.push_back(op);
                        S.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                S.push(c);
                state = OPERAND;
            }
            else if (c == '(')
            {
                S.push(c);
                state = OPERAND;
            }
            else if (c == ')')
            {
                if (!PopBracket(S, exp_posfix))
                    return make_pair(false, exp_posfix);
            }
            else
            {
                return make_pair(false, exp_posfix);
            }
            break;
        default:
            return make_pair(false, exp_posfix);
        }
    }

    return make_pair( S.empty(), exp_posfix );
}

int main() {
    int T;

    scanf("%d\n", &T);
    while (T--)
    {
        deque< char > exp;
        bool lexical_error = false;
        char c;

        exp.push_front('(');
        while (scanf("%c", &c) && c != '\n')
             exp.push_front(c);
        exp.push_front(')');

        auto res = SintaxCheck(exp);

        foreach(res.second, it)
            printf("%c", *it);
        printf("\n");
    }
}
