/**
 * @file resistor.h
 * @brief Class to represent an electrical resistor.
 * @author Adolfo Hernandez
 * @date 2023-04-11
 */
// Header guards -- RESISTOR_H is the unique identifier 
#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream> // iostream library for usage of input/output functionality 
#include <random> // random library used to generate random values
#include <string> // string library used to display messages to user


// Project namespace declared to encapsulate Resistor class
namespace project 
{
/**
 * @class Resistor
 * @brief Represents an electrical resistor with tolerance and number value generation.
 *
 * Class models an electrical resistor and calculates
 * actual resistance based on nominal resistance and tolerance using random value generation.
 */

    class Resistor 
    {
        private:

            const double nominalResistance_;
            const double tolerance_;
            double actualResistance_;


        public:
            /**
             * @brief Constructor of Resistor object.
             * @param nominalResistance_ Nominal resistance (static).
             * @param tolerance_ Tolerance percentage (static).
             */
           Resistor(const double nominalResistance_, const double tolerance_);

            /** @brief Gets nominal resistance of resistor.
             * @return Nomical resistance value.
             */
            double find_nominal_resistance() const;

            /**
             * @brief gets tolerance percentage of resistor.
             * @return tolerance percentage.
             */

            double find_tolerance() const;

            /**
             * @brief using random number generation, finds actual resistance.
             * @return returns actual resistance
             */
            double find_actual_resistance() const;

            /**
             * @brief Gets color bands of resistor.
             * @return Resturns a set of colors to respective resistor.
             */
            std::string get_color_bands() const;

    };



}; // End of project namespace


// End of header gaurd
#endif //RESISTOR_H 
