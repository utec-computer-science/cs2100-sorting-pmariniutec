#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

template <typename T>
class QuickSort : public Sort<T> {       
  public:
	QuickSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  quickSort(this->m_elements);
	  return this->m_elements;
	}

	std::size_t medianOfThree(T& a, T& b, T& c, std::size_t ai, std::size_t bi, std::size_t ci) {
	  if (a >= b && a <= c)
		return ai;
	  if (b >= a && b <= c)
		return bi;
	  return ci;
	}

	std::size_t partition(std::vector<T>& arr, std::size_t low, std::size_t high) {
	  auto ci = static_cast<std::size_t>(0.5 * static_cast<double>(low + high) + 0.5);
	  std::size_t pivotIndex = medianOfThree(arr[low], arr[ci], arr[high], low, ci, high);
	  T pivot = arr[pivotIndex];

	  std::size_t i = low;
	  std::size_t j = high;
	  while(true) {
		while(arr[i] <= pivot && i < pivotIndex) i++;
		while(arr[j] >= pivot && j > pivotIndex) j--;
		if (i == pivotIndex && j == pivotIndex)
		  return pivotIndex;

		T tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;

		if(i == pivotIndex)
		  pivotIndex = j;
		else if(j == pivotIndex)
		  pivotIndex = i;
	  }
	}

	void quickSort(std::vector<T>& arr, std::size_t low, std::size_t high) {
	  if (low < high) {
		auto p = partition(arr, low, high);

		if (p > 0) {
		  quickSort(arr, low, p - 1);
		}

		quickSort(arr, p + 1, high);
	  }
	}

	void quickSort(std::vector<T>& arr) {
	  if (arr.size() <= 1)
		return;

	  quickSort(arr, 0, arr.size()-1);
	}

	inline std::string name() const override { return "QuickSort"; }
};

#endif
