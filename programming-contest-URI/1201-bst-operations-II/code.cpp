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
    Node *left, *right, *parent;
    int data;

    Node() : Node(0) {}
    Node(int data) : Node(data, nullptr) {}
    Node(int data, Node *parent) : data(data), left(nullptr), right(nullptr), parent(parent) {}

    void Insert(int p_data)
    {
        if (p_data <= data)
        {
            if (left == nullptr)
                left = new Node(p_data, this);
            else
                left->Insert(p_data);
        }
        else
        {
            if (right == nullptr)
                right = new Node(p_data, this);
            else
                right->Insert(p_data);
        }
    }

    void Remove(int p_data)
    {
        if (p_data < data)
        {
            if (left)
                left->Remove(p_data);
        }
        else if (p_data > data)
        {
            if (right)
                right->Remove(p_data);
        }
        else
        {
            if (left == nullptr)
            {
                if (this == parent->left)
                {
                    parent->left = right;
                    if (parent->left)
                        parent->left->parent = parent;
                }
                else
                {
                    parent->right = right;
                    if (parent->right)
                        parent->right->parent = parent;
                }

                delete this;
            }
            else if (right == nullptr)
            {
                if (this == parent->left)
                {
                    parent->left = left;
                    if (parent->left)
                        parent->left->parent = parent;
                }
                else
                {
                    parent->right = left;
                    if (parent->right)
                        parent->right->parent = parent;
                }

                delete this;
            }
            else
            {
                Node *walk_node = left;

                while (walk_node->right)
                    walk_node = walk_node->right;

                if (walk_node->parent->right == walk_node)
                {
                    walk_node->parent->right = walk_node->left;

                    if (walk_node->left)
                        walk_node->left->parent = walk_node->parent;
                }
                else
                {
                    walk_node->parent->left = walk_node->left;

                    if (walk_node->left)
                        walk_node->left->parent = walk_node->parent;
                }

                data = walk_node->data;

                delete walk_node;
            }
        }
    }

    bool Search(int p_data)
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

    Tree() : root(new Node) {}

    void Insert(int data)
    {
        root->Insert(data);
    }

    void Remove(int data)
    {
        root->Remove(data);
    }

    bool Search(int data)
    {
        return root->Search(data);
    }

    void Print_pre_order()
    {
        stringstream buffer;
        int data;

        if (root->right)
        {
            root->right->Print_pre_order(buffer);

            buffer >> data;
            cout << data;
            while (buffer >> data)
                cout << " " << data;
        }

        cout << endl;
    }

    void Print_in_order()
    {
        stringstream buffer;
        int data;

        if (root->right)
        {
            root->right->Print_in_order(buffer);

            buffer >> data;
            cout << data;
            while (buffer >> data)
                cout << " " << data;
        }
        cout << endl;
    }

    void Print_pos_order()
    {
        stringstream buffer;
        int data;

        if (root->right)
        {
            root->right->Print_pos_order(buffer);

            buffer >> data;
            cout << data;
            while (buffer >> data)
                cout << " " << data;
        }

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
            int data;

            cin >> data;

            if (buffer == "I")
            {
                T.Insert(data);
            }
            else if (buffer == "P")
            {
                cout << data << ((T.Search(data) == false) ? " nao existe\n" : " existe\n");
            }
            else if (buffer == "R")
            {
                T.Remove(data);
            }
        }
	}
}
