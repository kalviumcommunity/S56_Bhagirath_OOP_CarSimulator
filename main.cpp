#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string color;

public:
    string model;
    int fuellevel;

    Car(string brand, string model, string color, int fuellevel) {
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->fuellevel = fuellevel;
    }

    void startCar() {
        if (fuellevel > 0) {
            cout << brand << " " << model << " is Started." << endl;
        } else {
            cout << "Out of fuel, please refuel." << endl;
        }
    }

    void checkFuel() {
        cout << brand << " " << model << " has " << fuellevel << " litres remaining." << endl;
    }

    void refuel(int amount) {
        if (fuellevel + amount <= 100) {
            fuellevel += amount;
            cout << "Your Fuel Level is increased by " << amount << " litres." << endl;
        } else {
            cout << "Fuel Tank is full." << endl;
        }
    }

    void getCarInfo() {
        cout << "Car Information: " << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Fuel Level: " << fuellevel << "%" << endl;
    }
};

class Sedan : public Car {
public:
    Sedan(string brand, string model, string color, int fuellevel) : Car(brand, model, color, fuellevel) {}

    void openBoot() {
        cout << "Boot is Opened." << endl;
    }

    void drive() {
        if (fuellevel > 0) {
            cout << model << " is driving smoothly!" << endl;
            fuellevel -= 10;
        } else {
            cout << model << " has no fuel left. Please refuel!" << endl;
        }
    }
};

class SUV : public Car {
public:
    SUV(string brand, string model, string color, int fuellevel) : Car(brand, model, color, fuellevel) {}

    void openBoot() {
        cout << "Boot is Opened." << endl;
    }

    void drive() {
        if (fuellevel > 0) {
            cout << model << " (SUV) is driving on rough terrain!" << endl;
            fuellevel -= 20;
        } else {
            cout << model << " has no fuel left. Please refuel!" << endl;
        }
    }

    void engage4x4() {
        cout << model << " (SUV) has engaged 4X4 mode for off-roading!" << endl;
    }
};

int main() {
    Sedan sedanCars[2] = {
        Sedan("Toyota", "Camry", "Red", 50),
        Sedan("Honda", "Accord", "Blue", 60)
    };

    SUV suvCars[2] = {
        SUV("Ford", "Explorer", "Black", 80),
        SUV("Jeep", "Cherokee", "Green", 70)
    };

    int carType, carIndex, action;

    while (true) {
        cout << "\nChoose Car Type:" << endl;
        cout << "1. Sedan" << endl;
        cout << "2. SUV" << endl;
        cout << "Type: ";
        cin >> carType;

        if (carType == 1) { // Sedan
            cout << "\nChoose Sedan Car (0 or 1): ";
            cin >> carIndex;

            if (carIndex < 0 || carIndex >= 2) {
                cout << "Invalid car index! Try again." << endl;
                continue;
            }

            while (true) {
                cout << "\nChoose an action:" << endl;
                cout << "1. Start Car" << endl;
                cout << "2. Drive Car" << endl;
                cout << "3. Refuel Car" << endl;
                cout << "4. Check Fuel" << endl;
                cout << "5. Open Boot" << endl;
                cout << "6. Get Car Info" << endl;
                cout << "7. Change Car Type" << endl;
                cout << "8. Exit" << endl;
                cout << "Action: ";
                cin >> action;

                if (action == 7) {
                    break; // Exit the Sedan action menu to choose a different car type
                } else if (action == 8) {
                    cout << "Exiting the game. Goodbye!" << endl;
                    return 0;
                }

                switch (action) {
                    case 1:
                        sedanCars[carIndex].startCar();
                        break;
                    case 2:
                        sedanCars[carIndex].drive();
                        break;
                    case 3: {
                        int refuelAmount;
                        cout << "Enter the amount to refuel: ";
                        cin >> refuelAmount;
                        sedanCars[carIndex].refuel(refuelAmount);
                        break;
                    }
                    case 4:
                        sedanCars[carIndex].checkFuel();
                        break;
                    case 5:
                        sedanCars[carIndex].openBoot();
                        break;
                    case 6:
                        sedanCars[carIndex].getCarInfo();
                        break;
                    default:
                        cout << "Invalid action! Please choose a valid option." << endl;
                        break;
                }
            }
        } else if (carType == 2) { // SUV
            cout << "\nChoose SUV Car (0 or 1): ";
            cin >> carIndex;

            if (carIndex < 0 || carIndex >= 2) {
                cout << "Invalid car index! Try again." << endl;
                continue;
            }

            while (true) {
                cout << "\nChoose an action:" << endl;
                cout << "1. Start Car" << endl;
                cout << "2. Drive Car" << endl;
                cout << "3. Refuel Car" << endl;
                cout << "4. Check Fuel" << endl;
                cout << "5. Open Boot" << endl;
                cout << "6. Engage 4X4" << endl;
                cout << "7. Get Car Info" << endl;
                cout << "8. Change Car Type" << endl;
                cout << "9. Exit" << endl;
                cout << "Action: ";
                cin >> action;

                if (action == 8) {
                    break; // Exit the SUV action menu to choose a different car type
                } else if (action == 9) {
                    cout << "Exiting the game. Goodbye!" << endl;
                    return 0;
                }

                switch (action) {
                    case 1:
                        suvCars[carIndex].startCar();
                        break;
                    case 2:
                        suvCars[carIndex].drive();
                        break;
                    case 3: {
                        int refuelAmount;
                        cout << "Enter the amount to refuel: ";
                        cin >> refuelAmount;
                        suvCars[carIndex].refuel(refuelAmount);
                        break;
                    }
                    case 4:
                        suvCars[carIndex].checkFuel();
                        break;
                    case 5:
                        suvCars[carIndex].openBoot();
                        break;
                    case 6:
                        suvCars[carIndex].engage4x4();
                        break;
                    case 7:
                        suvCars[carIndex].getCarInfo();
                        break;
                    default:
                        cout << "Invalid action! Please choose a valid option." << endl;
                        break;
                }
            }
        } else {
            cout << "Invalid car type! Please try again." << endl;
        }
    }

    return 0;
}
