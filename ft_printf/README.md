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
### Prototipo de ft_printf()
```
int  ft_printf(char const *src, ...);
```
### Requisitos
- No implementes la gestión del buffer del printf() original.
- Deberás implementar las siguientes conversiones: cspdiuxX %
- Tu función se comparará con el printf() original.
- Tienes que usar el comando ar para crear tu librería. El uso de libtool está prohibido.
- Tu archivo libftprintf.a deberá ser creado en la raiz de tu repositorio.
### Implementar las conversiones
|Tipo|Significado|Realizado|
|----|-----------|---------|
|%c|Imprime un solo carácter.|Sí|
|%s|Imprime una string (como se define por defecto en C).|Sí|
|%p|El puntero void * dado como argumento se imprime en formato hexadecimal.|No|
|%d|Imprime un número decimal (base 10).|No|
|%i|Imprime un entero en base 10.|Sí|
|%u|Imprime un número decimal (base 10) sin signo.|No|
|%x|Imprime un número hexadecimal (base 16) en minúsculas.|No|
|%X|Imprime un número hexadecimal (base 16) en mayúsculas.|No|
|%%|Para imprimir el símbolo del porcentaje.|Sí|
## Parte bonus
|BONUS|
|-----|
|- Gestiona cualquier combinación de los siguientes flags: ’-0.’ y el ancho mínimo (field minimum width) bajo todas las conversiones posibles.|
|- Gestiona todos los siguientes flags: ’# +’ (sí, uno de ellos es un espacio).|
