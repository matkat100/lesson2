#include "Device.h"
#include <string.h>


void Device::init(unsigned int id, DeviceType type, const std::string& os)
{
    this->id = id;
    this->type = type;
    this->os = os;
    this->active = true; 
}

// Get the device ID
unsigned int Device::getID() const {
    return id;
}

// Get the device type
DeviceType Device::getType() const
{
    return type;
}

// Get the operating system of the device
std::string Device::getOS() const 
{
    return os;
}

// Check if the device is active
bool Device::isActive() const 
{
    return active;
}

// Activate the device
void Device::activate() 
{
    active = true;
}

// Deactivate the device
void Device::deactivate() 
{
    active = false;
}
