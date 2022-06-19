#include "../linkedList.hpp"

int main(){
    LinkedList link;
    LinkedList::List l = NULL;
    LinkedList::List p = NULL;
    
    LinkedList::List *arr;
    arr = link.MakeList(l,p);
    l = *arr;
    p = *(arr+1);

    link.AddElement(l,p, "Olav", 60, false, (float)11.3);
    link.AddElement(l,p, "Sven", 60, false, (float)11.4);
    link.AddElement(l,p, "Rob" , 60, false, (float)11.5);
    
    link.PrintElement(l);
    char* fileName = "test.txt";
    
    link.SetFileName(fileName);
    link.SaveLinkedList(l);
    std::cout << std::endl;

    link.DeleteElement(l, 1);
    link.PrintElement(l);
    std::cout << std::endl;


    link.DeleteElement(l,2 );
    link.PrintElement(l);
    std::cout << std::endl;


    link.DeleteElement(l, -1);
    link.PrintElement(l);
    return 0;
}
