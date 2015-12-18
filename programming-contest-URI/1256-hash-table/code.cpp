#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <string.h>

using namespace std;

class Hash{
public:
    class Node {
    public:
        Node *next;
        int data;

        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}

        void Insert(int data) {
            Node *atual = this;

            while(atual->next)
                atual = atual->next;

            atual->next = new Node(data);
        }

        void Print() {
            if(data)
                printf("%d -> ", data);
            if(next)
                next->Print();
        }
    };

    Node *hash_table;
    int M;

    Hash() : hash_table(nullptr) {}
    void Insert(int key) {
        int index = key % M;

        hash_table[index].Insert(key);
    }

    void SetSize(int M) {
        if(hash_table) {
            delete[]hash_table;
        }
        hash_table = new Node[M];
        this->M = M;
    }

    void Print() {
        int index = 0;

        while(index < M) {
            printf("%d -> ", index);
            hash_table[index].Print();
            printf("\\\n");
            index++;
        }
    }
};

int main(){
    int N;

    cin >> N;
    while(N--) {
        int M, C, key;
        Hash hash;
        cin >> M >> C;

        hash.SetSize(M);
        for(int i = 0; i < C; ++i) {
            cin >> key;
            hash.Insert(key);
        }

        hash.Print();
        if(N)
            printf("\n");
    }
}
