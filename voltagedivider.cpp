// Includes access to voltage divider class
#include "voltagedivider.h"

namespace project 
{
    
// Constructor
VoltageDivider::VoltageDivider(const Resistor& r1, const Resistor& r2) : 
R1_{ r1 }, R2_{ r2 } {}

// Function implementation for nominal gain
double VoltageDivider::find_nominal_gain() const {
    return R1_.find_nominal_resistance() / (R1_.find_nominal_resistance() + R2_.find_nominal_resistance());
}

// Function implementation for actual gain
double VoltageDivider::find_actual_gain() const {
    return R1_.find_actual_resistance() / (R2_.find_actual_resistance() + R2_.find_actual_resistance());
}

};

