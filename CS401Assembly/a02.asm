; Sorting a list of 10 numbers using bubble Sorting

[org 0x100]

                jmp start                                       ; Jump to location marked as Start

data:           dw 5, 8, 45, -15, 67, 15, 9, -2, 14, 0          ; Data to be sorted
swap:           db 0                                            ; To check if there is no swap in an iteration then sorting is completed

start:          mov bx, 0                                       ; Initiate BX to zero
                mov byte [swap], 0                              ; Reset swap flag to no swap

loop1:           mov ax, [data + bx]
                cmp ax, [data + bx + 2]
                jbe noswap

    b           mov dx, [data + bx + 2]
                mov [data + bx + 2], ax
                mov [data + bx], dx
                mov byte [swap], 1

noswap:         add bx,2
                cmp bx, 18
                jne loop1

                cmp byte [swap], 1
                je start

                mov ax, 0x4c00
                int 0x21