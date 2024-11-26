#include "Profile.h"
#include <sstream>
#include "UserList.h"
#include "User.h"

void Profile::init(User owner)
{
    _owner = owner;
    _page.init();  // Initialize the page
    _friends.init();  // Initialize the friends list
}

void Profile::clear()
{
    _page.setStatus("");  // Reset status
    _page.addLineToPosts("");  // Clear posts
    _friends.clear();  // Clear the friends list
}

User Profile::getOwner() const
{
    return _owner;
}

void Profile::setStatus(const std::string& new_status)
{
    _page.setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string& post)
{
    _page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
    _friends.add(friend_to_add);  // Add the user to the friends list
}

std::string Profile::getPage() const
{
    std::ostringstream page;
    page << "Status: " << _page.getStatus() << "\n";
    page << "*******************\n";
    page << "*******************\n";
    page << _page.getPosts();
    return page.str();
}

std::string Profile::getFriends() const
{
    std::ostringstream friends;
    UserNode* curr = _friends.get_first();
    while (curr != nullptr)
    {
        friends << curr->get_data().getUserName();  // Assuming getUserName() returns the username
        if (curr->get_next() != nullptr) friends << ",";
        curr = curr->get_next();
    }
    return friends.str();
}

std::string Profile::getFriendsWithSameNameLength() const
{
    std::ostringstream friends;
    UserNode* curr = _friends.get_first();
    size_t ownerNameLength = _owner.getUserName().size();

    while (curr != nullptr)
    {
        if (curr->get_data().getUserName().size() == ownerNameLength)
        {
            friends << curr->get_data().getUserName();
            if (curr->get_next() != nullptr) friends << ",";
        }
        curr = curr->get_next();
    }
    return friends.str();
}
