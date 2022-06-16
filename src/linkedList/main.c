#include "linkedList.h"

int main(){
    List l = NULL;
    List p = NULL;
    
    List *arr;
    arr = MakeList(l,p);
    l = *arr;
    p = *(arr+1);

    AddElement(l,p, "olav" ,(float)11.3);
    AddElement(l,p, "olav" ,(float)11.3);
    AddElement(l,p, "olav" ,(float)11.3);
    
    PrintElement(l);


    return 0;
}
