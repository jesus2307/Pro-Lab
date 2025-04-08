# ActivityLogger

**Instrucciones de la practica** El examen consiste en un trabajo de programación en C++ a consensuar con el profesor. Las herramientas vistas en clase deberán ser utilizadas durante el desarrollo del proyecto. Se requiere que el código desarrollado esté versionado a través de Git (en GitHub , Codeberg o un servicio similar). Todas las clases principales deben estar sujetas a pruebas unitarias. Los trabajos deberán ser completados individualmente. Previa solicitud, es posible acordar con el profesor posibles variaciones a realizar en parejas.

El trabajo deberá ser revisado con el profesor al menos una vez antes del examen. Una vez considerado superado, el aprobado del examen podrá registrarse en la primera sesión disponible.

El tema del proyecto se puede elegir entre los indicados en esta página. Alternativamente, es posible desarrollar un proyecto no presente en la lista, sujeto a la aprobación del docente.

(3) Registro di attività che memorizza cosa si è fatto durante una giornata. Classe che rappresenta attività con descrizione, tempo inizio e fine, Classe registro che colleziona attività su base del giorno. Interfaccia semplice per mostrare il registro sulla base di un giorno fatta a scelta con:
nCurses
wxWidgets
QT

---

## Funcionalidades

- Registro de actividades con:
  - Descripción
  - Hora de inicio
  - Hora de finalización
- Visualización de las actividades del día
- Exportación del registro diario a un archivo CSV
- Interfaz gráfica construida con **Qt Widgets**

---

##  Tecnologías utilizadas

- Lenguaje: **C++**
- Framework: **Qt 6**
- Control de versiones: **Git**
- Sistema operativo objetivo: **Windows / Linux / macOS**

---

##  Estructura del proyecto

```
ActivityLogger/
├── activity.h / .cpp         # Clase que representa una actividad
├── activitylog.h / .cpp      # Clase que gestiona el registro de actividades
├── mainwindow.h / .cpp / .ui # Interfaz gráfica (Qt Designer)
├── main.cpp                  # Entrada principal del programa
├── ActivityLogger.pro        # Archivo de proyecto Qt
```

---

## Requisitos para compilar

- Tener instalado **Qt 6.x** con Qt Creator
- Compilador compatible con **C++17** o superior
- Git (opcional, para control de versiones)

---

##  Ejecución

1. Abrir el proyecto con **Qt Creator** (`ActivityLogger.pro`)
2. Seleccionar un kit de compilación válido
3. Pulsar el botón de **Ejecutar **

---

**Jesús Fernández Rueda**  
Estudiante Erasmus – UNIFI / UCAM  
Este proyecto se ha desarrollado individualmente como parte del examen de laboratorio de programación.
