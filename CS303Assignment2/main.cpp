#include "SingleLinkedList.hpp"
#include <iostream>
#include <string>


int main() {
	
	//Single Linked List Testing
	SingleLinkedList<std::string> testList;

	std::cout << "pushFront() and pushBack() test: " << std::endl;
	testList.pushBack("Bob");
	testList.pushBack("Candice");
	testList.display();

	testList.pushFront("Abraham");
	testList.pushBack("Dan");
	testList.display();
	std::cout << std::endl;

	std::cout << "Front() test: " << testList.front() << std::endl;
	std::cout << "Back() test: " << testList.back() << std::endl << std::endl;

	std::cout << "popBack() and popFront() test: ";
	
	//Initial Test
	testList.popBack();
	testList.popFront();
	testList.display();
	
	//Test removing last item using popFront
	testList.popBack();
	testList.popFront();
	std::cout << "Test removing last item using popFront(): ";
	testList.display();

	//Test removing last item using popBack
	testList.pushBack("Bob");
	testList.popBack();
	std::cout << "Test removing last item using popBack(): ";
	testList.display();
	std::cout << std::endl;

	
	//Repopulate list
	std::cout << "Repopulating list: " << std::endl;
	testList.pushBack("Abraham");
	testList.pushBack("Candice");
	testList.pushBack("Dan");
	testList.pushBack("Eric");
	testList.pushBack("Fred");
	testList.display();
	std::cout << std::endl;

	//Insert test
	std::cout << "insert(1, \"Brandy\") test: ";
	testList.insert(1, "Brandy");
	testList.display();
	std::cout << std::endl;

	//Remove test
	std::cout << "remove(1) test: ";
	testList.remove(1);
	testList.display();
	std::cout << std::endl;

	//Item found test
	std::cout << "find(\"Candice\") test: ";
	std::cout << testList.find("Candice") << " (Should be 1)" << std::endl << std::endl;

	//Item not found test
	std::cout << "find(\"Bob\") test: ";
	std::cout << testList.find("Bob") << " (Should be 5)" << std::endl << std::endl;

	std::cout << "isEmpty() test: ";
	while (!testList.isEmpty()) {
		testList.remove(0);
	}
	testList.display();

	return 0;
}