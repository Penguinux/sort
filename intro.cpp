#include"sort.h"
using namespace std;

template<typename T>
void introsort(T array[], int left, int right, int M, bool f){

	if(M<=0){

		heap_sort(array,left,right, f);


	}
	else{

		if(right<=left)
			return;
		int pivot=0,i=left-1,j=right+1,m=(left+right)/2;

		pivot=array[m];

		do{
			if(f){
		while(array[++i]<pivot);
		while(pivot<array[--j]);
			}
			else{
				while(array[++i]>pivot);
					while(pivot>array[--j]);
			}
		if(i<=j)
			swap(array[i],array[j]);
	}while(i<=j);

	if(j>left)
		introsort(array,left,j,M-1, f);
	if(i<right)
		introsort(array,i,right,M-1, f);


	}
}

template void introsort<int>(int array[], int left, int right, int M, bool f);
template void introsort<float>(float array[], int left, int right, int M, bool f);
template void introsort<long>(long array[], int left, int right, int M, bool f);
template void introsort<double>(double array[], int left, int right, int M, bool f);
