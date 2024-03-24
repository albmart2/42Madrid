# FT_PRINTF
Ejercicio que recrea la función printf en C
## Parte obligatoria
|Info|Descripción|
|----|-----------|
|Nombre de programa|libftprintf.a|
|Archivos a entregar|Makefile, *.h, */*.h, *.c, */*.c|
|Makefile|NAME, all, clean, fclean, re|
|Funciones autorizadas|malloc, free, write, va_start, va_arg, va_copy, va_end|
|Se permite usar libft|Yes|
|Descripción|Escribe una librería que contenga la función ft_printf(), que imite el printf() original|
### Implementar las conversiones
|Tipo|Significado|
|----|-----------|
|%c|Imprime un solo carácter.|
|%s|Imprime una string (como se define por defecto en C).|
|%p|El puntero void * dado como argumento se imprime en formato hexadecimal.|
|%d|Imprime un número decimal (base 10).|
|%i|Imprime un entero en base 10.|
|%u|Imprime un número decimal (base 10) sin signo.|
|%x|Imprime un número hexadecimal (base 16) en minúsculas.|
|%X|Imprime un número hexadecimal (base 16) en mayúsculas.|
|%%|Para imprimir el símbolo del porcentaje.|
