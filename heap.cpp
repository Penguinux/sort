#include "sort.h"
using namespace std;

template <typename T>
void heapify(T array[], int begin, int end, int i, bool f)
{
    int larg = begin+i ;
    int left = begin + (2*i) + 1;
    int right = begin + (2*i) + 2;
    if(f){
    if(left <= end &&  array[larg] < array[left])
    {
        larg = left;
    }
    if(right <= end &&  array[larg] < array[right])
    {
        larg = right;
    }
    }
    else{
    	   if(left <= end &&  array[larg] > array[left])
    	    {
    	        larg = left;
    	    }
    	    if(right <= end &&  array[larg] > array[right])
    	    {
    	        larg = right;
    	    }
    }
    if(larg != begin+i)
    {
        swap(array[larg], array[begin+i]);
        heapify(array, begin, end, larg-begin, f);
    }
}


template <typename T>
void heap_sort(T array[], int left, int right, bool f)
{
    for(int i=(right-left+1)/2; i>=0; --i)
    {
        heapify(array, left, right, i, f);
    }

    for(int i=right; i>left; --i)
    {
        swap(array[left], array[i]);
        heapify(array,left, i-1, 0, f);
    }
}
template void heapify<int>(int array[], int begin, int end, int i, bool f);
template void heapify<float>(float array[], int begin, int end, int i, bool f);
template void heapify<long>(long array[], int begin, int end, int i, bool f);
template void heapify<double>(double array[], int begin, int end, int i, bool f);
template void heap_sort<int>(int array[], int left, int right, bool f);
template void heap_sort<float>(float array[], int left, int right, bool f);
template void heap_sort<long>(long array[], int left, int right, bool f);
template void heap_sort<double>(double array[], int left, int right, bool f);

