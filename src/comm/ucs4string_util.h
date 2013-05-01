//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_UCS4_STRING_UTIL_H
#define JSEG_UCS4_STRING_UTIL_H

#include "ucs4string.h"

ucs4string utoustr(unsigned int u);

ucs4string stdtoustr(const std::string& s);

unsigned int ustrtou(const ucs4string& ustr);

template<typename C>
void ustrslipt(const ucs4string& ustr, ucs4_t delim, C& c)
{
	ucs4string us;
	for (size_t i=0; i<ustr.size(); ++i)
	{
		ucs4_t ch = ustr[i];
		if (ch==delim && !us.empty())
		{
			c.push_back(us);
			us.clear();
		}
		else
		{
			us.push_back(ch);
		}
	}
	if (!us.empty())
		c.push_back(us);
}

#endif // JSEG_UCS4_STRING_UTIL_H
