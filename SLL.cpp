#include <bits/stdc++.h>

using namespace std;

//Init LinkedList
struct MyLinkedList{
    int val;
    MyLinkedList* next; //Just iterator!!!!!!!
    MyLinkedList(int x) : val(x), next(nullptr) {};
};

//IN LinkedList
void printLinkedList (MyLinkedList* head)
{
    if(head == NULL)
    {
        cout<<"List is empty!";
    }
    else
    {
        MyLinkedList* newNode= head;
        while(newNode != NULL)
        {
            cout<<newNode->val;
            newNode=newNode->next;
            if(newNode != nullptr)
            {
                cout<<"->";
            }
            else cout<<endl;
        }
    }
}

MyLinkedList* addToHead(int n,MyLinkedList* Node)
{
    MyLinkedList* newNode= new MyLinkedList(n);
    if(Node==nullptr)
    {
        return newNode;
    }
    else
    {
        newNode->next=Node;
    return newNode;
    }
    return nullptr;
}

MyLinkedList* addToLast(int n, MyLinkedList* Node)
{
    MyLinkedList* newNode=new MyLinkedList(n);
    if(Node==nullptr) return newNode;
    else{
        MyLinkedList* last=Node;
        while(last->next != nullptr) last=last->next;
        last->next=newNode;
        return Node;
    }
    return nullptr;
}

MyLinkedList* addAtIndex(int value, int indice,MyLinkedList* Node)
{
    MyLinkedList* newNode=new MyLinkedList(value);
    if(Node == nullptr) return newNode;
    else{
        MyLinkedList* curNode=Node;
        for(int i=1;i<=indice-2;i++) curNode=curNode->next;
        newNode->next=curNode->next;
        curNode->next=newNode;
        return Node;
    }
    return nullptr;
}

MyLinkedList* eraseHeadNode (MyLinkedList* Node)
{
    if(Node==nullptr)
    {
        cout<<"Can't erase bcoz dont have any node!";
        return nullptr;
    }
    else{
        Node=Node->next;
        return Node;
    }
}

MyLinkedList* eraseLastNode (MyLinkedList* Node)
{
    if(Node != nullptr)
    {
        MyLinkedList* curNode=Node;
        while((curNode->next)->next != nullptr) curNode=curNode->next;
        curNode->next=nullptr;
    }
    return Node;
}

MyLinkedList* eraseAtIndex (int index, MyLinkedList* Node)
{
    if(Node!= nullptr)
    {
        MyLinkedList* curNode=Node;
        while(index >2)
        {
            curNode=curNode->next;
            index--;
        }
        curNode->next=(curNode->next)->next;
    }
    return Node;
}

MyLinkedList* deleteDuplicates(MyLinkedList* head)
{
    MyLinkedList* newNode = head;
    while(head->next != nullptr)
    {
        if(head->val == (head->next)->val )
        {
            head->next=(head->next)->next;
        }
        else head=head->next;
    }
    return newNode;
}

MyLinkedList* insertt( MyLinkedList* head,int value)
{
    MyLinkedList* newNode = head;
    int index=0;
    while (head != nullptr && head->val < value)
    {
        index++;
        head=head->next;
    }
    if(head == nullptr)
    {
        return addToLast(value,newNode);
    }
    else{
        return addAtIndex(value,index+1,newNode);
    }

}
int main()
{
    MyLinkedList* n1=new MyLinkedList(1);
    MyLinkedList* n2=new MyLinkedList(2);
    MyLinkedList* n3=new MyLinkedList(3);
    MyLinkedList* n4=new MyLinkedList(4);
    n1->next=n2;
    n2->next=n3;
    printLinkedList(n1);
    printLinkedList(n2);
    printLinkedList(n3);
    printLinkedList(addToHead(71,n1));
    printLinkedList(addToHead(71,n1));
    printLinkedList(addToLast(56,n1));
    printLinkedList(addToLast(56,n1));
    printLinkedList(addToLast(56,n1));
    printLinkedList(addToLast(56,n1));
    printLinkedList(addToLast(99,n1));
    printLinkedList(addToLast(99,n1));
    printLinkedList(addToLast(99,n1));
    printLinkedList(addToLast(99,n1));
    printLinkedList(addAtIndex(455,4,n1));
    printLinkedList(eraseAtIndex(4,n1));
    cout<<"DUNG INSERT"<<endl;
    printLinkedList(insertt(n1,45));
    cout<<"DUNG DELETE"<<endl;
    printLinkedList(deleteDuplicates(n1));
    return 0;
}
