#pragma once
#include <string>
#include "DeviceList.h"  // לכלול את המחלקה DevicesList על מנת להשתמש בה

class User {
public:
    // מאתחלת אובייקט של משתמש חדש
    void init(unsigned int id, const std::string& username, unsigned int age);

    // מנקה את האובייקט ומוחקת זיכרון שהוקצה לאובייקט
    void clear();

    // מחזירה את תעודת הזהות של המשתמש
    unsigned int getID() const;

    // מחזירה את שם המשתמש
    std::string getUserName() const;

    // מחזירה את גיל המשתמש
    unsigned int getAge() const;

    // מחזירה הפניה לרשימת המכשירים של המשתמש
    DevicesList& getDevices();

    // מוסיפה מכשיר לרשימת המכשירים של המשתמש
    void addDevice(const Device newDevice);

    // מחזירה true אם כל המכשירים שבבעלות המשתמש נמצאים במצב "פועל"
    bool checkIfDevicesAreOn() const;

private:
    unsigned int id;              // תעודת זהות של המשתמש
    std::string username;         // שם המשתמש
    unsigned int age;             // גיל המשתמש
    DevicesList devices;          // רשימת המכשירים של המשתמש
};
