; Sorting a list of 10 numbers using bubble Sorting

[org 0x100]

                jmp start                                       ; Jump to location marked as Start

data:           dw 5, 8, 45, -15, 67, 15, 9, -2, 14, 0          ; Data to be sorted
swaped:           db 0                                            ; To check if there is no swap in an iteration then sorting is completed

start:          mov bx, 0                                       ; Initiate BX to zero
                mov byte [swaped], 0                            ; Reset swaped flag to no swap

loop1:          mov ax, [data + bx]                             ; Load 1st number of comparison in AX
                cmp ax, [data + bx + 2]                         ; Compare 1st number with 2nd number
                ja noswap                                       ; Jump if 1st number is greater than 2nd number and no swap is needed

swap:           mov dx, [data + bx + 2]                         ; Temporarily save 2nd number in DX
                mov [data + bx + 2], ax                         ; Save the 1st number in 2nd number location
                mov [data + bx], dx                             ; Save the temporary number in 1st number location
                mov byte [swaped], 1                            ; Set swaped flag to 1

noswap:         add bx,2                                        ; Move to next pair of numbers
                cmp bx, 18                                      ; Check if all pairs are compared
                jne loop1                                       ; Jump to loop1 if all pairs are not compared

                cmp byte [swaped], 1                            ; Check if any swap is done
                je start                                        ; Jump to start if any swap is done

                mov ax, 0x4c00                                  ; Exit the program
                int 0x21