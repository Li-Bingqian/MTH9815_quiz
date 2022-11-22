//
//  MaxHeap.hpp
//  inclass_quiz_Nov22
//
//  Created by Aubree Li on 11/22/22.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp
#include <vector>

class MaxHeap {
private:
    int size;
    std::vector<int> v;
    
    // get index from left/right child or parent node
    int get_left (int i);
    int get_right (int i);
    int get_parent (int i);
    
    // check the max heap rule with i and parent(i)
    void heapify_up (int i);
    // check the max heap rule with i and i's children left(i) & right(i)
    void heapify_down(int i);
    
public:
    MaxHeap();
    // add elem to max heap
    void Add(int elem);
    // remove ith elem from maxheap
    // if Remove(0), means pop the first elem (max elem)
    int Remove(int i);
    void print();
    
};

#endif /* MaxHeap_hpp */
