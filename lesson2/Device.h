#pragma once
#include <string>
#include <iostream>

///////////////////////////////////////////////////////////
// Those definitions are used for tests, 
// you can add your own, but please do not delete any.  
///////////////////////////////////////////////////////////
enum DeviceType { PHONE, PC, LAPTOP, TABLET };

#define UbuntuOS "UbuntuLinux"
#define RedHatOS "RedHatLinux"
#define MacOS "MacOS"
#define IOS "IOS"
#define WINDOWS7 "Windows7"
#define WINDOWS10 "Windows10"
#define WINDOWS11 "Windows11"
#define ANDROID "Android"

///////////////////////////////////////////////////////////
// Class Declaration
///////////////////////////////////////////////////////////

class Device {
public:
    // Constructor to initialize a Device object
    void init(unsigned int id, DeviceType type, const std::string& os);

    // Getter to return the device ID
    unsigned int getID() const;

    // Getter to return the device type
    DeviceType getType() const;

    // Getter to return the OS name
    std::string getOS() const;

    // Getter to check if the device is active
    bool isActive() const;

    // Method to activate the device
    void activate();

    // Method to deactivate the device
    void deactivate();

private:
    unsigned int id;          // Device ID
    DeviceType type;          // Device type (PHONE, PC, LAPTOP, TABLET)
    std::string os;           // Operating system of the device
    bool active;              // Device status (active/inactive)
};
