//---------------------------------------------------------------------
// Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
// License:   LGPLv3
//---------------------------------------------------------------------
#ifndef JSEG_TYPEDEF_H
#define JSEG_TYPEDEF_H

#ifdef _WIN32
 typedef unsigned int  ucs4_t;
 typedef unsigned char uchar_t;
#else
# include <inttypes.h>
 typedef uint32_t ucs4_t;
 typedef uint8_t  uchar_t;
#endif

#endif //JSEG_TYPEDEF_H
