#ifndef USER_H
#define USER_H

#include <string>

class User
{
    std::string m_name;
    std::string m_firstSurname;
    std::string m_secondSurname;
    std::string m_password;
public:
    User();
};

#endif // USER_H
