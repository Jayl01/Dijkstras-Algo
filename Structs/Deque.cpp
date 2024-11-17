
#include <string>
#include "Deque.hpp"

using namespace std;

Deque::Deque()
{
	list = *new DoubleList();
	length = 0;
}

Deque::~Deque()
{
	//length = 0;
}

void Deque::Deconstruct()
{
	length = 0;
}

int Deque::Size() const
{
	return length;
}

bool Deque::Empty() const
{
	return length <= 0;
}

const Data& Deque::Front() const
{
	return list.Front();
};

const Data& Deque::End() const
{
	return list.End();
};

void Deque::InsertFront(const Data& elem)
{
	list.AddElementFront(elem);
	length++;
};

void Deque::InsertEnd(const Data& elem)
{
	list.AddElementFront(elem);
	length++;
};

void Deque::RemoveFront()
{
	list.RemoveElementFront();
	length--;
};

void Deque::RemoveEnd()
{
	list.RemoveElementEnd();
	length--;
};
