//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_DICT_GEN_H
#define JSEG_DICT_GEN_H

#include "comm/ucs4string.h"

#include <map>

typedef std::map<ucs4string, unsigned int> DictMap;

struct DictionaryGenerator
{
	void SetmentPhrase(const ucs4string& ustr);

	const DictMap& GetDictionary()
	{
		return m_dict;
	}

private:
	DictMap m_dict;
};

#endif // JSEG_DICT_GEN_H
