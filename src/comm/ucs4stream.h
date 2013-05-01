//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_UCS4_STREAM_H
#define JSEG_UCS4_STREAM_H

#include "ucs4string.h"
#include <iosfwd>

void ucs4getline(std::istream& is, ucs4string& ustr);

void ucs4putstr(std::ostream& os, const ucs4string& ustr);

void ucs4putch(std::ostream& os, ucs4_t ch);

#endif // JSEG_UCS4_STREAM_H
