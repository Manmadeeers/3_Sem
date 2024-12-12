#pragma once

#define ASM_HEAD \
<< ".586P" << endl \
<< ".MODEL FLAT, STDCALL" << endl \
<< "includelib kernel32.lib" << endl << endl\
<< "ExitProcess PROTO : DWORD" << endl\
<< "MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD" << endl << endl\
<< ".STACK 4096" << endl << endl\
<< ".CONST" << endl << endl \
<< ".DATA" << endl << endl \

#define ASM_FOOTER \
<< "\n.CODE" << endl \
<< "main PROC" << endl \
<< "mov \t EAX, INT_VAL" << endl \
<< "mov \t EBX, UINT_LIT" << endl \
<< "push 0" << endl \
<< "call ExitProcess" << endl \
<< "main ENDP" << endl \
<< "end main" << endl \

