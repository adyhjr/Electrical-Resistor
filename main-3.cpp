#include <iostream> // Includes input/output functionality 
#include <random> // Includes random value generation

#include "resistor.h" // Includes "Resistor" class
#include "voltagedivider.h" // Includes "Voltage divider class"


// Primary main function
int main() {

    auto base_nominal = 335; // Default value included in parameter line:20
    auto base_tolerance = 10; // Default value included in parameter line:20

    // For loop iterates through 5 sample resistors each with random
    // value generation 
    for (int i = 1; i <= 5; i++) {

    // Nominal resistance and tolerance will be set to default values 
    // denoted in project examples
    project::Resistor sample_resistor(base_nominal, base_tolerance);

    // Outputs for each of the resistors traits
    std::cout << "Resistor " << i << ": "
              << " Nominal Resistance: " << sample_resistor.find_nominal_resistance()
              << " Tolerance: " << sample_resistor.find_tolerance() << "% "
              << " Actual Resistance: " << sample_resistor.find_actual_resistance() << "\n" << std::endl;

    base_nominal += 5; // Increments nominal resistance parameter to follow project example

    }

    // Prints sample resistor using default values included in project
    // examples. Color bands are included depending on random value generation.
    project::Resistor resistor_one(2700000.0, 5.0);
    std::cout << "Sample Resistor 1: " << resistor_one.find_nominal_resistance()
              << " Tolerance: " <<  resistor_one.find_tolerance()
              << " Actual Resistance: " << resistor_one.find_actual_resistance() 
              << " Color Bands: " << "( " << resistor_one.get_color_bands() << " ) \n" << std::endl;

    // Interates through 10 circuits and displays values calculated from both resistor and voltage divider classes
    const int k_number_of_circuits = 10;
    for (auto counter = 0; counter <= k_number_of_circuits; counter++) {
        project::Resistor r1(330.0, 5.0);
        project::Resistor r2(750.0, 5.0);

        project::VoltageDivider divider(r1, r2);

        // Prints circuits
        std::cout << counter << ": " 
            << divider.find_nominal_gain() << " "
            << divider.find_actual_gain() << std::endl;
    }


    return 0;
}
