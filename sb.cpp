#include<iostream>
#include<conio.h>
using namespace std;
 class emplyee
 {
   float emp_id;
   float emp_salary;


   public:

       void emp_in();
       void emp_out();


 };

 void emplyee::emp_in()
 {
     cout<<"enter the emplyee detalis"<<endl;

     cout<<"enter the employee id"<<endl;
     cin>>emp_id;

     cout<<"enter the employee salary:"<<endl;
     cin>>emp_salary;
 }
void emplyee::emp_out()
{
    cout<<"the employee details are:"<<endl;

    cout<<"emp id is="<<emp_id<<"emp salary is="<<emp_salary<<endl;


}
int main()
{
    emplyee emp1;
    cout<<"accesing through object"<<endl;
   emp_ptr->emp_in();

    emplyee *emp_ptr;
    emp_ptr=&emp1;
    cout<<"accesing through pointer to an object:"<<endl;
    emp_ptr->emp_out();

    getch();
    return 0;

}
