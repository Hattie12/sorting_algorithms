
#include "InsertionSort.h"
using namespace std;
using std::swap;


//This function takes a vector and sorts it with the insertion sort method.
//Inputs: a vector of ints (as a reference)
//Outputs: the number of comparisons made to sort the vector (as well as modifying the\
original reference vector)
long long InsertionSort(vector<int> & vec_to_sort)
{
    long long comparison_count_ll(0); //counting variable 
    vector<int>::iterator edge_num_itr = begin(vec_to_sort); //the itr on the edge of the sorted\
                                                         part of the vector
    //vector<int>::iterator swapping_num_itr = begin(vec_to_sort); //itr for swapping  
    vector<int>::iterator sorted_num_itr = begin(vec_to_sort); //points to num to compare to


    edge_num_itr++; //point edge_num to second element, as the first element is sorted


    //check every number after the first to make sure its in the right place
    for (; edge_num_itr != end(vec_to_sort); ++edge_num_itr) {

        sorted_num_itr = edge_num_itr; //number to compare the value getting sorted with 
        //swapping_num_itr = edge_num_itr; //the number being sorted and moved through the vector

        //for every number between the edge_val and the vector beginning
        while(sorted_num_itr > begin(vec_to_sort)) {
            sorted_num_itr = sorted_num_itr - 1; //move sorted num to immediately \
                                         before the number being sorted

            comparison_count_ll++; //count the following comparison 

            //if the number before the edge num and the current number are in the wrong order
            if (*sorted_num_itr >= *(sorted_num_itr+1)){//swapping_num_itr) {

                //then swap them
                std::swap(*sorted_num_itr , *(sorted_num_itr + 1));
            }
            //if the number is larger than the adjacent sorted number
            else {
                //then it is in the right place
                break;
            }

        }
    }

    return comparison_count_ll;
}
