# Born2beroot
1. [¿En qué consiste este proyecto?](#en-qu%C3%A9-consiste-este-proyecto)
2. [Requisitos parte obligatoria](#requisitos-parte-obligatoria)
3. [Pasos a seguir](#pasos-a-seguir)
4. [Defensa](#defensa)
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
## 🚨Pasos a seguir
Los pasos que he seguido durante la realización de este proyecto han sido en el siguiente enlace:
https://github.com/gemartin99/Born2beroot-Tutorial?tab=readme-ov-file#9-1-respuestas-de-la-evaluaci%C3%B3n-
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
