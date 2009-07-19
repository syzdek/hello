/* gcc -o hello-sine hello-sine.c -lm */
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <math.h>
double HelloWorld(double x, double h, double w, int z)
{
   printf("\033[%i;%iH\033[1;%im%c\033[0m",
      (int)((sin(((x-((double)(z*2)))*(360.0/h))/57.3)*(h/2.0))+((h/2.0)+1.0)),
      (int)((sin(((x-((double)(z*2)))*(360.0/w))/57.3)*(w/2.0))+((w/2.0)+1.0)),
      30+(z%8) , __FUNCTION__[z]);
   return(z++ < 10 ? HelloWorld(x, h, w, z) : 1.0);
}
int main(int argc, char * argv[])
{
   double x = 0.0, b[512];
#ifdef TIOCGSIZE
   J1: x += HelloWorld(x, ((struct ttysize *)b)->ts_lines,
            ioctl(0,TIOCGSIZE,&b) ? 80 : ((struct ttysize *)b)->ts_cols, 0);
#else
   J1: x += HelloWorld(x, ((struct winsize *)b)->ws_row,
            ioctl(0,TIOCGWINSZ,&b) ? 80 : ((struct winsize *)b)->ws_col, 0);
#endif
   fflush(stdout);
   usleep(90000);
   printf("\033[2J\033[512;512H");
   goto *(&&J1);
}
