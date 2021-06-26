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
#include "util.h"

#define TEST_PASS                 0
#define TEST_FAIL                 1

#define DEFAULT_TEST_ITERATIONS  10

#define NUM_UNIT_TESTS 4

static int (*UnitTest[NUM_UNIT_TESTS])(int iterations);

enum t_testname
{
   TESTNAME_MAX_VALUE,
   TESTNAME_TYPENAME,
   TESTNAME_BINARY_DUMP,
   TESTNAME_MAX_MIN,
};

static const char* TestNameToAscii(enum t_testname name)
{
   switch (name)
   {
      case TESTNAME_MAX_VALUE:
         return "_TestMaxValue(int)";
      case TESTNAME_TYPENAME:
         return "_TestTypename(int)";
      case TESTNAME_BINARY_DUMP:
         return "_TestBinaryDump(int)";
      case TESTNAME_MAX_MIN:
         return "_TestMaxMin(int)";
      default:
         return "unknown";
   }

   return "";
}

static int _TestMaxValue(int iterations)
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

static int _TestTypename(int iterations)
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

static int _TestBinaryDumpByte(int iterations)
{
   BYTE test_byte;
   BYTE ret_val;

   FPRINTF_DEBUG("Running %d iteration(s) on a(n) '%s'...\n",
                 iterations, TypeToAscii(typename(test_byte)));

   for (int iter = 0; iter < iterations; iter++)
   {
      test_byte = MAX_RAND_BYTE;

      FPRINTF_DEBUG("iteration=%.4d, input=0x%02X\n",
                    (iter + 1), test_byte);

      ret_val = BinaryDumpByte(test_byte, "");

      if (ret_val != test_byte)
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=0x%02X actual=0x%02X for '%s'\n\n",
                         (iter + 1), test_byte, ret_val, TypeToAscii(typename(test_byte)));
         return TEST_FAIL;
      }
      Print("\n");
   }

   FPRINTF_SUCCESS("'%s'!\n\n", TypeToAscii(typename(test_byte)));

   return TEST_PASS;
}

static int _TestBinaryDumpUint16(int iterations)
{
   UINT16 test_uint16;
   UINT16 ret_val;

   FPRINTF_DEBUG("Running %d iteration(s) on a(n) '%s'...\n",
                 iterations, TypeToAscii(typename(test_uint16)));

   for (int iter = 0; iter < iterations; iter++)
   {
      test_uint16 = MAX_RAND_UINT16;

      FPRINTF_DEBUG("iteration=%.4d, input=0x%04X\n",
                    (iter + 1), test_uint16);

      ret_val = BinaryDumpUint16(test_uint16, "_");

      if (ret_val != test_uint16)
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=0x%04X actual=0x%04X for '%s'\n\n",
                         (iter + 1), test_uint16, ret_val, TypeToAscii(typename(test_uint16)));
         return TEST_FAIL;
      }
      Print("\n");
   }

   FPRINTF_SUCCESS("'%s'!\n\n", TypeToAscii(typename(test_uint16)));

   return TEST_PASS;
}

static int _TestBinaryDumpUint32(int iterations)
{
   UINT32 test_uint32;
   UINT32 ret_val;

   FPRINTF_DEBUG("Running %d iteration(s) on a(n) '%s'...\n",
                  iterations, TypeToAscii(typename(test_uint32)));

   for (int iter = 0; iter < iterations; iter++)
   {
      test_uint32 = MAX_RAND_UINT32;

      FPRINTF_DEBUG("iteration=%.4d, input=0x%04X\n",
                    (iter + 1), test_uint32);

      ret_val = BinaryDumpUint32(test_uint32, "_");

      if (ret_val != test_uint32)
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=0x%04X actual=0x%04X for '%s'\n\n",
                         (iter + 1), test_uint32, ret_val, TypeToAscii(typename(test_uint32)));
         return TEST_FAIL;
      }
      Print("\n");
   }

   FPRINTF_SUCCESS("'%s'!\n\n", TypeToAscii(typename(test_uint32)));

   return TEST_PASS;
}

static int _TestBinaryDumpUint64(int iterations)
{
   UINT64 test_uint64;
   UINT64 ret_val;

   FPRINTF_DEBUG("Running %d iteration(s) on a(n) '%s'...\n",
                  iterations, TypeToAscii(typename(test_uint64)));

   for (int iter = 0; iter < iterations; iter++)
   {
      test_uint64 = MAX_RAND_UINT64;

      FPRINTF_DEBUG("iteration=%.4d, input=0x%08lX\n",
                    (iter + 1), test_uint64);

      ret_val = BinaryDumpUint64(test_uint64, "_");

      if (ret_val != test_uint64)
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=0x%08lX actual=0x%08lX for '%s'\n\n",
                         (iter + 1), test_uint64, ret_val, TypeToAscii(typename(test_uint64)));
         return TEST_FAIL;
      }
      Print("\n");
   }

   FPRINTF_SUCCESS("'%s'!\n\n", TypeToAscii(typename(test_uint64)));

   return TEST_PASS;
}

static int _TestBinaryDump(int iterations)
{
   if (_TestBinaryDumpByte(iterations) != 0)
   {
      return TEST_FAIL;
   }

   if (_TestBinaryDumpUint16(iterations) != 0)
   {
      return TEST_FAIL;
   }

   if (_TestBinaryDumpUint32(iterations) != 0)
   {
      return TEST_FAIL;
   }

   if (_TestBinaryDumpUint64(iterations) != 0)
   {
      return TEST_FAIL;
   }

   return TEST_PASS;
}

static int _TestMaxMin(int iterations)
{
   BYTE x;
   BYTE y;
   BYTE result;

   for (int iter = 0; iter < iterations; iter++)
   {
      x = MAX_RAND_BYTE;
      y = MAX_RAND_BYTE;

      FPRINTF_DEBUG("iteration=%.4d, x=%d, y=%d\n", iter, x, y);

      result = MAX(x, y);

      if ((x > y) && (result != x))
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=(%d > %d) actual=(%d > %d)\n\n", iter, x, y, result, y);
         return TEST_FAIL;
      }

      if ((y > x) && (result != y))
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=(%d > %d) actual=(%d > %d)\n\n", iter, y, x, result, x);
         return TEST_FAIL;
      }
   }

   for (int iter = 0; iter < iterations; iter++)
   {
      x = MAX_RAND_BYTE;
      y = MAX_RAND_BYTE;

      FPRINTF_DEBUG("iteration=%.4d, x=%d, y=%d\n", iter, x, y);

      result = MIN(x, y);

      if ((x < y) && (result != x))
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=(%d > %d) actual=(%d > %d)\n\n", iter, x, y, result, y);
         return TEST_FAIL;
      }

      if ((y < x) && (result != y))
      {
         FPRINTF_FAILURE("iteration=%.4d, expected=(%d > %d) actual=(%d > %d)\n\n", iter, y, x, result, x);
         return TEST_FAIL;
      }
   }

   return TEST_PASS;
}

static void _InitTests()
{
   UnitTest[TESTNAME_MAX_VALUE]   = _TestMaxValue;
   UnitTest[TESTNAME_TYPENAME]    = _TestTypename;
   UnitTest[TESTNAME_BINARY_DUMP] = _TestBinaryDump;
   UnitTest[TESTNAME_MAX_MIN]     = _TestMaxMin;
}

static int _RunTests(int iterations)
{
   for (int test = 0; test < NUM_UNIT_TESTS; test++)
   {
      if ((*UnitTest[test])(iterations) == TEST_FAIL)
      {
         FPRINTF_FAILURE("%s\n", TestNameToAscii(test));
         return TEST_FAIL;
      }
      FPRINTF_SUCCESS("%s!\n\n", TestNameToAscii(test));
   }

   PRINT_SUCCESS("All tests passed!\n");
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
   _InitTests();

   st = _RunTests(iterations);

   return st;
}
