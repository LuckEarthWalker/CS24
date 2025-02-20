#include "GenePool.h"
#include <sstream>
#include <iostream>

// GenePool Member Functions
GenePool::GenePool(std::istream& stream) {
    std::string curr_person;
    while(std::getline(stream, curr_person)) {
        if (curr_person[0] == '#' || curr_person.length() < 3) {
            continue;
        }
        std::cout << "'" << curr_person << "'\n";
        std::istringstream iss(curr_person);
        std::string name;
        std::string gender;
        std::string mom;
        std::string dad;

        Person* temp = new Person;

        if (std::getline(iss, name, '\t')) { // get name
            temp->name(name);
        }

        if (std::getline(iss, gender, '\t')) { // get gender
            if (gender == "male") {
                temp->gender(Gender::MALE);
            } else {
                temp->gender(Gender::FEMALE);
            }
        }

        if (std::getline(iss, mom, '\t')) { // get mother
            if (mom == "???") {
                temp->mother(nullptr);
            } else {
                temp->mother(find(mom));
                if (find(mom) != nullptr) {
                    find(mom)->add_child(temp);
                }
            }
        }

        if (std::getline(iss, dad)) { // get father
            if (dad[dad.length()-1] == '\n') {    
                dad = dad.substr(0,dad.length()-1);
            }
            if (dad == "???") {
                temp->father(nullptr);
            } else {
                temp->father(find(dad));
                if (find(dad) != nullptr) {
                    find(dad)->add_child(temp);
                }
            }
        }
        
        //store in map
        genepool[temp->name()] = temp;
        temp = nullptr;
    }
}

GenePool::~GenePool() {
    for (auto person : genepool) {
        delete person.second;
    }
}

std::set<Person*> GenePool::everyone() const {
    std::set<Person*> all;
    for (auto person : genepool) {
        all.insert(person.second);
    }
    return all;
}

Person* GenePool::find(const std::string& name) const {
    for (auto person : genepool) {
        if (person.first == name) {
            return person.second;
        }
    }
    return nullptr;
}