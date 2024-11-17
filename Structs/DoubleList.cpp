#include <string>
#include "DoubleList.hpp"

using namespace std;

//Normally we would do DoubleList:AddElemtnFront(etc, etc) but we're making the classes here instead

ListNode::ListNode()
{
    prev = next = nullptr;
    data = '0';
};

DoubleList::DoubleList()
{
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->prev = head;
    length = 0;
};

DoubleList::~DoubleList()
{
    /*while (!Empty())
        RemoveElementFront();

    delete head;
    delete tail;*/
};

void DoubleList::Deconstruct()
{
    while (!Empty())
        RemoveElementFront();

    delete head;
    delete tail;
}

int DoubleList::Size() const
{
    return length;
};

bool DoubleList::Empty() const
{
    return length <= 0 || head->next == tail;
};

void DoubleList::AddElement(ListNode* targetNode, const Data& data)     //inserts node before targetNode
{
    ListNode* newNode = new ListNode();
    newNode->data = data;
    newNode->next = targetNode;
    newNode->prev = targetNode->prev;
    targetNode->prev->next = newNode;
    length += 1;
};

void DoubleList::RemoveElement(ListNode* targetNode)
{
    ListNode* prev = targetNode->prev;
    ListNode* next = targetNode->next;

    prev->next = next;
    next->prev = prev;

    delete targetNode;
    length -= 1;
};

const Data& DoubleList::Front() const
{
    return head->next->data;
};

const Data& DoubleList::End() const
{
    return tail->prev->data;
};

void DoubleList::AddElementFront(const Data& data)
{
    AddElement(head->next, data);
};

void DoubleList::AddElementEnd(const Data& data)
{
    AddElement(tail, data);
};

void DoubleList::RemoveElementFront()
{
    RemoveElement(head->next);
};

void DoubleList::RemoveElementEnd()
{
    RemoveElement(tail->prev);
};