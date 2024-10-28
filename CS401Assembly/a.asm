            [org 0x0100]				; Start Program

            mov ax, 5                   ; Move constant to AX Register
            mov bx, [num1]              ; Move value stored in num1 to BX Register
            add ax, bx                  ; Add AX to BX and save it to AX

            mov ax, [list1]             ; Move first value from list1 to AX
            mov bx, [list1 + 2]         ; Move second value from list1 to AX
            add ax, bx
            mov bx, [list1 + 4]
            add ax, bx
            mov bx, [list1 + 6]
            add ax, bx
            mov bx, [list1 + 8]
            add ax, bx

            mov ax, 0x4c00				; Terminate Program
            int 0x21

num1:       dw 10                       ; Make a variable named num1 and initialize it to 10
list1:      dw 2                       ; Save multiple values like array in a variable
            dw 4
            dw 6,8,10