#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>
 
using namespace std;

template <class T >
class Tree
{
public:
    class Node
    {
        friend class Tree;

        Node *left_, *right_, *parent_;
        T data_;

        Node(const T& data);
        Node(const T& data, Node *parent);
        void Insert(const T& data);
    };

    class Iterator
    {
        friend class Tree;

        enum State
        {
            kleft,
            kself,
            kright,
            kparent
        };

        State state_;
        Node *node_;
        
    public:
        Iterator();
        Iterator(Node *node_);
        const Iterator& operator++();
        const Iterator& next();
        T operator*() const;
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
    };

    Node *root_;

    Tree();
    void Insert(const T& data);
    Tree Intersection(const Tree& t) const;
    const Iterator begin() const;
    const Iterator end() const;
};

template <class T>
Tree<T>::Node::Node(const T& data) : Node(data, nullptr) {}

template <class T>
Tree<T>::Node::Node(const T& data, Node *parent) :
    data_(data), left_(nullptr), right_(nullptr), parent_(parent) {}

template <class T>
void Tree<T>::Node::Insert(const T& data)
{
    if (data < data_)
    {
        if (left_ == nullptr)
            left_ = new Node(data, this);
        else
            left_->Insert(data);
    }
    else if (data > data_)
    {
        if (right_ == nullptr)
            right_ = new Node(data, this);
        else
            right_->Insert(data);
    }
    else {}
}

template <class T>
Tree<T>::Iterator::Iterator() : Iterator(nullptr) {}

template <class T>
Tree<T>::Iterator::Iterator(Node *node) : node_(node) {}

template <class T>
bool Tree<T>::Iterator::operator==(const Iterator& it) const
{
    return node_ == it.node_;
}

template <class T>
bool Tree<T>::Iterator::operator!=(const Iterator& it) const
{
    return !((*this) == it);
}

template <class T>
const typename Tree<T>::Iterator& Tree<T>::Iterator::operator++()
{
    state_ = kright;

    if (node_ == nullptr)
        return (*this);

    return next();
}

template <class T>
const typename Tree<T>::Iterator& Tree<T>::Iterator::next()
{
    if (state_ == kleft)
    {
        if (node_->left_ != nullptr)
        {
            node_ = node_->left_;
            return next();
        }
        else
        {
            return (*this);
        }
    }
    else if (state_ == kself)
    {
        return (*this);
    }
    else if (state_ == kright)
    {
        if (node_->right_ != nullptr)
        {
            node_ = node_->right_;
            state_ = kleft;
            return next();
        }
        else
        {
            if (node_->parent_ == nullptr)
            {
                node_ = nullptr;
                return (*this);
            }
            else
            {
                state_ = (node_ == node_->parent_->left_ ? kself : kparent);
                node_ = node_->parent_;

                return next();
            }
        }
    }
    else // state_ == kparent
    {
        if (node_->parent_ == nullptr)
        {
            node_ = nullptr;
            return (*this);
        }
        else
        {
            state_ = (node_ == node_->parent_->left_ ? kself : kparent);
            node_ = node_->parent_;

            return next();
        }
    }
}

template <class T>
T Tree<T>::Iterator::operator*() const
{
    if (node_ == nullptr)
        return T();
    return node_->data_;
}

template <class T>
Tree<T>::Tree() : root_(nullptr) {}

template <class T>
void Tree<T>::Insert(const T& data)
{
    if (root_ == nullptr)
        root_ = new Node(data);
    else
        root_->Insert(data);
}

template <class T>
const typename Tree<T>::Iterator Tree<T>::begin() const
{
    Iterator it(root_);
    Node *&node = it.node_;

    while (node->left_ != nullptr)
        node = node->left_;

    return it;
}

template <class T>
const typename Tree<T>::Iterator Tree<T>::end() const
{
    return Iterator();
}

template <class T>
typename Tree<T> Tree<T>::Intersection(const Tree& t) const
{
    auto i = begin();
    auto j = t.begin();
    Tree intersection;

    while (i != end() && j != end())
    {
        if (*i == *j)
        {
            intersection.Insert(*i);
            i++;
        }
        else if (*i < *j)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return intersection;
}

int main()
{
    Tree< int > S, U;
    string str;
    stringstream buffer;
    int n;

    getline(cin, str);
    buffer.str(str);
    while (buffer >> n)
    {
        S.Insert(n);
    }
    getline(cin, str);
    buffer.clear(); buffer.str(str);
    while (buffer >> n)
    {
        U.Insert(n);
    }

    cout << "A: ";
    for (auto it = S.begin(); it != S.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << "B: ";
    for (auto it = U.begin(); it != S.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    Tree<int> inters = S.Intersection(U);
    for (auto it = inters.begin(); it != inters.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    
}