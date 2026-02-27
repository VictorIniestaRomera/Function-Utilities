#pragma once

#include "core_exception.h"

namespace util {
	template<class T>
	class Core {
		T* arr;
		int length;

		typedef T* iterator;

	public:
		//Constructors
		Core() : arr(new T[0]), length(0) {}

		~Core() {
			delete arr;
		}

		//Data
		inline int size() const {
			return length;
		}

		inline T front() const noexcept {
			return arr[0];
		}

		inline T back() const noexcept {
			return arr[size()];
		}

		inline T* begin() const noexcept {
			return &arr[0];
		}

		inline T* end() const noexcept {
			return &arr[size()];
		}

		inline T at(const int index) const {
			try {
				if (index < 0 || index >= length) throw(new CoreException(1));
				
				return arr[index];
			}
			catch (const CoreException* e) {
				std::cerr << e->what() << std::endl;

				return NULL;
			}
		}

		inline T at(const iterator index) const {
			try {
				if (index < begin() || index >= end()) throw(new CoreException(1));

				return *index;
			}
			catch (const CoreException* e) {
				std::cerr << e->what() << std::endl;

				return NULL;
			}
		}

		//Modify
		inline void push_back(const T item) noexcept {
			const int len = size();
			T* save = new T[len];

			for (int i = 0; i < len; i++) {
				save[i] = arr[i];
			}

			delete arr;

			arr = new T[len + 1];

			for (int i = 0; i < len; i++) {
				arr[i] = save[i];
			}

			arr[len] = item;
			length++;

			delete save;
		}

		inline void push_front(const T item) noexcept {
			const int len = size();
			T* save = new T[len + 1];

			for (int i = 0; i < len; i++) {
				save[i] = arr[i];
			}

			delete arr;

			arr = new T[len + 1];

			for (int i = 1; i < len + 1; i++) {
				arr[i] = save[i - 1];
			}

			arr[0] = item;
			length++;

			delete save;
		}

		inline void pop_back() {
			try {
				if (size() == 0) throw(new CoreException(1));

				const int len = size();
				T* save = new T[len];

				for (int i = 0; i < len; i++) {
					save[i] = arr[i];
				}

				delete arr;

				arr = new T[len - 1];

				for (int i = 0; i < len - 1; i++) {
					arr[i] = save[i];
				}

				length--;

				delete save;
			}
			catch (const CoreException* e) {
				std::cerr << e->what() << std::endl;
			}
		}

		inline void pop_front() {
			try {
				if (size() == 0) throw(new CoreException(1));

				const int len = size();
				T* save = new T[len];

				for (int i = 0; i < len; i++) {
					save[i] = arr[i];
				}

				delete arr;

				arr = new T[len - 1];

				for (int i = 1; i < len; i++) {
					arr[i - 1] = save[i];
				}

				length--;

				delete save;
			}
			catch (const CoreException* e) {
				std::cerr << e->what() << std::endl;
			}
		}

		inline void remove(const iterator pos) {
			if (pos > end()) return;

			const int len = size();
			T* save = new T[len - 1];
			int count = 0;
			int i = 0;

			for (iterator it = begin(); it != end(); it++) {
				if (it != pos) {
					save[count] = arr[i];

					count++;
				}

				i++;
			}

			delete arr;

			arr = new T[len - 1];

			for (int i = 0; i < len - 1; i++) {
				arr[i] = save[i];
			}

			length--;

			delete save;
		}

		inline void remove(const int pos) {
			try {
				if (pos < 0 || pos >= length) throw(new CoreException(1));

				const int len = size();
				T* save = new T[len];

				for (int i = 0; i < len; i++) {
					save[i] = arr[i];
				}

				delete arr;

				arr = new T[len - 1];
				int count = 0;

				for (int i = 0; i < len; i++) {
					if (i != pos) {
						arr[count] = save[i];

						count++;
					}
				}

				length--;

				delete save;
			}
			catch (const CoreException* e) {
				std::cerr << e->what() << std::endl;
			}
		}

		inline void clear() noexcept {
			delete arr;

			arr = new T[0];

			length = 0;
		}

		inline void copy(const Core<T> cor) noexcept {
			delete arr;

			length = cor.size();
			arr = new T[length];

			for (int i = 0; i < length; i++) {
				arr[i] = cor.at(i);
			}
		}

		inline void copy(const Core<T>* cor) noexcept {
			delete arr;

			length = cor->size();
			arr = new T[length];

			for (int i = 0; i < length; i++) {
				arr[i] = cor->at(i);
			}
		}

		//Operators
		inline T operator[](int index) const {
			return at(index);
		}

		inline T operator[](iterator index) const {
			return at(index);
		}

		inline void operator=(Core<T>& cor) {
			copy(cor);
		}

		inline void operator=(Core<T>* cor) {
			copy(cor);
		}

		inline void operator+=(T item) {
			push_back(item);
		}

		inline void operator--() {
			pop_back();
		}
	};
}

template<typename T>
inline void operator<<(std::ostream& out, const util::Core<T>& cor) {
	for (int i = 0; i < cor.size(); i++) {
		out << cor.at(i) << " ";
	}
}

template<typename T>
inline void operator<<(std::ostream& out, const util::Core<T>* cor) {
	for (int i = 0; i < cor->size(); i++) {
		out << cor->at(i) << " ";
	}
}

template<typename T>
inline void operator>>(std::istream& in, util::Core<T>& cor) {
	T add;
	in >> add;

	cor.push_back(add);
}

template<typename T>
inline void operator>>(std::istream& in, util::Core<T>* cor) {
	T add;
	in >> add;

	cor->push_back(add);
}