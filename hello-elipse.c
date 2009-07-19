/* gcc -o hello-elipse hello-elipse.c -lm */
#include <stdio.h>
#include <math.h>
#include <termios.h>
#include <sys/ioctl.h>
int dlroWolleH(int c, double x, double h, double k)
{
   double X = (x < 0.0) ? 0.0 - x - h: x - h;
   double y = sqrt((h*h) - (X*X));
   double Y = (x < 0.0) ? (0.0-y) * (k/h) : (0.0+y) * (k/h);
   return(printf("\033[%i;%iH%c", (int)(Y+k+1.0), (int)(X+h), __FUNCTION__[c]));
}
int main(void)
{
   int X, x = 0, c = 0;
   double w, h, k, win[512];
#ifdef TIOCGSIZE
   J1: ioctl(0, TIOCGSIZE, &win);
   h = ((double)((struct ttysize *)win)->ts_cols) / 2.0;
   k = ((double)((struct ttysize *)win)->ts_rows) / 2.0;
#else
   J1: ioctl(0, TIOCGWINSZ, &win);
   h = ((double)((struct winsize *)win)->ws_col) / 2.0;
   k = ((double)((struct winsize *)win)->ws_row) / 2.0;
#endif
   if ((x+=h/k?h/k:1) >= (int)(w = (h*2.0)))
      x = 0 - ((int)(h*2.0));
   for(c = 0; c < 11; c++)
      dlroWolleH(c,(x+(c*((h*4)/11)))>=w?(0-w+((x+(c*((h*4)/11)))-w)):(x+(c*((h*4)/11))),h,k);
   fflush(stdout);
   usleep(90000);
   printf("\033[2J");
   goto *(&&J1);
   return(0);
}
