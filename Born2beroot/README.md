# Born2beroot
1. [¿En qué consiste este proyecto?](#en-qu%C3%A9-consiste-este-proyecto)
2. [Requisitos parte obligatoria](#requisitos-parte-obligatoria)
3. [Pasos a seguir](#pasos-a-seguir)
4. [Script](#script)
5. [Defensa](#defensa)
   - [¿Qué es una máquina virtual?](#qu%C3%A9-es-una-m%C3%A1quina-virtual)
   - [¿Qué sistema operativo se ha elegido?](#qu%C3%A9-sistema-operativo-se-ha-elegido)
   - [Debian vs Rocky](#debian-vs-rocky)
   - [APT vs APTITUDE](#apt-vs-aptitude)
   - [¿Qué es APPAmor?](#qu%C3%A9-es-appamor)
   - [¿Qué es LVM?](#qu%C3%A9-es-lvm)
6. [Comandos](#comandos)
## ¿En qué consiste este proyecto?
Este proyecto consiste en configurar tu primer servidor siguiendo una serie de normas concretas.
## Requisitos parte obligatoria
- Elegir sistema operativo Devian vs Rocky.
- Crear al menos 2 particiones cifradas usando LVM.
- Crear un usuario y asignarlo a un grupo.
- El servicio SSH se ejecutará solo en el puerto 4242.
- Configurar tu sistema operativo con el firewall UFW.
- Configurar una política de contraseñas fuerte.
## Pasos a seguir
Los pasos que he seguido durante la realización de este proyecto han sido en este [enlace](https://github.com/gemartin99/Born2beroot-Tutorial).
## 🚨Script
### Architecture
Para poder ver la arquitectura del sistema operativo y su versión de kernel.
```
uname -a
```
### Núcleos físicos
Cuenta el número de identificadores físicos de CPU presentes en el sistema. Utiliza ```grep``` para encontrar las líneas que contienen "physical id" en el archivo /proc/cpuinfo y luego cuenta las líneas con ```wc -l```.
```
grep "physical id" /proc/cpuinfo | wc -l
```
### Núcleos virtuales
Similar al anterior, esta línea cuenta el número de procesadores virtuales (hilos) en el sistema.
```
grep processor /proc/cpuinfo | wc -l
```
### Memoria RAM
Utilizan el comando ```free --mega``` para obtener información sobre la memoria en megabytes y luego utilizan ```awk``` para filtrar y calcular el uso de la memoria y el porcentaje de uso.

Lo que haremos será comparar si la primera palabra de una fila es igual a "Mem:" printaremos la tercera palabra de esa fila que será la memoria usada. Todo el comando junto sería:
```
free --mega | awk '$1 == "Mem:" {print $3}'
```

Para obtener la memoria total el comando es prácticamente igual al anterior, lo único que deberemos cambiar es que en vez de printar la tercera palabra de la fila queremos la segunda:
```
free --mega | awk '$1 == "Mem:" {print $2}'
```

Por última parte debemos calcular el % de memoria usada. El comando de nuevo es parecido a los anteriores, la única modificación que haremos en la parte del printeo. Como la operación para conseguir el tanto porciento no es exacta, nos puede dar muchos decimales y en el subject solo aparecen 2 así que nosotros haremos lo mismo, por eso utilizamos %.2f para que así solo se muestren 2 decimales. Otra cosa que quizás no sepas es en printf para que se muestre un % hay que poner %%. 
```
free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'
```
### Memoria del disco
Para poder ver la memoria del disco ocupada y disponible utilizaremos el comando ```df``` que significa "disk filesystem", se utiliza para obtener un resumen completo del uso del espacio en disco. Como en el subject indica la memoria utilizada se muestra en MB, así que entonces utilizaremos el flag -m. Acto seguido haremos un grep para que solo nos muestre las líneas que contengan "/dev/" y seguidamente volveremos a hacer otro grep con el flag -v para excluir las líneas que contengan "/boot". Por último utilizaremos el comando awk y sumaremos el valor de la tercera palabra de cada línea para una vez sumadas todas las líneas printar el resultado final de la suma.
```
df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'
```
Para obtener el espacio total utilizaremos un comando muy parecido. Las únicas diferencias serán que los valores que sumaremos serán los $2 en vez de $3 y la otra diferencia es que en el subject aparece el tamaño total en Gb así que como el resultado de la suma nos da el número en Mb debemos transformarlo a Gb, para ello debemos dividir el número entre 1024 y quitar los decimales.
```
df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_result += $2} END {printf ("%.1fGb\n"), memory_result/1024}'
```
### Porcentaje uso de CPU
Estas líneas obtienen la carga de la CPU. Utilizan el comando ```vmstat``` para obtener información sobre la actividad del sistema y ```awk``` para extraer la carga de la CPU. También daremos uso del comando ```tail -1```, que este lo que nos va a permitir es que solo produzca el output la última línea, entonces de las 4 generadas solo se printará la última. Por último, solo printaremos la palabra 15 que es el uso de memoria disponible.
```
vmstat 1 4 | tail -1 | awk '{print $15}'
```
### Último reinicio
Esta línea obtiene la fecha y hora del último arranque del sistema. Utiliza el comando ```who -b``` para obtener la información de inicio y ```awk``` para extraer la fecha y hora.
```
who -b | awk '$1 == "system" {print $3 " " $4}'
```
### Uso de LVM
Esta línea verifica si LVM (Logical Volume Manager) está en uso en el sistema. Utiliza ```lsblk``` para listar los dispositivos de bloques y ```grep``` para buscar "lvm". Luego, ```wc -l``` cuenta las líneas para determinar si hay más de cero, lo que significa que LVM está en uso.
```
if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi
```
### Conexiones TCP
Esta línea cuenta el número de conexiones TCP establecidas. Utiliza ```ss``` para obtener información sobre los sockets y ```grep``` para buscar conexiones establecidas.
```
ss -ta | grep ESTAB | wc -l
```
### Números de usuarios
Esta línea cuenta el número de usuarios conectados. Utiliza el comando ```users``` para obtener una lista de usuarios y ```wc -w``` para contar las palabras en la lista.
```
users | wc -w
```
### Dirección IP y MAC
Para obtener la dirección del host haremos uso del comando:
```
hostname -I
```
Y ```ip link``` con ```grep``` y ```awk``` para obtener la dirección MAC:
```
ip link | grep "link/ether" | awk '{print $2}'
```
### Número de comandos ejecutados con sudo
Esta línea cuenta el número de comandos ejecutados con ```sudo```. Utiliza ```journalctl``` para buscar en los registros y ```grep``` para buscar comandos ```sudo```.
```
journalctl _COMM=sudo | grep COMMAND | wc -l)
```
### ⚠️Resultado Script
⚠️ A la hora de la defensa tendrás que explicar lo que hace cada comando ⚠️
```
#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
```
## Defensa
### ¿Qué es una máquina virtual?
Una máquina virtual consiste en simular mediante software algún recurso tecnológico físico. En resumen, es como tener uno o varios ordenadores dentro de nuestro equipo.
### ¿Qué sistema operativo se ha elegido?
Para poder realizar este proyecto, se ha utilizado el sistema operativo Debian, ya que es mucho más sencillo trabajar con él y si se busca documentación o tutoriales, la gran mayoría de ellos se han realizado en Debian.

Las diferencias entre Debian y Rocky se ven el siguiente punto.
### Debian vs Rocky
![debian vs rocky (1)](https://github.com/AlbaMartin17/42Madrid/assets/62957466/11af855b-744a-4bc6-acda-46c40c409ed7)
### APT vs APTITUDE
APT es más simple y rápido, mientras que aptitude ofrece una interfaz de usuario más avanzada y es mejor para resolver problemas de dependencias. La elección entre uno u otro depende de las preferencias personales y de las necesidades específicas del usuario. Muchos usuarios optan por APT para tareas simples y aptitude para tareas más complejas o cuando se enfrentan a problemas de dependencias.
### ¿Qué es APPAmor?
- Es un módulo de seguridad del kernel Linux que permite al administrador del sistema restringir las capacidades de un programa.

En resumen, podríamos decir que AppArmor funciona como una especie de "guardián" que controla y protege las aplicaciones y procesos en un sistema Linux.
### ¿Qué es LVM?
- Es un Administrador de Volúmenes Lógicos, que proporciona un método para asignar espacipo en dispositivos de almacenamiento masivo, que es más flexible que los esquemas de particionado convencionales para almacenar volúmenes.

De forma más sencilla, es como un "gerente" inteligente para tus discos duros en Linux. Te permite combinar varios discos en uno solo, crear "pedazos" de espacio que puedes usar como si fueran discos individuales, y cambiar el tamaño de estos "pedazos" sobre la marcha, sin necesidad de apagar tu computadora. Es útil porque te da más flexibilidad para organizar y gestionar el almacenamiento en tu computadora.
## Comandos
- Para comprobar que no hay ninguna interfaz gráfica.

	```
	ls /usr/bin/*session
	```
- Comprobar que el servicion UFW está en uso.
```
sudo ufw status
```
```
sudo service ufw status
```
- Comprobar que SSH está en uso.
```
sudo service ssh status
```
- Comprobar que se utiliza el SO Debian o Rocky
```
uname -v
```
```
uname --kernel-version
```
- Comprobar que el usuario este dentro de los grupos "sudo" y "user42"
```
getent group sudo
```
```
getent group user42
```
- Crear un nuevo usuario.
```
sudo adduser <name_user>
```
- Crear un nuevo grupo
```
sudo addgroup <name_group>
```
- Añadir el usuario al nuevo grupo
```
sudo adduser <name_user> <name_group>
```
- Para comprobar que se haya introducido correctamente.
```
getent group <name_group>
```
- Comprobar que el hostname de máquina es correcto
```
hostname
```
- Modificar hostname para remplazar tu login por el del evaluador. ```sudo nano /etc/hostname``` y remplazamos nuestro login por el nuevo.
- ```sudo nano /etc/hosts``` y remplazamos nuestro login por el nuevo.
- Reiniciar la máquina.
```
sudo reboot
```
- Una vez nos hemos logueado de nuevo podemos ver como el hostname se ha cambiado correctamente.
```
hostname
```
- Comprobar que todas las particiones son como indica el subject
```
lsblk
```
- Comprobar que sudo está instalado.
```
dpkg -s sudo
```
- Introducimos el nuevo usuario dentro del grupo sudo.
```
sudo adduser name_user sudo
```
