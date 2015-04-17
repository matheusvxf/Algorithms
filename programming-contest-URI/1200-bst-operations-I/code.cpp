#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)

class Node
{
public:
    Node *left, *right;
    char data;

    Node() : Node(0) {}
    Node(char data) : data(data), left(nullptr), right(nullptr) {}

    void Insert(char p_data)
    {
        if (p_data < data)
        {
            if (left == nullptr)
                left = new Node(p_data);
            else
                left->Insert(p_data);
        }
        else
        {
            if (right == nullptr)
                right = new Node(p_data);
            else
                right->Insert(p_data);
        }
    }

    bool Search(char p_data)
    {
        if (data == p_data)
            return true;
        if (left && p_data < data)
            return left->Search(p_data);
        else if (right)
            return right->Search(p_data);
        else 
            return false;
    }

    void Print_pre_order(stringstream& buffer)
    {
        buffer << " " << data;
        if (left)
            left->Print_pre_order(buffer);
        if (right)
            right->Print_pre_order(buffer);
    }

    void Print_in_order(stringstream& buffer)
    {
        if (left)
            left->Print_in_order(buffer);
        buffer << " " << data;
        if (right)
            right->Print_in_order(buffer);
    }

    void Print_pos_order(stringstream& buffer)
    {
        if (left)
            left->Print_pos_order(buffer);
        if (right)
            right->Print_pos_order(buffer);
        buffer << " " << data;
    }
};

class Tree
{
public:
    Node *root;

    Tree() : root(nullptr) {}

    void Insert(char data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            root->Insert(data);
        }
    }

    bool Search(char data)
    {
        if (root == nullptr)
            return false;
        else
            return root->Search(data);
    }

    void Print_pre_order()
    {
        stringstream buffer;
        char data;

        if (root)
            root->Print_pre_order(buffer);
        
        buffer >> data;
        cout << data;
        while (buffer >> data)
            cout << " " << data;

        cout << endl;
    }

    void Print_in_order()
    {
        stringstream buffer;
        char data;

        if (root)
            root->Print_in_order(buffer);

        buffer >> data;
        cout << data;
        while (buffer >> data)
            cout << " " << data;

        cout << endl;
    }

    void Print_pos_order()
    {
        stringstream buffer;
        char data;

        if (root)
            root->Print_pos_order(buffer);

        buffer >> data;
        cout << data;
        while (buffer >> data)
            cout << " " << data;

        cout << endl;
    }
};

int main() {
    string buffer;
    Tree T;

    while (cin >> buffer)
    {

        if (buffer == "INFIXA")
        {
            T.Print_in_order();
        }
        else if (buffer == "PREFIXA")
        {
            T.Print_pre_order();
        }
        else if (buffer == "POSFIXA")
        {
            T.Print_pos_order();
        }
        else
        {
            string data;

            cin >> data;

            if (buffer == "I")
            {
                T.Insert(data[0]);
            }
            else if (buffer == "P")
            {
                cout << data << ((T.Search(data[0]) == false) ? " nao existe\n" : " existe\n");
            }
        }
	}
}
