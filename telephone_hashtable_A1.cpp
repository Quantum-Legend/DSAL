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
  void insertLinearProbing();
  void insertQuadraticProbing();
  int searchLinearProbing(std::string name);
  int searchQuadraticProbing(std::string name);
  void display();
};

void hash::insertLinearProbing()
{
  telephoneRecord *t = new telephoneRecord;
  std::cout << "Enter name" << std::endl;
  std::cin >> t->name;
  std::cout << "Enter telephone number" << std::endl;
  std::cin >> t->telephoneNo;

  int loc, ASCII_sum;
  for(int i = 0; i < t->name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(t->name[i]);
  }
  loc = (ASCII_sum/t->name.size()) % size;
  for(int i = 0; i < size; i++)
  {
    if(flag[loc] == 0)
    {
      hashtable[loc] = *t;
      flag[loc] = 1;
      break;
    }
    else
    {
      loc = (loc + 1) % size;
    }
  }
}

void hash::insertQuadraticProbing()
{
  telephoneRecord *t = new telephoneRecord;
  std::cout << "Enter name" << std::endl;
  std::cin >> t->name;
  std::cout << "Enter telephone number" << std::endl;
  std::cin >> t->telephoneNo;

  int loc, ASCII_sum;
  for(int i = 0; i < t->name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(t->name[i]);
  }
  loc = (ASCII_sum/t->name.size()) % size;
  for(int i = 0; i < size; i++)
  {
    if(flag[loc] == 0)
    {
      hashtable[loc] = *t;
      flag[loc] = 1;
      break;
    }
    else
    {
      loc = (loc + i*i) % size;
    }
  }
}

int hash::searchLinearProbing(std::string name)
{
  int loc, ASCII_sum, count = 0;
  for(int i =0; i < name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(name[i]);
  }
  loc = (ASCII_sum/name.size()) % size;

  if(flag[loc] == 0)
  {
    std::cout << name << " does not exist in the telephone book!" << std::endl;
    return -1;
  }
  else
  {
    if(hashtable[loc].name == name)
    {
      std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
      return count;
    }
    else
    {
      for(int i = 0; i < size; i++)
      {
        loc = (loc + 1) % size;
        count++;
        if(hashtable[loc].name == name)
        {
          std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
          return count;
        }
      }
    }
  }
}

int hash::searchQuadraticProbing(std::string name)
{
  int loc, ASCII_sum, count = 0;
  for(int i =0; i < name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(name[i]);
  }
  loc = (ASCII_sum/name.size()) % size;

  if(flag[loc] == 0)
  {
    std::cout << name << " does not exist in the telephone book!" << std::endl;
    return -1;
  }
  else
  {
    if(hashtable[loc].name == name)
    {
      std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
      return count;
    }
    else
    {
      for(int i = 0; i < size; i++)
      {
        loc = (loc + i*i) % size;
        count++;
        if(hashtable[loc].name == name)
        {
          std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
          return count;
        }
      }
    }
  }
}

void hash::display()
{
  telephoneRecord *t;
  for(int i = 0; i < size; i++)
  {
      t = &hashtable[i];
      std::cout << t->name << " - " << t->telephoneNo << std::endl;
  }
}

int main()
{
  hash book1, book2;
  return 0;
}
