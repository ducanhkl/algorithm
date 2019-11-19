#include <bits/stdc++.h>

using namespace std;

class Qnode
{
public:
    int val;
    Qnode *nextNode;
    Qnode()
    {
        nextNode = nullptr;
    }
};

class Queue
{
public:
    Qnode *head, *near;
    int sz;
    Queue()
    {
        head = near = NULL;
        sz = 0;
    }
    void push_head(int k)
    {
        sz++;
        Qnode *temp = new Qnode;
        temp->val = k;
        if (head == nullptr)
        {
            head = near = temp;
            head -> nextNode = temp;
            return ;
        }
        temp->nextNode = head;
        head = temp;
    }
    void push_near(int k)
    {
        sz++;
        Qnode *temp = new Qnode;
        temp->val = k;
        temp->nextNode = nullptr;
        if (near == nullptr)
        {
            head = near = temp;
            head -> nextNode = temp;
            return ;
        }
        near->nextNode = temp;
        near = temp;
    }
    bool deleteNode(int k)
    {
        if (sz <= k)
            return false;
        int counter = 0;
        Qnode *now = head, *pre = nullptr;
        while (counter != k)
            {
                counter ++;
                pre = now;
                now = now->nextNode;
            }
        if (pre == nullptr)
        {
            Qnode *p = head;
            head = head->nextNode;
            sz --;
            if (sz == 0)
                head = near = nullptr;
            delete p;
            return true;
        }
        sz --;
        if (sz == counter )
        {
            delete now;
            near->nextNode = near = pre;
            return true;
        }
        pre->nextNode = now->nextNode;
        delete now;
        return true;
    }
    int findVal(int k)
    {
        int counter = 0;
        Qnode *temp = head;
        while (temp != nullptr && temp->val != k)
            temp = temp->nextNode, counter ++;
        if (temp->val == k)
            return counter;
        else
            return -1;
    }
    void show()
    {
        cout << near->val << endl;
    }
};


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s;
    Queue q;
    while (cin >> s)
    {
        if (s == "push")
        {
            int x;
            cin >> x;
            q.push_near(x);
        }
        if (s == "show")
        {
            if (q.sz == 0)
                cout << "empty" << endl;
            else
                q.show();
        }
        if (s == "pop")
        {
            q.deleteNode(q.sz - 1);
        }
    }
    return 0;
}
