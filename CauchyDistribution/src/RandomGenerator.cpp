#include "RandomGenerator.h"
#include <iostream>
#include <fstream>
#include <random>

RandomGenerator::RandomGenerator() {
    initializeGenerator();
}

void RandomGenerator::initializeGenerator() {
    std::random_device rd;
    generator = std::mt19937(rd());
    uniform_dist = std::uniform_real_distribution<double>(0.0, 1.0);
}

double RandomGenerator::generateUniform() {
    return uniform_dist(generator);
}

std::vector<double> RandomGenerator::generate(int n) {
    std::vector<double> values;
    values.reserve(n);
    
    for (int i = 0; i < n; ++i) {
        values.push_back(generate());
    }
    
    return values;
}

void RandomGenerator::saveToFile(const std::vector<double>& data, 
                                const std::string& filename) {
    std::ofstream outfile(filename);
    
    if (!outfile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
        return;
    }
    
    // Escribir encabezado con información
    outfile << "# Datos generados por: " << getDescription() << "\n";
    outfile << "# Número de valores: " << data.size() << "\n\n";
    
    // Escribir los datos
    for (size_t i = 0; i < data.size(); ++i) {
        outfile << data[i] << "\n";
    }
    
    outfile.close();
    std::cout << "✓ Datos guardados en " << filename << std::endl;
}