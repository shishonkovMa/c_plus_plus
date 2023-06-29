#include <fstream>
#include <iostream>
#include <algorithm>

#include "Register.h"

void Register::indexateSubordinates(Record* record, Record* root_record)
{
    if (!record->getBoss().empty())
    {
        subordinates_map[record->getBoss()].push_back(root_record);
        indexateSubordinates(getNamesMap().find(record->getBoss())->second, root_record);
    }
}

void Register::indexate()
{
    for (Record* r : storage)
    {
        names_map.insert({ r->getName(), r });
        departments_map[r->getDepartment()].push_back(r);
    }
    for (Record* r : storage)
    {
        indexateSubordinates(r, r);
    }
}

Register::Register() {}

Register::Register(const Register& reg)
{
    for (Record* r : reg.storage)
    {
        storage.push_back(new Record(*r));
    }
    indexate();
}

void swap(Register& first, Register& second)
{
    std::swap(first.storage, second.storage);
    std::swap(first.names_map, second.names_map);
    std::swap(first.departments_map, second.departments_map);
    std::swap(first.subordinates_map, second.subordinates_map);
}

Register& Register::operator=(const Register& reg)
{
    Register tmp(reg);
    swap(*this, tmp);
    return *this;
}

void Register::loadFile()
{
    clearRegister();

    std::cout << "Enter the filename : ";
    std::string filename;
    std::cin >> filename;
    if (filename.find(".csv") == std::string::npos)
    {
        filename += ".csv";
    }
    std::ifstream infile(filename);
    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
        {
            storage.push_back(new Record(line));
        }

        indexate();

        std::cout << filename  << " loaded " << std::endl;
    }
    else
    {
        std::cout << "Can't open " << filename << std::endl;
    }
}

void Register::clearMemory()
{
    for (Record* r : storage)
    {
        delete r;
    }
}

void Register::clearRegister()
{
    clearMemory();
    storage.clear();
    names_map.clear();
    departments_map.clear();
    subordinates_map.clear();
}

void Register::printRegister()
{
    for (Record* r : storage)
    {
        std::cout << *r << std::endl;
    }
}

int Register::storageSize() const
{
    return storage.size();
}

const Register::RecordVector& Register::getStorage() const
{
    return storage;
}

const std::set<Record*> Register::getEmployeesByDays(std::set<std::string> days) const
{
    std::set<Record*> employee_set;
    for (std::string day : days)
    {
        for (Record* r : storage)
        {
            if (std::find(r->getWorkingDays().begin(), r->getWorkingDays().end(), day) != r->getWorkingDays().end())
            {
                employee_set.insert(r);
            }
        }
    }
    return employee_set;
}

const std::map<std::string, Record*>& Register::getNamesMap() const
{
    return names_map;
}

const std::map<std::string, Register::RecordVector>& Register::getDepartmentsMap() const
{
    return departments_map;
}

const std::map<std::string, Register::RecordVector>& Register::getSubordinatesMap() const
{
    return subordinates_map;
}

Register::~Register()
{
    clearMemory();
}
