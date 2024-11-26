#include "SocialNetwork.h"
#include "Profile.h"
#include "ProfileList.h"
#include <string>
#include <sstream>

// מאתחלת את הרשת החברתית עם שם וגיל מינימלי
void SocialNetwork::init(const std::string& networkName, int minAge) {
    _networkName = networkName;
    _minAge = minAge;
    _profiles.init();  // מאתחלת את רשימת הפרופילים
}

// מנקה את הרשת החברתית ומוחקת את כל הפרופילים
void SocialNetwork::clear() {
    _profiles.clear();  // מנקה את רשימת הפרופילים
}

// מחזירה את שם הרשת
std::string SocialNetwork::getNetworkName() const {
    return _networkName;
}

// מחזירה את הגיל המינימלי להצטרפות לרשת
int SocialNetwork::getMinAge() const 
{
    return _minAge;
}

// מוסיפה פרופיל לרשת החברתית
bool SocialNetwork::addProfile(const Profile& profile_to_add) 
{
    // בודק אם הגיל של המשתמש בפרופיל מתאים לגיל המינימלי
    if (profile_to_add.getOwner().getAge() < _minAge) 
    {
        return false;  // אם הגיל לא מתאים, מחזירה false
    }

    // אם כן, מוסיפה את הפרופיל לרשת
    _profiles.add(profile_to_add);
    return true;
}

// מחזירה מחרוזת של מכשירים שמריצים מערכת הפעלה Windows ומחוברים לרשת
std::string SocialNetwork::getWindowsDevices() const
{
    std::string result = "";
    ProfileNode* currentProfileNode = _profiles.get_first(); // Start of the profile list

    // Traverse through each profile in the social network
    while (currentProfileNode != nullptr)
    {
        Profile profile = currentProfileNode->get_data(); // Get the profile data
        DeviceNode* currentDeviceNode = profile.getOwner().getDevices().get_first(); // Start of the devices list for this profile

        // Traverse through each device of the profile
        while (currentDeviceNode != nullptr)
        {
            Device device = currentDeviceNode->get_data(); // Get the device data

            // Check if the device runs Windows
            if (device.getOS().find("Windows") != std::string::npos)
            {
                if (!result.empty())
                {
                    result += ", "; // Add a comma and space for non-first entries
                }
                result += "[" + std::to_string(device.getID()) + ", " + device.getOS() + "]";
            }

            currentDeviceNode = currentDeviceNode->get_next(); // Move to the next device
        }

        currentProfileNode = currentProfileNode->get_next(); // Move to the next profile
    }

    return result;
}