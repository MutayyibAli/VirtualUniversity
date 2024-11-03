# Commands

> [org 0x0100] ;Start of Program

> mov ax, 0x4c00 | Terminate Program
> int 0x21

| Code              | Comment                                |
| ----------------- | -------------------------------------- |
| db                | Declare Byte                           |
| dw                | Declare Word                           |
| dd                | Declare Double                         |
| [num]             | Address of num                         |
| jmp start         | Unconditional Jump                     |
| mov ax, 5         | Move 5 -> ax                           |
| mov byte [num], 5 | Move 5 (as byte) -> num                |
| add ax, bx        | Add ax+bx                              |
| adc ax, bx        | Add with carry ax+bx+1                 |
| sub cx, 5         | Subtract cx-5                          |
| inc cx            | cx+1                                   |
| dec cx            | cx-1                                   |
| cmp ax, bx        | Subtract ax-bx (Don't change ax or bx) |
| xchg ax, bx       | Exchange ax <--> bx                    |
| push ax           | Push on Stack                          |
| pop ax            | Pop from Stack                         |
| call b            | Call                                   |
| ret               | Return                                 |
| ret 6             | Return and decrement SP by 6           |

### Jumps

| Code | Comment             | Opposite |
| ---- | ------------------- | -------- |
| jz   | Jump if Zero        | jnz      |
| je   | Jump if Equal       | jne      |
| jcxz | Jump if CX = 0      |
| jc   | Jump if Carry       | jnc      |
| jo   | Jump if Overflow    | jno      |
| js   | Jump if Sign        | jns      |
| jp   | Jump if Parity      | jnp      |
| jpe  | Jump if Parity Even | jpo      |

> Above or Below -- For Unsigned Numbers

| Code | Comment                     | Opposite |
| ---- | --------------------------- | -------- |
| jb   | Jump if Below [CF=1]        | jnb      |
| jnae | Jump if not above or equal  | jae      |
| ja   | Jump if Above [ZF=0 & CF=0] | jna      |
| jnbe | Jump if not Below or Equal  | jbe      |

> Greater or Less -- For Signed Numbers

| Code | Comment                        | Opposite |
| ---- | ------------------------------ | -------- |
| jl   | Jump if Less [SF != OF]        | jnl      |
| jnge | Jump if not Greater or Equal   | jge      |
| jg   | Jump if Greater [ZF=0 & SF=OF] | jng      |
| jnle | Jump if not Less or Equal      | jle      |

### Bit Manipulations

| Code | Comment                    | Opposite |
| ---- | -------------------------- | -------- |
| shr  | Shift Logical Right        | shl      |
| sar  | Shift Arithmetic Right     | sal      |
| ror  | Rotate Right               | rol      |
| rcr  | Rotate through Carry Right | rcl      |
| and  |
| or   |
| xor  |
| not  |
| test | Selective Bit Testing      |

> **Set the Bit which are to be changes**
> Selective Bit Clearing -- AND
> Selective Bit Setting -- OR
> Selective Bit Inversion -- XOR
> Selective Bit Testing -- AND

### Addressing Modes [base + index + offset]

| Type                               | Example 1       | Example 2  | Example 3 | Example 4 |
| ---------------------------------- | --------------- | ---------- | --------- | --------- |
| Direct                             | [ax]            | [bx]       | [cx]      |
| Based Register Indirect            | [bx]            | [bp]       |
| Indexed Register Indirect          | [si]            | [di]       |
| Based Register Indirect + Offset   | [bx + 200]      | [bp + 100] |
| Indexed Register Indirect + Offset | [si + 50]       | [di + 36]  |
| Base + Index                       | [bx + si]       | [bp + di]  | [bx + di] | [bp + si] |
| Base + Index + Offset              | [bx + si + 300] |

## Registers in iAPX88 (8088) (1MB Memory)

> **14 Registers**

### General Registers

- AX -- Accumulator Register
- BX -- Base Register
- CX -- Counter Register
- DX -- Destination Register

### Other Registers

| Segment Registers   | Pointer Registers         | Index Registers         |
| ------------------- | ------------------------- | ----------------------- |
| CS -- Code Segment  | IP -- Instruction Pointer |
| DS -- Data Segment  | SI -- Source Index        | DI -- Destination Index |
| SS -- Stack Segment | SP -- Stack Pointer       | BP -- Base Pointer      |
| ES -- Extra Segment |

> [cs:bx] -- Segment override prefix can be used to change segment association

### Flags (9)

> **[- - - - O D I T S Z - A - P - C]**

- C -- Carry Flag
- P -- Parity Flag
- A -- Auxiliary Flag
- Z -- Zero Flag
- S -- Sign Flag
- T -- Trap Flag
- I -- Interrupt Flag
- D -- Direction Flag
- O -- Overflow Flag

## Instruction Groups

- Data Movement Group
- Arithmetic and Logic Group
- Program Control Group
