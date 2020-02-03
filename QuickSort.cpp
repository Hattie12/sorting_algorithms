

#include "QuickSort.h"
#include <iostream>
using namespace std;

//all this function does is call QSH and start the comparison count at zero
//inputs: the vec to sort
long long QuickSort(std::vector<int> & vec_to_sort)
{
    long long comparison_count = 0;//start comparison count

    //call the helper function with the vec indices
    QuickSortSub(vec_to_sort, vec_to_sort.begin(), vec_to_sort.end()-1, comparison_count);
    
    return comparison_count;
}

//this function recursively calls QSS
// side effects: sorts the vec and edits the comparison count
//inputs: vec to sort, bottom of the vec, top of the vec, comparison count
void QuickSortSub(std::vector<int>& vec_to_sort, vector<int>::iterator bottom_itr,\
                        vector<int>::iterator top_itr,\
                        long long &comparison_count) {

    vector<int>::iterator pivot_position = top_itr; //as per instructions, pivot is at the start

    //if the input vec is at least two elements
    if(top_itr > bottom_itr){

        //sort it around a new pivot point, which should be saved
        pivot_position = Partition(vec_to_sort, bottom_itr, top_itr, \
                                                   comparison_count, false);

        //call QSS on the vec below the pivot (unless the pivot was at 0, then call it with\
        the lower bound as just position)
        QuickSortSub(vec_to_sort, bottom_itr, \
            (pivot_position == begin(vec_to_sort) ? pivot_position : pivot_position -1),\
            comparison_count);

        //call QSS on the larger part of the vec
        QuickSortSub(vec_to_sort, pivot_position+1, top_itr, comparison_count);

    }

    return;
}

//adjusts subarray so its ordered around the pivot
//input: func takes the the entire vector, iterators pointing to first/last parts of hte sub vect \
and also the comparison count and whether or not the smaller half of the vector is being recursively\
called
//returns: itr pointing at the pivot
vector<int>::iterator Partition(std::vector<int>& vec_to_sort, vector<int>::iterator start_itr, \
    vector<int>::iterator end_itr, \
    long long& comparison_count, bool bottom) {

    //address simple case that they're only two numbers that need ordering
    if (start_itr + 1 == end_itr) {

        comparison_count += 1;//count swap

        //if they're out of order
        if (*start_itr > *end_itr) {
            std::swap(*start_itr,*end_itr); //swap them
        }

        return(bottom ? start_itr: end_itr); //return the value that stops the recursion
    }

    //for all other cases:
    vector<int>::iterator pivot_itr = start_itr; //as per requirements
    int pivot = *pivot_itr;
    vector<int> smaller_nums{}; //basket for nums smaller than pivot
    vector<int> larger_nums{}; //basket for nums larger than pivot

    std::vector<int>::iterator edge_itr = start_itr + 1; //first ele to check out is to the left \
    of the pivot

    //check all the non-pivot elements
    for (edge_itr; edge_itr <= end_itr; edge_itr++) {

        comparison_count += 1; //count comp

        //if the num is bigger than the pivot
        if (*pivot_itr < *edge_itr) {
            larger_nums.push_back(*edge_itr); //put it in large basket
        }
        else {
            smaller_nums.push_back(*edge_itr); //smaller = small basket
        }
    }

    //write out all the small numbers in the sub of the vec
    for (int &small_num : smaller_nums) {
        *start_itr = small_num;
        start_itr++;
    }

    //write the pivot into the vec in the correct place
    *start_itr = pivot;
    pivot_itr = start_itr; //save pivot pos
    start_itr++;

    //write out larger numbers into the sub vec
    for (int& large_num : larger_nums) {
        *start_itr = large_num;
        start_itr++;
    }


    return(pivot_itr);
}

