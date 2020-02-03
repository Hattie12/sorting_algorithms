#include "VerifySort.h"
using namespace std;

bool VerifySort(const vector<int> &a)
{
    //for all the elements in the vec, starting with the second,
    for(int index(1); index <= a.size()-1; index++){
        //check that the current element is larger than the previous element
        if (a.at(index - 1) > a.at(index)) {
            return (false);
        } //if it isn't, then the vec isn't sorted
    }

    return (true); //if all element are greater (or equal) to the one before, them, the vec is sorted
}
