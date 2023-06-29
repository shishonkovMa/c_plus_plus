#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <map>
#include <set>

#include "Record.h"

class Register
{
public:
    typedef std::vector<Record*> RecordVector;

    Register();
    Register(const Register&);
    friend void swap(Register&, Register&);
    Register& operator=(const Register&);

    void loadFile();
    void clearRegister();
    void printRegister();
    int storageSize() const;
    const RecordVector& getStorage() const;
    const std::set<Record*> getEmployeesByDays(std::set<std::string> days) const;

    const std::map<std::string, Record*>& getNamesMap() const;
    const std::map<std::string, RecordVector>& getDepartmentsMap () const;
    const std::map<std::string, RecordVector>& getSubordinatesMap () const;

    ~Register();
private:
    RecordVector storage;
    std::map<std::string, Record*> names_map;
    std::map<std::string, RecordVector> departments_map;
    std::map<std::string, RecordVector> subordinates_map;

    void clearMemory();
    void indexate();
    void indexateSubordinates(Record*, Record*);
};

#endif // REGISTER_H
