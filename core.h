#pragma once

template<class T>
class Core {
	T* arr;
	int size;

	typedef T* iterator;

public:
	//Constructors
	Core() : arr(new T[0]), size(0) {}

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
		return arr[index];
	}

	//Modify
	inline void push_back(T item) {
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
	}

	inline void remove(iterator it) {

	}

	//Operators
};

template<typename T>
inline void operator<<(std::ostream& out, const Core<T>& cor) {
	for (int i = 0; i < cor.length(); i++) {
		out << cor.at(i) << " ";
	}
}