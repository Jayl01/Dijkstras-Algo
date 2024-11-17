#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

template<typename Data>
struct ListNode
{
    public:
        ListNode* next;
        Data data;

        ListNode();

    private:
        friend class List<Data>;        //gives "List" access to ListElem values.
};

template<typename Data>
class List
{
    public:
        List();
        
        ~List();

        void Deconstruct();

        int Size() const;

        bool Empty() const;

        const Data& Front() const;

        const ListNode& FrontNode() const;

        const Data& End() const;

        const ListNode& EndNode() const;

        void AddElementFront(const Data& data);

        void RemoveElementFront();

        void RemoveElement(const Data& data);

        void InsertAfter(const Data& targetData, const Data& data);

    private:
        ListNode* head;
        int length;
};

template<typename Data>
ListNode<Data>::ListNode()
{
    next = nullptr;
    data = nullptr;
};

template<typename Data>
List<Data>::List()
{
    head = new ListNode();
    length = 0;
};

template<typename Data>
List<Data>::~List()
{
    /*while (!Empty())
        RemoveElementFront();

    delete head;*/
};

template<typename Data>
void List<Data>::Deconstruct()
{
    while (!Empty())
        RemoveElementFront();

    delete head;
}

template<typename Data>
int List<Data>::Size() const
{
    return length;
};

template<typename Data>
bool List<Data>::Empty() const
{
    return length <= 0 || head == nullptr;
};

template<typename Data>
const Data& List<Data>::Front() const
{
    return head->next->data;
};

template<typename Data>
const ListNode<Data>& List<Data>::FrontNode() const
{
    return head->next;
};

template<typename Data>
const Data& List<Data>::End() const
{
    ListNode* currNode = head;
    ListNode* prev = head;
    while (currNode != nullptr)
    {
        prev = currNode;
        currNode = currNode->next;
    }

    return prev->data;
};

template<typename Data>
const ListNode<Data>& List<Data>::EndNode() const
{
    ListNode* currNode = head;
    ListNode* prev = head;
    while (currNode != nullptr)
    {
        prev = currNode;
        currNode = currNode->next;
    }

    return prev;
};

template<typename Data>
void List<Data>::AddElementFront(const Data& data)
{
    ListNode* newNode = new ListNode();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    length += 1;
};

template<typename Data>
void List<Data>::InsertAfter(const Data& targetData, const Data& data)
{
    if (Empty())
        return;

    ListNode* currNode = head;
    while (currNode != nullptr)
    {
        if (currNode->data == targetData)
            break;

        currNode = currNode->next;
    }

    ListNode* newNode = new ListNode();
    newNode->data = data;
    newNode->next = currNode->next;
    currNode->next = newNode;
    length += 1;
}

template<typename Data>
void List<Data>::RemoveElement(const Data& targetData)
{
    if (Empty())
        return;

    ListNode* currNode = head;
    ListNode* prev = head;
    while (currNode != nullptr)
    {
        if (currNode->data == targetData)
            break;

        prev = currNode;
        currNode = currNode->next;
    }
    if (currNode == nullptr)
    {
        //Error: Data does not exist.
        return;
    }

    prev->next = currNode->next;
    delete currNode;
    length -= 1;
};

template<typename Data>
void List<Data>::RemoveElementFront()
{
    ListNode* oldHead = head;
    head = head->next;

    delete oldHead;
    length -= 1;
};

#endif