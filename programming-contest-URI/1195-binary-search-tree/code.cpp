#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

class Node
{
public:
    Node *left, *right;
    int data;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}

    void insert(int data)
    {
        if (data < this->data)
        {
            if (left == nullptr)
            {
                left = new Node(data);
            }
            else
            {
                left->insert(data);
            }
        }
        else
        {
            if (right == nullptr)
                right = new Node(data);
            else
                right->insert(data);
        }
    }

    void print_pre_order()
    {
        cout << " " << data;
        if (left)
            left->print_pre_order();
        if (right)
            right->print_pre_order();
    }

    void print_in_order()
    {
        if (left)
            left->print_in_order();
        cout << " " << data;
        if (right)
            right->print_in_order();
    }

    void print_pos_order()
    {
        if (left)
            left->print_pos_order();
        if (right)
            right->print_pos_order();
        cout << " " << data;
    }
};

class Binary_tree
{
public:
    Node *root;

    Binary_tree() : root(nullptr) {}

    void insert(int data)
    {
        if (root == nullptr)
            root = new Node(data);
        else
            root->insert(data);
    }

    void print_pre_order()
    {
        if (root == nullptr)
            return;
        root->print_pre_order();
    }

    void print_in_order()
    {
        if (root == nullptr)
            return;
        root->print_in_order();
    }

    void print_pos_order()
    {
        if (root == nullptr)
            return;
        root->print_pos_order();
    }
};

int main() {
    uint C, N, x;

    cin >> C;
    for (int i = 0; i < C; ++i)
    {
        Binary_tree T;
        cin >> N;

        for (int j = 0; j < N; ++j)
        {
            cin >> x;
            T.insert(x);
        }

        printf("Case %d:\n", i + 1);
        cout << "Pre.:";
        T.print_pre_order();
        cout << endl;
        cout << "In..:";
        T.print_in_order();
        cout << endl;
        cout << "Post:";
        T.print_pos_order();
        cout << endl << endl;        
    }
}
