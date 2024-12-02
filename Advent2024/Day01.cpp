#include "StdAfx.h"
#include "Day01.h"

long Day01::Problem01()
{
	std::string line;
	std::ifstream file("Input/Day01_01.txt");
	std::vector<long> left;
	std::vector<long> right;
	while (std::getline(file, line))
	{
		std::stringstream ss(line, std::ios_base::in);
		std::string value1, value2;
		ss >> value1 >> value2;
		long x = std::stol(value1);
		long y = std::stol(value2);
		left.emplace_back(x);
		right.emplace_back(y);
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	auto jt = right.begin();
	long total = 0;
	for (auto it = left.begin(); it != left.end(); ++it)
	{
		long l = *it;
		long r = *jt;
		long delta = std::abs(l - r);
		total += delta;
		jt++;
	}

	file.close();

	return total;
}


long Day01::Problem02()
{
	std::string line;
	std::ifstream file("Input/Day01_01.txt");
	std::vector<long> left;
	std::unordered_map<long, long> right;
	while (std::getline(file, line))
	{
		std::stringstream ss(line, std::ios_base::in);
		std::string value1, value2;
		ss >> value1 >> value2;
		long x = std::stol(value1);
		long y = std::stol(value2);
		left.emplace_back(x);
		auto it = right.find(y);
		if (it == right.end())
		{
			right[y] = 0;
		}
		right[y]++;
	}

	
	long total = 0;
	for (auto it = left.begin(); it != left.end(); ++it)
	{
		long l = *it;
		auto jt = right.find(l);
		long appearances = 0;
		if (jt != right.end())
		{
			appearances = jt->second;
		}
		long delta = l * appearances;
		total += delta;
	}

	file.close();

	return total;
}
