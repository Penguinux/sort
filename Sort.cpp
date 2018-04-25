#include <iostream>
#include <cmath>
#include <chrono>
#include<algorithm>
#include<windows.h>
#include<vector>
#include<fstream>

#include"sort.h"
using namespace std;



int main() {
	bool test1=1,test2=1,test3=1;
   fstream plik;
   plik.open("dane.txt", ios::out);
  for(int i=0;i<100;i++){
	int size=500000;
	int r;
	int *arr=new int[size];
	int *arr1=new int[size];
	int *arr2=new int[size];

	for (int i=0;i<size;i++){
		r=rand();
	arr[i]=arr1[i]=arr2[i]=r;
	}

	auto start = chrono::steady_clock::now();
	long M=floor(2*log2(size));
	introsort(arr,0,size-1,M, 1);

	auto end= chrono::steady_clock::now();
	auto diff = end - start;

	auto start1 = chrono::steady_clock::now();
		merge_sort(arr1,0,size-1, 1);
		auto end1 = chrono::steady_clock::now();
		auto diff1 = end1 - start1;

		auto start2 = chrono::steady_clock::now();

		quick_sort(arr2,0,size-1, 1);

				auto end2 = chrono::steady_clock::now();
				auto diff2 = end2 - start2;

				for(int i=0; i<size-1;i++){
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

				if(test1){

				plik<< chrono::duration_cast<chrono::microseconds>(diff).count()<<" ";}
				else{
					plik<<"error ";}
				if(test2){
				plik<<chrono::duration_cast<chrono::microseconds>(diff1).count()<<" ";}
				else{
					plik<<"error ";}
				if(test3){
				plik<<chrono::duration_cast<chrono::microseconds>(diff2).count()<<endl;}
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

return 0;
}
