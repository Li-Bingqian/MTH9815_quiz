//
//  QuickSort.h
//  inclass_quiz_Nov22
//
//  Created by Aubree Li on 11/22/22.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

// partition func based on the pivot(arr[start_id])
int partition (int arr[], int start_id, int end_id) {
    int pivot = arr[start_id];
    // count of elem <= pivot
    int count = 0;
    for (int i = start_id; i <= end_id; ++i) {
        if (arr[i] <= pivot) count ++;
    }
    // fnid out the pivot index
    int pivot_id = start_id + count - 1;
    // swap pivot to the right index
    std::swap(arr[start_id], arr[pivot_id]);
    
    // put elem smaller than pivot to its left
    // put elem laerger than pivot to its right
    int i = start_id;
    int j = end_id;
    while (i < pivot_id && j > pivot_id) {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        // swap the elem not following the rule
        if(i < pivot_id && j > pivot_id) std::swap(arr[i++], arr[j--]);
    }
    
    return pivot_id;
}

void quick_sort(int arr[], int start_id, int end_id) {
    if (start_id >= end_id) return;
    
    int p = partition(arr, start_id, end_id);
    // divide and conquer
    // sorting the left
    quick_sort(arr, start_id, p-1);
    // sorting the right
    quick_sort(arr, p+1, end_id);
}

#endif /* QuickSort_hpp */
