#include "User.h"

// מאתחלת אובייקט של משתמש חדש
void User::init(unsigned int id, const std::string& username, unsigned int age) {
    this->id = id;
    this->username = username;
    this->age = age;
    this->devices.init();  // מאתחלת את רשימת המכשירים של המשתמש
}

// מנקה את האובייקט ומוחקת זיכרון שהוקצה לאובייקט
void User::clear() {
    this->devices.clear();  // מנקה את רשימת המכשירים
}

// מחזירה את תעודת הזהות של המשתמש
unsigned int User::getID() const {
    return id;
}

// מחזירה את שם המשתמש
std::string User::getUserName() const {
    return username;
}

// מחזירה את גיל המשתמש
unsigned int User::getAge() const {
    return age;
}

// מחזירה הפניה לרשימת המכשירים של המשתמש
DevicesList& User::getDevices() {
    return devices;
}

// מוסיפה מכשיר לרשימת המכשירים של המשתמש
void User::addDevice(const Device newDevice) {
    devices.add(newDevice);
}

// מחזירה true אם כל המכשירים שבבעלות המשתמש נמצאים במצב "פועל"
bool User::checkIfDevicesAreOn() const {
    DeviceNode* current = devices.get_first();
    while (current != nullptr) {
        if (!current->get_data().isActive()) {
            return false;  // אם נמצא מכשיר שאינו פועל, מחזירים false
        }
        current = current->get_next();  // ממשיכים למכשיר הבא ברשימה
    }
    return true;  // אם כל המכשירים פעילים, מחזירים true
}
