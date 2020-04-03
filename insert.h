#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

template <typename T>
class InsertSort : public Sort<T> {       
  public:
	InsertSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  T key;
	  std::size_t j;

	  for (std::size_t i = 1; i < this->m_elements.size(); i++) {
		key = this->m_elements[i];
		j = i - 1;

		while (j >= 0 && this->m_elements[j] > key) {
		  this->m_elements[j + 1] = this->m_elements[j];
		  j = j - 1;
		}
		this->m_elements[j + 1] = key;
	  }

	  return this->m_elements;
	}

	inline std::string name() const override { return "InsertSort"; }
};

#endif
