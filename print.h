#include <stdarg.h>

#include "ansi_color_codes.h"

#define PRINT_DEBUG(...) \
   do {                                                                                                                   \
      fprintf(stdout, "%sDEBUG%s: %s(): %s: Line %d: ", ANSI_COLOR_CYAN, ANSI_COLOR_RESET, __func__, __FILE__, __LINE__); \
      fprintf(stdout, __VA_ARGS__);                                                                                       \
   } while(0)

#define FPRINTF_DEBUG(format, ...) \
   do {                                                                                                                   \
      fprintf(stdout, "%sDEBUG%s: %s(): %s: Line %d: ", ANSI_COLOR_CYAN, ANSI_COLOR_RESET, __func__, __FILE__, __LINE__); \
      fprintf(stdout, format, __VA_ARGS__);                                                                               \
   } while(0)

#define PRINT_SUCCESS(...) \
   do {                                                                     \
      fprintf(stdout, "%sSUCCESS%s: ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET); \
      fprintf(stdout, __VA_ARGS__);                                         \
   } while(0)

#define FPRINTF_SUCCESS(format, ...) \
   do {                                                                     \
      fprintf(stdout, "%sSUCCESS%s: ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET); \
      fprintf(stdout, format, __VA_ARGS__);                                 \
   } while(0)

#define PRINT_WARNING(...) \
   do {                                                                                                        \
      fprintf(stdout, "%sWARNING%s: %s: Line %d: " , ANSI_COLOR_YELLOW, ANSI_COLOR_RESET, __FILE__, __LINE__); \
      fprintf(stdout, __VA_ARGS__);                                                                            \
   } while(0)

#define FPRINTF_WARNING(format, ...) \
   do {                                                                                                        \
      fprintf(stdout, "%sWARNING%s: %s: Line %d: " , ANSI_COLOR_YELLOW, ANSI_COLOR_RESET, __FILE__, __LINE__); \
      fprintf(stdout, format, __VA_ARGS__);                                                                    \
   } while(0)

#define PRINT_FAILURE(...) \
   do {                                                                                                                    \
      fprintf(stderr, "%sFAILED%s: %s(): %s: Line %d: " , ANSI_COLOR_RED, ANSI_COLOR_RESET, __func__, __FILE__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                                                                                        \
   } while(0)

#define FPRINTF_FAILURE(format, ...) \
   do {                                                                                                                    \
      fprintf(stderr, "%sFAILED%s: %s(): %s: Line %d: " , ANSI_COLOR_RED, ANSI_COLOR_RESET, __func__, __FILE__, __LINE__); \
      fprintf(stderr, format, __VA_ARGS__);                                                                                \
   } while(0)

/*
 * Protoypes
 */
void Print(const char *format, ...);
