#include <iostream>
#include <iomanip>

using namespace std;

enum Allergens { dairy = 1, eggs, gluten, nuts, soy };

// Represents item of food in a grocery store
// include names of item, price, and an array of common allergens
struct Food {
    string name;
    double price;
    Allergens * allergenList;
};

void inputFood(Food *);
void displayFoos(Food *);

int main() {
    Food grocery;
    Food *groceryPtr = &grocery;

    inputFood(groceryPtr);
    
    return 0;
}

void inputFood{Food * fptr} {
    static int numFood = 1;
    cout << "Collecting data for food " << numFood << endl;
    cout << "Name: ";
    // collects input name and stores it in the name variable of the food
    getline(cin, fptr->name);
    cout << "Price: $";
    // doesn't need to be a getLine b/c price shouldn't have any spaces in it
    cin >> fptr->price;
    cout << "The amount of allergens this food has is: ";
    int numAllergens;
    cin >> numAllergens;
    fptr->grases = new int[numAllergens];
    if (numAllergens != 0) {
        cout << "Key:\n"
        << "1: dairy\n"
        << "2: eggs\n"
        << "3: gluten\n"
        << "4: nuts\n"
        << "5: soy\n"
        << "enter the number which cooresponds to the allergen";
        for (int i = 0; i < numAllergens ++i) {
            cout << "allergen #" << (i + 1) << ": ";
            cin >> fptr->allergenList[i];
        }
        cin.ignore();
        cout << endl << endl;
        numFood+= 1;
    }
}