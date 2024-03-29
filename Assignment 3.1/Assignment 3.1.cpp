// Assignment 3.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector> // this 
#include <cstdlib> // for rand
#include<chrono>// for timings (I had to look this up!)

// Disclaimer: I looked up how to use the chrono library! 

using namespace std;
using namespace std::chrono; //for timings!

// function called SelectionSort(vector)
// typeReturned functionName(argument1, arg2,...)
microseconds selectionSort(vector<int>& numbers);
microseconds insertionSort(vector<int>& insertionSortNumbers);

// defining the sizes of the arrays
const int SMALLEST = 100;
const int MEDIUM = 1000;
const int LARGE = 10'000;
const int EXTREME = 100'000;

int main()
{
    // need someplace to store all the data, and a size

    // fill up the array with random data of 'size' elmts;
    vector<int> smallestArray(SMALLEST);// makes a list of numbers of 'size' length
    vector<int> mediumArray(MEDIUM);
    vector<int> largeArray(LARGE);
    vector<int> extremeArray(EXTREME);

    // loop of some kind to get random data
    // loop from index 0 to index < size, adn for each index in n[], 

    // Fill up our arrays with random numbers
    for(int index = 0; index < SMALLEST; index++) {
        smallestArray[index] = mediumArray[index] = largeArray[index] = extremeArray[index] = rand();
    }// now done with smallestArray
	for (int index = SMALLEST; index < MEDIUM; index++) {
		mediumArray[index] = largeArray[index] = extremeArray[index] = rand();
	}
	for (int index = MEDIUM; index < LARGE; index++) {
		int value = rand();
		largeArray[index] = extremeArray[index] = rand();
	}
	for (int index = LARGE; index < EXTREME; index++) {
		extremeArray[index] = rand();
	}


    // 1. call our sorting alogrithm on our array
    //selectionSort(numbers2sort);
	microseconds time1 = selectionSort(smallestArray);
	microseconds time2 = selectionSort(mediumArray);
	microseconds time3 = selectionSort(largeArray);
	microseconds time4 = selectionSort(extremeArray);

    // print out the times for each of these
    cout << "smallestArray sorted in " << time1.count() << " microseconds\n";
	cout << "mediumArray sorted in " << time2.count() << " microseconds\n";
	cout << "largeArray sorted in " << time3.count() << " microseconds\n";
	cout << "extremeArray sorted in " << time4.count() << " microseconds\n";


    return 0;
}

// selection sort looks at each index in the array and finds the index'th smallest value
// for spot 0, it finds the smallest value
// for spot 1, it looks at rest of array and find the smallset value


// Selection sort goes through every index ('spot' in the code)
// and from index 'spot' to the end (this numbers[spot..end] is what we call 'subarray')
// it tries to find the smallest element
// so if spot=50 and size = 100, it looks for smallest value in numbers[50..99]
microseconds selectionSort(vector<int>& numbers){
	auto start = high_resolution_clock::now();// get the starting time
    for (int spot = 0; spot < numbers.size(); spot++) {// this goes through every spot in the array
        // for each of those spots we search the array from 'spot' to end and find the smallest value
        int smallestIndex = spot;// 10,20,5,2
        for(int index = spot; index < numbers.size(); index++) {//THIS IS SOURCE OF DIFFERENCE; SelSort goes through ENTIRE subarray
            if(numbers[index]<numbers[smallestIndex]) {
                smallestIndex = index;
            }
        }
        // now we have the index of the smallest value in numbers[spot...end]
        std::swap(numbers[spot], numbers[smallestIndex]);
        // index dne
    }
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	return duration;
}

// Insertion sort goes through every index ('i' in the code)
// and from index 'i' to the beginning (this numbers[0..i] is what we call 'subarray')
// it DOES NOT try to find the smallest element, 
// but instead just swaps values that are out of order; so if it sees a bigger value BEFORE a smaller value, then it swaps them
// but it will stop if numbers[j] is > than numbers[i]
// element i is fixed for each run; elment j will change as long as condition holds
// but this condition--while(j >= 0 && numbers[j] > value)-- can end earlier than when we hit beginnig of array
// so we don't have to look at every single element!
microseconds insertionSort(vector<int>& numbers) {
    auto start = high_resolution_clock::now();// get the starting time
	for (int i = 1; i < numbers.size(); i++) {
		// for each of those spots we search the array from 'spot' to end and find the smallest value

        int value = numbers[i];
        int j = i - 1;
		while(j >= 0 && numbers[j] > value) {// THIS IS WNY INSERTION SORT IS FASTER
            numbers[j + 1] = numbers[j];// 
            j--;// move j down one
        }
        numbers[j + 1] = value;
		// now we have the index of the smallest value in numbers[spot...end]
		// index dne
	}
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration;
}
