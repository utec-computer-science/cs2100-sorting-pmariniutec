#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

template <typename T>
class MergeSort : public Sort<T> {       
  public:
	MergeSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  mergeSort(this->m_elements, 0, this->m_elements.size() - 1);
	  return this->m_elements;
	}

	void mergeSort(std::vector<T>& arr, std::size_t l, std::size_t r) {
	  if (l < r) {
		std::size_t m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	  }
	}

	void merge(std::vector<T>& arr, std::size_t l, std::size_t m, std::size_t r) { 
	  std::size_t i, j, k; 
	  auto size1 = m - l + 1; 
	  auto size2 =  r - m; 

	  std::vector<T> L(size1);
	  std::vector<T> R(size2);

	  for (i = 0; i < size1; ++i)
		L[i] = arr[l + i];

	  for (j = 0; j < size2; ++j)
		R[j] = arr[m + 1+ j];

	  i = 0;
	  j = 0;
	  k = l;

	  while (i < size1 && j < size2) { 
		if (L[i] <= R[j]) { 
		  arr[k] = L[i]; 
		  ++i; 
		} else { 
		  arr[k] = R[j]; 
		  ++j; 
		}
		++k; 
	  }

	  while (i < size1) { 
		arr[k] = L[i]; 
		++i; 
		++k; 
	  }

	  while (j < size2) { 
		arr[k] = R[j];
		++j;
		++k;
	  }
	}

	std::string name() const override { return "MergeSort"; }
};

#endif
