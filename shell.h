#ifndef SHELL_H
#define SHELL_H

#include "sort.h"
#include <vector>

template<typename T>
class ShellSort : public Sort<T> {       
  public:
	ShellSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  for (std::size_t gap = this->m_elements.size() / 2; gap > 0; gap /= 2) {
		for (std::size_t i = gap; i < this->m_elements.size(); ++i) {
		  auto temp = this->m_elements[i];

		  std::size_t j;
		  for (j = i; j >= gap && this->m_elements[j - gap] > temp; j -= gap) {
			this->m_elements[j] = this->m_elements[j - gap];
		  }

		  this->m_elements[j] = temp;
		}
	  }

	  return this->m_elements;
	}

	inline std::string name() const override { return "ShellSort"; }
};

#endif
