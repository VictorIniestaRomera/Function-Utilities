#pragma once

#include <iostream>
#include <vector>

template<class I, class P>
class Dictionary {
	std::vector<I> ind;
	std::vector<P> pos;

public:
	//Constructors
	Dictionary() {}

	//Modify
	void insert(I index, P position) noexcept {
		if (std::find(ind.begin(), ind.end(), index) == ind.end()) {
			ind.push_back(index);
			pos.push_back(position);
		}
	}

	inline void remove(I index) {
		int p = 0;
		auto i_it = std::find(ind.begin(), ind.end(), index);

		for (; i_it != ind.begin(); i_it--) {
			p++;
		}

		auto p_it = pos.begin() + p;

		ind.erase(i_it);
		pos.erase(p_it);
	}

	//Data
	inline P at(int index) {
		return pos.at(index);
	}
};