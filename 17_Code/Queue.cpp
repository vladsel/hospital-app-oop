#include "Queue.h"
#pragma warning (disable: 6386)

//destructor
Queue::~Queue() {
	if (!Empty())
		Delete();
}

//add element to the list
void Queue::Push(Medical_Institution *value) {
	struct list *temp = new list;
	temp->next = nullptr;
	if (beg_q == nullptr) {
		temp->field = value;
		beg_q = temp;
	}
	else {
		temp->field = value;
		end_q->next = temp;
	}
	end_q = temp;
}

//delete element from the list
void Queue::Pop() {
	if (!Empty()) {
		struct list *temp = beg_q;
		beg_q = beg_q->next;
		delete temp;
		if (beg_q == nullptr)
			end_q = nullptr;
	}
}

//output the list to stream
void Queue::Output(ostream &out) const {
	if (!Empty()) {
		struct list *temp = beg_q;
		while (temp != nullptr) {
			temp->field->Display(out);
			temp = temp->next;
		}
		cout << "\n";
	}
}

//input the list to stream
void Queue::Input(istream &in) {
	while (1) {
		int flag = -1;
		in >> flag;
		if (in.eof())
			break;
		Medical_Institution *temp = nullptr;
		if (flag == 0)
			temp = new Clinic();
		else if (flag == 1)
			temp = new Hospital();
		temp->Input(in);
		Push(temp);
	}
}

//delete the list
void Queue::Delete() {
	if (!Empty()) {
		struct list *temp = nullptr;
		while (beg_q != nullptr) {
			temp = beg_q;
			beg_q = beg_q->next;
			delete temp;
		}
		end_q = nullptr;
	}
}

//check the list for emptiness
bool Queue::Empty() const {
	return (!beg_q && !end_q);
}

//sort the list
void Queue::Sort() {
	if (!Empty()) {
		size_t n = Size();
		Medical_Institution **vec = new Medical_Institution * [n];
		struct list *temp = beg_q;
		size_t i = 0;
		while (temp != nullptr) { //move the values (field) from the list to the vector
			vec[i] = temp->field;
			temp = temp->next;
			i++;
		}

		bool flag = true;
		Medical_Institution *med_inst = nullptr;
		size_t r = n - 1;
		while (flag) {
			flag = false;
			for (i = 0; i < r; i++) {
				if (vec[i]->GetCity() > vec[i + 1]->GetCity()) { //sort the vector
					med_inst = vec[i];
					vec[i] = vec[i + 1];
					vec[i + 1] = med_inst;
					flag = true;
				}
			}
			r--;
		}

		temp = beg_q;
		i = 0;
		while (temp != nullptr) { //move the values from the vector to the list (field)
			temp->field = vec[i];
			temp = temp->next;
			i++;
		}
		delete[] vec; 
	}
}

//get list size
size_t Queue::Size() const {
	if (!Empty()) {
		int count = 0;
		struct list *temp = beg_q;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}
}

//do request in the list
int Queue::Task(string city_task) const {
	if (!Empty() && !city_task.empty()) {
		int sum = 0;
		bool flag = false;
		struct list *temp = beg_q;
		while (temp != nullptr) {
			while (temp->field->GetCity() == city_task) {
				sum += temp->field->GetDoctors();
				temp = temp->next;
				flag = true;
				if (temp == nullptr)
					break;
			}
			if (flag)
				break;
			temp = temp->next;
		}
		if (!flag) {
			cout << "\nerror, your city is wrong\n\n";
			return -1;
		}
		else
			return sum;
	}
	else {
		cout << "\nerror, your list is empty\n\n";
		return -1;
	}
}
