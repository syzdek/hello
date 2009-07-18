#include <stdio.h>
static unsigned m[] = { 0x00000000, 0x1c082792, 0x92082092, 0x9208239e,
                        0x92082092, 0x1c79e792, 0x10000000, 0x9c13c622,
                        0xa4124922, 0xa411c92a, 0xa4124936, 0x9cf24622 };
unsigned * dot(unsigned * d)
{
   if ((*d = *d >> 1) == 1)
      return(write(1, "\033[0m\n", 5) ? d : d);
   return(write(1, (d[0] & 0x1) ? "\033[44m " : "\033[00m ", 6) ? dot(d) : d);
}
int line(unsigned * p)
{
   if (dot(p = &p[1]) > (m+10))
      return(0);
   return(line(p));
}
int main(void)
{
   return(line(m));
}
