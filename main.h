#ifndef MAIN_H
#define MAIN_H


/*
 * File: main.h
 * Desc: A Header file contains all prototype functions
 */

#include <stdarg.h>

/* Core printf */
int _printf(const char *format, ...);

/* Specifier routing */
int specifier(const char *spec, va_list args);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);

/* Number printing */
int print_signed(signed int n);
int print_unsigned(unsigned int n);

/* Base printing */
int print_hex(unsigned int n, int upper);
int print_octal(unsigned int n);

int print_pointer(void *p);
/* int print_binary(unsigned int num); */

#endif /* MAIN_H */
