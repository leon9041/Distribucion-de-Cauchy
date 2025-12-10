#ifndef GENERATORCAUCHY_H
#define GENERATORCAUCHY_H

#include "RandomGenerator.h"

class GeneratorCauchy : public RandomGenerator {
private:
    double c; // Parámetro de escala
    double M_PI = 3.14159265358979323846; // PI
public:
    // Constructores
    GeneratorCauchy();
    GeneratorCauchy(double c_param);
    
    // Implementación del método generate
    double generate() override;
    
    // Implementación del método getDescription
    std::string getDescription() const override;
    
    // Método específico para Cauchy: calcular PDF teórica
    double theoreticalPDF(double x) const;
    
    // Método para generar y mostrar estadísticas
    void generateAndAnalyze(int n, const std::string& filename = "");
    
    // Getters y Setters
    double getParameter() const { return c; }
    void setParameter(double c_param) { c = c_param; }
};

#endif