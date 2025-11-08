#include <stdio.h>

int main(void)
{
    unsigned int i = 0xAABBCCDD;
    unsigned char *ptr = (unsigned char *)&i;

    printf("Zawartość pamięci (bajty):\n");
    for (int j = 0; j < sizeof(i); j++) {
        printf("Bajt %d: 0x%02X\n", j, ptr[j]);
    }

    if (ptr[0] == 0xDD) {
        printf("\nTwój komputer używa LITTLE ENDIAN.\n");
    } else if (ptr[0] == 0xAA) {
        printf("\nTwój komputer używa BIG ENDIAN.\n");
    } else {
        printf("\nNieznana kolejność bajtów.\n");
    }

    return 0;
}
