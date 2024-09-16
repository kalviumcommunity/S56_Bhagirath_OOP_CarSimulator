#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string color;

public:
    string model;
    int fuellevel;
    static int totalCars; 

    Car(string brand, string model, string color, int fuellevel) {
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->fuellevel = fuellevel;
        totalCars++; 
    }

    ~Car() {
        totalCars--;
    }

    // Accessor (getter) for brand
    string getBrand() const {
        return brand;
    }

    // Mutator (setter) for brand
    void setBrand(const string& newBrand) {
        brand = newBrand;
    }

    // Accessor (getter) for color
    string getColor() const {
        return color;
    }

    // Mutator (setter) for color
    void setColor(const string& newColor) {
        color = newColor;
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

    static int getTotalCars() { 
        return totalCars;
    }
};

int Car::totalCars = 0; 

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
    Sedan* sedanCars = new Sedan[2]{
        Sedan("Toyota", "Camry", "Red", 50),
        Sedan("Honda", "Accord", "Blue", 60)
    };
    cout << "Total Cars: " << Car::getTotalCars() << endl;
    SUV* suvCars = new SUV[2]{
        SUV("Ford", "Explorer", "Black", 80),
        SUV("Jeep", "Cherokee", "Green", 70)
    };

    sedanCars[0].setBrand("Lexus"); 
    cout << "Updated Brand Name, Brand: " << sedanCars[0].getBrand() << endl;

    delete[] sedanCars;
    delete[] suvCars;

    return 0;
}
