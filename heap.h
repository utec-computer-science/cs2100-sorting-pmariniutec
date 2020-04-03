#ifndef HEAP_H
#define HEAP_H

#include "sort.h"

template<typename T>
class HeapSort : public Sort<T> {
  public:
	HeapSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  heapSort(this->m_elements);
	  return this->m_elements;
	}

	void heapify(std::vector<T>& arr, std::size_t cur, std::size_t offset) {
	  if (cur + offset > arr.size())
		return;

	  heapify(arr, left_child(cur), offset);
	  heapify(arr, right_child(cur), offset);

	  if(cur > 1 && arr[cur + offset - 1] < arr[parent(cur) + offset - 1])
		std::swap(arr[cur + offset - 1], arr[parent(cur) + offset - 1]);
	}

	void heapSort(std::vector<T>& arr) {
	  for (std::size_t i = 0; i < arr.size(); ++i) {
		heapify(arr, 1, i);
	  }
	}

	inline std::string name() const override { return "HeapSort"; }

  private:
	inline std::size_t parent(std::size_t i) { return i >> 1; }

	inline std::size_t left_child(std::size_t i) { return i << 1; }

	inline std::size_t right_child(std::size_t i) { return (i << 1) + 1; }

};

#endif
