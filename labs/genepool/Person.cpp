#include "Person.h"
#include <iostream>

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

void Person::get_full_sis(std::set<Person*>& sis, PMod pmod) {
    std::set<Person*> f_daughters;
    std::set<Person*> m_daughters;
    if (this->pmother != nullptr) {
        m_daughters = this->pmother->daughters();
    }
    if (this->pfather != nullptr) {
        f_daughters = this->pfather->daughters();
    }

    if (pmod == PMod::MATERNAL || pmod == PMod::ANY) {
        for (Person* sister : m_daughters) {
            if (f_daughters.count(sister) != 0 && sister != this) {
                sis.insert(sister);
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY) {
        for (Person* sister : f_daughters) {
            if (m_daughters.count(sister) != 0 && sister != this) {
                sis.insert(sister);
            }
        }
    }

}

void Person::get_half_sis(std::set<Person*>& sis, PMod pmod) {
    std::set<Person*> f_daughters;
    std::set<Person*> m_daughters;
    if (this->pmother != nullptr) {
        m_daughters = this->pmother->daughters();
    }
    if (this->pfather != nullptr) {
        f_daughters = this->pfather->daughters();
    }

    if (pmod == PMod::MATERNAL || pmod == PMod::ANY) {
        for (Person* sister : m_daughters) {
            if (f_daughters.count(sister) == 0 && sister != this) {
                sis.insert(sister);
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY) {
        for (Person* sister : f_daughters) {
            if (m_daughters.count(sister) == 0 && sister != this) {
                sis.insert(sister);
            }
        }
    }
}

std::set<Person*> Person::sisters(PMod pmod, SMod smod) {
    std::set<Person*> sis;
    if (smod == SMod::HALF || smod == SMod::ANY) {
        this->get_half_sis(sis, pmod);
    }
    if (smod == SMod::FULL || smod == SMod::ANY) {
        this->get_full_sis(sis, pmod);
    }
    return sis;
}

void Person::get_half_bro(std::set<Person*>& bro, PMod pmod) {
    std::set<Person*> f_sons;
    std::set<Person*> m_sons;
    if (this->pmother != nullptr) {
        m_sons = this->pmother->sons();
    }
    if (this->pfather != nullptr) {
        f_sons = this->pfather->sons();
    }

    if (pmod == PMod::MATERNAL || pmod == PMod::ANY) {
        for (Person* brother : m_sons) {
            if (f_sons.count(brother) == 0 && brother != this) {
                bro.insert(brother);
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY) {
        for (Person* brother : f_sons) {
            if (m_sons.count(brother) == 0 && brother != this) {
                bro.insert(brother);
            }
        }
    }
}

void Person::get_full_bro(std::set<Person*>& bro, PMod pmod) {
    std::set<Person*> f_sons;
    std::set<Person*> m_sons;
    if (this->pmother != nullptr) {
        m_sons = this->pmother->sons();
    }
    if (this->pfather != nullptr) {
        f_sons = this->pfather->sons();
    }

    if (pmod == PMod::MATERNAL || pmod == PMod::ANY) {
        for (Person* brother : m_sons) {
            if (f_sons.count(brother) != 0 && brother != this) {
                bro.insert(brother);
            }
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY) {
        for (Person* brother : f_sons) {
            if (m_sons.count(brother) != 0 && brother != this) {
                bro.insert(brother);
            }
        }
    }
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod) {
    std::set<Person*> bro;
    if (smod == SMod::HALF || smod == SMod::ANY) {
        this->get_half_bro(bro, pmod);
    }
    if (smod == SMod::FULL || smod == SMod::ANY) {
        this->get_full_bro(bro, pmod);
    }
    return bro;
}

void Person::get_parents(std::set<Person*>& Ancesters) {
    if (this->pmother == nullptr && this->pfather == nullptr) {
        return;
    } 
    if (this->pmother != nullptr) {
        this->pmother->get_parents(Ancesters);
    }
    if (this->pfather != nullptr) {
        this->pfather->get_parents(Ancesters);
    }
    std::set<Person*> temp = this->parents();
    Ancesters.merge(temp);
}

std::set<Person*> Person::ancestors(PMod pmod) {
    std::set<Person*> Ancestors;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && this->pmother != nullptr) {
        Ancestors.insert(this->pmother);
        this->pmother->get_parents(Ancestors);
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && this->pfather != nullptr) {
        Ancestors.insert(this->pfather);
        this->pfather->get_parents(Ancestors);
    }
    return Ancestors;
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod) {
    std::set<Person*> aunt;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && this->pmother != nullptr) {
        std::set<Person*> temp = this->pmother->sisters(PMod::ANY, smod);
        aunt.merge(temp);
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && this->pfather != nullptr) {
        std::set<Person*> temp = this->pfather->sisters(PMod::ANY, smod);
        aunt.merge(temp);
    }
    return aunt;
}

std::set<Person*> Person::children() {
    return this->pchildren;
}

std::set<Person*> Person::cousins(PMod pmod, SMod smod) {
    std::set<Person*> cousin;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && this->pmother != nullptr) {
        std::set<Person*> m_siblings = this->pmother->siblings(PMod::ANY, smod);
        for (Person* m_sibling : m_siblings) {
            std::set<Person*> temp = m_sibling->children();
            cousin.merge(temp);
        }
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && this->pfather != nullptr) {
        std::set<Person*> f_siblings = this->pfather->siblings(PMod::ANY, smod);
        for (Person* f_sibling : f_siblings) {
            std::set<Person*> temp = f_sibling->children();
            cousin.merge(temp);
        }
    }
    return cousin;
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
    std::set<Person*> temp = this->grandparents(pmod);
    std::set<Person*> Grandfathers;
    for (Person* grandparent : temp) {
        if (grandparent->pgender == Gender::MALE) {
            Grandfathers.insert(grandparent);
        }
    }
    return Grandfathers;
}

std::set<Person*> Person::grandmothers(PMod pmod) {
    std::set<Person*> temp = this->grandparents(pmod);
    std::set<Person*> Grandmothers;
    for (Person* grandparent : temp) {
        if (grandparent->pgender == Gender::FEMALE) {
            Grandmothers.insert(grandparent);
        }
    }
    return Grandmothers;
}

std::set<Person*> Person::grandparents(PMod pmod) {
    std::set<Person*> Grandparents;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && this->pmother != nullptr) {
        std::set<Person*> temp = this->pmother->parents();
        Grandparents.merge(temp);
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && this->pfather != nullptr) {
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
    std::set<Person*> nephew;
    std::set<Person*> sibling = this->siblings(pmod, smod);
    for (Person* sib : sibling) {
        std::set<Person*> temp = sib->sons();
        nephew.merge(temp);
    }
    return nephew;
}

std::set<Person*> Person::nieces(PMod pmod, SMod smod) {
    std::set<Person*> niece;
    std::set<Person*> sibling = this->siblings(pmod, smod);
    for (Person* sib : sibling) {
        std::set<Person*> temp = sib->daughters();
        niece.merge(temp);
    }
    return niece;
}

std::set<Person*> Person::parents(PMod pmod) {
    std::set<Person*> Parents;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && this->pmother != nullptr) {
        Parents.insert(this->pmother);
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && this->pfather != nullptr) {
        Parents.insert(this->pfather);
    }
    return Parents;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod) {
    std::set<Person*> bros = this->brothers(pmod, smod);
    std::set<Person*> sis = this->sisters(pmod, smod);
    bros.merge(sis);
    return bros;
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
    std::set<Person*> uncle;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && this->pmother != nullptr) {
        std::set<Person*> temp = this->pmother->brothers(PMod::ANY, smod);
        uncle.merge(temp);
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && this->pfather != nullptr) {
        std::set<Person*> temp = this->pfather->brothers(PMod::ANY, smod);
        uncle.merge(temp);
    }
    return uncle;
}