; Assignment 1

[org 0x0100]

                jmp start

firstname:      db 0x4D, 0x75, 0x74, 0x61, 0x79, 0x79, 0x69, 0x62, 0x00       ; "Mutayyib"
count:          db 0

countletters:   push bp
                mov bp, sp
                push si
                push bx
                mov bx, [bp+4]
                mov si, 0

loop1:          inc si
                cmp byte [bx+si-1], 0
                jne loop1

                mov [count], si
                ret 2

start:          mov ax, [firstname]
                push ax
                call countletters

                mov ax, 1
                mov cx, count

loop:           shl ax, 1
                dec cx
                cmp cx, 0
                jne loop

                mov ax, 0x4C00
                int 0x21