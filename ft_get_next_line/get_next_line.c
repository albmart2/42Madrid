/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:55:20 by albmart2          #+#    #+#             */
/*   Updated: 2024/12/30 20:59:07 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*char    *get_next_line(int fd){
    fprintf(fd, "This is testing for fprintf...\n");
    fclose(f);

}*/

int main(){
    const char *nombre_archivo;
    FILE *archivo;

    nombre_archivo = "texto.txt";
    archivo = fopen("texto.txt", "r");
    char caracteres[1000000];
    if (archivo == NULL) {
        // Si fopen devuelve NULL, significa que hubo un error al abrir el archivo
        return 1; 
    }
    // Si llegamos aquí, el archivo se abrió correctamente
    while (fgets(caracteres, 100, archivo) != NULL)
 	{
        printf("%s",caracteres);
 	}
    fclose(archivo);
    return 0;
}
