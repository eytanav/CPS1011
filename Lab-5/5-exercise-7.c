#include <stdio.h>
#include <stdint.h>

union IPv4Address
{
    uint32_t address;
    uint8_t octets[4];
};

int main()
{
    union IPv4Address ip;
    unsigned int octet1, octet2, octet3, octet4;

    printf("Enter an IPv4 address in octet form (e.g. 192.168.100.24): ");
    scanf("%u.%u.%u.%u", &octet1, &octet2, &octet3, &octet4);

    // swapping order as else hex address will be in reverse order
    ip.octets[3] = (uint8_t)octet1;
    ip.octets[2] = (uint8_t)octet2;
    ip.octets[1] = (uint8_t)octet3;
    ip.octets[0] = (uint8_t)octet4;

    printf("IPv4 Address (Octet Form): %u.%u.%u.%u\n", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);

    printf("IPv4 Address (Hexadecimal): 0x%08X\n", ip.address);

    return 0;
}
