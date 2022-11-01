pragma once

struct Node
{
	Node(int d, Node* p = nullptr)
		: data(d)
		, next(p)
	{}

	int data;
	Node* next;
};

class Set
{
public:
	Set() : m_head(nullptr) {}
	Set(int* a, int n);

	void insert(int value);
	bool contains(int value) const;
	Set merge(const Set& other) const;

	void print() const;

private:
	Node* m_head;
};
Set::Set(int* a, int n)
	: m_head(nullptr)
{
	for (int i = 0; i < n; ++i) {
		insert(a[i]);
	}
}

void Set::insert(int value)
{
	Node* ptr = m_head;
	Node* ptrPrev = nullptr;
	while (ptr && ptr->data < value) {
		ptrPrev = ptr;
		ptr = ptr->next;
	}

	if (ptr && ptr->data == value) {
		std::cout << "existing value, skipping " << value << std::endl;
		return;
	}

	if (ptrPrev == nullptr) {
		m_head = new Node(value, m_head);
	} else {
		ptrPrev->next = new Node(value, ptrPrev->next);
	}
}

void Set::print() const
{
	Node* ptr = m_head;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

bool Set::contains(int value) const
{
	Node* ptr = m_head;
	while (ptr && ptr->data < value) {
		ptr = ptr->next;
	}

	return ptr && ptr->data == value;
}

Set Set::merge(const Set& other) const
{
	Set res;

	Node* ptr1 = m_head;
	Node* ptr2 = other.m_head;
	Node* tail = nullptr;

	while (ptr1 && ptr2) {
		int dataToInsert = ptr1->data;
		if (ptr1->data < ptr2->data) {
			ptr1 = ptr1->next;
		} else if (ptr2->data < ptr1->data) {
			dataToInsert = ptr2->data;
			ptr2 = ptr2->next;
		} else {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		if (tail == nullptr) {
			tail = res.m_head = new Node(dataToInsert);
		} else {
			tail = tail->next = new Node(dataToInsert);
		}
	}

	while (ptr1) {
		tail = tail->next = new Node(ptr1->data);
		ptr1 = ptr1->next;
	}

	while (ptr2) {
		tail = tail->next = new Node(ptr2->data);
		ptr2 = ptr2->next;
	}

	return res;
}


//task  11.5//
#include <queue>
#include <stack>

#include <iostream>

int main()
{
	std::queue<int> q1;
	std::queue<int> q2;

	for (int i = 0; i < 7; ++i) {
		q1.push(i);
		q2.push(2 * i + 1);
	}

	std::queue<int> q3;
	while (!q1.empty()) {
		q3.push(q1.front());
		q1.pop();
	}

	std::stack<int> s;
	while (!q2.empty()) {
		s.push(q2.front());
		q2.pop();
	}

	while (!s.empty()) {
		q3.push(s.top());
		s.pop();
	}

	while (!q3.empty()) {
		std::cout << q3.front() << " ";
		q3.pop();
	}

	system("pause");
	return 0;
}
