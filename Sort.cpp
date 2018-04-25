#include <iostream>
#include <cmath>
#include <chrono>
#include<algorithm>
#include<fstream>

#include"sort.h"
using namespace std;

int main() {
	bool test1=1,test2=1,test3=1;
   fstream plik;
   plik.open("dane.txt", ios::out);
  for(int i=0;i<100;i++){
	int size=1000000;             // array size
	int r;
	int *arr=new int[size];
	int *arr1=new int[size];
	int *arr2=new int[size];

	for (int i=0;i<size;i++){ // random array
		r=rand();
	arr[i]=arr1[i]=arr2[i]=r;
	}
/*
quick_sort(arr,0,(size)-1, 0);         // presorting
quick_sort(arr1,0,(size)-1, 0);
quick_sort(arr2,0,(size)-1, 0);

*/
	auto start = chrono::steady_clock::now();
	int M=floor(2*log2(size-1));
	introsort(arr,0,size-1,M,1);

	auto end= chrono::steady_clock::now();
	auto diff = end - start;

	auto start1 = chrono::steady_clock::now();
		merge_sort(arr1,0,size-1,1);
		auto end1 = chrono::steady_clock::now();
		auto diff1 = end1 - start1;

		auto start2 = chrono::steady_clock::now();

		quick_sort(arr2,0,size-1,1);

				auto end2 = chrono::steady_clock::now();
				auto diff2 = end2 - start2;

				for(int i=0; i<size-1;i++){  // sort check
					if(arr[i]>arr[i+1]){
						test1=0;
					}
					if(arr1[i]>arr1[i+1]){
						test2=0;
					}
					if(arr2[i]>arr2[i+1]){
						test3=0;
					}
				}

				if(test1){ // if sorting is correct write to file

				plik<< chrono::duration_cast<chrono::milliseconds>(diff).count()<<" ";}
				else{
					plik<<"error ";}
				if(test2){
				plik<<chrono::duration_cast<chrono::milliseconds>(diff1).count()<<" ";}
				else{
					plik<<"error ";}
				if(test3){
				plik<<chrono::duration_cast<chrono::milliseconds>(diff2).count()<<endl;}
				else{
					plik<<"error"<<endl;}
				}

/*for(int i=0; i<size;i++){
	cout<<arr[i]<<' ';
}
cout<<endl;
for(int i=0; i<size;i++){
	cout<<arr1[i]<<' ';
}
cout<<endl;
for(int i=0; i<size;i++){
	cout<<arr2[i]<<' ';
}
cout<<endl; */

	   		   system("pause");
	   		   plik.close();

return 0;
}
