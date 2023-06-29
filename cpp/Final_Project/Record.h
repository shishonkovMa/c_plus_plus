#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <vector>

class Record
{
public:
    Record(std::string);
    static Record* makeRecord(std::string);
    const std::string& getName() const;
    const std::string& getDepartment() const;
    const std::string& getBoss() const;
    const std::string& getPosition() const;
    int getAge() const;
    const std::vector<std::string>& getWorkingDays() const;
    friend std::ostream& operator<<(std::ostream&, const Record&);
private:
    std::string name;
    int age;
    std::string department;
    std::string position;
    std::string boss_name;
    std::vector<std::string> working_days;
};

#endif // RECORD_H
