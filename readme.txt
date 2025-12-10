==================================================
      SIMULACIÓN DE DISTRIBUCIÓN CAUCHY
==================================================

📊 DESCRIPCIÓN DEL PROYECTO
Este proyecto genera valores aleatorios con distribución Cauchy
(parámetro c=1) usando programación orientada a objetos en C++,
y visualiza los resultados mediante gráficos en Python.

La distribución Cauchy tiene la función de densidad:
  f(x) = 1 / [π * (1 + x²)]

🎯 OBJETIVOS
1. Generar 100,000 valores con distribución Cauchy (c=1)
2. Guardar los datos en results/cauchy.dat
3. Crear histograma comparativo con la curva teórica
4. Analizar estadísticas descriptivas

📁 ESTRUCTURA DEL PROYECTO
CauchyDistribution/
├── src/
│   ├── main.cpp                 # Programa principal
│   ├── RandomGenerator.cpp      # Clase base abstracta
│   └── GeneratorCauchy.cpp      # Generador de distribución Cauchy
├── include/
│   ├── RandomGenerator.hpp      # Interfaz generador
│   └── GeneratorCauchy.hpp      # Declaración generador Cauchy
├── results/                     # Datos y gráficos (se crean)
│   ├── cauchy.dat               # Datos generados
│   └── hist_cauchy.png          # Gráfico del histograma
├── plot_cauchy.py               # Script para gráficos en Python
├── build.py                     # Sistema de build automático
└── README.txt                   # Este archivo

🚀 CÓMO EJECUTAR EL PROGRAMA

OPCIÓN 1: Usando el sistema de build automático (Recomendado)
-------------------------------------------------------------
1. Asegúrate de tener Python instalado
2. Abre terminal en la carpeta CauchyDistribution
3. Ejecuta:
   > python build.py

   Esto hará automáticamente:
   - Compilar el programa C++
   - Ejecutar la simulación
   - Generar los gráficos

OPCIÓN 2: Pasos manuales
------------------------
1. COMPILAR C++ (Windows):
   > g++ -std=c++11 -Iinclude -o cauchy_simulator.exe src\main.cpp src\RandomGenerator.cpp src\GeneratorCauchy.cpp -lm

   Linux/macOS:
   > g++ -std=c++11 -I./include -o cauchy_simulator src/main.cpp src/RandomGenerator.cpp src/GeneratorCauchy.cpp -lm

2. EJECUTAR SIMULACIÓN:
   > cauchy_simulator.exe  (Windows)
   > ./cauchy_simulator    (Linux/macOS)

3. GENERAR GRÁFICOS:
   > python plot_cauchy.py

📋 REQUISITOS DEL SISTEMA

1. COMPILADOR C++:
   - Windows: MinGW (https://sourceforge.net/projects/mingw/)
   - Linux: g++ (sudo apt install g++)
   - macOS: Xcode Command Line Tools (xcode-select --install)

2. PYTHON 3.6+ con las siguientes librerías:
   - numpy
   - matplotlib
   - scipy

   Instalar con: pip install numpy matplotlib scipy

3. ESPACIO EN DISCO: ~5 MB

🔧 DETALLES TÉCNICOS

IMPLEMENTACIÓN C++ (POO):
- RandomGenerator: Clase base abstracta con métodos virtuales
- GeneratorCauchy: Clase derivada específica para distribución Cauchy
- Método de transformada inversa para generar valores Cauchy
- Uso de Mersenne Twister para números pseudoaleatorios

GENERACIÓN DE VALORES CAUCHY:
  x = c * tan(π * (u - 0.5))
  donde u ~ Uniforme(0,1) y c=1

ANÁLISIS EN PYTHON:
- Histograma normalizado vs curva teórica
- Estadísticas descriptivas
- Comparación teoría vs práctica
- Gráfico de alta calidad (300 DPI)

📈 SALIDA ESPERADA

1. CONSOLA:
   - Estadísticas descriptivas de los datos
   - Comparación con valores teóricos
   - Confirmación de archivos generados

2. ARCHIVOS EN results/:
   - cauchy.dat: 100,000 valores numéricos
   - hist_cauchy.png: Gráfico con histograma y curva teórica

🔄 FLUJO DEL PROGRAMA
   main.cpp → GeneratorCauchy → results/cauchy.dat → plot_cauchy.py → results/hist_cauchy.png

⚡ COMANDOS RÁPIDOS

# Limpiar y ejecutar todo
> python build.py

# Solo compilar C++
> python build.py compile

# Solo ejecutar simulación
> python build.py run

# Solo generar gráficos
> python build.py plot

# Ver información del proyecto
> python build.py info

🧪 EJECUCIÓN DE PRUEBA
Si todo funciona correctamente, verás:
1. Mensaje "SIMULACIÓN COMPLETADA EXITOSAMENTE"
2. Archivo results/cauchy.dat con 100,000 líneas
3. Archivo results/hist_cauchy.png con el gráfico
4. Estadísticas en consola comparando teoría y práctica

⚠️ POSIBLES PROBLEMAS Y SOLUCIONES

1. "No se encuentra el compilador g++"
   - Instala MinGW (Windows) o g++ (Linux/macOS)

2. "No se encontró results/cauchy.dat"
   - Asegúrate de ejecutar desde la carpeta correcta
   - Verifica que results/ existe

3. Error en Python "ModuleNotFoundError"
   - Ejecuta: pip install numpy matplotlib scipy

4. Valores extremos en el gráfico
   - Es normal en Cauchy (colas pesadas)
   - El script filtra valores fuera de [-20, 20] para mejor visualización

📝 NOTAS
- La distribución Cauchy no tiene media ni varianza definidas teóricamente
- Los valores muestrales pueden variar entre ejecuciones
- Para c=1, la mediana teórica es 0, Q1=-1, Q3=1
- La probabilidad en x=0 es f(0)=1/π≈0.3183

🎲 EJEMPLO DE SALIDA EN CONSOLA
=========================================
   SIMULACIÓN DE DISTRIBUCIÓN CAUCHY
=========================================
Generando 100000 valores...
Estadísticas descriptivas:
  Mínimo: -3185.6243
  Mediana: 0.0024
  Máximo: 3129.8741
✓ Datos guardados en results/cauchy.dat

📧 CONTACTO Y SOPORTE
Proyecto académico para simulación de distribuciones de probabilidad
Si encuentras problemas, verifica:
1. La estructura de carpetas
2. Las instalaciones de compilador y Python
3. Los permisos de escritura en results/

==================================================
       ¡LISTO PARA SIMULAR DISTRIBUCIÓN CAUCHY!
==================================================
