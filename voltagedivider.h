
/**
 * @file voltagedivider.h
 * @brief Class to model a voltage divider circuit.
 * @author Adolfo Hernandez
 * @date 2023-05-11
 *
 * This class uses two Resistor objects to model a voltage divider
 * and calculate its nominal and actual gain based on the resistances.
 */
// Header gaurds for header file
#ifndef VOLTAGE_DIVIDER_H
#define VOLTAGE_DIVIDER_H

#include "resistor.h" // Resistor class access

// Encapsulation of class within project namespace
namespace project 
{
    /**
     * @class VoltageDivider
     * @brief Models a voltage divider circuit.
     *
     */

    class VoltageDivider 
    {
        private: 

            const Resistor R1_; // First resistor
            const Resistor R2_; // Second resistor

        public:

        /** 
         * @brief Construct a new VoltageDivider object.
         * 
         * @param r1 A Resistor object representing the first resistor.
         * @param r2 A Resistor object representing the second resistor.
         */
        VoltageDivider(const Resistor& r1, const Resistor& r2);

        /**
        * @brief Calculate and return the nominal gain of the voltage divider.
        * The nominal gain is calculated using the nominal resistances of R1 and R2.
        * @return Nominal gain as a double.
         */
        double find_nominal_gain() const;

        /**
         * @brief Calculate and return the nominal gain of the voltage divider.
         * @return returns nominal gain
         */
        
        double find_actual_gain() const;
    };

} // End of namespace 

#endif // VOLTAGE_DIVIDER_H 
