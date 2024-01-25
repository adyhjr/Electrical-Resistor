
// Header to include "Resistor" class
#include "resistor.h"

#include <cmath> // cmath library used to include math operators
#include <vector> // vector library used to store color from resistor table in container
#include <string> // string library used to allow string usage for variables

// Namespace declared in resistor.h header file encapsulating "Resistor" class
namespace project 
{
    /// Constructor included with random value generation
     Resistor::Resistor(const double nominalResistance_, const double tolerance_) :
            nominalResistance_ { nominalResistance_ }, 
            tolerance_{ tolerance_ }
             {
            std::default_random_engine generator(std::random_device{}());
            std::uniform_real_distribution<double> distribution((1 - tolerance_ / 100.0), (1 + tolerance_ / 100.0));
            actualResistance_ = nominalResistance_ * distribution(generator);
             }


     double Resistor::find_nominal_resistance() const {
            return nominalResistance_;
    }

     double Resistor::find_tolerance() const {
        return tolerance_;
    }
     
     double Resistor::find_actual_resistance() const{
        return actualResistance_;
    }

    std::string Resistor::get_color_bands() const {
        // Vectors for color coding
        const std::vector<std::string> color_codes = {
            "Black", "Brown", "Red", "Orange", "Yellow",
            "Green", "Blue", "Violet", "Grey", "White"
        };

        const std::vector<std::string> tolerance_colors = {
            "Brown", "Red", "Green", "Blue", "Violet", "Grey", "Gold", "Silver", "None"
        };

        auto first_band = static_cast<int>(nominalResistance_) / 10 % 10;
        auto second_band = static_cast<int>(nominalResistance_) % 10;
        
        auto multiplier_band = 0;
        auto multiplier_value = nominalResistance_;
        while (multiplier_value >= 100.0) {
            multiplier_value /= 10.0;
            multiplier_band++;
        }

        auto tolerance_band_index = -1;
            if (tolerance_ == 1) {
                tolerance_band_index = 0; // Brown
            } else if (tolerance_ == 2) {
                tolerance_band_index = 1; // Red
            } else if (tolerance_ == 0.5) {
                tolerance_band_index = 2; // Green
            } else if (tolerance_ == 0.25) {
                tolerance_band_index = 3; // Blue
            } else if (tolerance_ == 0.1) {
                tolerance_band_index = 4; // Violet
            } else if (tolerance_ == 0.05) {
                tolerance_band_index = 5; // Grey
            } else if (tolerance_ == 5) {
                tolerance_band_index = 6; // Gold
            } else if (tolerance_ == 10) {
                tolerance_band_index = 7; // Silver
            } else {
                tolerance_band_index = 8; // None
            }

            std::string color_bands = color_codes[first_band] + " " + 
                                 color_codes[second_band] + " " +
                                 color_codes[multiplier_band];
        
        if (tolerance_band_index >= 0 && tolerance_band_index < tolerance_colors.size()) {
            color_bands += " " + tolerance_colors[tolerance_band_index];
        }

        return color_bands;
    }

}; // End of implementation file


