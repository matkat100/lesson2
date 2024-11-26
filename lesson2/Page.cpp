#include "Page.h"
#include "UserList.h"

void Page::init()
{
    _status = "";  // Empty status initially
    _posts = "";   // Empty posts initially
}

std::string Page::getPosts() const
{
    return _posts;
}

std::string Page::getStatus() const
{
    return _status;
}

void Page::setStatus(const std::string& status)
{
    _status = status;
}

void Page::addLineToPosts(const std::string& new_line)
{
    if (!_posts.empty())
        _posts += "\n";
    _posts += new_line;
}
