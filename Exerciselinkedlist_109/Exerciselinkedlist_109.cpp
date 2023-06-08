#include <iostream>
#include <string>
using namespace std;

class Node {		//Allocate memory for the new node
public:
	int rollNumber;
	string name;
	Node* prev;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
	Node* habibah;
	Node* START;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node* habibah, Node* putri);
	bool listEmpty();
	bool dellNode();
	void traverse();
};

CircularLinkedList::CircularLinkedList() {
	START = NULL;
	habibah = NULL;	//Make previous point to NULL
};

void CircularLinkedList::addNode() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();	//Allocate memory for the new node
	cout << "Enter the roll number of the student: ";	//Assign value to the data field of the new node
	cin >> nim;
	cout << "Enter the name of the student: ";
	cin >> nama;
	nodeBaru->rollNumber = nim;
	nodeBaru->name = nama;

	/*insert a node in the beginning of a circular - linked list*/
	if (START == NULL || nim <= START->rollNumber) {
		if (START != NULL && nim == START->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		nodeBaru->next = START;
		START == nodeBaru;
		return;
	}
}

bool search(int rollno, Node** habibah, Node** putri) {
	* habibah = LAST->next;
	* putri = LAST->next;
}

bool CircularLinkedList::listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;
}

bool CircularLinkedList::dellNode() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	cout << "\nEnter the roll nuumber of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (CircularLinkedList::dellNode() == false)
		cout << "Record not found" << endl;
	else
		cout << "Record not found" << rollNo << " deleted" << endl;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST)
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
	}
	cout << LAST->rollNumber << "  " << LAST->name << endl;

}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.dellNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}