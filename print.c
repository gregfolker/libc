#include <stdio.h>
#include <stdarg.h>

void Printf(const char *format, ...)
{
   va_list args;

   va_start(args, format);
   vfprintf(stdout, format, args);
   va_end(args);
}

void Print(const char *text)
{
   fputs(text, stdout);
}
