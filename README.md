# ft_printf

## Description
This project is pretty straight forward. I recode **libc's printf**.  

The project aims to study how to use variadic arguments.

The versatility of the printf function in C represents a great exercise in programming. 

I tried to make this project structured and well extensible. As before, one of the main requirements is the absence of memory leaks.

A small description of the implemented conversions:
- %c print a single character.
- %s print a string of characters.
- %p The void * pointer argument is printed in hexadecimal.
- %d print a decimal (base 10) number.
- %i print an integer in base 10.
- %u print an unsigned decimal (base 10) number.
- %x print a number in hexadecimal (base 16), with lowercase.
- %X print a number in hexadecimal (base 16), with uppercase.
- %% print a percent sign.
