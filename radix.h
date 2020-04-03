#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include <queue>
#include <type_traits>

template<typename T>
class RadixSort : public Sort<T> {       
  public:
	RadixSort(std::vector<T> elements) : Sort<T>(elements) {}

	std::vector<T> execute() override {
	  radixSort(this->m_elements);
	  return this->m_elements;
	}

	void radixSort(std::vector<T>& arr){
	  constexpr std::size_t BASE = 10;

	  auto start = arr.begin();
	  auto end = arr.end();

	  std::vector<T> output{arr.begin(), arr.end()};

	  std::queue<T> bucket[BASE];

	  T max = *std::max_element(start, end);

	  for (std::size_t power = 1; max != 0; max /= static_cast<int>(BASE), power *= BASE) {

		for (auto it = output.begin(); it != output.end(); it++){
		  auto bucketNumber =  static_cast<std::size_t>((*it / power) % BASE);
		  bucket[bucketNumber].push(*it);
		}

		auto it = output.begin();
		for (std::size_t i = 0; i < BASE; i++){
		  auto bucketSize = bucket[i].size();
		  for (std::size_t j = 0; j < bucketSize; j++){
			*it = bucket[i].front();
			bucket[i].pop();
			it++;
		  }
		}
	  }
	}

	inline std::string name() const override { return "RadixSort"; }
};

#endif
