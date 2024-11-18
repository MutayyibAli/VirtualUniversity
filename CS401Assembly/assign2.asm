[org 0x100]

                jmp start                       ; Jump to start of program

id              db 2, 3, 0, 4, 1, 6, 1, 7, 5    ; Student ID digits excluding "BC"
sum             db 0                            ; Memory location for storing sum of digits

start:          xor ax, ax                      ; Clear AX register

                lea si, [id]                    ; Load the address of studentID array into SI register
                mov cx, 9                       ; Set the loop counter to 9 (number of digits in studentID)

sum_digits:     add al, [si]                    ; Add the current digit to the sum in AL register
                inc si                          ; Move to the next digit in the array
                loop sum_digits                 ; Repeat until all digits are summed

                mov [sum], al                   ; Store the sum in the sum variable

                test al, 1                      ; Check if the sum is even or odd using bitwise AND
                jz even                         ; If zero, the sum is even, jump to even label
                mov dx, 0                       ; Otherwise, the sum is odd and set DX register to 0
                jmp done

even:           mov dx, 1                       ; Set DX register to 1 if the sum is even

done:           mov ax, 0x4C00                  ; Exit the program
                int 0x21                        ; Call the DOS interrupt to exit the program
