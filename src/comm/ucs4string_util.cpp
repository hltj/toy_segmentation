//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "ucs4string_util.h"
#include <deque>

ucs4string utoustr(unsigned int u)
{
	std::deque<ucs4_t> q;
	for (; u>0; u/=10)
		q.push_front(u % 10 + '0');
	return ucs4string(q.begin(), q.end());
}

ucs4string stdtoustr(const std::string& s)
{
	ucs4string us;
	for (size_t i=0; i<s.size(); ++i)
		us.push_back(s[i]);
	return us;
}

unsigned int ustrtou(const ucs4string& ustr)
{
	unsigned int u = 0;
	for (size_t i=0; i<ustr.size(); ++i)
	{
		ucs4_t ch = ustr[i];
		if (ch<'0' || ch>'9')
			break;

		u = u * 10 + (ch - '0');
	}
	return u;
}
