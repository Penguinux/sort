
#include"sort.h"
using namespace std;
template<typename T>
void merge(T array[], int left, int middle, int right, bool f){
	T temp[right];

	int i=left, j=middle+1, k=left;
	for(int i=left; i<=right; i++){
		temp[i]=array[i];}
	while(i<=middle && j<=right){
		if(f){
		if(temp[i]<temp[j]){
			array[k++]=temp[i++];}
			else{
				array[k++]=temp[j++];}


		}
		else
			if(temp[i]>temp[j]){
						array[k++]=temp[i++];}
						else{
							array[k++]=temp[j++];}
	}


	while (i<=middle) array[k++]=temp[i++];


}

template<typename T>
void merge_sort(T array[], int left, int right, bool f){

	int middle=0;

	if(right<=left){
		return;
	}
	else{
	middle=(left+right)/2;
	merge_sort(array,left, middle, f);
	merge_sort(array,middle+1,right, f);

	merge(array,left,middle,right,f);}
}


template void merge<int>(int array[], int left, int middle, int right, bool f);
template void merge<float>(float array[], int left, int middle, int right, bool f);
template void merge<long>(long array[], int left, int middle, int right, bool f);
template void merge<double>(double array[], int left, int middle, int right, bool f);
template void merge_sort<int>(int array[], int left, int right, bool f);
template void merge_sort<float>(float array[], int left, int right, bool f);
template void merge_sort<long>(long array[], int left, int right, bool f);
template void merge_sort<double>(double array[], int left, int right, bool f);


