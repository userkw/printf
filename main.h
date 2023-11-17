#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * by Joseph and Ciny
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_ch(va_list typ, char buff[],
	int flags, int width, int precision, int size);
int print_str(va_list typ, char buff[],
	int flags, int width, int precision, int size);
int print_perc(va_list typ, char buff[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_i(va_list typ, char buff[],
	int flags, int width, int precision, int size);
int print_bin(va_list typp, char buff[],
	int flags, int width, int precision, int size);
int print_uns(va_list typ, char buff[],
	int flags, int width, int precision, int size);
int print_oc(va_list typ, char buff[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list typ, char buff[],
	int flags, int width, int precision, int size);
int print_hexa_up(va_list typ, char buff[],
	int flags, int width, int precision, int size);

int print_hexa(va_list typ, char m_to[], char buff[],
	int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_print(va_list lst, char buff[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_ptr(va_list typp, char buff[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *ft, int *a);
int get_width(const char *ft, int *a, va_list lst);
int get_precision(const char *ft, int *a, va_list lst);
int get_size(const char *ft, int *a);

/*Function to print string in reverse*/
int print_rever(va_list lst, char buff[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13str(va_list lst, char buffeerr[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char cyp, char buff[],
	int flags, int width, int precision, int size);
int write_nbr(int is_n, int index, char buff[],
	int flags, int width, int precision, int size);
int write_num(int index, char buff[],
	int flags, int width, int prec,
	int length, char padd, char extra_c);
int write_pointer(char buff[], int index, int lent,
	int width, int flags, char pdd, char ex_c, int p_start);

int write_unsgnd(int is_n, int index,
	char buff[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
