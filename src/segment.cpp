//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "segmentation.h"
#include "comm/ucs4stream.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage:" << argv[0] << " <ucs4-phrasing-file> <ucs4-dictionary> <ucs4-segmented-file>" << std::endl;
		exit(1);
	}

	std::ifstream fin(argv[1], std::ios::binary);
	if (!fin.is_open())
	{
		std::cerr << "Failed to open " << argv[1] << " for read." << std::endl;
		exit(2);
	}
	std::ifstream fdict(argv[2], std::ios::binary);
	if (!fdict.is_open())
	{
		std::cerr << "Failed to open " << argv[2] << " for read." << std::endl;
		exit(3);
	}
	std::ofstream fout(argv[3], std::ios::binary);
	if (!fout.is_open())
	{
		std::cerr << "Failed to open " << argv[3] << " for write." << std::endl;
		exit(4);
	}

	Segmentation seg;
	seg.LoadDict(fdict);

	while(!fin.eof())
	{
		ucs4string s;
		ucs4getline(fin, s);

		ucs4putstr(fout, seg.Segment(s));
		ucs4putch(fout, ucs4_t('\n'));
	}

	return 0;
}
