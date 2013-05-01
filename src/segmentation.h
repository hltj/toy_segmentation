//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_SEGMENTATION_H
#define JSEG_SEGMENTATION_H

#include "comm/ucs4string.h"
#include <iosfwd>
#include <map>
#include <vector>
#include <limits>

typedef std::map<ucs4string, unsigned int> DictMap;

struct Segmentation
{
	void LoadDict(std::istream& dict_is);
	ucs4string Segment(const ucs4string& ustr);

	Segmentation(): m_word_sum(1.0), m_max_rr(1.0) {}
private:
	struct SegmentData
	{
		double m_rr;
		ucs4string m_res;
		SegmentData(): m_rr(std::numeric_limits<double>::max()) {}
	};

	double GetRateReciprocal(const ucs4string& ustr);
	void DoSegment(ucs4string base, double base_rr, ucs4string to_seg, SegmentData& data);

	DictMap m_dict_map;
	double m_word_sum;
	double m_max_rr;
};

#endif // JSEG_SEGMENTATION_H
