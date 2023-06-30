#include "SingleLinkedList.hpp"
#include <iostream>
#include <string>


int main() {
	
	//Single Linked List Testing
	SingleLinkedList<std::string> testList;

	testList.pushBack("Adam");
	testList.pushBack("Bob");

	testList.display();


	//Professional Testing

	//Nonprofessional Testing

	return 0;
}