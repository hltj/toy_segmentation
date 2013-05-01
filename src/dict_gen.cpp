//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "dict_gen.h"

void DictionaryGenerator::SetmentPhrase(const ucs4string& ustr)
{
	size_t len = ustr.size();
	for (size_t i0=0; i0<len; ++i0)
	{
		for(size_t i1=1; i1<len-i0+1; ++i1)
		{
			++m_dict[ustr.substr(i0, i1)];
		}
	}
}
