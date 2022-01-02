org 100h

;section .data     


;section .code

array DD 5 DUP(0)

prompt0: db "Please enter 5 numbers to find there GCD : $"

prompt1: db "The GCD of the set of value is : $"


;Part B

main PROC

mov ah,9        ; print prompt
mov dx,prompt0
int     21h

mov di, 5              ; set of values

mov si, OFFSET array   

l11:
    mov ax, 3          ; Read user input into str
    mov bx, 0          ; |
    mov cx, [si]        ; | <- destination
    mov dx, 100        ; | <- length
    int 80h       
    add si, 4
    dec di
    cmp di, 0
    jne l11


;mov cx, LENGTHOF array /2

mov si,OFFSET array


l1:

mov di,2


l3:

            mov ax,[si]

            add si,4

            cmp ax,0

            jl l9

            jmp l2

l9:

            neg ax

l2:

            push ax

            dec di

            cmp di,0

            jne l3

            call gcd                       
            
            loop l1
              
              
              
            mov dx, offset prompt1

            mov ah,9        ; print prompt
           
            mov dx,prompt1
           
            int     21h
           

 ;                       exit

main ENDP


;Part A

gcd proc

            pop di

            pop ax

            pop bx

gcd1:

            mov dx,0

            div bx

            mov ax,bx

            mov bx,dx

            cmp bx,0

            jg gcd1

            push di

ret

gcd endp

END main       

