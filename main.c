/*
 * File: `main.c`
 * Author: Greg Folker
 * Description: Test code for custom library function definitions inside `libc`
 */
#include <stdio.h>

#include "print.h"
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

   PRINT_DEBUG("Verifying 4 max value(s)...\n");

   max_byte = MaxValue(sizeof(BYTE));
   expected = 255;

   PRINT_DEBUG("Testing BYTE max value...\n");

   if (max_byte != expected)
   {
      FPRINTF_FAILURE("expected=%zu actual=%d\n\n", expected, max_byte);
      return TEST_FAIL;
   }

   max_uint16 = MaxValue(sizeof(UINT16));
   expected = 65535;

   PRINT_DEBUG("Testing UINT16 max value...\n");

   if (max_uint16 != expected)
   {
      FPRINTF_FAILURE("expected=%zu actual=%d\n\n", expected, max_uint16);
      return TEST_FAIL;
   }

   max_uint32 = MaxValue(sizeof(UINT32));
   expected = 4294967295;

   PRINT_DEBUG("Testing UINT32 max value...\n");

   if (max_uint32 != expected)
   {
      FPRINTF_FAILURE("expected=%zu actual=%d\n\n", expected, max_uint32);
      return TEST_FAIL;
   }

   max_uint64 = MaxValue(sizeof(UINT64));
   expected = 18446744073709551615UL;

   PRINT_DEBUG("Testing UINT64 max value...\n");

   if (max_uint64 != expected)
   {
      FPRINTF_FAILURE("expected=%zu actual=%ld\n\n", expected, max_uint64);
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

   FPRINTF_DEBUG("Verifying %d type(s)...\n", num_types);

   for (BYTE t = 0; t <= num_types; t++)
   {
      FPRINTF_DEBUG("Checking '%s' type...\n", TypeToAscii(t));
      switch (t)
      {
         case TYPENAME_BOOL:
            type = typename(test_bool);

            if (type != TYPENAME_BOOL)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_BOOL), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_CHAR:
            type = typename(test_unsigned_char);

            if (type != TYPENAME_UNSIGNED_CHAR)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_UNSIGNED_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_CHAR:
            type = typename(test_char);

            if (type != TYPENAME_CHAR)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_SIGNED_CHAR:
            type = typename(test_signed_char);

            if (type != TYPENAME_SIGNED_CHAR)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_SIGNED_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_SHORT_INT:
            type = typename(test_short_int);

            if (type != TYPENAME_SHORT_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_SHORT_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_SHORT_INT:
            type = typename(test_unsigned_short_int);

            if (type != TYPENAME_UNSIGNED_SHORT_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_UNSIGNED_SHORT_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_INT:
            type = typename(test_int);

            if (type != TYPENAME_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_INT:
            type = typename(test_unsigned_int);

            if (type != TYPENAME_UNSIGNED_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_UNSIGNED_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_LONG_INT:
            type = typename(test_long_int);

            if (type != TYPENAME_LONG_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_LONG_INT:
            type = typename(test_unsigned_long_int);

            if (type != TYPENAME_UNSIGNED_LONG_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_UNSIGNED_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_LONG_LONG_INT:
            type = typename(test_long_long_int);

            if (type != TYPENAME_LONG_LONG_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_LONG_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_UNSIGNED_LONG_LONG_INT:
            type = typename(test_unsigned_long_long_int);

            if (type != TYPENAME_UNSIGNED_LONG_LONG_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_UNSIGNED_LONG_LONG_INT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_FLOAT:
            type = typename(test_float);

            if (type != TYPENAME_FLOAT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_FLOAT), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_DOUBLE:
            type = typename(test_double);

            if (type != TYPENAME_DOUBLE)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_DOUBLE), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_LONG_DOUBLE:
            type = typename(test_long_double);

            if (type != TYPENAME_LONG_DOUBLE)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_LONG_DOUBLE), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_POINTER_TO_CHAR:
            type = typename(test_pointer_to_char);

            if (type != TYPENAME_POINTER_TO_CHAR)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_POINTER_TO_CHAR), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_POINTER_TO_VOID:
            type = typename(test_pointer_to_void);

            if (type != TYPENAME_POINTER_TO_VOID)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_POINTER_TO_VOID), TypeToAscii(type));
               return TEST_FAIL;
            }
            break;
         case TYPENAME_POINTER_TO_INT:
            type = typename(test_pointer_to_int);

            if (type != TYPENAME_POINTER_TO_INT)
            {
               FPRINTF_FAILURE("expected=%s actual=%s\n\n", TypeToAscii(TYPENAME_POINTER_TO_INT), TypeToAscii(type));
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

   FPRINTF_DEBUG("Running %d iteration(s)...\n", iterations);

   for (int iter = 0; iter < iterations; iter++)
   {
      test_val = RandUint32Max();

      FPRINTF_DEBUG("iteration=%.4d, input=0x%08X, output=", (iter + 1), test_val);

      ret_val = BinaryDumpUint32(test_val, "_");

      if (ret_val != test_val)
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=0x%08X actual=0x%08X\n\n", (iter + 1), test_val, ret_val);
         return TEST_FAIL;
      }
   }

   return TEST_PASS;
}

static int _RunTests(int iterations)
{
   if (_TestMaxValue() == 0)
   {
      PRINT_SUCCESS("_TestMaxValue()\n\n");
   }
   else
   {
      PRINT_FAILURE("_TestMaxValue()\n\n");
      return TEST_FAIL;
   }

   if (_TestTypename() == 0)
   {
      PRINT_SUCCESS("_TestTypeName()\n\n");
   }
   else
   {
      PRINT_FAILURE("_TestTypeName()\n\n");
      return TEST_FAIL;
   }

   if (_TestBinaryDumpUint32(iterations) == 0)
   {
      PRINT_SUCCESS("_TestBinaryDumpUint32()\n\n");
   }
   else
   {
      PRINT_FAILURE("_TestBinaryDumpUint32()\n\n");
      return TEST_FAIL;
   }

   PRINT_SUCCESS("All Unit Tests Passed\n\n");
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
