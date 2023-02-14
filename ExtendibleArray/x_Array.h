// homework03
// x_Array.h
// create an extendable 2d array with templates
#ifndef X_ARRAY_H
#define X_ARRAY_H
#include <iostream>



class X_Array {
	public:
		X_Array();
		X_Array( const X_Array &);
		~X_Array();

		// operators
		X_Array & operator = ( const X_Array &);
		bool operator == ( const X_Array &) const;
		bool operator != ( const X_Array &) const;

		void pushValue( int value);
		void grow();

		int add( int value);
		void removeLast();
		int getSize() const;
		int getAt( int index) const;
		void setAt( int index, int value);
	
	private:
		int ** dataArray;

		int currMax;
		int currLength;
		int arrCounter;
		int tempLength;
};

#endif
