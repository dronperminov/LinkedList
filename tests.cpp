#include <iostream>
#include <cassert>

#include "LinkedList.hpp"

using namespace std;

LinkedList<int> GetList(int n, int mode) {
	LinkedList<int> list;

	for (int i = 0; i < n; i++) {
		if (mode == 0) {
			list.AddBack(i + 1);
		}
		else if (mode == 1) {
			list.AddBack(n - i);
		}
		else {
			list.AddBack(1 + rand() % n);
		}
	}

	return list;
}

void AddFrontTests() {
	cout << "AddFrontTests:" << endl;

	LinkedList<int> list;

	assert(list.IsEmpty());

	list.AddFront(1);

	assert(!list.IsEmpty());
	assert(list.GetFirst() == 1);
	assert(list.GetLast() == 1);
	assert(list.Get(0) == 1);

	list.AddFront(2);

	assert(!list.IsEmpty());
	assert(list.GetFirst() == 2);
	assert(list.GetLast() == 1);
	assert(list.Get(0) == 2);
	assert(list.Get(1) == 1);

	cout << "OK" << endl;
}

void AddBackTests() {
	cout << "AddBackTests: " << endl;

	LinkedList<int> list;

	assert(list.IsEmpty());

	list.AddBack(1);

	assert(!list.IsEmpty());
	assert(list.Length() == 1);
	assert(list.GetFirst() == 1);
	assert(list.GetLast() == 1);
	assert(list.Get(0) == 1);

	list.AddBack(2);

	assert(!list.IsEmpty());
	assert(list.Length() == 2);
	assert(list.GetFirst() == 1);
	assert(list.GetLast() == 2);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 2);

	cout << "OK" << endl;
}

void InsertAtTests() {
	cout << "InsertAtTests:" << endl;

	LinkedList<int> list;

	list.AddBack(1); // 1
	list.AddBack(2); // 1 2

	list.InsertAt(0, 0);

	assert(!list.IsEmpty());
	assert(list.Length() == 3);
	assert(list.GetFirst() == 0);
	assert(list.GetLast() == 2);
	assert(list.Get(0) == 0);
	assert(list.Get(1) == 1);
	assert(list.Get(2) == 2);

	list.InsertAt(2, 4);

	assert(!list.IsEmpty());
	assert(list.Length() == 4);
	assert(list.GetFirst() == 0);
	assert(list.GetLast() == 2);
	assert(list.Get(0) == 0);
	assert(list.Get(1) == 1);
	assert(list.Get(2) == 4);
	assert(list.Get(3) == 2);

	list.InsertAt(0, 5);

	assert(!list.IsEmpty());
	assert(list.Length() == 5);
	assert(list.GetFirst() == 5);
	assert(list.GetLast() == 2);
	assert(list.Get(0) == 5);
	assert(list.Get(1) == 0);
	assert(list.Get(2) == 1);
	assert(list.Get(3) == 4);
	assert(list.Get(4) == 2);

	cout << "OK" << endl;
}

void RemoveFrontTests() {
	cout << "RemoveFrontTests:" << endl;

	LinkedList<int> list = GetList(5, 0);

	list.RemoveFront();

	assert(!list.IsEmpty());
	assert(list.Length() == 4);
	assert(list.Get(0) == 2);
	assert(list.Get(1) == 3);
	assert(list.Get(2) == 4);
	assert(list.Get(3) == 5);

	list.RemoveFront();

	assert(!list.IsEmpty());
	assert(list.Length() == 3);
	assert(list.Get(0) == 3);
	assert(list.Get(1) == 4);
	assert(list.Get(2) == 5);

	list.RemoveFront();

	assert(!list.IsEmpty());
	assert(list.Length() == 2);
	assert(list.Get(0) == 4);
	assert(list.Get(1) == 5);

	list.RemoveFront();

	assert(!list.IsEmpty());
	assert(list.Length() == 1);
	assert(list.Get(0) == 5);

	list.RemoveFront();

	assert(list.IsEmpty());
	assert(list.Length() == 0);

	cout << "OK" << endl;
}

void RemoveBackTests() {
	cout << "RemoveBackTests:" << endl;

	LinkedList<int> list = GetList(5, 0);

	list.RemoveBack();

	assert(!list.IsEmpty());
	assert(list.Length() == 4);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 2);
	assert(list.Get(2) == 3);
	assert(list.Get(3) == 4);

	list.RemoveBack();

	assert(!list.IsEmpty());
	assert(list.Length() == 3);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 2);
	assert(list.Get(2) == 3);

	list.RemoveBack();

	assert(!list.IsEmpty());
	assert(list.Length() == 2);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 2);

	list.RemoveBack();

	assert(!list.IsEmpty());
	assert(list.Length() == 1);
	assert(list.Get(0) == 1);

	list.RemoveBack();

	assert(list.IsEmpty());
	assert(list.Length() == 0);

	cout << "OK" << endl;
}

void RemoveAtTests() {
	cout << "RemoveAtTests:" << endl;

	LinkedList<int> list = GetList(5, 0);

	list.RemoveAt(2);

	assert(!list.IsEmpty());
	assert(list.Length() == 4);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 2);
	assert(list.Get(2) == 4);
	assert(list.Get(3) == 5);

	list.RemoveAt(1);

	assert(!list.IsEmpty());
	assert(list.Length() == 3);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 4);
	assert(list.Get(2) == 5);

	list.RemoveAt(2);

	assert(!list.IsEmpty());
	assert(list.Length() == 2);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 4);

	list.RemoveAt(0);

	assert(!list.IsEmpty());
	assert(list.Length() == 1);
	assert(list.Get(0) == 4);

	list.RemoveBack();

	assert(list.IsEmpty());
	assert(list.Length() == 0);

	cout << "OK" << endl;	
}

void RemoveTests() {
	cout << "RemoveTests:" << endl;

	LinkedList<int> list;

	list.AddBack(1);
	list.AddBack(2);
	list.AddBack(1);

	list.Remove(0);

	assert(!list.IsEmpty());
	assert(list.Length() == 3);
	assert(list.Get(0) == 1);
	assert(list.Get(1) == 2);
	assert(list.Get(2) == 1);

	list.Remove(1);

	assert(!list.IsEmpty());
	assert(list.Length() == 1);
	assert(list.Get(0) == 2);
	
	list.Remove(2);

	assert(list.IsEmpty());
	assert(list.Length() == 0);

	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(1);

	assert(!list.IsEmpty());
	assert(list.Length() == 6);

	list.Remove(1);

	assert(list.IsEmpty());
	assert(list.Length() == 0);

	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(2);
	list.AddBack(3);
	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(4);
	list.AddBack(1);
	list.AddBack(5);
	list.AddBack(1);
	list.AddBack(1);
	list.AddBack(1);

	assert(!list.IsEmpty());
	assert(list.Length() == 12);

	list.Remove(1);

	assert(!list.IsEmpty());
	assert(list.Length() == 4);
	assert(list.Get(0) == 2);
	assert(list.Get(1) == 3);
	assert(list.Get(2) == 4);
	assert(list.Get(3) == 5);

	cout << "OK" << endl;	
}

void IsSortedTests() {
	cout << "IsSortedTests:" << endl;
	LinkedList<int> list;

	assert(!list.IsSorted());

	list.AddBack(1);

	assert(list.IsSorted());

	list.AddBack(2);

	assert(list.IsSorted());

	list.AddBack(2);
	list.AddBack(3);

	assert(list.IsSorted());

	list.AddBack(1);

	assert(!list.IsSorted());

	cout << "OK" << endl;
}

void BubleSortTests() {
	cout << "BubleSortTests:" << endl;

	LinkedList<int> list1 = GetList(5, 0);
	LinkedList<int> list2 = GetList(5, 1);
	LinkedList<int> list3 = GetList(1000, 2);

	assert(list1.IsSorted());
	assert(!list2.IsSorted());

	list1.BubleSort();
	assert(list1.IsSorted());
	assert(list1.GetFirst() == 1);
	assert(list1.GetLast() == 5);
	assert(list1.Get(0) == 1);
	assert(list1.Get(1) == 2);
	assert(list1.Get(2) == 3);
	assert(list1.Get(3) == 4);
	assert(list1.Get(4) == 5);
	
	list2.BubleSort();
	assert(list2.IsSorted());
	assert(list2.GetFirst() == 1);
	assert(list2.GetLast() == 5);
	assert(list2.Get(0) == 1);
	assert(list2.Get(1) == 2);
	assert(list2.Get(2) == 3);
	assert(list2.Get(3) == 4);
	assert(list2.Get(4) == 5);

	list3.BubleSort();
	assert(list3.IsSorted());

	cout << "OK" << endl;
}

void SelectionSortTests() {
	cout << "SelectionSortTests:" << endl;

	LinkedList<int> list1 = GetList(5, 0);
	LinkedList<int> list2 = GetList(5, 1);
	LinkedList<int> list3 = GetList(1000, 2);

	assert(list1.IsSorted());
	assert(!list2.IsSorted());

	list1.SelectionSort();
	assert(list1.IsSorted());
	assert(list1.GetFirst() == 1);
	assert(list1.GetLast() == 5);
	assert(list1.Get(0) == 1);
	assert(list1.Get(1) == 2);
	assert(list1.Get(2) == 3);
	assert(list1.Get(3) == 4);
	assert(list1.Get(4) == 5);
	
	list2.SelectionSort();
	assert(list2.IsSorted());
	assert(list2.GetFirst() == 1);
	assert(list2.GetLast() == 5);
	assert(list2.Get(0) == 1);
	assert(list2.Get(1) == 2);
	assert(list2.Get(2) == 3);
	assert(list2.Get(3) == 4);
	assert(list2.Get(4) == 5);

	list3.SelectionSort();
	assert(list3.IsSorted());

	cout << "OK" << endl;
}

void MergeSortTests() {
	cout << "MergeSortTests:" << endl;

	LinkedList<int> list1 = GetList(5, 0);
	LinkedList<int> list2 = GetList(5, 1);
	LinkedList<int> list3 = GetList(1000, 2);

	assert(list1.IsSorted());
	assert(!list2.IsSorted());

	list1.MergeSort();
	assert(list1.IsSorted());
	assert(list1.GetFirst() == 1);
	assert(list1.GetLast() == 5);
	assert(list1.Get(0) == 1);
	assert(list1.Get(1) == 2);
	assert(list1.Get(2) == 3);
	assert(list1.Get(3) == 4);
	assert(list1.Get(4) == 5);
	
	list2.MergeSort();
	assert(list2.IsSorted());
	assert(list2.GetFirst() == 1);
	assert(list2.GetLast() == 5);
	assert(list2.Get(0) == 1);
	assert(list2.Get(1) == 2);
	assert(list2.Get(2) == 3);
	assert(list2.Get(3) == 4);
	assert(list2.Get(4) == 5);

	list3.MergeSort();
	assert(list3.IsSorted());

	cout << "OK" << endl;
}

int main() {
	AddFrontTests();
	AddBackTests();
	InsertAtTests();

	RemoveFrontTests();
	RemoveBackTests();
	RemoveAtTests();
	RemoveTests();

	IsSortedTests();
	BubleSortTests();
	SelectionSortTests();
	MergeSortTests();
}