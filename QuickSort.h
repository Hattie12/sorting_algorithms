#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include <vector>
#include <fstream>


//sorts a reference vec using quicksort method
//returns number of comparisons made
long long QuickSort(std::vector<int> & a); 


//this function recursively calls QSS
// side effects: sorts the vec and edits the comparison count
//inputs: vec to sort, bottom of the vec, top of the vec, comparison count
void QuickSortSub(std::vector<int>& vec_to_sort, std::vector<int>::iterator bottom_itr, \
    std::vector<int>::iterator top_itr, \
    long long& comparison_count);


//adjusts subarray so its ordered around the pivot
//input: func takes the the entire vector, iterators pointing to first/last parts of hte sub vect \
and also the comparison count and whether or not the smaller half of the vector is being recursively\
called
//returns: itr pointing at the pivot
std::vector<int>::iterator Partition(std::vector<int>& vec_to_sort, std::vector<int>::iterator start_itr, \
    std::vector<int>::iterator end_itr, \
    long long& comparison_count, bool bottom);

#endif

