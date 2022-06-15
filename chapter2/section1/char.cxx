#include <cstdio>
#include <ctype.h>
#include <stdio.h>

using namespace std;


void hexdump(void *ptr, int buflen) {
  unsigned char *buf = (unsigned char*)ptr;
  int i, j;
  for (i=0; i<buflen; i+=16) {
    printf("%06x: ", i);
    for (j=0; j<16; j++)
      if (i+j < buflen)
        printf("%02x ", buf[i+j]);
      else
        printf("   ");
    printf(" ");
    for (j=0; j<16; j++)
      if (i+j < buflen)
        printf("%c", isprint(buf[i+j]) ? buf[i+j] : '.');
    printf("\n");
  }
}

int main() {
  char array[10][11] = {
    "0123456789", // => '0123456789\0'
    "0123456789",
    "0123456789",
    "0123456789",
    "0123456789",
    "0123456789",
    "0123456789",
    "0123456789",
    "0123456789",
    "0123456789",
  };

  hexdump(array, sizeof(array));

  printf("%s", (char*)array);
}
