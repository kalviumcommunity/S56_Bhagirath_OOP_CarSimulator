#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
protected:
    string brand;
    string model;
    string color;
    int fuelLevel;

public:
    Car(string brand, string model, string color, int fuelLevel)
        : brand(brand), model(model), color(color), fuelLevel(fuelLevel) {}

    virtual ~Car() {}

    virtual void drive() = 0;

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    int getFuelLevel() const { return fuelLevel; }

    void refuel(int amount) {
        if (fuelLevel + amount <= 100) {
            fuelLevel += amount;
            cout << "Refueled by " << amount << " liters. Current fuel level: " << fuelLevel << endl;
        } else {
            cout << "Fuel tank is full." << endl;
        }
    }
};

class Sedan : public Car {
public:
    Sedan(string brand, string model, string color, int fuelLevel)
        : Car(brand, model, color, fuelLevel) {}

    void drive() override {
        if (fuelLevel > 0) {
            cout << "Driving the sedan smoothly on the road!" << endl;
            fuelLevel -= 10;
        } else {
            cout << "No fuel left. Please refuel the sedan." << endl;
        }
    }
};

class SUV : public Car {
public:
    SUV(string brand, string model, string color, int fuelLevel)
        : Car(brand, model, color, fuelLevel) {}

    void drive() override {
        if (fuelLevel > 0) {
            cout << "Driving the SUV on rough terrain!" << endl;
            fuelLevel -= 15;
        } else {
            cout << "No fuel left. Please refuel the SUV." << endl;
        }
    }

    void engage4x4() {
        cout << "4x4 mode engaged for off-roading!" << endl;
    }
};

// Abstraction for car services
class CarServiceInterface {
public:
    virtual void performMaintenance(Car& car) = 0;
    virtual ~CarServiceInterface() {}
};

// General car service implementing the interface
class GeneralCarService : public CarServiceInterface {
public:
    void performMaintenance(Car& car) override {
        cout << "Performing general maintenance on " << car.getBrand() << " " << car.getModel() << endl;
    }
};

// Specialized SUV service implementing the interface
class SUVService : public CarServiceInterface {
public:
    void performMaintenance(Car& car) override {
        cout << "Performing specialized maintenance for SUV: " << car.getBrand() << " " << car.getModel() << endl;
    }

    void perform4x4Check(SUV& suv) {
        cout << "Checking 4x4 functionality on the SUV." << endl;
    }
};

class CarDisplay {
public:
    static void displayCarInfo(const Car& car) {
        cout << "Brand: " << car.getBrand() << ", Model: " << car.getModel()
             << ", Color: " << car.getColor() << ", Fuel Level: " << car.getFuelLevel() << "%" << endl;
    }
};

class Garage {
private:
    CarServiceInterface& service;

public:
    Garage(CarServiceInterface& service) : service(service) {}

    void performService(Car& car) {
        service.performMaintenance(car);
    }
};

int main() {
    Sedan mySedan("Toyota", "Camry", "Red", 70);
    SUV mySUV("Ford", "Explorer", "Black", 80);

    CarDisplay::displayCarInfo(mySedan);
    CarDisplay::displayCarInfo(mySUV);

    mySedan.drive();
    mySUV.drive();

    GeneralCarService generalService;
    SUVService suvService;

    Garage sedanGarage(generalService);
    Garage suvGarage(suvService);

    sedanGarage.performService(mySedan);
    suvGarage.performService(mySUV);
    suvService.perform4x4Check(mySUV);

    return 0;
}
