#ifndef _CDLIB_UTILITY_H
#define _CDLIB_UTILITY_H
#include "stdafx.h"
#include <math.h>

#ifndef M_PI
#undef M_PI
#define M_PI		3.14159265358979323846
#endif

namespace CDLib
{
	template <class T> const T& max(const T& a, const T& b)
	{
		return (a < b ? b : a);
	}

	template <class T> const T& min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}

	template <class T> const T abs(const T& a)
	{
		if( a < 0 ) return -a; else return a;
	}

	template <> inline const float abs(const float& a)
	{
		return fabs(a);
	} 

	template <class T> const T rad2deg(T rad)
	{
		return rad * 180 / M_PI;
	}

	template <class T> const T deg2rad(T deg)
	{
		return deg * M_PI / 180;
	}

	template <class T> const bool inrange(T value, T min, T max)
	{
		if( value >= min && value <= max )
			return true;
		else return false;
	}

	template <class T> void swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}

	
	inline double frand()
	{
		return rand() / (double)RAND_MAX;
	}

	inline double frand(double a, double b)
	{
		return (b-a)*frand() + a;
	}

	inline std::string fgetline(FILE* fp)
	{
		std::string retval;
		char data;
		while( fread(&data, 1, 1, fp) != 0 )
		{
			if( data == '\n' )
			{
				retval.push_back(0);
				return retval;
			}
			else
				retval.push_back(data);
		}

		return retval;
	}

	inline int tokenize(std::string str, std::string delim, std::vector<std::string>& tokens)
	{
		std::string tmp;
		int token_count=1;
		for(unsigned i=0; i<str.size(); i++)
		{
			//If we cannot find the current char in the delimiter list,
			//append to the current token
			if( delim.find(str[i]) == delim.npos )
			{
				tmp += str[i];
			}

			//Otherwise, if we have found it, and tmp.size() > 0, 
			//add to the token list and start a new token
			else if(tmp.size() > 0)
			{
				tokens.push_back(tmp);
				tmp.erase();
				token_count++;
			}
		}	

		if(tmp.size() > 0)
			tokens.push_back(tmp);
		return token_count;	
	} 
}
#endif

