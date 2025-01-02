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
    *archivo = fopen("texto.txt", "r");
    if (archivo == NULL) {
        // Si fopen devuelve NULL, significa que hubo un error al abrir el archivo
        printf("No se pudo abrir el archivo '%s'.\n", nombre_archivo);
        return 1;  // Salir con un código de error
    }
    // Si llegamos aquí, el archivo se abrió correctamente
    printf("El archivo '%s' se abrió correctamente.\n", nombre_archivo);
    fclose(archivo);
    return 0;
}
