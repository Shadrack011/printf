#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
    char c;
    int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_different_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);
typedef struct prv
{
	char id;
	int (*f)(va_list args);
} prv_t;

int _printf(const char *format, ...);

int (*get_func(const char id))(va_list);

int _putchar(int ch);

int pr_char(va_list args);

int pr_str(va_list args);

int pr_bin(va_list args);
int cnvrt_to_bin(unsigned int n, int *cnt);

int pr_dec(va_list args);
int cnvrt_to_dec(int n, int *cnt);

int pr_un_int(va_list args);
int cnvrt_to_un_int(unsigned int n, int *cnt);

int pr_octa(va_list args);
int cnvrt_to_octa(unsigned int n, int *cnt);

int pr_hex(va_list args);
int cnvrt_to_hex(unsigned int n, int *cnt);

int pr_heX(va_list args);
int cnvrt_to_heX(unsigned int n, int *cnt);

int get_base_len(int n, int b);

int pr_non_prt(va_list args);

int pr_rev(va_list args);
int get_str_len(char *s);

int pr_rot13(va_list args);

int pr_ptr(va_list args);
int cnvrt_to_mem_addr(unsigned long int n, int *ptr);


#endif