//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "ucs4stream.h"
#include <iostream>

void ucs4getline(std::istream& is, ucs4string& ustr)
{
	while (!is.eof())
	{
		ucs4_t ch = ucs4_t('\n');
		is.read(reinterpret_cast<char *>(&ch), 4);

		if (ch == ucs4_t('\n'))
			break;
		ustr.push_back(ch);
	}
}

void ucs4putstr(std::ostream& os, const ucs4string& ustr)
{
	size_t bytes = ustr.size() * 4;
	os.write(reinterpret_cast<const char *>(ustr.data()), bytes);
}

void ucs4putch(std::ostream& os, ucs4_t ch)
{
	os.write(reinterpret_cast<const char *>(&ch), 4);
}
