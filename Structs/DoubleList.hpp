#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

using namespace std;

typedef string Data;

struct ListNode
{
    public:
        ListNode* prev;
        ListNode* next;
        Data data;

        ListNode();

    private:
        friend class DoubleList;        //gives "DoubleList" access to ListElem values.
};

class DoubleList
{
    public:
        DoubleList();
        
        ~DoubleList();

        void Deconstruct();

        int Size() const;

        bool Empty() const;

        const Data& Front() const;

        const Data& End() const;

        void AddElement(ListNode* targetNode, const Data& data);

        void RemoveElement(ListNode* targetNode);

        void AddElementFront(const Data& data);

        void AddElementEnd(const Data& data);

        void RemoveElementFront();

        void RemoveElementEnd();

    private:
        ListNode* head;
        ListNode* tail;
        int length;
};

#endif /* DOUBLElIST_H */