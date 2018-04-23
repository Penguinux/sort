
#include <iostream>
#include <cmath>
#include <chrono>
#include<algorithm>
#include<windows.h>
#include<vector>
#include<fstream>
using namespace std;

int *temp;
void heapify(int array[],int heap_size, int i){

	int larg=i;
	int left=0, right=0;

	left=2*(i)+1;
	right=2*(i)+2;

	if(left<heap_size && array[larg]<array[left])
		larg=left;
	if(right<heap_size && array[larg]<array[right])
		larg=right;


	if(larg!=i){
		swap(array[i],array[larg]);
	heapify(array,heap_size,larg);}
}

void heap_sort(int array[],int begin, int end){

	for(int i=(end)/2;i>=begin;i--){

		heapify( array,end,i);
	}

	for(int i=end;i>=begin;i--){

		swap(array[begin],array[i]);


		heapify(array,i,begin);
		}
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify1(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify1(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[],int b, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2; i >= b; i--)
        heapify1(arr, n, i);

    // One by one extract an element from heap
    for (int i=n; i>=b; i--)
    {
        // Move current root to end
        swap(arr[b], arr[i]);

        // call max heapify on the reduced heap
        heapify1(arr, i, b);
    }
}
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







void introsort(int *array, int left, int right, int M){

	if(M<=0){

		heap_sort(array,left,right);


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
   fstream plik;
   plik.open("dane.txt", ios::out);
   for(int i=0;i<100;i++){
	int size=1000000;
	int r;
	int *arr=new int[size];
	int *arr1=new int[size];
	int *arr2=new int[size];
		temp=new int[size];
	for (int i=0;i<size;i++){
		r=rand();
	arr[i]=arr1[i]=arr2[i]=r;
	}
	vector<int> v(arr1,arr1+size);
	make_heap(v.begin(),v.end());

	auto start = chrono::steady_clock::now(); //use auto keyword to minimize typing strokes :)
	quick_sort(arr,0,size-1);
	auto end= chrono::steady_clock::now();
	auto diff = end - start;

	auto start1 = chrono::steady_clock::now(); //use auto keyword to minimize typing strokes :)
		merge_sort(arr1,0,size-1);
		auto end1 = chrono::steady_clock::now();
		auto diff1 = end1 - start1;
		//cout<<"Elapsed time is :  "<< chrono::duration_cast<chrono::nanoseconds>(diff1).count()<<""
				//" ns "<<endl;
		auto start2 = chrono::steady_clock::now(); //use auto keyword to minimize typing strokes :)
        long M=floor(2*log2(size));
		introsort(arr2,0,size-1,M);

				auto end2 = chrono::steady_clock::now();
				auto diff2 = end2 - start2;
				//cout<<"Elapsed time is :  "<< chrono::duration_cast<chrono::nanoseconds>(diff2).count()<<endl;
				//while(chrono::duration_cast<chrono::microseconds>(diff2).count()==0){
				plik<< chrono::duration_cast<chrono::microseconds>(diff).count()<<" "<<chrono::duration_cast<chrono::microseconds>(diff1).count()<<" "<<chrono::duration_cast<chrono::microseconds>(diff2).count()<<endl;
				}


       /* for (int i=0;i<size;i++){
	cout<<arr2[i] << " ";
	 		   }
	cout << endl;*/
   // }
   //for (int i=0;i<size;i++){
	//cout<<arr2[i] << " ";
	 		  //}
	//cout << endl;
//heap_sort(arr2,1,5);
    /*auto start1 = chrono::steady_clock::now();
	heap_sort(arr2,0,size-1);
	auto end1 = chrono::steady_clock::now();

	auto diff1 = end1 - start1;
	cout<<"Elapsed time is :  "<< chrono::duration_cast<chrono::nanoseconds>(diff1).count()<<" ns "<<endl;*/
	//for (int i=0;i<size;i++){
	//cout<<arr2[i] << " ";
	 		  //}
	//cout << endl;
	cout<<"1234";
	   		   system("pause");

	return 0;
}
