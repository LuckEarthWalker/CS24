#include "GenePool.h"
#include <sstream>
#include <iostream>

// GenePool Member Functions
GenePool::GenePool(std::istream& stream) {
    std::string curr_person;
    while(std::getline(stream, curr_person)) {
        if (curr_person[0] == '#' || curr_person.length() == 0) {
            continue;
        }
        std::istringstream iss(curr_person);
        std::string buffer;

        Person* temp = new Person;

        if (std::getline(iss, buffer, '\t')) { // get name
            temp->name(buffer);
        }

        if (std::getline(iss, buffer, '\t')) { // get gender
            if (buffer == "male") {
                temp->gender(Gender::MALE);
            } else {
                temp->gender(Gender::FEMALE);
            }
        }

        if (std::getline(iss, buffer, '\t')) { // get mother
            if (buffer == "???") {
                temp->mother(nullptr);
            } else {
                temp->mother(find(buffer));
                if (find(buffer) != nullptr) {
                    find(buffer)->add_child(temp);
                }
            }
        }

        if (std::getline(iss, buffer)) { // get father
            if (buffer == "???") {
                temp->father(nullptr);
            } else {
                temp->father(find(buffer));
                if (find(buffer) != nullptr) {
                    find(buffer)->add_child(temp);
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