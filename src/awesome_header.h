#ifndef _AWESOME_HEADER_
#define _AWESOME_HEADER_

#ifdef __cplusplus
extern "C"
{
#endif

int openFunction(int param);
void closedFunction();
void closedFunctionWithPublic();

//closedFunctionWithPublic helper
void publicFunction();

#ifdef UNIT
void privateFunction();
#endif

#ifdef __cplusplus
} //extern "C"
#endif
#endif //_AWESOME_HEADER_