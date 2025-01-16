# ft_printf

## What is it?

Ft_printf (Forty-Two_printf) is a custom implementation of the standard libray function 'printf'. It receives a string as input along with an undetermined amount of format specifiers to which different variables can be passed and printed. 

## How does it work?

Ft_printf works by parsing the input and looking for format specifiers (%) followed by a valid data type (cdipsuxX%) and using the standard library function 'write' to output the display. Ft_printf also mirrors the standard 'printf' functionality of returning the amount of characters written, or -1 in certain failure cases.

## What can ft_printf print?

Ft_printf can handle the basic input of 'printf' however the more advanced functionality of ft_printf has not been handled here.

 - %c - This specifiers is used when a single byte with the data type of char needs to be printed.

 - %d / %i - These specifiers can be used interchangably and are used to print out integers.

 - %p - This specifier is used to print out the memory address of a pointer. 

 - %s - This specifier is used to print out a cstring, or character array.

 - %u - This specifier is used to print out an unsigned integer.

 - %x / %X - These specifiers are used to print out an integer in base 16 (hexadecimal) with %x used to print out characters in lowercase and %X used to print out characters in uppercase.

 > [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.