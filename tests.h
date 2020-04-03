#ifndef TESTS_H
#define TESTS_H 

#include <iostream>
#include <cassert>
#include <vector>
#include <random>

#include "insert.h"
#include "select.h"
#include "bubble.h"
#include "merge.h"
#include "heap.h"
#include "quick.h"

#include "shell.h"
#include "radix.h"

constexpr uint32_t NUM_TESTS = 20;

constexpr uint32_t MIN = 1;
constexpr uint32_t MAX = 9999;

enum SortType { INSERT, SELECT, BUBBLE, MERGE, HEAP, QUICK, SHELL };

class Tests {
  public:
	Tests() : m_rng{std::random_device()()} {}

	template<typename T>
	void executeTests() {
	  for (std::size_t count = 0; count < NUM_TESTS; ++count) {
		auto size  = generateRandomInt();
		auto arr = generateRandomVector<T>(size);

		for (int i = SortType::INSERT; i <= SortType::SHELL; ++i) {
		  auto sort = dispatchSort<T>(static_cast<SortType>(i), arr);

		  std::cout << sort->name() << '\n';
		  sort->execute();
		}

		// NOTE: Special test for RadixSort because we test it only with integers
		auto arr2 = generateRandomVector<int>(size);
		auto sort = new RadixSort<int>(arr2);
		std::cout << sort->name() << '\n';
		sort->execute();
	  }
	}

  private:
	std::mt19937 m_rng;
	std::uniform_int_distribution<int> m_intDist{MIN, MAX};
	std::uniform_real_distribution<float> m_floatDist{MIN, MAX};

	// Simple dispatcher
	template<typename T>
	Sort<T>* dispatchSort(SortType sort, const std::vector<T>& arr) {
	  switch (sort) {
		case INSERT: return new InsertSort<T>(arr);
		case SELECT: return new SelectSort<T>(arr);
		case BUBBLE: return new BubbleSort<T>(arr);
		case MERGE:  return new MergeSort<T>(arr);
		case HEAP:   return new HeapSort<T>(arr);
		case QUICK:  return new QuickSort<T>(arr);
		case SHELL:  return new ShellSort<T>(arr);

		default: throw std::invalid_argument("Not a valid sort type.");
	  }
	}

	int generateRandomInt() {
	  return m_intDist(m_rng);
	}

	float generateRandomFloat() {
	  return m_floatDist(m_rng);
	}

	template<typename T, std::enable_if_t<!std::is_same_v<int, T>, int> = 0>
	std::vector<T> generateRandomVector(std::size_t size) {
	  std::vector<T> values(size);

	  for (std::size_t i = 0; i < size; i++) {
		values[i] = generateRandomFloat();
	  }

	  return values;
	}

	template<typename T, std::enable_if_t<std::is_same_v<int, T>, int> = 0>
	std::vector<T> generateRandomVector(std::size_t size) {
	  std::vector<T> values(size);

	  for (std::size_t i = 0; i < size; i++) {
		values[i] = generateRandomInt();
	  }

	  return values;
	}

};

#endif
