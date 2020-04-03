#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

template <typename T>
class SelectSort : public Sort<T> {       
  public:
	SelectSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  std::size_t min_idx;

	  for (std::size_t i = 0; i < this->m_elements.size() - 1; ++i)  {
		min_idx = i;
		for (std::size_t j = i + 1; j < this->m_elements.size(); ++j) {
		  if (this->m_elements[j] < this->m_elements[min_idx]) {
			min_idx = j;
		  }
		}

		std::swap(this->m_elements[min_idx], this->m_elements[i]);
	  }

	  return this->m_elements;
	}

	inline std::string name() const override { return "SelectSort"; }
};

#endif
