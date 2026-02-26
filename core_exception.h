#pragma once

#include "exception.h"

class CoreException : public Exception {
	const int code;

public:
	CoreException(int code) : code(code) {}

	virtual ~CoreException() = default;

	inline const char* what() const noexcept override {
		const char* txt;

		if (code == 1) txt = "Index out of bounds!";
		else txt = "Unknown exception!";

		return txt;
	}
};