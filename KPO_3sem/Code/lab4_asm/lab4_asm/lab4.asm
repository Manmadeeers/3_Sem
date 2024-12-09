	.586P
	.MODEL FLAT, STDCALL
	includelib kernel32.lib

	ExitProcess PROTO:DWORD
	MessageBoxA PROTO:DWORD,:DWORD,:DWORD,:DWORD

	.STACK 4096

	.CONST

	.DATA

	MB_OK EQU 0
	STR1 DB "My fourth ASM program",0
	STR2 DB ?
	

	.CODE

	main PROC
	START:
	
		
		INVOKE MessageBoxA, 0, OFFSET STR2, OFFSET STR1, MB_OK

		push 0
		call ExitProcess
	main ENDP

	end main