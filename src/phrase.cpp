//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "phrasing.h"
#include "comm/ucs4stream.h"

#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage:" << argv[0] << " <ucs4-text-file> <ucs4-phrase-file>" << std::endl;
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

	setlocale(LC_ALL, "");

	Phrasing phr(fout);

	while(!fin.eof())
	{
		ucs4string ustr;
		ucs4getline(fin, ustr);

		phr.Phrase(ustr);
	}

	std::cout << "Max phrase length: " << phr.MaxLength() << std::endl;
	std::cout << "Phrases count: " << phr.Count() << std::endl;

	CountMap::const_iterator it = phr.GetStatistics().begin();
	CountMap::const_iterator itend = phr.GetStatistics().end();
	for(; it!=itend; ++it)
	{
		std::cout << "[ " << it->first << " ]: " << it->second << std::endl;
	}

	return 0;
}
