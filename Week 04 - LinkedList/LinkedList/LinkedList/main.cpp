#include <iostream>

using namespace std;

template <typename T>
struct Node {
	Node* next;
	Node* prev;
	T data;
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	int getSize();
	void add(T data);
	bool remove(int index);
	void reverse();
	T get(int index);
};

template<typename T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template<typename T>
void LinkedList<T>::add(T data)
{
	Node<T>* val = new Node<T>();
	val->data = data;
	val->next = nullptr;
	size++;
	if (!head)
	{
		val->prev = nullptr;
		head = val;
		tail = val;
	}
	else
	{
		Node<T>* curr = head;
		while (curr->next)
			curr = curr->next;
		val->prev = curr;
		curr->next = val;
		tail = val;
	}
}

template<typename T>
bool LinkedList<T>::remove(int index)
{
	if (index > size - 1)
		return false;

	Node<T> *curr = head;
	size--;

	if (index == 0)
	{
		head = head->next;
		return true;
	}

	for (int i = 0; i < index - 1; i++)
	{
		curr = curr->next;
	}

	curr->next = curr->next->next;
	curr->next->prev = curr->next;
	return true;
}

template<typename T>
void LinkedList<T>::reverse()
{
	Node<T> *current = head;
	Node<T> *prev = nullptr, *next = nullptr;

	bool tr = true;

	while (current)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		if (tr) tail = current;

		current = next;
		tr = false;
	}

	tail = current;
	head = prev;
}

template<typename T>
T LinkedList<T>::get(int index)
{
	if (index > size - 1)
	{
		throw out_of_range("Index out of range!");
	}
	Node<int>* curr = head;
	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}
	return curr->data;
}

template<typename T>
LinkedList<T> merge(LinkedList<T> first, LinkedList<T> second) {

	for (int i = 0; i < second.getSize(); i++)
		first.add(second.get(i));

	return first;
}

int main() {
	LinkedList<int> list = LinkedList<int>();

	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);

	list.reverse();
	bool success = list.remove(6);
	int size = list.getSize();

	return 0;
}