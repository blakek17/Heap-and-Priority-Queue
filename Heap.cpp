#ifndef HEAP_CPP
#define HEAP_CPP
#include "Heap.h"

template< typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(int maxNumber) {
	maxSize = maxNumber;
	size = 0;
	dataItems = new DataType[maxSize]{};
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(const Heap& other) {
	maxSize = 0;
	size = 0;
	dataItems = nullptr;
	*this = other; //Assignment operator overload function and clear() initalize size, maxSize, and dataItems
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>& Heap<DataType, KeyType, Comparator>::operator=(const Heap& other) {
	maxSize = other.maxSize;
	clear();
	if (!other.isEmpty()) {
		size = other.size;
		for (int i = 0; i < size; i++) {
			dataItems[i] = other.dataItems[i]; //Copy the data items from other heap into this one
		}
		//Starting from last parent index and going backward, heapify is called to ensure heap order in
		//case of minheap being copied to maxheap or vice versa
		for (int i = (int)floor((size - 2) / 2); i >= 0; i--) {
			heapify(i);
		}
	}
	return *this;
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::~Heap() {
	delete dataItems;
	dataItems = nullptr;
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::insert(const DataType& newDataItem) throw (logic_error) {
	if (isFull()) {
		throw logic_error("e");
	}
	int childIndex = size; //Size will increment by 1, so index of new item is current size
	int parentIndex = (int)floor((size++ - 1) / 2); //Size is incremented and new item's parent found
	while (childIndex > 0 && comparator(newDataItem.getPriority(), dataItems[parentIndex].getPriority())) {
		//Percolate up the heap, swapping parent and child when necessary
		dataItems[childIndex] = dataItems[parentIndex];
		childIndex = parentIndex;
		parentIndex = (int)floor((parentIndex - 1) / 2);
	}
	dataItems[childIndex] = newDataItem; //Insert new item with heap order maintained
}

template< typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType, KeyType, Comparator>::remove() throw (logic_error) {
	if (isEmpty()) {
		throw logic_error("e");
	}
	DataType removeItem = dataItems[0];
	dataItems[0] = dataItems[--size]; //Copy last item to root index and decrement size
	heapify(0); //Relocate root index item to restore heap order
	return removeItem;
}

template< typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::clear() {
	delete dataItems;
	dataItems = new DataType[maxSize]{};
	size = 0;
}

template< typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isEmpty() const {
	return size == 0;
}

template< typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isFull() const {
	return size == maxSize;
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::heapify(int index) {
	DataType item = dataItems[index]; //This is item to be relocated to maintain heap order
	//Swap through heap while not in heap order and item at current index has 2 children
	while (2 * index + 2 < size) {
		if (comparator(dataItems[2 * index + 1].getPriority(), item.getPriority()) &&
			comparator(dataItems[2 * index + 1].getPriority(), dataItems[2 * index + 2].getPriority())) {
			//Item at current index must swap with its left child
			dataItems[index] = dataItems[2 * index + 1];
			index = 2 * index + 1;
		}
		else if (comparator(dataItems[2 * index + 2].getPriority(), item.getPriority()) &&
			comparator(dataItems[2 * index + 2].getPriority(), dataItems[2 * index + 1].getPriority())) {
			//Item at current index must swap with its right child
			dataItems[index] = dataItems[2 * index + 2];
			index = 2 * index + 2;
		}
		else
			break;
	}
	if (2 * index + 1 < size &&
		comparator(dataItems[2 * index + 1].getPriority(), item.getPriority())) {
		//Only last parent can have 1 child. If this item is last parent and has 1 child,
		//check if swap is needed between them.
		dataItems[index] = dataItems[2 * index + 1];
		index = 2 * index + 1;
	}
	dataItems[index] = item; //Insert relocated item into its new index
}
#endif