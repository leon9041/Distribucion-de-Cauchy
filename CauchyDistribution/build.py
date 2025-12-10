#!/usr/bin/env python3
"""
Build simple para Cauchy Distribution
Solo compila, ejecuta y genera gráficos
"""

import os
import sys
import subprocess
from pathlib import Path

def main():
    print("=" * 50)
    print("BUILD - DISTRIBUCIÓN CAUCHY")
    print("=" * 50)
    
    # Directorios (solo results)
    root = Path(__file__).parent
    results_dir = root / "results"
    results_dir.mkdir(exist_ok=True)
    
    # 1. COMPILAR
    print("\n[1/3] Compilando C++...")
    compile_cmd = [
        "g++",
        "-std=c++11",
        "-I./include",
        "-Wall",
        "-o", "cauchy_simulator.exe" if os.name == 'nt' else "cauchy_simulator",
        "src/main.cpp",
        "src/RandomGenerator.cpp",
        "src/GeneratorCauchy.cpp",
        "-lm"
    ]
    
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("✗ Error compilando:")
        print(result.stderr)
        return 1
    print("✓ Compilado exitosamente")
    
    # 2. EJECUTAR
    print("\n[2/3] Ejecutando simulación...")
    exe = "./cauchy_simulator" if os.name != 'nt' else "cauchy_simulator.exe"
    result = subprocess.run([exe], capture_output=True, text=True)
    print(result.stdout)
    
    if result.returncode != 0:
        print("✗ Error ejecutando:", result.stderr)
        return 1
    
    # 3. GENERAR GRÁFICOS
    print("\n[3/3] Generando gráficos...")
    if Path("plot_cauchy.py").exists():
        result = subprocess.run([sys.executable, "plot_cauchy.py"], 
                              capture_output=True, text=True)
        if result.returncode == 0:
            print("✓ Gráficos generados en /results/")
        else:
            print("✗ Error:", result.stderr)
    else:
        print("✗ No se encontró plot_cauchy.py")
    
    print("\n" + "=" * 50)
    print("COMPLETADO")
    print("=" * 50)
    return 0

if __name__ == "__main__":
    sys.exit(main())