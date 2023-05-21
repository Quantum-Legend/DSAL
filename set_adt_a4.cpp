#include <iostream>

class Set
{
    int *arr, capacity, top;

public:
    Set()
    {
        capacity = 10;
        arr = new int[capacity];
        top = -1;
        std::cout << "Default capacity of size 10 created" << std::endl;
    }
    Set(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
        std::cout << "Set of capacity " << n+1 << " created" << std::endl;
    }
    void add(int newElement);
    void remove(int element);
    bool contains(int element);
    int size();
    Set* intersection(Set B);
    Set* uni(Set B);
    Set* diff(Set B);
    bool subset(Set B);
    void menu();
    void show();
};

void Set::add(int newElement)
{
    if(top >= capacity)
    {
        std::cout << "Overflow" << std::endl;
    }
    else if(this->contains(newElement))
    {
        std::cout << "Already contains the element" << std::endl;
    }
    else
    {
        top++;
        arr[top] = newElement;
        std::cout << "New element " << newElement << " was added in the set." << std::endl; 
    }
}
void Set::remove(int element)
{
    if (top < 0)
    {
        std::cout << "Underflow" << std::endl;
    }
    else
    {
        for (int i = 0; i < top + 1; i++)
        {
            if (arr[i] == element)
            {
                arr[i] = arr[top];
                top--;
                std::cout << "The element " << element << " was removed from the set." << std::endl;
                return;
            }
        }
        std::cout << "Element not found. Nothing was removed" << std::endl;
    }
}
bool Set::contains(int element)
{
    if (top < 0)
    {
        return false;
    }
    for (int i = 0; i < top + 1; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }
    return false;
}
int Set::size()
{
    return top + 1;
}
Set* Set::intersection(Set B)
{
    Set *C = new Set(this->capacity + B.capacity);
    for (int i = 0; i < this->top + 1; i++)
    {
        for (int j = 0; j < B.top + 1; j++)
        {
            if (this->arr[i] == B.arr[j])
            {
                C->add(B.arr[j]);
            }
        }
    }
    return C;
}
Set* Set::uni(Set B)
{
    Set *C = new Set(this->capacity + B.capacity);
    for(int i = 0; i < this->top + 1; i++)
    {
        C->add(this->arr[i]);
    }
    for (int i = 0; i < B.top + 1; i++)
    {
        for (int j = 0; j < this->top; j++)
        {
            if (B.arr[i] != this->arr[j])
            {
                C->add(B.arr[i]);
            }
        }
    }
    return C;
}
Set* Set::diff(Set B)
{
    Set *C = new Set(this->capacity + B.capacity);
    int flag;
    for (int i = 0; i < this->top + 1; i++)
    {
        for (int j = 0; j < B.top + 1; j++)
        {
            if (this->arr[i] == B.arr[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            C->add(this->arr[i]);
        }
    }
    return C;
}
bool Set::subset(Set B)
{
    for(int i = 0; i < B.top + 1; i++)
    {
        for(int j = 0; j < this->top + 1; j++)
        {
            if(!(B.contains(this->arr[j])))
                return false;
        }
    }
    return true;
}
void Set::show()
{
    std::cout << "{";
    for(int i = 0; i < this->top; i++)
    {
        std::cout << this->arr[i] << ",";
    }
    std::cout << this->arr[top] << "}" << std::endl;
}

void Set::menu()
{
    int ch, x;
    do
    {
        std::cout << "\nWhat do you want to do?" << std::endl;
        std::cout << "1)Add element to set\n2)Remove element from set\n3)Set contains element\n4)Size of set\n5)Show set\n6)Exit\n\tEnter choice - ";
        std::cin >> ch;
        switch(ch)
        {
            case 1:
                std::cout << "Enter element to add to set: " << std::endl;
                std::cin >> x;
                this->add(x);
                break;
            case 2:
                std::cout << "Enter element to remove from the set: " << std::endl;
                std::cin >> x;
                this->remove(x);
                break;
            case 3:
                std::cout << "Enter the element to check if the set contains it: " << std::endl;
                std::cin >> x;
                if(this->contains(x))
                    std::cout << "The set contains " << x << std::endl;
                else
                    std::cout << "The set does not contain " << x << std::endl;
                break;
            case 4:
                std::cout << "The size of the set is " << this->size() << std::endl;
                break;
            case 5:
                std::cout << "The set is: " << std::endl;
                this->show();
                break;
            case 6:
                std::cout << "Exiting current set..." << std::endl;
                break;
            default:
                std::cout << "Please enter valid choice!" << std::endl;
        }
    }while(ch != 6);
    std::cout << "Current set exited!" << std::endl;
}

int main()
{
    int sizeA, sizeB, ch;
    std::cout << "Enter max capacity of set A and B: " << std::endl;
    std::cin >> sizeA >> sizeB;
    Set A(sizeA-1), B(sizeB-1), *C;
    do
    {
        std::cout << "\nWhat do you want to do?" << std::endl;
        std::cout << "1)Work on set A\n2)Work on set B\n3)A union B\n4)A intersection B\n5)A - B\n6)B - A\n7)A is subset of B?\n8)B is subset of A?\n9)Exit\n\tEnter your choice - ";
        std::cin >> ch;
        switch(ch)
        {
            case 1:
                A.menu();
                break;
            case 2:
                B.menu();
                break;
            case 3:
                C = A.uni(B);
                C->show();
                break;
            case 4:
                C = A.intersection(B);
                C->show();
                break;
            case 5:
                C = A.diff(B);
                C->show();
                break;
            case 6:
                C = B.diff(A);
                C->show();
                break;
            case 7:
                if(A.subset(B))
                    std::cout << "A is a subset of B" << std::endl;
                else
                    std::cout << "A is not a subset of B" << std::endl;
                break;
            case 8:
                if(B.subset(A))
                    std::cout << "B is a subset of A" << std::endl;
                else
                    std::cout << "B is not a subset of A" << std::endl;
                break;
            case 9:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Please enter valid choice!" << std::endl;
        }
    }while(ch != 9);
    std::cout << "Set as an ADT program completed!" << std::endl;
    return 0;
}
