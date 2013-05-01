//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "dict_gen.h"
#include "comm/ucs4stream.h"
#include "comm/ucs4string_util.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage:" << argv[0] << " <ucs4-phrase-file> <ucs4-dictionary>" << std::endl;
		exit(1);
	}

	std::ifstream fin(argv[1], std::ios::binary);
	if (!fin.is_open())
	{
		std::cerr << "Failed to open " << argv[1] << " for read." << std::endl;
		exit(2);
	}
	std::ofstream fout(argv[2], std::ios::binary);
	if (!fout.is_open())
	{
		std::cerr << "Failed to open " << argv[2] << " for write." << std::endl;
		exit(3);
	}

	DictionaryGenerator dg;

	while (!fin.eof())
	{
		ucs4string s;

		ucs4getline(fin, s);

		dg.SetmentPhrase(s);
	}

	DictMap::const_iterator it = dg.GetDictionary().begin();
	DictMap::const_iterator itend = dg.GetDictionary().end();
	for (; it!=itend; ++it)
	{
		const ucs4string ustr=it->first;
		unsigned int cnt=it->second;
		if (cnt==1 && ustr.size()!=1)
			continue;
		ucs4putstr(fout, ustr);
		ucs4putstr(fout, stdtoustr(" "));
		ucs4putstr(fout, utoustr(cnt));
		ucs4putch(fout, ucs4_t('\n'));
	}

	return 0;
}
