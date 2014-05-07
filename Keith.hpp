#ifndef KEITH_H_INCLUDED
#define KEITH_H_INCLUDED

#include "Types.hpp"


extern void FindKeiths
 (
 ulong pLimit
 );
extern void *FindKeithsThread
 (
 void *pState
 );

extern bool IsKeith
 (
 ulong pNum
 );


#endif // KEITH_H_INCLUDED
