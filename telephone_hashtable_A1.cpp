/* Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers */

#include <iostream>
#include <string>

struct telephoneRecord
{
  std::string name;
  long telephoneNo;
};

class hash
{
  int size;
  telephoneRecord *hashtable;
  bool *flag;
  public:
  hash()
  {
    std::cout << "Creating telephone book of default size 10" << std::endl;
    size = 10;
    hashtable = new telephoneRecord[size];
    flag = new bool[size];
    for(int i = 0; i < size; i++)
    {
      flag[i] = 0;
    }
  }
  hash(int a)
  {
    std::cout << "Creating telephone book of size " << a << std::endl;
    size = a;
    hashtable = new telephoneRecord[size];
    flag = new bool[size];
    for(int i = 0; i < size; i++)
    {
      flag[i] = 0;
    }
  }
  void insert();
  void display();
};

void hash::insert()
{
  telephoneRecord *t = new telephoneRecord;
  std::cout << "Enter name" << std::endl;
  std::cin >> t->name;
  std::cout << "Enter telephone number" << std::endl;
  std::cin >> t->telephoneNo;
  for(int i = 0; i < size; i++)
  {
    if(flag[i] == 0)
    {
      hashtable[i] = *t;
      flag[i] = 1;
      break;
    }
  }
}

void hash::display()
{
  telephoneRecord *t;
  for(int i = 0; i < size; i++)
  {
    if(flag[i] == 1)
    {
      t = &hashtable[i];
      std::cout << t->name << " - " << t->telephoneNo << std::endl;
    }
  }
}

int main()
{
  hash book1, book2(5);
  book1.insert();
  book1.insert();
  book1.insert();
  book1.insert();
  book1.display();
  book2.insert();
  book2.insert();
  book2.insert();
  book2.insert();
  book2.insert();
  book2.display();
  return 0;
}
