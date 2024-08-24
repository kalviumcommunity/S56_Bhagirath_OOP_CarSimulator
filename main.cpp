#include <iostream>
using namespace std;
class Car{
    private:
    string brand;
    string color;
    public:
    string model;
    int fuellevel;
    Car(string brand,string model,string color,int fuellevel){
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->fuellevel = fuellevel;
    }
    void startCar(){
        if(fuellevel>0){
            cout << brand << " " << model << " is Started." <<endl;
        }
        else{
            cout<< "Out of fuel please refuel"<<endl;
        }
    }
    void checkFuel(){
        cout<< brand << " " << model << " " << "has" << " "<< fuellevel <<" "<<"litres remaining."<<endl;
    }
    void refuel(int amount){
        if(fuellevel <= 90){
            fuellevel+=10;
            cout<<"Your Fuel Level is increased"<<endl;
        }
        else{
            cout<<"Fuel Tank is full"<<endl;
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
class Sedan:public Car{
    public:
    Sedan(string brand, string model, string color, int fuellevel) : Car(brand,model,color,fuellevel){}
    void openBoot(){
        cout<<"Boot is Opened"<<endl;
    }
    void drive(){
        if (fuellevel > 0) {
            cout << " " << model << " "<< "is driving smoothly!" << endl;
            fuellevel -= 10;
        } else {
            cout << " " << model << " has no fuel left. Please refuel!" << endl;
        }
    }
};
class SUV : public Car {
public:
    SUV(string brand, string model, string color, int fuelLevel) 
        : Car(brand, model, color, fuelLevel) {}
    void openBoot(){
        cout<<"Boot is Opened"<<endl;
    }
    void drive() {
        if (fuellevel > 0) {
            cout << " " << model << " (SUV) is driving on rough terrain!" << endl;
            fuellevel -= 20;
        } else {
            cout<< " " << model << " has no fuel left. Please refuel!" << endl;
        }
    }
};

int main() {
    string brand, model, color;
    int fuelLevel, carType;

    cout << "Enter the type of car you want to create:" << endl;
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

    Sedan sedanCar("", "", "", 0);
    SUV suvCar("", "", "", 0);

    if (carType == 1) {
        sedanCar = Sedan(brand, model, color, fuelLevel);
    } 
    else if (carType == 2) {
        suvCar = SUV(brand, model, color, fuelLevel);
    } 
    else {
        cout << "Invalid choice! Exiting the program." << endl;
        return 1;
    }

  
    int action;
    while (true) {
        cout << "\nChoose an action:" << endl;
        cout << "1. Start Car" << endl;
        cout << "2. Drive Car" << endl;
        cout << "3. Refuel Car" << endl;
        cout << "4. Check Fuel" << endl;
        cout << "5. Open Boot" << endl;
        cout << "6. Get Car Info" << endl;
        cout << "7. Exit" << endl;
        cout << "Action: ";
        cin >> action;

        if (carType == 1) {  
            switch (action) {
                case 1:
                    sedanCar.startCar();
                    break;
                case 2:
                    sedanCar.drive();
                    break;
                case 3: {
                    int refuelAmount;
                    cout << "Enter the amount to refuel: ";
                    cin >> refuelAmount;
                    sedanCar.refuel(refuelAmount);
                    break;
                }
                case 4:
                    sedanCar.checkFuel();
                    break;
                case 5:
                    sedanCar.openBoot();
                    break;
                case 6:
                    sedanCar.getCarInfo();
                    break;
                case 7:
                    cout << "Exiting the game. Goodbye!" << endl;
                    return 0;
                default:
                    cout << "Invalid action! Please choose a valid option." << endl;
                    break;
            }
        } 
        else if (carType == 2) {  
            switch (action) {
                case 1:
                    suvCar.startCar();
                    break;
                case 2:
                    suvCar.drive();
                    break;
                case 3: {
                    int refuelAmount;
                    cout << "Enter the amount to refuel: ";
                    cin >> refuelAmount;
                    suvCar.refuel(refuelAmount);
                    break;
                }
                case 4:
                    suvCar.checkFuel();
                    break;
                case 5:
                    suvCar.openBoot();
                    break;
                case 6:
                    suvCar.getCarInfo();
                    break;
                case 7:
                    cout << "Exiting the game. Goodbye!" << endl;
                    return 0;
                default:
                    cout << "Invalid action! Please choose a valid option." << endl;
                    break;
            }
        }
    }

    return 0;
}
