#pragma once
#include <string>

class Page
{
public:
    // Initialize a new Page object with empty status and posts
    void init();

    // Get the list of posts in the page, each post on a new line
    std::string getPosts() const;

    // Get the status of the page
    std::string getStatus() const;

    // Set a new status for the page
    void setStatus(const std::string& status);

    // Add a new post to the page
    void addLineToPosts(const std::string& new_line);

private:
    // Data members: status and posts
    std::string _status;
    std::string _posts;
};
