; Assignment 1

[org 0x0100]

                jmp start                                                   ; Jump to the start of the program

firstname:      db 0x4D, 0x75, 0x74, 0x61, 0x79, 0x79, 0x69, 0x62, 0x00     ; "Mutayyib" in ASCII
count:          db 5

countletters:   push bp                                                     ; Save the base pointer to stack
                mov bp, sp                                                  ; Set the base pointer to the stack pointer
                push si                                                     ; Save the source index to stack
                push bx                                                     ; Save the base index to stack
                mov bx, [bp+4]                                              ; Set the base index to the first character of name
                mov si, 0                                                   ; Set the source index to 0

loop1:          inc si                                                      ; Increment the source index
                cmp byte [bx+si-1], 0                                       ; Check if the character is null
                jne loop1                                                   ; If not, repeat the loop

                mov [count], si                                             ; Set the count to the source index
                pop bx                                                      ; Restore the base index from stack
                pop si                                                      ; Restore the source index from stack
                pop bp                                                      ; Restore the base pointer from stack
                ret 2                                                       ; Return from the function and remove the arguments

start:          mov ax, [firstname]                                         ; Load the address of the first character of name to ax
                push ax                                                     ; Push the address to stack
                call countletters                                           ; Call the countletters function

                mov ax, 1                                                   ; Initialize the ax register to 1
                mov bl, [count]                                             ; Load the count to bl

loop2:          shl ax, 1                                                   ; Shift the ax register to the left to multiply by 2
                dec bl                                                      ; Decrement the count
                cmp bl, 0                                                   ; Check if the count is 0
                jne loop2                                                   ; If not, repeat the loop

                mov ax, 0x4C00                                              ; Exit the program
                int 0x21