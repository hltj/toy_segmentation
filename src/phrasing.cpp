//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "phrasing.h"
#include "comm/zh_ctype.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const ucs4string& ustr)
{
	size_t bytes = ustr.size() * 4;
	ucs4_t newline = (ucs4_t)'\n';
	os.write(reinterpret_cast<const char *>(ustr.data()), bytes);
	os.write(reinterpret_cast<const char *>(&newline), 4);
	return os;
}

void Phrasing::CheckPhrase(ucs4string& tmp_ustr)
{
	if (tmp_ustr.empty())
		return;

	m_fout << tmp_ustr;

	size_t len = tmp_ustr.size();
	++m_count_map[len];

	m_maxlen = (m_maxlen < len)? len: m_maxlen;
	++m_count;

	tmp_ustr.clear();
}

void Phrasing::Phrase(const ucs4string& ustr)
{
	ucs4string tmp_ustr;
	static ZhCharClassification zhccls;
	for (size_t i=0; i<ustr.size(); ++i)
	{
		ucs4_t ch = ustr[i];
		if (zhccls.IsZh(ch))
			tmp_ustr.push_back(ch);
		else
			CheckPhrase(tmp_ustr);
	}
	CheckPhrase(tmp_ustr);
}
