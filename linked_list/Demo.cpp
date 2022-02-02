#include<iostream>
#include "singleList.cpp"
#include<conio.h>

using namespace std;

int main()
{
    SingleLinkedList list;
    int choice,data,position;

    while (1)
    {
        cout <<"\n";
        cout<<"1. Display The number of Nodes\n";
        cout <<"2. Count the Number of Nodes\n";
        cout<< "3. Search an element\n";
        cout<<" 4.Create a New List\n";
        cout<<" 5. Insert An Element at Beginning\n";
        cout<<" 6. Insert An Element at End\n";
            
        cout<<"19. quite\n";

        cout<<"Enter your Choice\n";
        cin>> choice;
          if(choice==19)
          break;
        switch (choice)
        {
        case 1:
            list.displayList();
            break;
        case 2:
            cout<<"number of nodes is :"<<list.countNodes()<<"\n";
            break;
        case 3:
           cout<<"enter the element  to be search";
           cin>>data;
           position=list.find(data);
           if(position==0)
               cout<<"element is not in the list";
            else
             cout<<"Element found in the list at "<<position<<"postion";
             break;
        case 4:
             list.createList();
             break;
        case 5:
             cout<<"enter  an element to be inserted";
             cin>>data;
             list.insertAtbeginning(data);
             break;
        case 6:
             cout<<"enter  an element to be inserted";
             cin>>data;
             list.insertAtend(data);
             break;
                 
        default :
              cout<<"Wrong Choice";
              break;
        }
    }


    
}