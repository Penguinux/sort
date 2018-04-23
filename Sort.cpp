//============================================================================
// Name        : Sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <chrono>
#include<algorithm>
#include<windows.h>
#include<vector>
using namespace std;

int *temp;
void merge(int array[], int left, int middle, int right){


	int i=left, j=middle+1, k=left;
	for(int i=left; i<=right; i++){
		temp[i]=array[i];}
	while(i<=middle && j<=right){
		if(temp[i]<temp[j]){
			array[k++]=temp[i++];}
			else{
				array[k++]=temp[j++];}


		}
	while (i<=middle) array[k++]=temp[i++];


}

void merge_sort(int array[], int left, int right){

	int middle=0;

	if(right<=left){
		return;
	}
	else{
	middle=(left+right)/2;
	merge_sort(array,left, middle);
	merge_sort(array,middle+1,right);
	merge(array,left,middle,right);}
}


void quick_sort(int *array, int left, int right){
	if(right<=left)
		return;
	int pivot=0,i=left-1,j=right+1,m=(left+right)/2;

	pivot=array[m];

	do{
		while(array[++i]<pivot);
		while(pivot<array[--j]);
		if(i<=j)
			swap(array[i],array[j]);
	}while(i<=j);

	if(j>left)
		quick_sort(array,left,j);
	if(i<right)
		quick_sort(array,i,right);


}




void heapify(int array[],int heap_size, int i){
	for (int z=0;z<=heap_size-1;z++){
		cout<<array[z] << " ";
		 		   }
		cout << endl;
	int larg=i;
	int left=0, right=0;

	left=2*(i)+1;
	right=2*(i)+2;

	if(array[larg]<array[left] && left<heap_size)
		larg=left;
	if(array[larg]<array[right] && right<heap_size)
		larg=right;


	if(larg!=i){
		swap(array[i],array[larg]);
	heapify(array,heap_size,larg);}
}

void heap_sort(int array[],int begin, int end){
	int size=end;
	for(int i=(end)/2+1;i>=begin;i--){

		heapify( array,end+1,i);
	}
	for (int i=0;i<=size;i++){
	cout<<array[i] << " ";
	 		   }
	cout << endl;
	for(int i=end;i>=begin;i--){

		swap(array[i],array[0]);

		//end--;
		heapify(array,i,0);
		}


}
void introsort(int *array, int left, int right, int M){

	if(M<=0){

		heap_sort(array,left,right);

		return;
	}
	else{

		if(right<=left)
			return;
		int pivot=0,i=left-1,j=right+1,m=(left+right)/2;

		pivot=array[m];

		do{
			while(array[++i]<pivot);
			while(pivot<array[--j]);
			if(i<=j)
				swap(array[i],array[j]);
		}while(i<=j);

		if(j>left)
			introsort(array,left,j,M-1);

		if(i<right)
			introsort(array,i,right,M-1);



	}
}

int main() {
	int size=12;
	int r;
	int *arr=new int[size];
	int *arr1=new int[size];
	int *arr2=new int[size];
		temp=new int[size];
	for (int i=0;i<size;i++){
		cin>>r;
	arr[i]=r;
	arr1[i]=r;
	arr2[i]=r;}
	/*vector<int> v(arr1,arr1+size);
	make_heap(v.begin(),v.end());


	auto start = chrono::steady_clock::now(); //use auto keyword to minimize typing strokes :)
	quick_sort(arr,0,size-1);

	auto end= chrono::steady_clock::now();
	auto diff = end - start;
	cout<<"Elapsed time is :  "<< chrono::duration_cast<chrono::nanoseconds>(diff).count()<<" ns "<<endl;
	auto start1 = chrono::steady_clock::now(); //use auto keyword to minimize typing strokes :)
		merge_sort(arr1,0,size-1);
		auto end1 = chrono::steady_clock::now();
		auto diff1 = end1 - start1;
		cout<<"Elapsed time is :  "<< chrono::duration_cast<chrono::nanoseconds>(diff1).count()<<""
				" ns "<<endl;
		auto start2 = chrono::steady_clock::now(); //use auto keyword to minimize typing strokes :)
				//long M=floor(2*log10(size));
		heap_sort(arr2,0,size-1);
				auto end2 = chrono::steady_clock::now();
				auto diff2 = end2 - start2;
				cout<<"Elapsed time is :  "<< chrono::duration_cast<chrono::nanoseconds>(diff2).count()<<endl;*/
	heap_sort(arr2,0,size-1);
	for (int i=0;i<size;i++){
	cout<<arr2[i] << " ";
	 		   }
	cout << endl;
	cout<<"1234";
	   		   system("pause");

	return 0;
}
