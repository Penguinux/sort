#include"sort.h"
using namespace std;


template<typename T>
void quick_sort(T array[], int left, int right, bool f){
	if(right<=left){
		return;}
	T pivot=0;
	int i=left-1,j=right+1,m=(left+right)/2;

	pivot=array[m];

	do{
		if(f){
		while(array[++i]<pivot);
		while(pivot<array[--j]);}
		else{
			while(array[++i]>pivot);
			while(pivot>array[--j]);
		}

		if(i<=j)
			swap(array[i],array[j]);
	}while(i<=j);

	if(j>left)
		quick_sort(array,left,j, f);
	if(i<right)
		quick_sort(array,i,right, f);


}


template void quick_sort<int>(int array[], int left, int right, bool f);
template void quick_sort<float>(float array[], int left, int right, bool f);
template void quick_sort<long>(long array[], int left, int right, bool f);
template void quick_sort<double>(double array[], int left, int right, bool f);


