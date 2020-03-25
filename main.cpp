#include <stdio.h>
#include <iostream>

using namespace std;

int * countSortInt(int arr[], int start, int end, int num)
//input: array of integers, lowest number in array, highest value in array, and number of ints in array
//output: an sorted copy of the provided array
//-------------------------------------------------------------------
//Upsides:
// - simple implementation
// - useful if desire a copy of the array, rather than altering the original
//Downsides:
// - copy can be potentially expensive if the provided array is large
// - only works for integer values
//
//**Note: algorithm can be easily altered to alter the original array, rather than creating a copy since
//        storing of values is unrelated to the original array - only the initial counting requires the
//        original array
{
    int * sortArr = new int[num];               //array to store all the values in arr
    int * countArr = new int[end-start+1];      //create array that is the size of the number of possible values in arr
    
    for (int i = 0; i < num; ++i)
    {
        ++countArr[arr[i]-start];               //count number of each possible value, with index offset by the starting value
    }
    
    int next = 0;                               //variable to keep track of next position to store a value
    for(int i = 0; i < end-start+1; ++i)        //loop to run through the length of countArr (all possible values in arr)
    {
        for (int j = 0; j < countArr[i]; ++j)
        {
            sortArr[next] = i + start;          //value to be added to sortArr is equal to i + offset of start 
            ++next;
        }
    }
    
    return sortArr;
}

const int SIZE = 10;

int main()
{
    int myArr[SIZE] = { 1, 1, 4, 9, 5, 3, 7, 7, 9, 13 };
    
    int * myPtr = countSortInt(myArr, 1, 13, SIZE);
    
    for (int i = 0; i < SIZE; ++i)
        cout << myPtr[i] << " ";
    cout << endl;

    return 0;
}
