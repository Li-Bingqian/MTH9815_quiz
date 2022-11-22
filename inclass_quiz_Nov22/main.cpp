//
//  main.cpp
//  inclass_quiz_Nov22
//
//  Created by Aubree Li on 11/22/22.
//

#include <iostream>
#include <vector>
#include "QuickSort.hpp"
#include "MaxHeap.hpp"


void print(int arr[], int n) {
    for (int i =0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main(int argc, const char * argv[]) {
    std::cout << "\n------- test quick sort --------\n";
    // create an array of integers
    int n = 10;
    int arr[n];
    for(int i = 0; i<10; i++) {
        arr[i] = rand();
    }
    print(arr, n);

    // call quick sort
    quick_sort(arr, 0, n-1);
    print(arr, n);

    std::cout << "\n------- test max heap --------\n";
    // add element to max heap
    MaxHeap mh;
    for (int i = 0; i < n; ++i) {
        mh.Add(rand());
    }
    // print the maxheap in list
    mh.print();
    
    // remove the max elem in the max heap one by one
    // i.e. remove the elem whose index is 0
    for (int i = 0; i < n; ++i) {
        std::cout << mh.Remove(0) << " ";
    }
    return 0;
    
    
}
