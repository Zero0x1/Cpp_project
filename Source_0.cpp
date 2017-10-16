#pragma once
#ifndef _HEADER_
#define _HEADER_

#define _NSP_BEGIN namespace nsp {
#define _NSP_END }

#include <iostream>
#include <vector>
//#include <fstream>
//#include <ctime>
#include <memory>
#include <string>
//#include <functional>

_NSP_BEGIN
unsigned int fact(unsigned int x)
{
	if (x == 1) { return 1; }

	return x * fact(x - 1);
}

int beSearch(std::vector<int> n, int v)
{
	size_t size = n.size();

	size_t low = 0;
	size_t hight = size - 1;

	while (low <= hight)
	{
		size_t mid = (low + hight) / 2;

		if (v == n[mid])
		{
			std::cout << "Value: " << v << std::endl
				<< "Search index: " << mid << std::endl;

			return 0;
		}

		else if (v > n[mid])
		{
			low = mid + 1;
		}

		else
		{
			hight = mid - 1;
		}
	}

	return 1;
}

void squareBruteForce(double n)
{
	double epicilon = 0.01;
	int numGuesses = 0;
	double ans = 0.0;

	while (abs(pow(ans, 2) - n) >= epicilon)
	{
		ans += 0.00001;
		numGuesses += 1;
	}

	std::cout << ans << " close to square root of " << n << " with " << numGuesses << " number of guesses" << std::endl;
}

void squareBeSearch(double n)
{
	double epicilon = 0.01;
	int numGuesses = 0;

	double low = 0;
	double hight = n;

	double guess = (low + hight) / 2.0;

	while (abs(pow(guess, 2) - n) >= epicilon)
	{
		if (pow(guess, 2) < n)
		{
				low = guess;
		}

		else
		{
			hight = guess;
		}

		guess = (low + hight) / 2.0;
		numGuesses += 1;
	}

	std::cout << guess << " close to square root of " << n << " with " << numGuesses << " number of guesses" << std::endl;
}

void swap_(int& a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

char* cryCaesar(char* str)
{
	char str_norm[] = "abcdefghijklmnopqrstuvwxyz ";
	char str_cry[] = "defghijklmnopqrstuvwxyzabc ";

	size_t size_str = strlen(str);

	char* str_res = new char[size_str];

	str_res[size_str] = '\0';

	for (size_t i(0); i < size_str; i++)
	{
		for (size_t j(0); j < 27; j++)
		{
			if (str[i] == str_norm[j])
			{
				str_res[i] = str_cry[j];
				break;
			}
		}
	}

	return str_res;
}
_NSP_END
#endif //_HEADER_