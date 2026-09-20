#include <iostream>
#include <iomanip>

using namespace std;

// starting food array size
const int NUM_FOODS = 3;

// Represents item of food in a grocery store
// include names of item, price, and an array of common allergens
struct Food {
    string name;
    double price;
    // list of ints, 1 = dairy, 2 = eggs, 3 = gluten, 4 = nuts, 5 = soy
    // numAllergens stores the amount of allergens. Never displayed to user, just used for internal counters
    int numAllergens;
    int * allergenList;

    // destructor to remove pointer
    ~Food() {
        if (allergenList) {
            delete [] allergenList;
        }
        allergenList = nullptr;
    }
};

void inputFood(Food *);
void displayFood(Food *);
// returns name of allergen based on input number
string allergenByNum(int);

int main() {
    // list represents store stock
    Food *stock = new Food[NUM_FOODS];
    for (int i = 0; i < NUM_FOODS; ++i) {
        inputFood(&stock[i]);
    }

    cout << endl;

    cout << "Store stock: \n\n";
    for (int i = 0; i < NUM_FOODS; ++i) {
        displayFood(&stock[i]);
    }
    
    return 0;
}

void inputFood(Food *fptr) {
    // statically stores how many foods are in the list total
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
    fptr->allergenList = new int[numAllergens];
    fptr->numAllergens = numAllergens;
    if (numAllergens != 0) {
        cout << "Key:\n"
        << "1: dairy\n"
        << "2: eggs\n"
        << "3: gluten\n"
        << "4: nuts\n"
        << "5: soy\n"
        << "enter the number which cooresponds to...\n";
        for (int i = 0; i < numAllergens; ++i) {
            cout << "allergen #" << (i + 1) << ": ";
            cin >> fptr->allergenList[i];
        }
    }
        cin.ignore();
        cout << endl << endl;
        numFood+= 1;
}

void displayFood(Food *fptr) {
    cout << "Food: " << fptr->name << endl;
    cout << "Price $" << fptr->price << endl;
    if (fptr->numAllergens != 0) {
        cout << "Contains: ";
        for (int i = 0; i < fptr->numAllergens; ++i) {
            cout << allergenByNum(fptr->allergenList[i]);
            // adds comma and spaces to make output a proper list
            if (i < fptr->numAllergens - 1)
                cout << ", ";
        }
    }
    cout << endl << endl;
}

string allergenByNum(int num) {
    switch(num) {
        case 1:
            return "dairy";
            break;
        case 2:
            return "eggs";
            break;
        case 3:
            return "gluten";
            break;
        case 4:
            return "nuts";
            break;
        case 5:
            return "soy";
            break;
        default:
            return "unknown";
            break;
    }
}