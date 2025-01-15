# GET_NEXT_LINE
Recreación de get_next_line en C.
## Parte obligatoria
|**INFO**|**DESCRIPCIÓN**|
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
- La función deberá de comportarse adecuadamente cuando lea de un archivo y cuando lea de stdin.
- Cada línea devuelta debe de terminar en caracter n, excepto si se ha llegado al final del archivo.
- En el header get_next_line.h se deberá tener como mínimo el prototipo de la función get_next_line.
- Añade todas las funciones de ayuda que necesites en el archivo get_next_line_utils.c
### Prohibido
- Utilizar la libft en este proyecto.
- Utilizar **lseek**.
- Utlizar variables globales.
## A la hora de corregir
- Tu programa debe compilar con el flag -D BUFFER_SIZE=xx. Este flag se utilizará para determinar el tamaño del buffer de las lecturas de tu get_next_line(). Este parámetro será modificado por tus evaluadores y por Moulinette para probar tu programa.
- El programa se compilará de la siguiente forma (se utiliza como ejemplo un tamaño de buffer de 42):

> *cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.*
- Se considera que get_next_line() tiene un comportamiento indeterminado si el archivo al que apunta el fd ha cambiado desde la última vez que se llamó, siempre que read() no haya llegado al final del archivo.
- Se considera que get_next_line() tiene un comportamiento indeterminado cuando lo que se lee es un archivo binario. Sin embargo, puedes implementar alguna manera lógica de sortear este problema, si quieres

|**NOTA**|
|--------|
|*Aún no presentado*|