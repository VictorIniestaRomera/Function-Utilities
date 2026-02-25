#pragma once

#include <iostream>
#include <vector>

namespace util {
	template<class T>
	class Items {
		std::vector<T> items;

		typedef std::vector<T>::iterator iterator;

	public:
		//Constructors
		Items() {}

		Items(const Items<T>& v) {
			for (auto i : v) {
				items.push_back(i);
			}
		}

		Items(const std::vector<T>& v) {
			for (auto i : v) {
				items.push_back(i);
			}
		}

		//Modify
		inline void push_back(T i) noexcept {
			items.push_back(i);
		}

		inline void pop_back() {
			items.pop_back();
		}

		inline void insert(iterator it, T i) {
			items.emplace(it, i);
		}

		void fill(int pos, T i) noexcept {
			for (; pos > 0; pos--) {
				items.push_back(i);
			}
		}

		void remove(iterator pos) {
			items.erase(pos);
		}

		inline void clear() noexcept {
			items.clear();
		}

		//Data
		inline int size() const noexcept {
			return items.size();
		}

		inline T front() const {
			return items.front();
		}

		inline T back() const {
			return items.back();
		}

		inline iterator begin() {
			return items.begin();
		}

		inline iterator end() {
			return items.end();
		}

		T at(int index) const {
			return items.at(index);
		}

		T at(iterator it) const {
			return *it;
		}

		inline bool empty() noexcept {
			return items.empty();
		}

		//External
		void swap(Items& ei) noexcept {
			Items<T> save = items;

			int ei_size = ei.size();
			int i_size = items.size();

			items.clear();

			for (int i = 0; i < ei_size; i++) {
				items.push_back(ei.at(i));
			}

			ei.clear();

			for (int i = 0; i < i_size; i++) {
				ei.push_back(save.at(i));
			}
		}

		inline void copy(const iterator it, const Items& item) {
			items.push_back(item.at(it));
		}

		inline void copy(const int it, const Items& item) {
			items.push_back(item.at(it));
		}

		void copy(const Items& item) noexcept {
			int size = item.size();

			for (int i = 0; i < size; i++) {
				items.push_back(item.at(i));
			}
		}

		//Operators
		inline void operator=(const Items<T> item) noexcept {
			items.clear();

			int size = item.size();

			for (int i = 0; i < size; i++) {
				items.push_back(item.at(i));
			}
		}
	};
}

template <typename T>
inline void operator<<(std::ostream& out, const util::Items<T>& item) noexcept {
	int size = item.size();

	for (int i = 0; i < size; i++) {
		out << item.at(i) << " ";
	}
}