#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <string>
#include <vector>

template <typename T>
class Sort {
  public:
	Sort(std::vector<T> elements) : m_elements(elements) {}

	virtual ~Sort() {}

	virtual std::vector<T> execute() = 0;
	virtual std::string name() const = 0;

	std::vector<T> m_elements;
};

#endif
