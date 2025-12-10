import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import cauchy
import os

# Configuración de estilo
plt.style.use('seaborn-v0_8-darkgrid')
plt.rcParams['figure.figsize'] = [10, 6]
plt.rcParams['font.size'] = 12

# Crear directorio results si no existe
if not os.path.exists('results'):
    os.makedirs('results')

# Cargar datos generados por C++
print("Cargando datos desde results/cauchy.dat...")
try:
    data = np.loadtxt('results/cauchy.dat')
    print(f"Datos cargados: {len(data)} valores")
except FileNotFoundError:
    print("Error: No se encontró el archivo results/cauchy.dat")
    print("Ejecuta primero el programa C++ para generar los datos")
    exit(1)

# Parámetros
c = 1.0  # Parámetro de escala
n_bins = 100

# Filtrar valores extremos para mejor visualización
data_filtered = data[(data > -20) & (data < 20)]
print(f"Valores fuera del rango [-20, 20]: {len(data) - len(data_filtered)}")
print(f"Porcentaje descartado: {(len(data) - len(data_filtered))/len(data)*100:.2f}%")

# Crear figura con un solo gráfico
fig, ax = plt.subplots(figsize=(12, 7))

# Histograma con curva teórica
n, bins, patches = ax.hist(data_filtered, bins=n_bins, density=True, 
                           alpha=0.7, color='steelblue', edgecolor='black',
                           label='Datos generados')

# Calcular y graficar la curva teórica
x = np.linspace(-20, 20, 1000)
pdf = cauchy.pdf(x, loc=0, scale=c)
ax.plot(x, pdf, 'r-', linewidth=3, label='Teórica: $f(x) = \\frac{1}{\\pi(1+x^2)}$')

ax.set_xlabel('x', fontsize=14)
ax.set_ylabel('Densidad de probabilidad', fontsize=14)
ax.set_title('Distribución Cauchy (c=1) - Histograma vs Curva Teórica', 
             fontsize=16, fontweight='bold')
ax.legend(fontsize=12, loc='upper right')
ax.grid(True, alpha=0.3)

# Agregar información estadística
stats_text = f'N = {len(data):,}\n'
stats_text += f'Media = {np.mean(data):.3f}\n'
stats_text += f'Desv. estándar = {np.std(data):.3f}\n'
stats_text += f'Mediana = {np.median(data):.3f}\n'
stats_text += f'Mín = {np.min(data):.3f}\n'
stats_text += f'Máx = {np.max(data):.3f}\n'
stats_text += f'Fuera de [-20,20]: {(len(data)-len(data_filtered))/len(data)*100:.1f}%'

ax.text(0.02, 0.98, stats_text, transform=ax.transAxes,
         fontsize=11, verticalalignment='top',
         bbox=dict(boxstyle='round', facecolor='lightyellow', alpha=0.9))

# Ajustar diseño y guardar
plt.tight_layout()
output_file = 'results/hist_cauchy.png'
plt.savefig(output_file, dpi=300, bbox_inches='tight')
print(f"\nGráfica guardada como: {output_file}")

# Mostrar resumen
print("\n" + "="*50)
print("RESUMEN DE LA SIMULACIÓN")
print("="*50)
print(f"Número total de valores: {len(data):,}")
print(f"Rango de datos: [{np.min(data):.2f}, {np.max(data):.2f}]")
print(f"Media muestral: {np.mean(data):.4f}")
print(f"Mediana: {np.median(data):.4f} (teórica: 0.0000)")
print(f"Desviación estándar: {np.std(data):.4f}")

# Teoría vs práctica
print("\nComparación teórica vs práctica:")
print(f"Valor teórico en x=0: {1/(np.pi):.4f}")
hist_val = n[np.abs(bins).argmin()]  # Valor cerca de x=0
print(f"Valor práctico en x≈0: {hist_val:.4f}")

plt.show()