//  TEst driver for sorted array


#include <iostream>
#include "x_Array.h"
#include <cassert>


using namespace std;

void printArray( const X_Array  &);

void testone();
void testtwo();
void testthree();
void testfour();
void testfive();
void testsix();
///////////////////////////////////////////////////////////
// Our test procedure
// Create array1 and add 101 elements
//

int main ()
{

    cout << "Performing test one"<<endl;
    testone();
    cout << "Performing test two"<<endl;
    testtwo();
    cout << "Performing test three"<<endl;
    testthree();
    cout << "Performing test four"<<endl;
    testfour();
    cout << "Performing test five"<<endl;
    testfive();
    cout << "Performing test six"<<endl;
    testsix();



    cout << "Passed all tests"<<endl;
    return (0);
}

//////////////////////////////////////
// Test that an automatic and dynamic array 
//  extends appropriately and does not crash
/////////////////////////////////////////
void testone()
{

    X_Array a1;
    X_Array * pa = new X_Array();

    for ( int i = 0 ; i < 161 ; i++) {
	a1.add(i);
	pa -> add ( i*2);
    }

    assert ( a1.getSize() == 161);
    cout << "Print a1"<<endl;
    printArray(a1);
    cout << "Print *pa "<<endl;
    printArray(*pa);


    delete pa;
}



///////////////////////////////////////////
//  TEst for operator =
/////////////////////////////////////////
void testtwo()
{
    X_Array a1;
    for ( int i = 0 ; i < 50 ; i++) {
	a1.add(i);
    }

    X_Array a2 = a1;

    X_Array * pa= new X_Array();
    (*pa) = a2;


    cout << "Print a1"<<endl;
    printArray(a1);
    cout << "Print *pa "<<endl;
    printArray(*pa);

    delete pa;

}


///////////////////////////////////
// test for operator == iteratigvely
///////////////////////////////////
void testthree()
{
    X_Array a1;
    X_Array * pa;
    pa = new X_Array;

    for ( int i = 0 ; i < 101 ; i++) {
	a1.add(i);
	pa->add(i);
    }
    assert ( a1 == (*pa));

    a1.add(0);
    assert ( a1 != (*pa));
    delete pa;
}

//////////////////////////////////////////
//  TEsting for pathological operator =
///////////////////////////////////////
void testfour()
{
    X_Array a1;
    X_Array * pa = & a1;

    for ( int i = 0 ; i < 101 ; i++) {
	a1.add(i);
	pa->add(i);
    }

    a1 = *pa;

    assert ( a1 == a1);
    printArray(a1);
}

////////////////////////////////////////////
//  Testing the setAt and getAt function
////////////////////////////////////////////
void testfive()
{
    X_Array a1;
    for ( int i = 0 ; i < 20 ; i++) {
	a1.add(i);
    }

    assert ( a1.getAt(3) == 3);
    assert( a1.getAt(20) == 0);
    assert ( a1.getAt(19) == 19);
    a1.setAt(-1, 10);
    a1.setAt( 0, 10);
    assert ( a1.getAt(0) == 10);
    a1.setAt(20, -1);
    assert( a1.getSize() == 20);
    a1.add(100);
    assert ( a1.getSize ()== 21);
    assert ( a1.getAt(20) == 100);
}
   

//////////////////////////////////////////
//  Test the removeLast method
// ////////////////////////////////////////
void testsix()
{
    X_Array a1;
    a1.add(101);
    a1.add( 102);
    assert ( a1.getSize() == 2);
    a1.removeLast();
    assert( a1.getAt( 1) == 0);
    a1.removeLast();
    a1.removeLast();
    a1.removeLast();
    assert( a1.getSize() == 0);
    a1.add(99);
    assert( a1.getSize() == 1);
    assert( a1.getAt(0) == 99);

}
     


void printArray( const X_Array  & array)
{
    for ( int i = 0 ; i < array.getSize() ; i++) {
	cout << array.getAt(i) << "  ";
    }
    cout << endl;
}
