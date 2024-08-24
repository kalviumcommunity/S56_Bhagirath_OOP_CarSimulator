#include <iostream>
#include <vector>
using namespace std;

enum CarType {SEDAN, SUV};

class Car {
private:
    string brand;
    string color;
    CarType carType;

public:
    string model;
    int fuellevel;

    Car(string brand, string model, string color, int fuellevel, CarType carType)
        : brand(brand), model(model), color(color), fuellevel(fuellevel), carType(carType) {}

    void startCar() {
        if (this->fuellevel > 0) {
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

    CarType getCarType() {
        return carType;
    }

    void drive() {
        if (fuellevel > 0) {
            cout << model << " is driving!" << endl;
            fuellevel -= (carType == SUV ? 15 : 10);
        } else {
            cout << model << " has no fuel left. Please refuel!" << endl;
        }
    }

    void openBoot() {
        if (carType == SUV) {
            cout << model << " (SUV) Boot is Opened with extra space." << endl;
        } else {
            cout << model << " (Sedan) Boot is Opened with normal space." << endl;
        }
    }

    void engage4x4() {
        if (carType == SUV) {
            cout << model << " (SUV) has engaged 4X4 mode for off-roading!" << endl;
        } else {
            cout << "4X4 mode is not available for this car." << endl;
        }
    }
};

int main() {
    string brand, model, color;
    int fuelLevel, carType, carCount;

    cout << "How many cars would you like to create? ";
    cin >> carCount;

    vector<Car> cars;
    for (int i = 0; i < carCount; i++) {
        cout << "\nEnter the type of car for car " << i + 1 << ":" << endl;
        cout << "1. Sedan" << endl;
        cout << "2. SUV" << endl;
        cout << "Choice: ";
        cin >> carType;

        cout << "Enter car details:" << endl;
        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Color: ";
        cin >> color;
        cout << "Initial Fuel Level (0-100): ";
        cin >> fuelLevel;

        CarType type = (carType == 1) ? SEDAN : SUV;
        cars.emplace_back(brand, model, color, fuelLevel, type);
    }

    int action;
    while (true) {
        cout << "\nChoose a car by its index (0 to " << cars.size() - 1 << "): ";
        int carIndex;
        cin >> carIndex;

        if (carIndex < 0 || carIndex >= cars.size()) {
            cout << "Invalid index! Please choose a valid car." << endl;
            continue;
        }

        Car& car = cars[carIndex];
        CarType type = car.getCarType();

        cout << "\nCar Actions:" << endl;
        cout << "1. Start Car" << endl;
        cout << "2. Drive Car" << endl;
        cout << "3. Refuel Car" << endl;
        cout << "4. Check Fuel" << endl;
        cout << "5. Open Boot" << endl;
        cout << "6. Get Car Info" << endl;
        cout << "7. Go Back" << endl;
        cout << "8. Exit" << endl;

        if (type == SUV) {
            cout << "9. Engage 4X4" << endl;
        }

        cout << "Action: ";
        cin >> action;

        if (action == 8) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else if (action == 7) {
            continue;
        }

        switch (action) {
            case 1:
                car.startCar();
                break;
            case 2:
                car.drive();
                break;
            case 3: {
                int refuelAmount;
                cout << "Enter the amount to refuel: ";
                cin >> refuelAmount;
                car.refuel(refuelAmount);
                break;
            }
            case 4:
                car.checkFuel();
                break;
            case 5:
                car.openBoot();
                break;
            case 6:
                car.getCarInfo();
                break;
            case 9:
                if (type == SUV) {
                    car.engage4x4();
                } else {
                    cout << "4X4 mode is not available for this car." << endl;
                }
                break;
            default:
                cout << "Invalid action! Please choose a valid option." << endl;
                break;
        }
    }

    return 0;
}
