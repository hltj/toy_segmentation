//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "segmentation.h"
#include "comm/ucs4stream.h"
#include "comm/ucs4string_util.h"

#include <math.h>
#include <iostream>

void Segmentation::LoadDict(std::istream& dict_is)
{
	unsigned int sum = 0;
	unsigned int word_max_len = 0;
	typedef std::vector<ucs4string> UStrVec;
	while (!dict_is.eof())
	{
		ucs4string s;
		ucs4getline(dict_is, s);

		UStrVec usvec;
		ustrslipt(s, ucs4_t(' '), usvec);

		if (usvec.size() != 2)
			continue;

		ucs4string& word = usvec[0];
		ucs4_t cnt = ustrtou(usvec[1]);

		m_dict_map[word] = cnt;
		sum += cnt;

		if (word_max_len < word.size())
			word_max_len = word.size();
	}
	m_word_sum = sum * 1.0;
	m_max_rr = pow(m_word_sum, word_max_len+1.0);
}

ucs4string Segmentation::Segment(const ucs4string& ustr)
{
	SegmentData data;
	DoSegment(ucs4string(), 1.0, ustr, data);

	if (data.m_res.empty())
		return ustr;

	return data.m_res;
}

void Segmentation::DoSegment(ucs4string base, double base_rr, ucs4string to_seg, SegmentData& data)
{
	for (size_t i=1; i<to_seg.size(); ++i)
	{
		ucs4string us = to_seg.substr(0, i);
		DoSegment(base + ucs4_t(' ') + us, base_rr*GetRateReciprocal(us), to_seg.substr(i), data);
	}

	double rr = base_rr*GetRateReciprocal(to_seg);
	if (rr > data.m_rr)
		return;

	data.m_rr = rr;
	data.m_res = base + ucs4_t(' ') + to_seg;
}

double Segmentation::GetRateReciprocal(const ucs4string& ustr)
{
	DictMap::const_iterator it = m_dict_map.find(ustr);
	if (it == m_dict_map.end() || it->second==0)
		return m_max_rr;

	return m_word_sum / it->second;
}

