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

	/*
	* A function which takes an item, creates a new node containing it, 
		and adds it to the front of the list

	* @param item - Item_Type item to used in the new node creation
	*/
	void pushFront(Item_Type item);

	/*
	* A function which takes an item, creates a new node containing it,
		and adds it to the back of the list

	* @param item - Item_Type item to used in the new node creation
	*/
	void pushBack(Item_Type item);

	/*
	* Deletes the current node at the front of the list, and sets the node following it as the new head
	*/
	Item_Type popFront();

	/*
	* Deletes the current node at the front of the list, and sets the node following it as the new tail
	*/
	Item_Type popBack();

	/*
	* Returns the item in the data private data member from the head node
	*/
	Item_Type front();

	/*
	* Returns the item in the data private data member from the tail node
	*/
	Item_Type back();

	/*
	* Returns true if the list is empty, false if not
	*/
	bool isEmpty();

	/*
	* Creates a new node containing item, and places it in the queue at the correct position, index.
	* 
	* @param index - The location to add the new node in the list. Index counting starts at 0
	* @param item - The Item_Type item used in the creation of the new node
	*/
	void insert(size_t index, const Item_Type& item);

	/*
	* Removes the node from the list at the inputed location, index.
	* 
	* @param index - The location of the list where to remove the node from.
	* 
	* return - True if node was able to be deleted, false otherwise.
	*/
	bool remove(size_t index);

	/*
	* Finds the first node containing the passed in item and returns its location.
	* 
	* @param item - the data that is attempting to be found.
	* 
	* return - the index of where the item is found. Size of list if item not found.
	*/
	size_t find(const Item_Type& item);

	/*
	* Displays the list and the number of items. Used for proof of functions working correctly.
	*/
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
		numItems++;
	}
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
	Item_Type returnItem = tail->data;
	numItems--;

	if (isEmpty()) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* curTracker = head;
		Node* prevTracker = head;

		while (curTracker->next != nullptr) {
			prevTracker = curTracker;
			curTracker = curTracker->next;
		}

		prevTracker->next = nullptr;
		tail = prevTracker;
		delete curTracker;
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

	if (index < 0) {
		index = 0;
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

		for (int i = 0; i < index - 1; i++) {
			prevNode = prevNode->next;
		}

		newNode->next = prevNode->next;
		prevNode->next = newNode;
		numItems++;
	}
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

			numItems--;
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
	else {
		while (curPtr != nullptr) {
			if (curPtr->next == nullptr) {
				std::cout << curPtr->data;
			}
			else {
				std::cout << curPtr->data << " -> ";
			}
			curPtr = curPtr->next;
		}

		std::cout << " | Num items: " << numItems << std::endl;
	}
}

#endif //SINGLELINKEDLIST_HPP_