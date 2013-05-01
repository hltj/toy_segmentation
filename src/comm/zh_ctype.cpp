//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#include "zh_ctype.h"

bool ZhCharClassification::IsZh(ucs4_t ch)
{
	CharClassMap::const_iterator it = m_ccls_map.lower_bound(ch);
	return (it != m_ccls_map.end())? it->second: false;
}

ZhCharClassification::ZhCharClassification()
{
	// 以下 Unicode 6.2 字符當作中文識別：
	//  U+2E80 -  U+2EFF    中日韓越部首補充
	//  U+2F00 -  U+2FDF    中日韓越部首/康熙部首
	//  U+2FF0 -  U+2FFF    漢字結構描述字符
	//  U+3005 -  U+3005    "々"
	//  U+31C0 -  U+31EF    中日韓越筆畫
	//  U+3400 -  U+4DBF    中日韓越統一表意文字擴展區A
	//  U+4E00 -  U+9FCF    中日韓越統一表意文字（漢）
	//  U+E000 -  U+F8FF    私用造字區
	//  U+F900 -  U+FAFF    中日韓越兼容表意文字
	// U+20000 - U+2A6DF    中日韓越統一表意文字擴展區B
	// U+2A700 - U+2B73F    中日韓越統一表意文字擴展區C
	// U+2B740 - U+2B81F    中日韓越統一表意文字擴展區D
	// U+2F800 - U+2FA1F    中日韓越兼容表意文字增補區
	m_ccls_map[ 0x2E80-1]=false; m_ccls_map[ 0x2EFF]=true;
	m_ccls_map[ 0x2F00-1]=false; m_ccls_map[ 0x2FDF]=true;
	m_ccls_map[ 0x2FF0-1]=false; m_ccls_map[ 0x2FFF]=true;
	m_ccls_map[ 0x3005-1]=false; m_ccls_map[ 0x3005]=true;
	m_ccls_map[ 0x31C0-1]=false; m_ccls_map[ 0x31EF]=true;
	m_ccls_map[ 0x3400-1]=false; m_ccls_map[ 0x4DBF]=true;
	m_ccls_map[ 0x4E00-1]=false; m_ccls_map[ 0x9FCF]=true;
	m_ccls_map[ 0xE000-1]=false; m_ccls_map[ 0xF8FF]=true;
	m_ccls_map[ 0xF900-1]=false; m_ccls_map[ 0xFAFF]=true;
	m_ccls_map[0x20000-1]=false; m_ccls_map[0x2A6DF]=true;
	m_ccls_map[0x2A700-1]=false; m_ccls_map[0x2B73F]=true;
	m_ccls_map[0x2B740-1]=false; m_ccls_map[0x2B81F]=true;
	m_ccls_map[0x2F800-1]=false; m_ccls_map[0x2FA1F]=true;

	m_ccls_map[0x10FFFF]=false;
}
