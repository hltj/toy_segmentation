//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_ZH_CTYPE_H
#define JSEG_ZH_CTYPE_H

#include "typedef.h"
#include <map>

struct ZhCharClassification
{
	// 中文
	bool IsZh(ucs4_t ch);
	// 其他字符
	bool IsOther(ucs4_t ch)
	{
		return !IsZh(ch);
	}

	ZhCharClassification();
private:
	typedef std::map<ucs4_t, bool> CharClassMap;
	CharClassMap m_ccls_map;
};

#endif // JSEG_ZH_CTYPE_H
