/*
 * File: `main.c`
 * Author: Greg Folker
 * Description: Test code for custom library function definitions inside `libc`
 */

#include <stdio.h>

#include "types.h"
#include "dump.h"
#include "rand.h"
#include "lib.h"

#define TEST_PASS                 0
#define TEST_FAIL                 1

#define DEFAULT_TEST_ITERATIONS  10

static int _TestMaxValue()
{
   UINT expected;
   BYTE max_byte;
   UINT16 max_uint16;
   UINT32 max_uint32;
   UINT64 max_uint64;

   max_byte = MaxValue(sizeof(BYTE));
   expected = 255;

   if (max_byte != expected)
   {
      fprintf(stderr, "\n%s: FAILED! expected=%zu actual=%d\n\n", __func__, expected, max_byte);
      return TEST_FAIL;
   }

   max_uint16 = MaxValue(sizeof(UINT16));
   expected = 65535;

   if (max_uint16 != expected)
   {
      fprintf(stderr, "\n%s: FAILED! expected=%zu actual=%d\n\n", __func__, expected, max_uint16);
      return TEST_FAIL;
   }

   max_uint32 = MaxValue(sizeof(UINT32));
   expected = 4294967295;

   if (max_uint32 != expected)
   {
      fprintf(stderr, "\n%s: FAILED! expected=%zu actual=%d\n\n", __func__, expected, max_uint32);
      return TEST_FAIL;
   }

   max_uint64 = MaxValue(sizeof(UINT64));
   expected = 18446744073709551615UL;

   if (max_uint64 != expected)
   {
      fprintf(stderr, "\n%s: FAILED! expected=%zu actual=%ld\n\n", __func__, expected, max_uint64);
      return TEST_FAIL;
   }

   return TEST_PASS;
}

static int _TestTypename()
{
   BYTE num_types = (BYTE)(TYPENAME_UNKNOWN - 1);

   enum t_typename type;

   bool                    test_bool;
   unsigned char           test_unsigned_char;
   char                    test_char;
   signed char             test_signed_char;
   short int               test_short_int;
   unsigned short int      test_unsigned_short_int;
   int                     test_int;
   unsigned int            test_unsigned_int;
   long int                test_long_int;
   unsigned long int       test_unsigned_long_int;
   long long int           test_long_long_int;
   unsigned long long int  test_unsigned_long_long_int;
   float                   test_float;
   double                  test_double;
   long double             test_long_double;
   char                   *test_pointer_to_char;
   void                   *test_pointer_to_void;
   int                    *test_pointer_to_int;

   for (BYTE t = 0; t <= num_types; t++)
   {
      switch (t)
      {
         case TYPENAME_BOOL:
            type = typename(test_bool);

            if (type != TYPENAME_BOOL)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_BOOL), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_CHAR:
            type = typename(test_unsigned_char);

            if (type != TYPENAME_UNSIGNED_CHAR)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_UNSIGNED_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_CHAR:
            type = typename(test_char);

            if (type != TYPENAME_CHAR)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_SIGNED_CHAR:
            type = typename(test_signed_char);

            if (type != TYPENAME_SIGNED_CHAR)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_SIGNED_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_SHORT_INT:
            type = typename(test_short_int);

            if (type != TYPENAME_SHORT_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_SHORT_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_SHORT_INT:
            type = typename(test_unsigned_short_int);

            if (type != TYPENAME_UNSIGNED_SHORT_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_UNSIGNED_SHORT_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_INT:
            type = typename(test_int);

            if (type != TYPENAME_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_INT:
            type = typename(test_unsigned_int);

            if (type != TYPENAME_UNSIGNED_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_UNSIGNED_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_LONG_INT:
            type = typename(test_long_int);

            if (type != TYPENAME_LONG_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_LONG_INT:
            type = typename(test_unsigned_long_int);

            if (type != TYPENAME_UNSIGNED_LONG_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_UNSIGNED_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_LONG_LONG_INT:
            type = typename(test_long_long_int);

            if (type != TYPENAME_LONG_LONG_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_LONG_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_LONG_LONG_INT:
            type = typename(test_unsigned_long_long_int);

            if (type != TYPENAME_UNSIGNED_LONG_LONG_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_UNSIGNED_LONG_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_FLOAT:
            type = typename(test_float);

            if (type != TYPENAME_FLOAT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_FLOAT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_DOUBLE:
            type = typename(test_double);

            if (type != TYPENAME_DOUBLE)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_DOUBLE), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_LONG_DOUBLE:
            type = typename(test_long_double);

            if (type != TYPENAME_LONG_DOUBLE)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_LONG_DOUBLE), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_POINTER_TO_CHAR:
            type = typename(test_pointer_to_char);

            if (type != TYPENAME_POINTER_TO_CHAR)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_POINTER_TO_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_POINTER_TO_VOID:
            type = typename(test_pointer_to_void);

            if (type != TYPENAME_POINTER_TO_VOID)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_POINTER_TO_VOID), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_POINTER_TO_INT:
            type = typename(test_pointer_to_int);

            if (type != TYPENAME_POINTER_TO_INT)
            {
               fprintf(stderr, "\n%s: FAILED! expected=%s actual=%s\n\n", __func__, TypeToAscii(TYPENAME_POINTER_TO_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNKNOWN:
            break;
      }

   }

   return TEST_PASS;
}

static int _TestBinaryDumpUint32(int iterations)
{
   UINT32 test_val;
   UINT32 ret_val;

   fprintf(stdout, "Running %s for %d iteration(s)...\n\n", __func__, iterations);

   for (int iter = 0; iter < iterations; iter++)
   {
      test_val = RandUint32Max();

      fprintf(stdout, "%s iteration=%d, test_val=%d\n\n", __func__, iter, test_val);

      fputs("Result:\n", stdout);
      ret_val = BinaryDumpUint32(stdout, test_val, "_");

      if (ret_val != test_val)
      {
         fprintf(stderr, "\nFAILED %s iteration=%d, expected=%d actual=%d\n\n", __func__, iter, test_val, ret_val);
         return TEST_FAIL;
      }
      fputs("\n", stdout);
   }

   return TEST_PASS;
}

static int _RunTests(int iterations)
{
   if (_TestMaxValue() == 0)
   {
      fputs("MaxValue() verification PASSED\n\n", stdout);
   }
   else
   {
      fputs("MaxValue() verification FAILED\n\n", stderr);
      return TEST_FAIL;
   }

   if (_TestTypename() == 0)
   {
      fputs("typename() verification PASSED\n\n", stdout);
   }
   else
   {
      fputs("typename() verification FAILED\n\n", stderr);
      return TEST_FAIL;
   }

   if (_TestBinaryDumpUint32(iterations) == 0)
   {
      fputs("BinaryDump() verification PASSED\n\n", stdout);
   }
   else
   {
      fputs("BinaryDump() verification FAILED\n\n", stderr);
      return TEST_FAIL;
   }

   return TEST_PASS;
}

int main(int argc, char *argv[])
{
   int st;
   int iterations = DEFAULT_TEST_ITERATIONS;

   if (argc > 1)
   {
      if (atoi(argv[1]) != 0)
      {
         iterations = atoi(argv[1]);
      }
   }

   SeedRNG();
   st = _RunTests(iterations);

   return st;
}
