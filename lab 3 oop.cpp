// lab 3 oop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "nlohmann/json.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

using json = nlohmann::json;

int main()
{
    cout << "Hi!" << endl;
    // create a JSON object
    json j =
    {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {
            "answer", {
                {"everything", 42}
            }
        },
        {"list", {1, 0, 2}},
        {
            "object", {
                {"currency", "USD"},
                {"value", 42.99}
            }
        }
    };

    // add new values
    j["new"]["key"]["value"] = { "another", "list" }; //фунція запису

    // count elements
    auto s = j.size();
    j["size"] = s; //функція запису
    j["laba_3"] = 100;
    cout << (j.find("laba_3") != j.end()) << endl; //пошук елементу, 1
    cout << (j.find("laba_5") != j.end()) << endl; //пошук елементу, 0

    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n'; //виведення на екран
}