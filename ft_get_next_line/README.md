# GET_NEXT_LINE
Recreación de get_next_line en C.
## Parte obligatoria
|INFO|DESCRIPCIÓN|
|----|-----------|
|Prototipo|char *get_next_line(int fd)|
|Archivos a entregar|get_next_line.c, get_next_line_utils.c, get_next_line.h|
|Valor devuelto|Si todo va bien: la línea leída. En caso de fallo o si la lectura termina: NULL|
|Funciones autorizadas|read, malloc, free|
### Cosas a tener en cuenta
- Se debe de llamar a la función get_next_line de manera repetida que permitirá leer el contenido del archivo línea a línea, hasta llegar hasta el final.
- La función devolverá la línea que acaba de leer.
    - Si no hay nada más que leer, deberá devolver NULL.
    - Si ha ocurrido un error, deberá devolver NULL.