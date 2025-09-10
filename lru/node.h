#ifndef _NODE_H
#define _NODE_H

#include "types.h"

namespace dcll
{
class Node
{
friend class DcllImpl;
public:
	Node() {
		next = nullptr;
		prev = nullptr;
	}

	Node(data_t d)
	{
		data = d;
		next = nullptr;
		prev = nullptr;
	}
private:
	data_t data;
	Node* next;
	Node* prev;
};
} //namespace dcll
#endif
