#ifndef PERSON_H
#define PERSON_H

#include "Enums.h"

#include <set>
#include <string>

// This is the Person class you need to implement.
// It has many member functions that perform relationship queries.
// Add any member variables you need to support this.
// Implement the member functions in Person.cpp.

class Person {
  // Member Variables
  std::string pname;
  Gender pgender;
  Person* pmother;
  Person* pfather;
  std::set<Person*> pchildren;
  // Helper Functions
  void get_childern(std::set<Person*>& Descendants);
  void get_parents(std::set<Person*>& Ancesters);
public:
  // Constructor
  Person();
  // Destructor?


  // setter
  void name(std::string i_name);
  void gender(Gender i_gender);
  void mother(Person* i_mother);
  void father(Person* i_father);
  void add_child(Person* i_child);
  // Required Getter Functions
  const std::string& name()   const;
  Gender             gender() const;
  Person*            mother();
  Person*            father();

  // Required Relationship Functions
  std::set<Person*> ancestors(PMod pmod = PMod::ANY);
  std::set<Person*> aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> children();
  std::set<Person*> cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> daughters();
  std::set<Person*> descendants();
  std::set<Person*> grandchildren();
  std::set<Person*> granddaughters();
  std::set<Person*> grandfathers(PMod pmod = PMod::ANY);
  std::set<Person*> grandmothers(PMod pmod = PMod::ANY);
  std::set<Person*> grandparents(PMod pmod = PMod::ANY);
  std::set<Person*> grandsons();
  std::set<Person*> nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> parents(PMod pmod = PMod::ANY);
  std::set<Person*> siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
  std::set<Person*> sons();
  std::set<Person*> uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);

  // Other Member Functions
};

#endif
