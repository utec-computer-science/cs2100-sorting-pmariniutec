#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

template <typename T>
class BubbleSort : public Sort<T> {       
  public:
	BubbleSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  for (std::size_t i = 0; i < this->m_elements.size() - 1; ++i) {
		for (std::size_t j = 0; j < this->m_elements.size() - i - 1; ++j) {
		  if (this->m_elements[j] > this->m_elements[j + 1]) {
			std::swap(this->m_elements[j], this->m_elements[j + 1]);
		  }
		}
	  }

	  return this->m_elements;
	}

	inline std::string name() const override { return "BubbleSort"; }
};

#endif
