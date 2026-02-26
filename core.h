#pragma once

#include "core_exception.h"

namespace util {
	template<class T>
	class Core {
		T* arr;
		int size;

		typedef T* iterator;

	public:
		//Constructors
		Core() : arr(new T[0]), size(0) {}

		~Core() {
			delete arr;
		}

		//Data
		inline int length() const {
			return size;
		}

		inline T front() const noexcept {
			return arr[0];
		}

		inline T back() const noexcept {
			return arr[length()];
		}

		inline T* begin() const noexcept {
			return &arr[0];
		}

		inline T* end() const noexcept {
			return &arr[length()];
		}

		inline T at(int index) const {
			try {
				if (index < 0 || index >= size) throw(new CoreException(1));
				
				return arr[index];
			}
			catch (const CoreException* e) {
				std::cerr << e->what() << std::endl;

				return NULL;
			}
		}

		inline T at(iterator index) const {
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
		inline void push_back(T item) noexcept {
			const int len = length();
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
			size++;

			delete save;
		}

		inline void remove(iterator pos) {
			if (pos > end()) return;

			const int len = length();
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

			size--;

			delete save;
		}

		inline void remove(int pos) {
			if (pos > length() - 1) return;

			const int len = length();
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

			size--;

			delete save;
		}

		inline void clear() noexcept {
			delete arr;

			arr = new T[0];

			size = 0;
		}

		//Operators
		inline T operator[](int index) {
			return at(index);
		}

		inline T operator[](iterator index) {
			return at(index);
		}
	};
}

template<typename T>
inline void operator<<(std::ostream& out, const util::Core<T>& cor) {
	for (int i = 0; i < cor.length(); i++) {
		out << cor.at(i) << " ";
	}
}

template<typename T>
inline void operator<<(std::ostream& out, const util::Core<T>* cor) {
	for (int i = 0; i < cor->length(); i++) {
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