#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <math.h>
double HelloWorld(double x, double w, int z)
{
   printf("\033[%i;%iH%c", z+1, (int)((sin(((x-((double)(z*2)))*(360.0/w))/57.3)*(w/2.0))+((w/2.0)-1.0)), __FUNCTION__[z]);
   return(z++ < 10 ? HelloWorld(x, w, z) : 1.0);
}
int main(int argc, char * argv[])
{
   double x = 0.0;
   struct ttysize ts;
   J1: x += HelloWorld(x, (double)ts.ts_cols, ioctl(0, TIOCGWINSZ, &ts));
   fflush(stdout);
   usleep(60000);
   printf("\033[2J\033[512;512H");
   goto *(&&J1);
}
