#include <sstream>
#include <iostream>

#include "Record.h"

Record::Record(std::string line)
{
    std::istringstream input;
    input.str(line);
    std::string t;

    std::getline(input, name, '\t');
    std::getline(input, t, '\t');
    age = std::stoi(t);
    getline(input, department, '\t');
    getline(input, position, '\t');
    getline(input, boss_name, '\t');
    while (getline(input, t, '\t'))
    {
        working_days.push_back(t);
    }
}

Record* Record::makeRecord(std::string s)
{
    return new Record(s);
}

const std::string& Record::getName() const
{
    return name;
}

const std::string& Record::getDepartment() const
{
    return department;
}

const std::string& Record::getBoss() const
{
    return boss_name;
}

const std::string& Record::getPosition() const
{
    return position;
}

int Record::getAge() const
{
    return age;
}

const std::vector<std::string>& Record::getWorkingDays() const
{
    return working_days;
}

std::ostream& operator<<(std::ostream& os, const Record& r)
{
    os << "Name: " << r.name << "; age " << r.age
       << "; department: " << r.department << "; position: " << r.position
       << "; boss name: ";
    if (r.boss_name.empty())
    {
        os << "---";
    }
    else
    {
        os << r.boss_name;
    }
    os << "; working days: ";
    for (std::string s : r.working_days)
    {
        os << s << ' ';
    }
    return os;
}
