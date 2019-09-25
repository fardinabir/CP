#include<windows.h>
#include<iostream>
#include<stdlib.h> //for system("cls");
using namespace std;

int main()
{
 int i;
 char h='*';
 system("cls");
 Sleep(800);
 cout<<"\t\t";

 cout<<"\n\n";
 system("color E");

 Sleep(400);
 system("color F");
 cout<<"\t\t\t\ti i i i i\n";
 system("color A");
 Sleep(400);
 cout<<"\t\t\t\ti i i i i\n";
 system("color D");
 Sleep(400);
 system("color 6");
 cout<<"\t\t\t      __i_i_i_i_i__\n";

 system("color D");
 Sleep(800);
 system("color 1");
 cout<<"\t\t\t     |"<<h<<"           "<<h<<"|\n";
 system("color 5");
 Sleep(400);
 system("color E");
 cout<<"\t\t\t   __| "<<h<<"   ---   "<<h<<" |__\n";
 system("color 6");
 Sleep(400);
 cout<<"\t\t\t  | "<<h<<"   "<<h<<"       "<<h<<"   "<<h<<" |\n";
 system("color F");
 Sleep(400);
 cout<<"\t\t\t__|"<<h<<"   HAPPY     "<<h<<"   "<<h<<"|__\n";
 system("color 9");
 Sleep(700);
 cout<<"\t\t       | "<<h<<"   "<<h<<"     BIRTHDAY    "<<h<<" |\n";
 system("color F");
 Sleep(400);
 cout<<"\t\t       |"<<h<<"  "<<h<<"     "<<h<<"    "<<h<<"     "<<h<<"   "<<h<<"|\n";

 system("color D");
 Sleep(800);
 cout<<"\t\t       | "<<h<<" "<<h<<" "<<h<<" "<<h<<"  Monty  "<<h<<" "<<h<<" "<<h<<" "<<h<<" |\n";


 system("color 4");
 Sleep(800);
 system("color F");
 cout<<"_______________________|_________________________|__________________________\n";

 cout<<"\n\n\t       ";
 for(i=0;i<42;i++)
 cout<<"_";
 cout<<"\n\n\n\n\n";
 system("pause");
 while(1)
 {
     cout<<"\n\n\n\n\n\t\t\t      Say treat !???\n\n\n";
     Sleep(400);
 }

 return 0;
}
