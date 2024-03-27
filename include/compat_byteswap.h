#ifndef HAVE_COMPAT_BYTESWAP_H
#define HAVE_COMPAT_BYTESWAP_H

#if defined(__GLIBC__) || defined(__BIONIC__) || defined(__CYGWIN__)
 #include <byteswap.h>
#elif defined(__APPLE__)
// Make sure that byte swap functions are not already defined.
#if !defined(bswap_16)
// Mac OS X / Darwin features
#include <libkern/OSByteOrder.h>
#define bswap_16(x) OSSwapInt16(x)
#define bswap_32(x) OSSwapInt32(x)
#define bswap_64(x) OSSwapInt64(x)
#endif
#endif

#endif