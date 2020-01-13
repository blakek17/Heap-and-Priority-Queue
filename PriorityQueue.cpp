//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1            PriorityQueue.cpp
//
//  ** SOLUTION: Heap implementation of the Priority Queue ADT **
//
//--------------------------------------------------------------------
#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP
using namespace std;
#include "PriorityQueue.h"
//--------------------------------------------------------------------
template < typename DataType, typename KeyType, typename Comparator >
PriorityQueue<DataType, KeyType, Comparator>::PriorityQueue(int maxNumber)
// Creates an empty priority queue.
	: Heap<DataType, KeyType, Comparator>(maxNumber)
{}
//--------------------------------------------------------------------
template < typename DataType, typename KeyType, typename Comparator >
void PriorityQueue<DataType, KeyType, Comparator>::enqueue(const DataType
	& newDataItem)
	// Inserts newDataItem into a priority queue.
{
	Heap<DataType, KeyType, Comparator>::insert(newDataItem);
}
//--------------------------------------------------------------------
template < typename DataType, typename KeyType, typename Comparator >
DataType PriorityQueue<DataType, KeyType, Comparator>::dequeue()
// Removes the least recently added (front) data item from a priority
// queue and returns it.
{
	return Heap<DataType, KeyType, Comparator>::remove();
}
#endif            // #ifndef PRIORITYQUEUE_CPP