.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD,:DWORD,:DWORD,:DWORD

.STACK 4096


.DATA


NUM1 DD 1
NUM2 DD 6


STR1 DB "My second program",0
STR2 DB "Sum:", 0

.CODE

main PROC
START:
    
    MOV EAX, NUM1
    ADD EAX ,NUM2
    ADD EAX,48

    MOV STR2+4,AL
   

    INVOKE MessageBoxA,0,OFFSET STR2,OFFSET STR1,0 

    push 0
    call ExitProcess
main ENDP
END main