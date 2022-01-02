GCD(int, int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi
        mov     DWORD PTR [rbp-24], esi
        mov     eax, DWORD PTR [rbp-20]
        sar     eax, 31
        xor     DWORD PTR [rbp-20], eax
        sub     DWORD PTR [rbp-20], eax
        mov     eax, DWORD PTR [rbp-24]
        sar     eax, 31
        xor     DWORD PTR [rbp-24], eax
        sub     DWORD PTR [rbp-24], eax
.L3:
        mov     eax, DWORD PTR [rbp-20]
        cdq
        idiv    DWORD PTR [rbp-24]
        mov     DWORD PTR [rbp-4], edx
        mov     eax, DWORD PTR [rbp-24]
        mov     DWORD PTR [rbp-20], eax
        mov     eax, DWORD PTR [rbp-4]
        mov     DWORD PTR [rbp-24], eax
        cmp     DWORD PTR [rbp-24], 0
        jle     .L2
        jmp     .L3
.L2:
        mov     eax, DWORD PTR [rbp-20]
        pop     rbp
        ret