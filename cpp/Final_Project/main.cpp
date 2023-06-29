#include <iostream>
#include <sstream>

#include "Register.h"

int main()
{
    Register reg;

    std::cout << "Employee database\n=================\n";
    char choice = ' ';
    while (true)
    {
        std::cout << std::endl;
        std::cout << "(L) Load a file\n";
        std::cout << "(C) Clear a dataset\n";
        std::cout << "(N) Print number of records in dataset\n";
        std::cout << "(P) Print all records\n";
        std::cout << "(A) List of  employees whose age belongs to a given range\n";
        std::cout << "(D) List of employees distributed by departments\n";
        std::cout << "(F) Search employee by their name\n";
        std::cout << "(S) List of all subordinates of a given employee\n";
        std::cout << "(W) List of employees working on given days\n";
        std::cout << "(T) Test copy & assignment\n";
        std::cout << "(X) Exit\n";
        std::cout << '\n';

        std::cout << "Choose an action: ";
        std::cin >> choice;

        if (choice == 'X' || choice == 'x')
        {
            break;
        }

        switch (choice)
        {
        case 'L': case 'l':
            reg.loadFile();
            break;
        case 'C': case 'c':
            reg.clearRegister();
            std::cout << "Dataset was cleared\n";
            break;
        case 'N': case 'n':
            std::cout << reg.storageSize() << " records\n";
            break;
        case 'P': case 'p':
            reg.printRegister();
            break;
        case 'A': case 'a':
            int min, max;
            std::cout << "Enter lower and upper bounds: ";
            std::cin >> min >> max;
            for (Record* r : reg.getStorage())
            {
                if (r->getAge() >= min && r->getAge() <= max)
                    std::cout << *r << std::endl;
            }
            break;
        case 'D': case 'd':
            for (auto a : reg.getDepartmentsMap())
            {
                std::cout << a.first << std::endl;
                for (Record* r : a.second)
                {
                    std::cout << "  " << r->getName() << std::endl;
                }
            }
            break;
        case 'F': case 'f':
        {
            std::string name;
            std::cout << "Enter the name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            auto iter = reg.getNamesMap().find(name);
            if (iter != reg.getNamesMap().end())
            {
                std::cout << *(iter->second) << std::endl;
            }
            else
            {
                std::cout << "No employee with that name\n";
            }
            break;
        }
        case 'S': case 's':
        {
            std::string name;
            std::cout << "Enter the name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            auto iter = reg.getSubordinatesMap().find(name);
            if (iter != reg.getSubordinatesMap().end())
            {
                for (Record* r : iter->second)
                {
                    std::cout << "  " << r->getName() << std::endl;
                }
            }
            else
            {
                std::cout << "No employee with that name or employee has no subordinates\n";
            }
            break;
        }
        case 'W': case 'w':
        {
            std::set<std::string> days;

            std::cout << "Enter days ( Mon Tue Wed Thu Fri Sat Sun ): ";
            std::string line;
            std::cin.ignore();
            std::getline(std::cin, line);
            std::istringstream input;
            input.str(line);
            std::string t;
            while (getline(input, t, ' '))
            {
                days.insert(t);
            }

            for (Record* r : reg.getEmployeesByDays(days))
            {
                std::cout << r->getName() << " ( ";
                for (std::string d : r->getWorkingDays())
                {
                    std::cout << d << ' ';
                }
                std::cout << ")\n";
            }
            break;
        }
        case 'T': case 't':
        {
            std::cout << "Copy constructor test:\n";
            Register temp_reg(reg);
            temp_reg.printRegister();
            std::cout << std::endl;

            std::cout << "Assignment test:\n";
            temp_reg = reg;
            temp_reg.printRegister();

            break;
        }
        default:
            std::cout << "Incorrect input.\n";
        }
    }

    return 0;
}
