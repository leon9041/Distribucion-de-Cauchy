#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>
#include <vector>
#include <string>

class RandomGenerator {
protected:
    std::mt19937 generator;
    std::uniform_real_distribution<double> uniform_dist;
    
    // Método para inicializar el generador
    void initializeGenerator();
    
public:
    // Constructor
    RandomGenerator();
    
    // Método virtual puro para generar un número
    virtual double generate() = 0;
    
    // Método para generar múltiples valores
    virtual std::vector<double> generate(int n);
    
    // Método para guardar datos en archivo
    virtual void saveToFile(const std::vector<double>& data, 
                           const std::string& filename);
    
    // Método virtual para obtener información del generador
    virtual std::string getDescription() const = 0;
    
    // Método para generar número uniforme [0,1)
    double generateUniform();
    
    // Destructor virtual
    virtual ~RandomGenerator() = default;
};

#endif