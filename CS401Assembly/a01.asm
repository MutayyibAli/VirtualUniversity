            [org 0x0100]				; Start Program

            mov ax, 5                   ; Move constant to AX Register
            mov bx, [num1]              ; Move value stored in num1 to BX Register
            add ax, bx                  ; Add AX to BX and save it to AX

            mov ax, 0x4c00				; Terminate Program
            int 0x21

num1:       dw 10                       ; Make a variable named num1 and initialize it to 10