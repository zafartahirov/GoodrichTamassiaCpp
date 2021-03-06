#include <iostream>

using namespace std;

// prototypes:
template <typename T> class SLinkedList;
template <typename T> ostream& operator<<(ostream&, const SLinkedList<T>&);

template <typename T>
class SNode {
private:
	T elem;			// element value
	SNode<T> *next;	// next item in the list

	friend class SLinkedList<T>;	// access to SLinkedList
};

template <typename T>
class SLinkedList {
public:
	SLinkedList();				// Empty list constructor
	~SLinkedList();				// Destructor
	bool empty() const;			// is the list empty?
	const T& front() const;// get the front element
	void addFront(const T& e);	// add to the front
	void removeFront();			// remove from the front
private:
	friend ostream& operator<< <T>(ostream&, const SLinkedList<T>&);
private:
	SNode<T>* head;			// Pointer to the head
};

template <typename T>
SLinkedList<T>::SLinkedList() : head(NULL) {}	// constructor

template <typename T>
SLinkedList<T>::~SLinkedList() {					// destructor
	while (!empty())
		removeFront();
}

template <typename T>
bool SLinkedList<T>::empty() const {			// empty?
	return head == NULL;
}

template <typename T>
const T& SLinkedList<T>::front() const {		// front element
	return head->elem;
}

template <typename T>
void SLinkedList<T>::addFront(const T& e) {
	SNode<T>* v = new SNode<T>;	// New node
	v->elem = e;
	v->next = head;
	head = v;
}

template <typename T>
void SLinkedList<T>::removeFront() {
	SNode<T>* old = head;
	head = old->next;
	delete old;
}

template <typename T>
ostream& operator<<(ostream& os, const SLinkedList<T>& SL) {
	SNode<T> *p = SL.head;
	os << "HEAD" << "->";
	while (p != NULL) {
		os << p->elem << "->";
		p = p->next;
	}
	// delete p;
	os << "NULL";
	return os;
}

//////////////////////////////////////
int main() {
	SLinkedList<string> a;
	a.addFront("MSP");
	cout << a << endl;
	a.addFront("LSB");
	cout << a << endl;
}



