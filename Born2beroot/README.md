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
### 🚨Script
⚠️A la hora de la defensa tendrás que explicar lo que hace cada comando⚠️
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
