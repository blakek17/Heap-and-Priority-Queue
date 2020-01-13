//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                test11pq.cpp
//
//  Test program for the operations in the Priority Queue ADT
//
//--------------------------------------------------------------------
#include <iostream>
#include <cctype>
#include "PriorityQueue.cpp"
#include "show11.cpp"
using namespace std;
void printHelp();
//--------------------------------------------------------------------
//
// Declaration for the priority queue data item class
//
class TestData
{
public:
	void setPriority(int newPriority)
	{
		priority = newPriority;
	}  // Set the priority
	int getPriority() const
	{
		return priority;
	}         // Returns the priority
private:
	int priority;                    // Priority for the data item
};
//--------------------------------------------------------------------
int main()
{
	PriorityQueue<TestData> testQueue(8);   // Test priority queue
	TestData testData;                 // Queue data item
	int inputPty;                      // User input priority
	char cmd;                          // Input command
	printHelp();
	do
	{
		testQueue.showStructure();                    // Output queue
		cout << endl << "Command (H for help): ";     // Read command
		cin >> cmd;
		cmd = toupper(cmd);                    // Normalize to uppercase
		if ((cmd == '+') || (cmd == '>'))
			cin >> inputPty;
		switch (cmd)
		{
		case '+':                                  // enqueue
			try {
				testData.setPriority(inputPty);
				cout << "Enqueue :  pty = " << testData.getPriority()
					<< endl;
				testQueue.enqueue(testData);
			}
			catch (logic_error) {
				cout << "Error: Queue is full" << endl;
			}
			break;
		case '-':                                  // dequeue
			try {
				testData = testQueue.dequeue();
				cout << "Dequeued :  pty = " << testData.getPriority()
					<< endl;
			}
			catch (logic_error) {
				cout << "Error: Queue is empty" << endl;
			}
			break;
		case 'C':
			cout << "Clear the queue" << endl;
			testQueue.clear();
			break;
		case 'E':                                  // isEmpty
			if (testQueue.isEmpty())
				cout << "Queue is empty" << endl;
			else
				cout << "Queue is NOT empty" << endl;
			break;
		case 'F':                                  // isFull
			if (testQueue.isFull())
				cout << "Queue is full" << endl;
			else
				cout << "Queue is NOT full" << endl;
			break;
		case 'H':                                  // Print out help menu
			printHelp();
			break;
		case 'Q':                                  // Quit test program
			break;
		default:                                   // Invalid command
			cout << "Invalid command" << endl;
		}
	} while (cmd != 'Q');
	return 0;
}
void printHelp() {
	cout << endl << "Commands:" << endl;
	cout << "  +x : Enqueue data item with priority x" << endl;
	cout << "  -  : Dequeue data item" << endl;
	cout << "  C  : Clear the queue" << endl;
	cout << "  E  : Empty queue?" << endl;
	cout << "  F  : Full queue?" << endl;
	cout << "  H  : Print this help message" << endl;
	cout << "  Q  : Quit the test program" << endl;
	cout << endl;
}