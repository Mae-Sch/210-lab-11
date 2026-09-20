#include <iostream>
#include <iomanip>

using namespace std

enum Allergens { dairy, eggs, gluten, nuts, soy };

// Represents item of food in a grocery store
// include names of item, price, and an array of common allergens
struct Food {
    string name;
    double price;
    Allergens AllergenList[0];
};
