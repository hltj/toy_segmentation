//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_PHRASING_H
#define JSEG_PHRASING_H

#include "comm/ucs4string.h"
#include <iosfwd>
#include <map>

typedef std::map<size_t, unsigned int> CountMap;

struct Phrasing
{
	Phrasing(std::ostream& os)
		: m_fout(os), m_maxlen(0), m_count(0)
	{
	}

	void CheckPhrase(ucs4string& us_tmp);

	void Phrase(const ucs4string& ustr);

	size_t MaxLength()
	{
		return m_maxlen;
	}

	size_t Count()
	{
		return m_count;
	}

	const CountMap& GetStatistics()
	{
		return m_count_map;
	}

private:

	std::ostream& m_fout;
	CountMap m_count_map;
	size_t m_maxlen;
	unsigned int m_count;
};

#endif // JSEG_PHRASING_H
