// x_Array.cpp
#include "x_Array.h"
#include <iostream>
#include <cassert>



// Constructor
X_Array::X_Array() {
	dataArray = new int *[1];
	dataArray[0] = new int[10];

	currLength = 0;
	tempLength = 0;
	currMax = 10;
	arrCounter = 0;
}

// Copy Constructor
X_Array::X_Array( const X_Array & rhs) {
	/*currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;

	int ** temp = new int *[arrCounter];
	for ( int i = 0; i < currMax / 10; i++) {
		temp[i] = rhs.dataArray[i];
	}
	
	dataArray = temp;*/

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;
	dataArray = new int *[currLength/10];
	for (int j = 0; j < currLength/10; j++) {
		dataArray[i] = new int[10];

		for (int k = 0; k < 10; k++) {
			dataArray[j][k] = rhs.dataArray[j][k];
		}
	}

}

// Destructor
X_Array::~X_Array() {
	for (int i = 0; i < arrCounter + 1; i++) {
		delete [] dataArray[i];
	}
	delete [] dataArray;
}



// Operator = 
X_Array & X_Array::operator = ( const X_Array & rhs) {
	/*if ( this == & rhs) {
		return * this;
	}

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;

	int ** temp = new int *[arrCounter];
	for ( int i = 0; i < currMax / 10; i++) {
		temp[i] = rhs.dataArray[i];
	}
	delete [] dataArray;
	dataArray = temp;

	return * this;*/
	if ( *this == rhs) {
		return * this;
	}
	for (int i = 0; i < currLength/10; i++) {
		delete [] dataArray[i];
	}
	delete [] dataArray;

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;
	dataArray = new int *[currLength/10];
	for (int j = 0; j < currLength/10; j++) {
		dataArray[i] = new int[10];

		for (int k = 0; k < 10; k++) {
			dataArray[j][k] = rhs.dataArray[j][k];
		}
	}
}

// Operator == 
bool X_Array::operator == ( const X_Array & rhs) const {
	if ( this->currMax != rhs.currMax) {
		return false;
	}
	if ( this->currLength != rhs.currLength) {
		return false;
	}

	// complete row checker
	for ( int j = 0; j < arrCounter; j++) {
		for ( int i = 0; i < 10; i++) {
			if ( this->dataArray[j][i] != rhs.dataArray[j][i]) {
				return false;
			}
		}
	}

	// incomplete row checker
	for ( int k = 0; k < tempLength; k++) {
		if ( this->dataArray[arrCounter][k] != rhs.dataArray[arrCounter][k]) {
			return false;
		}
	}
	return true;
}

// Operator !=
bool X_Array::operator != ( const X_Array & rhs) const {
	if ( X_Array::operator == (rhs)) {
		return false;
	}
	return true;
}



//////////////////////////////////////////
// Grow dataArray when dataArray
// reaches a multiple of 10
//////////////////////////////////////////
void X_Array::grow() {
	arrCounter++;
	tempLength = 0;
	currMax = currMax + 10;
	
	int ** temp = new int *[arrCounter + 1];

	for ( int i = 0; i < arrCounter; i++) {
		temp[i] = dataArray[i];
	}

	temp[arrCounter] = new int[10];


	delete dataArray;


	dataArray = temp;
	
}

//////////////////////////////////////////
// Push a given value onto dataArray
// and increase count variables
//////////////////////////////////////////
void X_Array::pushValue( int value) {
	dataArray[arrCounter][tempLength] = value;
	tempLength++;
	currLength++;
}

//////////////////////////////////////////
// Add an element to the end of the array
// return the index where we added the element
//  This call will automatically grow our memory
//  as needed
//////////////////////////////////////////
int X_Array::add( int value) {
	// if dataArray needs to hold 4 pointers to other arrays: dataArray = new int *[4];
	/*if ( currLength == currMax) {
		grow();
		pushValue( value);
		return currLength - 1;
	}
	else {
		pushValue( value);
		return currLength - 1;
	}*/
	if ( currLength < currMax) {
		int newLoc = currLength;
		int masterIndex = newLoc/10;
		int locIndex = newLoc % 10;
		dataArray[masterIndex][locIndex] = value;
		currLength++;
	}
	else {
		int numMasterElements = currLength/10;
		int ** temp = new int * [numMasterElements + 1];
		for (int i = 0; i < numMasterElements; i++) {
			temp[i] = dataArray[i];
		}
		temp[numMasterElements] = new int[10];
		delete dataArray;
		dataArray = temp;
		currMax = currMax + 10;
		add( value);
	}
	return currLength - 1;
}

//////////////////////////////////////////
// Delete the last element in the array
//////////////////////////////////////////
void X_Array::removeLast() {
	if ( currLength > 0) {
		currLength--;
		tempLength--;
		dataArray[arrCounter][tempLength] = 0;
	}
}

//////////////////////////////////////////
// Get the current number of elements in the array
//////////////////////////////////////////
int X_Array::getSize() const {
	return currLength;
}

//////////////////////////////////////////
// Get the element at the index
// return 0 if the index is out of bounds
//////////////////////////////////////////
int X_Array::getAt( int index) const {
	int intCounter = 0;
	if ( index < currMax && index >= 0) {
		while ( index >= 10) {
			index = index - 10;
			intCounter++;
		}
		return dataArray[intCounter][index];
	}
	else {
		return 0;
	}
}

//////////////////////////////////////////
// setAt.  Puts the value at a specific location
// fails silently if index is out
// of bounds
//////////////////////////////////////////
void X_Array::setAt( int index, int value) {
	int intCounter = 0;
	if ( index < currMax && index >= 0) {
		while ( index >= 10) {
			index = index - 10;
			intCounter++;
		}
		dataArray[intCounter][index] = value;
	}
}
