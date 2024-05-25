#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Clinic.h"
#include "Hospital.h"

struct list {
	Medical_Institution *field;
	list *next;
};

//queue class
class Queue {
public:
	Queue() : beg_q(nullptr), end_q(nullptr) {}
	~Queue();
	void Push(Medical_Institution *value);
	void Pop();
	void Output(ostream &out) const;
	void Input(istream &in);
	void Delete();
	bool Empty() const;
	void Sort();
	size_t Size() const;
	int Task(string city_task) const;
private:
	struct list *beg_q;
	struct list *end_q;
};

#endif // _QUEUE_H_