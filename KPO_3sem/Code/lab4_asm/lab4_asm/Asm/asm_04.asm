.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

INT_VAL 	 SDWORD 23
BOOL_LIT 	 BYTE 1

.CODE
main PROC
mov 	 EAX, INT_VAL
mov 	 EBX, UINT_LIT
push 0
call ExitProcess
main ENDP
end main
