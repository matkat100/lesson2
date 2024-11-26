#pragma once
#include "ProfileList.h"
#include <string>
#include <vector>

class SocialNetwork {
public:
    // מאתחלת את הרשת החברתית עם שם וגיל מינימלי
    void init(const std::string& networkName, int minAge);

    // מנקה את הרשת החברתית ומוחקת את כל הפרופילים
    void clear();

    // מחזירה את שם הרשת
    std::string getNetworkName() const;

    // מחזירה את הגיל המינימלי
    int getMinAge() const;

    // מוסיפה פרופיל לרשת החברתית
    bool addProfile(const Profile& profile_to_add);

    // מחזירה מחרוזת של מכשירים שמריצים מערכת הפעלה Windows ומחוברים לרשת
    std::string getWindowsDevices() const;

private:
    std::string _networkName;  // שם הרשת
    int _minAge;               // גיל מינימלי להצטרפות
    ProfileList _profiles;     // רשימת פרופילים ברשת
};
