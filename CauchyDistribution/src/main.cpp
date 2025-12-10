#include <iostream>
#include <vector>
#include <string>
#include "GeneratorCauchy.h"

int main() {
    std::cout << "=========================================" << std::endl;
    std::cout << "   SIMULACIÓN DE DISTRIBUCIÓN CAUCHY     " << std::endl;
    std::cout << "=========================================" << std::endl;
    
    // Crear generador con parámetro c=1
    GeneratorCauchy cauchy_generator(1.0);
    
    // Generar 10^5 valores
    int n_values = 1000000;
    
    // Usar el método que incluye análisis
    cauchy_generator.generateAndAnalyze(n_values, "results/cauchy.dat");
    
    // Generar algunos valores adicionales para mostrar
    std::cout << "\nPrimeros 5 valores generados:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "  " << cauchy_generator.generate() << std::endl;
    }
    
    // Ejemplo de PDF teórica en algunos puntos
    std::cout << "\nPDF teórica en algunos puntos:" << std::endl;
    std::cout << "  f(0) = " << cauchy_generator.theoreticalPDF(0.0) << std::endl;
    std::cout << "  f(1) = " << cauchy_generator.theoreticalPDF(1.0) << std::endl;
    std::cout << "  f(2) = " << cauchy_generator.theoreticalPDF(2.0) << std::endl;
    
    std::cout << "\n=========================================" << std::endl;
    std::cout << "Simulación completada exitosamente!" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    return 0;
}