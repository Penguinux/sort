

#ifndef SORT_H_
#define SORT_H_
#include <algorithm>
// if flag == 1 soring is normal, if flag ==1 reverse sorting

template<typename T>
void merge(T array[], int left, int middle, int right, bool f);
template<typename T>
extern void merge_sort(T array[], int left, int right, bool f);
template<typename T>
void quick_sort(T array[], int left, int right, bool f);
template <typename T>
void heapify(T array[], int begin, int end, int i, bool f);
template <typename T>
void heap_sort(T array[], int left, int right, bool f);
template<typename T>
void introsort(T *array, int left, int right, int M, bool f);



#endif /* SORT_H_ */
