#include "Person.h"

// Person Member Functions
Person::Person() {
    this->pname = "";
    this->pgender = Gender::ANY;
    this->pmother = nullptr;
    this->pfather = nullptr;
}

// setter funcs
void Person::name(std::string i_name) {
    this->pname = i_name;
}
void Person::gender(Gender i_gender) {
    this->pgender = i_gender;
}
void Person::mother(Person* i_mother) {
    this->pmother = i_mother;
}
void Person::father(Person* i_father) {
    this->pfather = i_father;
}
void Person::add_child(Person* i_child) {
    this->pchildren.insert(i_child);
}

const std::string& Person::name() const {
    return this->pname;
}

Gender Person::gender() const {
    return this->pgender;
}

Person* Person::mother() {
    return this->pmother;
}

Person* Person::father() {
    return this->pfather;
}

//for stubbing
std::set<Person*> stub = {nullptr};

std::set<Person*> Person::ancestors(PMod pmod) {
    return stub;
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::children() {
    return this->pchildren;
}

std::set<Person*> Person::cousins(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::daughters() {
    std::set<Person*> Daughters;
    for (Person* child : this->pchildren) {
        if (child->pgender == Gender::FEMALE) {
            Daughters.insert(child);
        }
    }
    return Daughters;
}

void Person::get_childern(std::set<Person*>& Descendants) {
    if (this->pchildren.size() == 0) {
        return;
    } else {
        std::set<Person*> temp = this->pchildren;
        Descendants.merge(temp);
        for (Person* child : this->pchildren) {
            child->get_childern(Descendants);
        }
    }
}

std::set<Person*> Person::descendants() {
    std::set<Person*> Descendants;
    get_childern(Descendants);
    return Descendants;
}

std::set<Person*> Person::grandchildren() {
    std::set<Person*> Grandsons = this->grandsons();
    std::set<Person*> Granddaughters = this->granddaughters();
    Grandsons.merge(Granddaughters);
    return Grandsons;
}

std::set<Person*> Person::granddaughters() {
    std::set<Person*> Granddaughters;
    for (Person* child : this->pchildren) {
        std::set<Person*> temp = child->daughters();
        Granddaughters.merge(temp);
    }
    return Granddaughters;
}

std::set<Person*> Person::grandfathers(PMod pmod) {
    std::set<Person*> Grandfathers = this->grandparents(pmod);
    for (Person* grandparent : Grandfathers) {
        if (grandparent->pgender == Gender::FEMALE) {
            Grandfathers.erase(grandparent);
        }
    }
    return Grandfathers;
}

std::set<Person*> Person::grandmothers(PMod pmod) {
    std::set<Person*> Grandmothers = this->grandparents(pmod);
    for (Person* grandparent : Grandmothers) {
        if (grandparent->pgender == Gender::MALE) {
            Grandmothers.erase(grandparent);
        }
    }
    return Grandmothers;
}

std::set<Person*> Person::grandparents(PMod pmod) {
    std::set<Person*> Grandparents;
    if (pmod == PMod::ANY) {
        if (this->pmother != nullptr) {
            std::set<Person*> temp = this->pmother->parents();
            Grandparents.merge(temp);
        }
        if (this->pfather != nullptr) {
            std::set<Person*> temp = this->pfather->parents();
            Grandparents.merge(temp);
        }
    } else if (pmod == PMod::MATERNAL && this->pmother != nullptr) {
        std::set<Person*> temp = this->pmother->parents();
        Grandparents.merge(temp);
    } else if (this->pfather != nullptr) {
        std::set<Person*> temp = this->pfather->parents();
        Grandparents.merge(temp);
    }
    return Grandparents;
}

std::set<Person*> Person::grandsons() {
    std::set<Person*> Grandsons;
    for (Person* child : this->pchildren) {
        std::set<Person*> temp = child->sons();
        Grandsons.merge(temp);
    }
    return Grandsons;
}

std::set<Person*> Person::nephews(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::nieces(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::parents(PMod pmod) {
    std::set<Person*> Parents;
    if (pmod == PMod::ANY) {
        if (this->pmother != nullptr) {
            Parents.insert(this->pmother);
        }
        if (this->pfather != nullptr) {
            Parents.insert(this->pfather);
        }
    } else if (pmod == PMod::MATERNAL && this->pmother != nullptr) {
        Parents.insert(this->pmother);
    } else if (this->pfather != nullptr) {
        Parents.insert(this->pfather);
    }
    return Parents;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::sisters(PMod pmod, SMod smod) {
    return stub;
}

std::set<Person*> Person::sons() {
    std::set<Person*> Sons;
    for (Person* child : this->pchildren) {
        if (child->pgender == Gender::MALE) {
            Sons.insert(child);
        }
    }
    return Sons;
}
    
std::set<Person*> Person::uncles(PMod pmod, SMod smod) {
    return stub;
}