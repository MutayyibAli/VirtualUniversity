; Bubble Sort subroutine

[org 0x0100]

            jmp start

data1:      dw 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5
data2:      dw 328, 329, 898, 8923, 8293, 2345, 10, 877, 355, 98
            dw 888, 533, 2000, 1020, 30, 200, 761, 167, 90, 5

bubblesort: push bp                     ; save base pointer
            mov bp, sp                  ; set base pointer to stack pointer to access the passed arguments
            sub sp, 2                   ; allocate space for local variables
            push ax                     ; save registers used in the subroutine
            push bx                     ; -do-
            push cx                     ; -do-
            push si                     ; -do-

            mov bx, [bp+6]              ; bx = address of the array
            mov cx, [bp+4]              ; cx = number of elements in the array
            dec cx                      ; decrement cx because number of comparisons is 1 less than number of elements
            shl cx, 1                   ; multiply cx by 2 to convert to byte count

mainloop:   mov si, 0                   ; set si to 0 to start from the beginning of the array
            mov word [bp-2], 0          ; flag to check if any swap was made

innerloop:  mov ax, [bx+si]             ; at ax to 1st element of comparison
            cmp ax, [bx+si+2]           ; compare with the next element
            ja noswap                   ; if ax > [bx+si+2] then no swap is needed

swap:       xchg ax, [bx+si+2]          ; swap the elements
            mov [bx+si], ax             ; -do-
            mov word [bp-2], 1          ; set flag to 1 to indicate a swap was made

noswap:     add si, 2                   ; move to the next element
            cmp si, cx                  ; check if end of array is reached
            jl innerloop                ; if not, continue inner loop

            cmp word [bp-2], 0          ; check if any swap was made
            je mainloop                 ; if swap was made, repeat the main loop

            pop si                      ; restore registers
            pop cx                      ; -do-
            pop bx                      ; -do-
            pop ax                      ; -do-
            mov sp, bp                  ; restore stack pointer
            pop bp                      ; restore base pointer
            ret 4                       ; return and remove arguments from the stack (2 arguments * 2 bytes each)

start:      mov ax, data1               ; call bubblesort subroutine for data1
            push ax                     ; push the address of the array
            mov ax, 10                  ; push the number of elements in the array
            push ax                     ; -do-
            call bubblesort             ; call the subroutine

            mov ax, data2               ; call bubblesort subroutine for data2
            push ax                     ; push the address of the array
            mov ax, 20                  ; push the number of elements in the array
            push ax                     ; -do-
            call bubblesort             ; call the subroutine

            mov ax, 0x4c00              ; exit program
            int 0x21