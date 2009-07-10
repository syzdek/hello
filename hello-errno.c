#include <stdio.h>
#include <errno.h>
static int k[] = { ESRCH,  6, ENOEXEC, 2, ENOENT, 10, ENOENT,  10,
                   ECHILD, 1, EBADF,   3, 255,    5,  E2BIG,   15,
                   EPIPE,  1, ENOTBLK, 1, EBADF,  2,  ENOEXEC, 4 };
int letter(const int * h)
{
   if ((h = &h[2]) > (k+24))
      return(0);
   return(write(1, &((const char *)strerror(h[-2]))[h[-1]], 1) ? letter(h): 0);
}
int main(void)
{
   return(letter(k));
}
