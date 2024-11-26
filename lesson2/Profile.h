#pragma once
#include <string>
#include "User.h"
#include "UserList.h"
#include "Page.h"

class Profile
{
public:
    // Initialize the profile with the user's data
    void init(User owner);

    // Clear the profile (reset all data)
    void clear();

    // Get a copy of the user owning the profile
    User getOwner() const;

    // Set the status of the profile's page
    void setStatus(const std::string& new_status);

    // Add a post to the profile's page
    void addPostToProfilePage(const std::string& post);

    // Add a friend to the profile
    void addFriend(User friend_to_add);

    // Get the page of the profile as a string (status + posts)
    std::string getPage() const;

    // Get a comma-separated list of friends
    std::string getFriends() const;

    // Get a list of friends with the same name length as the owner's
    std::string getFriendsWithSameNameLength() const;

private:
    User _owner;          // The user owning the profile
    Page _page;           // The page associated with the profile
    UserList _friends;    // The list of friends
};
