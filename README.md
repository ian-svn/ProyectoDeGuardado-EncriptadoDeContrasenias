# LocalPass CLI 🔐

**Bóveda Local de Credenciales (C/C++)**

Gestor integral de seguridad en consola que implementa un sistema CRUD sobre archivos `.txt`. Incluye una capa de autenticación maestra y persistencia de datos mediante `structs`. Destaca por su motor de cifrado algorítmico propio que ofusca caracteres basándose en su posición relativa (z*z) y desplazamientos ASCII, garantizando privacidad local para el usuario.

---

## 🚀 Características Principales

* **Autenticación Maestra:** Protege el acceso a tu bóveda con una única clave de ingreso.
* **Gestión Completa (CRUD):** Añade, visualiza, edita y elimina credenciales fácilmente desde un menú interactivo.
* **Motor de Encriptación Propio:** Algoritmo matemático a nivel de caracteres para ofuscar contraseñas y probar el cifrado en tiempo real.
* **Almacenamiento Local:** Los datos persisten de forma local y sin dependencias externas mediante el manejo nativo de archivos en C.

## 🛠️ Requisitos e Instalación

Para compilar y ejecutar este proyecto necesitas un entorno de desarrollo de C/C++ (como MinGW/GCC) o un IDE compatible (como Dev-C++, Code::Blocks o Visual Studio).

1. Clona este repositorio o descarga el código fuente (`main.cpp`).
2. Abre tu terminal en la carpeta del proyecto y compila el archivo principal:

    ```bash
    g++ main.cpp -o localpass
    ```

3. Ejecuta el programa compilado:

    ```bash
    ./localpass
    ```

## 📖 Guía de Uso

### 1. Configuración Inicial (Primer Acceso)
Al abrir el programa por primera vez, el sistema detectará que no hay configuraciones previas:
* Te solicitará que ingreses una **Contraseña Maestra**.
* **Importante:** Recordá esta clave, ya que será tu única forma de acceder a la bóveda en el futuro.

### 2. Acceso Regular
En los usos posteriores, el programa te pedirá tu Contraseña Maestra. Solo si la ingresas correctamente, accederás al menú principal.

### 3. Menú Principal
El programa se maneja ingresando el número correspondiente a la acción que deseas realizar:

* **1 - Ingresar una nueva contraseña:** Te pedirá el nombre de la aplicación, el usuario y la contraseña. El sistema le asignará automáticamente un número de ID único.
* **2 - Encriptar una contraseña:** Herramienta interactiva para probar el motor de cifrado. Ingresás un texto libre y te devuelve la versión ofuscada.
* **3 - Desencriptar una contraseña:** Proceso inverso a la opción 2. Introducí un texto encriptado para ver su valor original.
* **4 - Modificar una contraseña:** Muestra tus credenciales guardadas. Ingresá el ID de la que querés editar y vas a poder actualizar sus datos.
* **5 - Borrar una contraseña:** Elimina un registro específico ingresando su número de ID.
* **6 - Mostrar contraseñas:** Imprime en pantalla todas las credenciales guardadas en tu bóveda.
* **7 - Borrar Todo:** Elimina de forma permanente todas las contraseñas registradas.
* **8 - Salir:** Cierra el programa de forma segura.

## 🗂️ Estructura de Archivos

El programa genera automáticamente los siguientes archivos en la misma carpeta donde se ejecuta para mantener la persistencia de datos:

* `cantVecesAbiertas.txt`: Controla los estados de inicio del programa.
* `contraseñaAcceso.txt`: Almacena tu contraseña maestra inicial.
* `CantRegistros.txt`: Lleva el conteo autoincremental de los IDs generados.
* `Contraseñas.txt`: El archivo principal donde se guardan tus credenciales.

## ⚠️ Aviso de Seguridad (Disclaimer)

Este proyecto fue desarrollado con fines educativos para practicar la algoritmia, el uso de estructuras de datos y la persistencia de archivos en C/C++. **No se recomienda** su uso en un entorno de producción real para almacenar contraseñas críticas, ya que el método de encriptación lineal y el almacenamiento en archivos `.txt` son vulnerables a técnicas de ingeniería inversa.
