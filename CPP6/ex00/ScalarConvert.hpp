#pragma once

#include <string>
#include <cctype>
#include <iostream>

class ScalarConvert{
	public:
		ScalarConvert();
		ScalarConvert(const ScalarConvert &rhs);
		ScalarConvert &operator=(const ScalarConvert &rhs);
		~ScalarConvert();

		static void convert(const std::string str);

	private:
		static bool	isInt(const std::string &str);
		static bool	isDouble(const std::string &str);
		static bool	isFloat(const std::string &str);
};
