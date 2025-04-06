#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Created by: Haidar Alessa 10682@holbertonstudents.com
 * Desc: A Header file contains all prototype functions
 */

#include <stdarg.h>
#include <stdint.h>

/* Flags structure for format specifiers */
typedef struct flags
{
int plus;
int space;
int hash;
} flags_t;

/* Core printf */
int _printf(const char *format, ...);

/* Specifier routing */
int route_specifier(const char *spec, va_list args);

/* Number printing */
int print_signed(long n, flags_t flags);
int print_unsigned(unsigned long n);

/* Base printing */
int print_hex(unsigned long n, int upper, flags_t flags);
int print_octal(unsigned long n, flags_t flags);

/* Pointer printing */
int print_pointer(void *p);

#endif /* MAIN_H */
