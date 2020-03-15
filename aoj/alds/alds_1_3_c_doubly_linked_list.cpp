// 双方向連結リスト
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_C

// g++ -std=c++11 xxx.cpp && ./a.out

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

struct Node
{
    uint64_t key;
    Node *next_ = nullptr;
    Node *prev_ = nullptr;
};

struct DLList
{
    Node *nil;
    DLList()
    {
        nil = new Node;
        nil->next_ = nil;
        nil->prev_ = nil;
    }

    // 連結リストの先頭にキー x を持つ要素を継ぎ足す
    void insert(uint64_t key)
    {
        Node *n = new Node();
        n->key = key;
        n->next_ = nil->next_;
        n->next_->prev_ = n;
        n->prev_ = nil;
        nil->next_ = n;
    }

    void delete_node(Node *node)
    {
        if (node == nil)
        {
            return;
        }
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
        delete node;
    }

    void delete_(uint64_t key)
    {
        Node *cur = nil->next_;
        while (cur != nil)
        {
            if (cur->key == key)
            {
                delete_node(cur);
                break;
            }
            cur = cur->next_;
        }
    }

    void deleteFirst()
    {
        delete_node(nil->next_);
    }

    void deleteLast()
    {
        delete_node(nil->prev_);
    }

    void write()
    {
        Node *cur = nil->next_;
        while (cur != nil)
        {
            cout << cur->key;
            cur = cur->next_;
            if (cur != nil)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
};

int main(void)
{
    int n;
    cin >> n;

    DLList list;

    char com[20];
    int key;

    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", com, &key);
        if (com[0] == 'i')
        {
            list.insert(key);
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                {
                    list.deleteFirst();
                }
                else if (com[6] == 'L')
                {
                    list.deleteLast();
                }
            }
            else
            {
                list.delete_(key);
            }
        }
    }

    list.write();

    return 0;
}