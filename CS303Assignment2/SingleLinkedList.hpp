#ifndef SINGLELINKEDLIST_HPP_
#define SINGLELINKEDLIST_HPP_
#include <iostream>

template<typename Item_Type>
class SingleLinkedList {
private:

	struct Node {
		Item_Type data;
		Node* next;

		Node(const Item_Type& data_item, Node* next_ptr = nullptr) :data(data_item), next(next_ptr) {}
	};

	Node* head;
	Node* tail;
	size_t numItems;

public:
	SingleLinkedList();
	void pushFront(Item_Type item);
	void pushBack(Item_Type item);
	Item_Type popFront();
	Item_Type popBack();
	Item_Type front();
	Item_Type back();
	bool isEmpty();
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);

	void display();
};

template<typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() {
	head = nullptr;
	tail = nullptr;
	numItems = 0;
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::pushFront(Item_Type item) {
	Node* newNode = new Node(item);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	numItems++;
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::pushBack(Item_Type item) {

	if (isEmpty()) {
		pushFront(item);
	}
	else {
		Node* newNode = new Node(item);
		tail->next = newNode;
		tail = newNode;
	}
	numItems++;
}

template<typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::popFront() {
	Item_Type returnItem = head->data;
	Node* toDelete = head;
	head = head->next;
	delete toDelete;
	numItems--;

	if (isEmpty()) {
		head = nullptr;
		tail = nullptr;
	}

	return returnItem;
}

template<typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::popBack() {
	//TODO
	Item_Type returnItem = tail->data;
	delete tail;
	numItems--;

	if (isEmpty()) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* tracker = head;

		while (tracker->next != nullptr) {
			tracker = tracker->next;
		}
		tail = tracker;
	}

	return returnItem;
}

template<typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::front() {
	return head->data;
}

template<typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::back() {
	return tail->data;
}

template<typename Item_Type>
bool SingleLinkedList<Item_Type>::isEmpty() {
	bool empty = false;
	if (numItems == 0) {
		empty = true;
	}

	return empty;
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
	if (index > numItems) {
		index = numItems;
	}

	if (isEmpty() || index == 0) {
		pushFront(item);
	}
	else if (index == numItems) {
		pushBack(item);
	}
	else {
		Node* newNode = new Node(item);
		Node* prevNode = head;

		for (int i = 0; i < index; i++) {
			prevNode = prevNode->next;
		}

		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}

	numItems++;
}

template<typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
	bool didRemove;
	if (index >= numItems || index < 0) {
		didRemove = false;
	}
	else {
		didRemove = true;
	}

	if (didRemove) {
		if (index == 0) {
			popFront();
		}
		else if (index == numItems - 1) {
			popBack();
		}
		else {
			Node* prevPtr = head;
			Node* pointerToDelete = head->next;
			for (int i = 0; i < index - 1; i++) {
				prevPtr = prevPtr->next;
				pointerToDelete = pointerToDelete->next;
			}

			prevPtr->next = pointerToDelete->next;
			delete pointerToDelete;
		}
	}

	return didRemove;
}

template<typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) {
	size_t indexFound = 0;

	Node* curPtr = head;

	while (curPtr != nullptr) {
		if (curPtr->data == item) {
			break;
		}
		curPtr = curPtr->next;
		indexFound++;
	}

	return indexFound;
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::display() {
	Node* curPtr = head;
	if (isEmpty()) {
		std::cout << "The list is empty!" << std::endl;
	}

	while (curPtr != nullptr) {
		if (curPtr->next == nullptr) {
			std::cout << curPtr->data;
		}
		else {
			std::cout << curPtr->data << " -> ";
		}
		curPtr = curPtr->next;
	}

	std::cout << std::endl;
}

#endif //SINGLELINKEDLIST_HPP_