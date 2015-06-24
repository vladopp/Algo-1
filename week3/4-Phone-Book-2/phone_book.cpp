#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Contact {
public:
  Contact(string name, int number)
  {
    this->name = name;
    this->number = number;
  }
  string name;
  int number;
};

class PhoneBook {
public:

  static bool comp(Contact a, Contact b)
  {
    return a.name<b.name;
  }

  //inserts a new contact
  void insert(Contact contact){
    if(!vec.size())
    {
      vec.push_back(contact);
    }
    else
    {
      vector<Contact>::iterator it = lower_bound(vec.begin(), vec.end(), contact, comp);
      if(it!=vec.end() && it->name == contact.name)
      {
        vec[it-vec.begin()].number = contact.number;
      }
      else
      {
        vec.insert(it, contact);
      }
    }
  }
  
  //lookup a name and print its phone number
  void lookup(string name){
    vector<Contact>::iterator it = lower_bound(vec.begin(), vec.end(), Contact(name, 0), comp);
    if(it==vec.end() || it->name != name)
    {
      cout << "NOT FOUND!" << endl;
    }
    else
    {
        cout << it->number << endl;
    }
  }
  
  //list all records in an alphabetical order
  void list() {
    for(int i=0; i<vec.size(); i++)
    {
      cout << vec[i].name << "-" << vec[i].number << endl;
    }
  }
  
  //remove a record for a given name
  void remove(string name) {
    vector<Contact>::iterator it = lower_bound(vec.begin(), vec.end(), Contact(name, 0), comp);
    if(it!=vec.end() && it->name == name)
    {
      vec.erase(it);
    }
  }

private:
  vector<Contact> vec;
};

int main()
{
  PhoneBook pb;
  Contact a = Contact("c", 5);
  Contact b = Contact("a", 6);
  pb.insert(a);
  pb.insert(b);
  pb.lookup("z");
  pb.lookup("a");
  pb.list();
  pb.remove("a");
  pb.list();
  return 0;
}