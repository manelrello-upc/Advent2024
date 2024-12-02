#include "StdAfx.h"
#include "Day02.h"

long Day02::Problem01()
{
	std::string line;
	std::ifstream file("Input/Day02_sample.txt");
	long total = 0;
	
	while (std::getline(file, line))
	{
		std::stringstream ss(line, std::ios_base::in);
		bool valid = true;
		long last = -1;
		long numIncreassing = 0;
		long numDecreassing = 0;
		while (!ss.eof() && valid)
		{
			long x;
			ss >> x;
			if (last != -1)
			{
				long delta = last - x;
				if (delta > 0)
				{
					numIncreassing++;
				}
				else if (delta < 0)
				{
					numDecreassing++;
				}

				if (delta == 0 || std::abs(delta) > 3 || (numIncreassing > 0 && numDecreassing > 0))
				{
					valid = false;
				}
			}
			last = x;
		}
		if (valid)
		{
			total++;
		}
	}

	file.close();

	return total;
}


long Day02::Problem02()
{
	
	return 0;
}
