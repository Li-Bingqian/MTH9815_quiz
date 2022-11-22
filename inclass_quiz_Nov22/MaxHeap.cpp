//
//  MaxHeap.cpp
//  inclass_quiz_Nov22
//
//  Created by Aubree Li on 11/22/22.
//

#include "MaxHeap.hpp"
#include <iostream>

MaxHeap::MaxHeap() : size(0) {}

// get left child index
int MaxHeap::get_left(int i) {
    return i * 2 + 1;
}

// get right child index
int MaxHeap::get_right(int i) {
    return i * 2 + 2;;
}

// get parent index
int MaxHeap::get_parent(int i) {
    return (i-1) / 2;;
}

void MaxHeap::heapify_up (int i) {
    if (i > 0 && v[get_parent(i)] < v[i]) {
        // swap the two if heap property is violated
        // i.e if parent(i) < i's value
        std::swap(v[get_parent(i)], v[i]);
        // call heapify_up on i's parent
        heapify_up(get_parent(i));
    }
}


void MaxHeap::heapify_down(int i) {
    int l = get_left(i);
    int r = get_right(i);
    int largest;
    // find the largest among three nodes
    largest = (l <= size && v[l] > v[i]) ? l : i;
    largest = (r <= size && v[r] > v[largest]) ?
    r : largest;
    
    if (largest != i) {
        // swap to make the largest value as parent node
        std::swap(v[i], v[largest]);
        // heapify the child node
        heapify_down(largest);
    }

}


void MaxHeap::Add(int elem) {
    v.push_back(elem);
    size++;
    int new_id = size - 1;
    heapify_up(new_id);
}


int MaxHeap::Remove(int i) {
    // check whether the max heap is empty
    assert(size != 0);
    // check whether the index to remove is in the range
    assert(i < size);
    
    size--;
    int elem = v[i];
    
    // replace the ith elem with the last elem
    v[i] = v[size];
    // remove the last elem
    v.pop_back();
    
    // call heapify_down from index i
    heapify_down(i);
    
    // return the ith elem
    return elem;
}


void MaxHeap::print() {
    std::for_each(v.begin(), v.end(), [](int i){std::cout << i << " ";});
    std::cout << "\n";
}
