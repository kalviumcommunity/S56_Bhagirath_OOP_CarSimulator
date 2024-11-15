#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string color;

public:
    string model;
    static int totalCars;
    int fuellevel;

    Car(string brand, string model, string color, int fuellevel) {
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->fuellevel = fuellevel;
        totalCars++;
    }

    virtual ~Car() {
        totalCars--;
    }

    string getBrand() {
        return brand;
    }

    void setBrand(string newBrand) {
        brand = newBrand;
    }

    string getColor() {
        return color;
    }

    void setColor(string newColor) {
        color = newColor;
    }

    void startCar() {
        if (fuellevel > 0) {
            cout << brand << " " << model << " is started." << endl;
        } else {
            cout << "Out of fuel, please refuel." << endl;
        }
    }

    virtual void drive() = 0;

    static int getTotalCars() {
        return totalCars;
    }
};

int Car::totalCars = 0;

class FuelManager {
public:
    static void refuel(Car& car, int amount) {
        if (car.fuellevel + amount <= 100) {
            car.fuellevel += amount;
            cout << "Fuel Level increased by " << amount << " litres." << endl;
        } else {
            cout << "Fuel Tank is full." << endl;
        }
    }

    static void checkFuel(const Car& car) {
        cout << car.getBrand() << " " << car.model << " has " << car.fuellevel << " litres remaining." << endl;
    }
};

class CarDisplay {
public:
    static void displayInfo(const Car& car) {
        cout << "Car Information: " << endl;
        cout << "Brand: " << car.getBrand() << endl;
        cout << "Model: " << car.model << endl;
        cout << "Color: " << car.getColor() << endl;
        cout << "Fuel Level: " << car.fuellevel << "%" << endl;
    }
};

class SUV : public Car {
private:
    bool fourByFourEngaged;

public:
    SUV(string brand, string model, string color, int fuellevel)
        : Car(brand, model, color, fuellevel), fourByFourEngaged(false) {}

    bool isFourByFourEngaged() {
        return fourByFourEngaged;
    }

    void setFourByFourEngaged(bool status) {
        fourByFourEngaged = status;
    }

    void openBoot() {
        cout << "Boot is opened." << endl;
    }

    void drive() override {
        if (fuellevel > 0) {
            cout << model << " (SUV) is driving on rough terrain!" << endl;
            fuellevel -= 20;
        } else {
            cout << model << " has no fuel left. Please refuel!" << endl;
        }
    }

    void engage4x4() {
        setFourByFourEngaged(true);
        cout << model << " (SUV) has engaged 4X4 mode for off-roading!" << endl;
    }
};

class Sedan : public Car {
public:
    Sedan(string brand, string model, string color, int fuellevel)
        : Car(brand, model, color, fuellevel) {}

    void openBoot() {
        cout << "Boot is opened." << endl;
    }

    void drive() override {
        if (fuellevel > 0) {
            cout << model << " is driving smoothly!" << endl;
            fuellevel -= 10;
        } else {
            cout << model << " has no fuel left. Please refuel!" << endl;
        }
    }
};

int main() {
    Sedan sedan("Toyota", "Camry", "Red", 50);
    SUV suv("Ford", "Explorer", "Black", 80);

    cout << "Total Cars: " << Car::getTotalCars() << endl;

    FuelManager::checkFuel(sedan);
    FuelManager::refuel(sedan, 30);

    CarDisplay::displayInfo(sedan);
    
    sedan.startCar();
    sedan.drive();
    FuelManager::checkFuel(sedan);

    suv.startCar();
    suv.drive();
    FuelManager::checkFuel(suv);
    
    suv.engage4x4();
    CarDisplay::displayInfo(suv);

    cout << "Total Cars: " << Car::getTotalCars() << endl;

    return 0;
}
