#include "GeneratorCauchy.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
GeneratorCauchy::GeneratorCauchy() : c(1.0) {
    // Constructor por defecto con c=1
}

GeneratorCauchy::GeneratorCauchy(double c_param) : c(c_param) {
    if (c_param <= 0) {
        std::cerr << "Advertencia: El parámetro c debe ser positivo. Usando c=1." << std::endl;
        c = 1.0;
    }
}

double GeneratorCauchy::generate() {
    // Método de transformada inversa para Cauchy:
    // x = c * tan(π*(u - 0.5)), donde u ~ Uniforme(0,1)
    double u = generateUniform();
    return c * tan(M_PI * (u - 0.5));
}

std::string GeneratorCauchy::getDescription() const {
    return "Generador de Distribución Cauchy (c=" + std::to_string(c) + ")";
}

double GeneratorCauchy::theoreticalPDF(double x) const {
    // f(x) = 1 / [π * c * (1 + (x/c)²)]
    return 1.0 / (M_PI * c * (1.0 + (x/c)*(x/c)));
}

void GeneratorCauchy::generateAndAnalyze(int n, const std::string& filename) {
    std::cout << "\n" << getDescription() << std::endl;
    std::cout << "Generando " << n << " valores..." << std::endl;
    
    // Generar valores
    std::vector<double> values = RandomGenerator::generate(n);
    
    // Calcular estadísticas
    double min_val = *std::min_element(values.begin(), values.end());
    double max_val = *std::max_element(values.begin(), values.end());
    
    // Calcular media y desviación (aunque para Cauchy no están definidas teóricamente)
    double sum = 0.0;
    for (double val : values) {
        sum += val;
    }
    double mean = sum / n;
    
    // Calcular cuartiles aproximados
    std::vector<double> sorted_values = values;
    std::sort(sorted_values.begin(), sorted_values.end());
    
    double q1 = sorted_values[n/4];
    double median = sorted_values[n/2];
    double q3 = sorted_values[3*n/4];
    
    // Mostrar estadísticas
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Estadísticas descriptivas:" << std::endl;
    std::cout << "  Mínimo: " << min_val << std::endl;
    std::cout << "  Q1 (25%): " << q1 << std::endl;
    std::cout << "  Mediana: " << median << std::endl;
    std::cout << "  Q3 (75%): " << q3 << std::endl;
    std::cout << "  Máximo: " << max_val << std::endl;
    std::cout << "  Media muestral: " << mean << std::endl;
    
    // Teórico: mediana = 0, Q1 = -c, Q3 = c
    std::cout << "\nValores teóricos (para c=" << c << "):" << std::endl;
    std::cout << "  Mediana: 0.0000" << std::endl;
    std::cout << "  Q1: " << -c << std::endl;
    std::cout << "  Q3: " << c << std::endl;
    
    // Guardar si se especificó un archivo
    if (!filename.empty()) {
        saveToFile(values, filename);
    }
}