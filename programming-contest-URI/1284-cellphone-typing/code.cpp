#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define FIND(Q, q) (Q.find(q) != Q.end())
#define LETTERS 26


class String : public string
{
public:
    int pos;

    String() : pos(0), string() {}
    String(const char str[]) : pos(0), string(str) {}
    String(string::const_iterator begin, string::const_iterator end) : pos(0), string(begin, end) {}
    String(String &s) : pos(0)
    {
        string::assign(all(s));
    }

    void copy(string::const_iterator begin, string::const_iterator end)
    {
        pos = 0;
        assign(begin, end);
    }

    inline string::const_iterator begin() const
    {
        return string::begin() + pos;
    }

    inline string::iterator begin()
    {
        return string::begin() + pos;
    }

    inline string::const_iterator end() const
    {
        return string::end();
    }

    inline string::iterator end()
    {
        return string::end();
    }

    inline unsigned int size() const
    {
        return string::size() - pos;
    }

    inline bool empty() const
    {
        return size() == 0;
    }

    inline char operator[](size_t pos)
    {
        return string::operator[](this->pos + pos);
    }

    bool operator<(const String& a) const
    {
        auto str_1 = this->begin();
        auto str_2 = a.begin();
        int size_1 = size();
        int size_2 = a.size();
        int i = 0;

        while (i < size_1 && i < size_2 && str_1[i] == str_2[i]) i++;

        if (i == size_1 && i == size_2)
            return false;
        else if (i == size_1 && i != size_2)
            return true;
        else if (i != size_1 && i == size_2)
            return false;
        else
            return str_1[i] < str_2[i];
    }

    String& operator=(String s)
    {
        string::assign(s.begin(), s.end());

        return *this;
    }

    int Match(String& a) const
    {
        auto str_1 = this->begin();
        auto str_2 = a.begin();
        int size_1 = size();
        int size_2 = a.size();
        int i = 0;

        while (i < size_1 && i < size_2 && str_1[i] == str_2[i]) i++;

        return i;
    }

};

class Patricia
{
public:
    typedef string::iterator string_pos;
    long long int words;
    static long long int acumulator;

    class Node;

    class Edge
    {
    public:
        String substr;
        Node *next;

        Edge(String& s) : Edge(s, new Node()) {}

        Edge(String& s, Node *n) : substr(s), next(n) {}
    };

    class Node
    {
    public:
        unordered_map< char, Edge* > v;
        long long int words;

        Node() : words(0) {}

        inline void Insert(string::const_iterator begin, string::iterator end)
        {
            String str(begin, end);
            Insert(str);
        }

        void Insert(string::const_iterator begin, string::iterator end, Node *n)
        {
            String s(begin, end);

            words += n->words;
            v[s[0]] = new Edge(s, n);
        }

        inline void Insert(const char s[])
        {
            String str(s);
            Insert(str);
        }

        void Insert(String& s)
        {
            auto it = v.find(s[0]);

            if (s.empty())
            {
                if (it == v.end())
                {
                    words++;
                    v['\0'] = new Edge(s);
                }
                return;
            }

            if (it == v.end())
            {
                words++;
                acumulator++;
                v[s[0]] = new Edge(s);
                v[s[0]]->next->Insert("");
            }
            else
            {
                Edge *e = it->second;
                int match_index = e->substr.Match(s);
                Node *tmp = e->next;

                if (e->substr.size() == match_index) // perfect match
                {
                    s.pos += match_index;
                    e->next->Insert("");
                    e->next->Insert(s);
                    s.pos -= match_index;
                    words++;
                    acumulator++;
                }
                else
                {
                    e->next = new Node();
                    e->next->Insert(s.begin() + match_index, s.end());
                    e->next->Insert(e->substr.begin() + match_index, e->substr.end(), tmp);
                    acumulator += e->next->words - 1;
                    e->substr.copy(e->substr.begin(), e->substr.begin() + match_index);

                    words++;
                    acumulator++;
                }
            }
        }
    };

    Node R;

    Patricia() : words(0) {
        acumulator = 0;
    }

    void Insert(String& s)
    {
        R.Insert(s);
    }
};

long long int Patricia::acumulator = 0; 

class Trie
{
public:
    class Node
    {
    public:
        Node **v;
        int paths;
        int num_str;
        int lbl;

        Node() : lbl(0), num_str(0), v(new Node*[26]), paths(0) {
            fill(v, v + 26, nullptr);
        }

        inline int Insert(const char str[])
        {
            int res = 0;
            int c;

            if (*str == '\0')
            {
                if (!lbl)
                {
                    lbl = 1;
                    return num_str;
                }
                else
                    return 0;
            }

            c = *str - 'a';
            num_str++;

            if (lbl)
                res++;

            if (v[c] == nullptr)
            {
                v[c] = new Node;
                paths++;
            }
            res += v[c]->Insert(str + 1);

            if (!lbl && paths == 2)
            {
                lbl = 1;
                res += num_str;
            }

            return res;
        }
    };

    Node R;
    long long int keystrokes;

    Trie() : keystrokes(0) {
        R.lbl = 1;
    }

    inline void Insert(const char str[])
    {
        keystrokes += R.Insert(str);
    }
};


void generate();

int main() {
    int N;

    //generate();

    while (scanf("%d\n", &N) != EOF)
    {
        char str[81];
        Trie T;

        for (int i = 0; i < N; ++i)
        {
            scanf("%s\n", str);
            T.Insert(str);
        }

        printf("%.2f\n", (double)T.keystrokes / (double)N);
    }
}

#include <fstream>

void generate()
{
    fstream stream("test.in", fstream::out);
    int n_test = 10;
    int N;

    srand(time(NULL));
    while (n_test--)
    {
        N = rand() % 100 + 1;
        set< string > S;

        stream << N << endl;
        while (N--)
        {
            bool valid = false;

            while (!valid)
            {
                int size = rand() % 80 + 1;
                string str;
                while (size--)
                {
                    str.push_back(rand() % 3 + 'a');
                }
                if (!FIND(S, str))
                {
                    valid = true;
                    stream << str << endl;
                }
            }
        }
    }


}