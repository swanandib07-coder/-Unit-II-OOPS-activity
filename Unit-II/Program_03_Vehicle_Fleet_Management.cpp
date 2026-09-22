#include <iostream>   // Input/output
#include <memory>     // Smart pointers
#include <string>     // String data type
#include <vector>     // Vector container
using namespace std;  // Use standard namespace


// Base class for all vehicles
class Vehicle
{
protected:
    string vehicleId;          // Vehicle ID
    string registrationNumber; // Registration number
    double fuelLevel;          // Fuel level

public:
    // Constructor
    Vehicle(string vid, string reg)
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {}

    // Start vehicle engine
    void startEngine() const
    {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
    }

    // Add fuel to the vehicle
    void refuel(double amount)
    {
        fuelLevel += amount;

        // Limit fuel level to 100%
        if (fuelLevel > 100.0)
        {
            fuelLevel = 100.0;
        }
    }

    // Virtual function to display vehicle information
    virtual void displayInfo() const
    {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};


// Truck inherits from Vehicle
class Truck : public Vehicle
{
private:
    double cargoCapacity;   // Cargo capacity

public:
    // Constructor
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity) {}

    // Override vehicle information
    void displayInfo() const override
    {
        cout << "Truck | ";

        // Call base class displayInfo()
        Vehicle::displayInfo();

        cout << "Cargo capacity: "
             << cargoCapacity << " tonnes" << endl;
    }
};


// Delivery van inherits from Vehicle
class DeliveryVan : public Vehicle
{
private:
    int packageCount;   // Number of packages

public:
    // Constructor
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {}

    // Override vehicle information
    void displayInfo() const override
    {
        cout << "Delivery Van | ";

        // Call base class displayInfo()
        Vehicle::displayInfo();

        cout << "Packages loaded: "
             << packageCount << endl;
    }
};


// Bike inherits from Vehicle
class Bike : public Vehicle
{
private:
    bool hasDeliveryBox;   // Delivery box availability

public:
    // Constructor
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

    // Override vehicle information
    void displayInfo() const override
    {
        cout << "Delivery Bike | ";

        // Call base class displayInfo()
        Vehicle::displayInfo();

        // Conditional operator checks delivery box availability
        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};


int main()
{
    // Vector of smart pointers to Vehicle objects
    vector<unique_ptr<Vehicle>> fleet;

    // Add truck to fleet
    fleet.push_back(
        make_unique<Truck>(
            "V001", "MH12-AB-1234", 10.5
        )
    );

    // Add delivery van to fleet
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002", "MH12-CD-5678", 50
        )
    );

    // Add delivery bike to fleet
    fleet.push_back(
        make_unique<Bike>(
            "V003", "MH12-EF-9012", true
        )
    );


    // Display fleet heading
    cout << "=== Fleet Status ===" << endl;


    // Process every vehicle in the fleet
    for (const auto& vehicle : fleet)
    {
        // Start the vehicle engine
        vehicle->startEngine();

        // Display vehicle-specific information
        vehicle->displayInfo();

        // Print a blank line
        cout << endl;
    }

    return 0;   // Successful execution
}
