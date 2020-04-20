// COMP1521 19t2 ... lab 2 warm-up

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int bigint;
bigint minsigned(int bytes);
bigint minunsigned(int bytes);

static void range_uchar (void);
static void range_char (void);
static void range_uhint (void);
static void range_hint (void);
static void range_int (void);
static void range_uint (void);
static void range_lint (void);
static void range_ulint (void);
static void range_llint (void);
static void range_ullint (void);


int main (void)
{
	range_char ();
	range_uchar ();
	range_hint ();
	range_uhint ();
	range_int ();
	range_uint ();
	range_lint ();
	range_ulint ();
	range_llint ();
	range_ullint ();

	return EXIT_SUCCESS;
}

// Calculate and print the largest and smallest `int` values
static void range_int (void)
{

	int bytes=sizeof(int);
	int int_min = minsigned(bytes);
	int int_max = minsigned(bytes)-1;
	printf (
		"                   int (%zu bytes): %d ... %d\n",
		sizeof (int), int_min, int_max
	);
}

// Calculate and print the largest and smallest `unsigned int` values
static void range_uint (void)
{
	int bytes=sizeof(unsigned int);

	unsigned int uint_min = minunsigned(bytes);
	unsigned int uint_max = minunsigned(bytes)-1;
	printf (
		"          unsigned int (%zu bytes): %u ... %u\n",
		sizeof (unsigned int), uint_min, uint_max
	);
}

// Calculate and print the largest and smallest `long int` values
static void range_lint (void)
{
	int bytes=sizeof(long int);

	long int long_min = minsigned(bytes);
	long int long_max = minsigned(bytes)-1;
	printf (
		"              long int (%zu bytes): %ld ... %ld\n",
		sizeof (long int), long_min, long_max
	);
}

// Calculate and print the largest and smallest `unsigned long int` values
static void range_ulint (void)
{
	int bytes=sizeof(unsigned long int);
	unsigned long int ulong_min = minunsigned(bytes);
	unsigned long int ulong_max = minunsigned(bytes)-1;
	printf (
		"     unsigned long int (%zu bytes): %lu ... %lu\n",
		sizeof (unsigned long int), ulong_min, ulong_max
	);
}

// Calculate and print the largest and smallest `long long int` values
static void range_llint (void)
{
	int bytes=sizeof(long long int);
	long long int llong_min = ((minunsigned(bytes)-1)/2)+1;
	long long int llong_max = llong_min-1;
	printf (
		"         long long int (%zu bytes): %lld ... %lld\n",
		sizeof (long long int), llong_min, llong_max
	);
}

// Calculate and print the largest and smallest `unsigned long long int` values
static void range_ullint (void)
{
	int bytes=sizeof(unsigned long long int);
	unsigned long long int ullong_min = minunsigned(bytes);
	unsigned long long int ullong_max = minunsigned(bytes)-1;
	printf (
		"unsigned long long int (%zu bytes): %llu ... %llu\n",
		sizeof (unsigned long long int), ullong_min, ullong_max
	);
}

// Calculate and print the largest and smallest `short int` values
static void range_hint (void)
{
	int bytes=sizeof(short int);
	short int hint_min = minsigned(bytes);
	short int hint_max = minsigned(bytes)-1;
	printf (
		"             short int (%zu bytes): %hd ... %hd\n",
		sizeof (short int), hint_min, hint_max
	);
}

// Calculate and print the largest and smallest `unsigned short int` values
static void range_uhint (void)
{
	int bytes=sizeof(unsigned short int);
	unsigned short int uhint_min = minunsigned(bytes);
	unsigned short int uhint_max = minunsigned(bytes)-1;
	printf (
		"    unsigned short int (%zu bytes): %hu ... %hu\n",
		sizeof (unsigned short int), uhint_min, uhint_max
	);
}

// Calculate and print the largest and smallest `char` values
static void range_char (void)
{
	int bytes=sizeof(char);
	char char_min = minsigned(bytes);
	char char_max = minsigned(bytes)-1;
	printf (
		"                  char (%zu bytes): %d ... %d\n",
		sizeof (char), char_min, char_max
	);
}

// Calculate and print the largest and smallest `unsigned char` values
static void range_uchar (void)
{
	int bytes=sizeof(unsigned char);
	unsigned char uchar_min = minunsigned(bytes);
	unsigned char uchar_max = minunsigned(bytes)-1;
	printf (
		"         unsigned char (%zu bytes): %d ... %d\n",
		sizeof (unsigned char), uchar_min, uchar_max
	);
}

bigint minsigned(int bytes){
	
	bigint ans=1;
	int i;
	for (i=0 ; i<bytes ; i+=1){
		ans = ans*256;	
	}
	return ans/2;
}

bigint minunsigned(int bytes){
	
	bigint ans=1;
	int i;
	for (i=0 ; i<bytes ; i+=1){
		ans = ans*256;	
	}
	return ans;
}