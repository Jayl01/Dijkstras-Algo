#ifndef DEQUE_H
#define DEQUE_H

#include <string>
#include "DoubleList.hpp"

using namespace std;

class Deque
{
	public:

		Deque();

		~Deque();

		void Deconstruct();

		int Size() const;

		bool Empty() const;

		const Data& Front() const;

		const Data& End() const;

		void InsertFront(const Data& elem);

		void InsertEnd(const Data& elem);

		void RemoveFront();

		void RemoveEnd();

	private:
		DoubleList list;
		int length;
};

#endif /* DEQUE_H */