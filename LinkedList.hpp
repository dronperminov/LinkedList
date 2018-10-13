#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T>
class LinkedList {
	struct Node {
		T value; // значение элемента списка
		Node *next; // указатель на следующий элемент списка
	};

	Node *head; // начало списка
	int length; // количество элементов списка

public:
	LinkedList(); // конструктор по умолчанию
	LinkedList(const LinkedList &list); // конструктор копирования

	int Length() const; // получение длины списка
	bool IsEmpty() const; // проверка списка на пустоту

	T& GetFirst(); // получение первого элемента списка: O(1)
	T& GetLast(); // получение последнего элемента списка: O(N)
	T& Get(int index); // получение элемента по индексу: O(N)

	void AddFront(const T& value); // добавление в начало списка: O(1)
	void AddBack(const T& value); // добавление в конец списка: O(N)
	void InsertAt(int index, const T& value); // добавление в произвольное место списка: O(N)

	void RemoveFront(); // удаление с начала списка: O(1)
	void RemoveBack(); // удаление с конца списка: O(N)
	void RemoveAt(int index); // удаление по индексу: O(N)
	void Remove(const T& value); // удаление элементов равных value: O(N)

	void Print() const; // печать списка

	~LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &list) {
	head = nullptr;
	length = list.length;

	Node *prev = nullptr;
	
	for (Node *orig = list.head; orig != nullptr; orig = orig->next) {
		Node *node = new Node;

		node->value = orig->value;
		node->next = nullptr;

		if (prev == nullptr) {
			head = node;
		}
		else {
			prev->next = node;
		}

		prev = node;
	}
}

template <typename T>
int LinkedList<T>::Length() const {
	return length;
}

template <typename T>
bool LinkedList<T>::IsEmpty() const {
	return length == 0;
}

template <typename T>
T& LinkedList<T>::GetFirst() {
	// если нет элементов, бросаем исключение
	if (IsEmpty())
		throw "LinkedList::GetFirst(): list is empty";

	return head->value; // возвращаем первый элемент
}

template <typename T>
T& LinkedList<T>::GetLast() {
	// если нет элементов, бросаем исключение
	if (IsEmpty())
		throw "LinkedList::GetLast(): list is empty";

	Node *node = head;

	// идём до последнего элемента
	while (node->next)
		node = node->next;

	return node->value; // возврашаем его знчение
}

template <typename T>
T& LinkedList<T>::Get(int index) {
	// если индекс вне границ
	if (index < 0 || index >= length)
		throw "LinkedList::Get(index): index out of bounds"; // бросаем исключение

	Node *node = head;

	// доходим до элемента с нужным индексом
	while (node != nullptr && index) {
		index--;
		node = node->next;
	}

	return node->value; // возвращаем его значение
}

template <typename T>
void LinkedList<T>::AddFront(const T& value) {
	Node *node = new Node; // создаём элемент

	node->value = value; // сохраняем значение
	node->next = head;

	head = node; // обновляем начало списка

	length++; // увеличиваем длину
}

template <typename T>
void LinkedList<T>::AddBack(const T& value) {
	Node *node = new Node; // создаём элемент

	node->value = value; // сохраняем значение
	node->next = nullptr;

	if (head == nullptr) { // если начала списка нет
		head = node; // то этот элемент и является началом
	}
	else {
		Node *prev = head;

		// иначе идём до последнего элемента
		while (prev->next)
			prev = prev->next;

		prev->next = node; // и обновляем указатель на следующий элемент
	}

	length++; // увеличиваем длину
}

template <typename T>
void LinkedList<T>::InsertAt(int index, const T& value) {
	if (index < 0 || index >= length)
		throw "LinkedList::InsertAt(index): index out of bounds";

	// если вставляем перед нулевым элементом
	if (index == 0) {
		AddFront(value); // то вставляем в начало
		return;
	}

	// доходим до элемента с индексом index - 1
	Node *prev = head;

	while (index - 1) {
		index--;
		prev = prev->next;
	}

	// создаём новый элемент и вставляем его
	Node *node = new Node;

	node->value = value;
	node->next = prev->next;
	prev->next = node;

	length++; // увеличиваем длину
}

template <typename T>
void LinkedList<T>::RemoveFront() {
	// если список пуст
	if (IsEmpty())
		throw "LinkedList::RemoveFront(): list is empty"; // бросаем исключение

	Node *tmp = head; // сохраняем значение текущего начала
	head = head->next; // переходим к следующему элементу
	delete tmp; // удаляем старое начало

	length--; // уменьшаем длину
}

template <typename T>
void LinkedList<T>::RemoveBack() {
	// если список пуст
	if (IsEmpty())
		throw "LinkedList::RemoveBack(): list is empty"; // бросаем исключение

	length--;

	if (head->next == nullptr) {
		delete head;

		head = nullptr;
		return;
	}

	Node *prev = head;

	// доходим до последнего элемента
	while (prev->next->next)
		prev = prev->next;
	
	delete prev->next;

	prev->next = nullptr;
}

template <typename T>
void LinkedList<T>::RemoveAt(int index) {
	// если индекс находится вне границ
	if (index < 0 || index >= length)
		throw "LinkedList::RemoveAt(index): index out of bounds"; // бросаем исключение

	// если удаляем из нулевого индекса
	if (index == 0) {
		RemoveFront(); // то удаляем из начала
		return;
	}

	Node *prev = nullptr;
	Node *node = head;

	while (index) {
		index--;

		prev = node;
		node = node->next;
	}

	prev->next = node->next;
	delete node;

	length--;
}

template <typename T>
void LinkedList<T>::Remove(const T& value) {
	// пока нужный элемент в начале списка
	while (!IsEmpty() && head->value == value)
		RemoveFront(); // удаляем из начала

	// если удалять больше нечего
	if (IsEmpty())
		return; // то выходим

	// запоминаем текущее и предыдущее значения элементов списка
	Node *prev = head;
	Node *node = head->next;

	// доходим до конца списка
	while (node != nullptr) {
		if (node->value == value) { // если нашли элемент для удаления, то удаляем его
			length--; // уменьшаем длину
			
			Node *tmp = node; // сохраняем адрес текущего элемента
			prev->next = node->next; // подменяем указатели

			delete tmp; // удаляем ненужный элемент

			node = prev;
		}

		prev = node;
		node = node->next; // переходим к следующему элементу
	}
}

template <typename T>
void LinkedList<T>::Print() const {
	if (IsEmpty())
		std::cout << "(empty)";
	
	Node *node = head;

	while (node != nullptr) {
		std::cout << node->value << " ";

		node = node->next;
	}
}

template <typename T>
LinkedList<T>::~LinkedList() {
	while (head) {
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
}

#endif