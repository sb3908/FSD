#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int ch;
    vector<float>v;
    vector<float>::iterator itr;

    do{
    cout<<"-----menu-----"<<endl;
    cout<<"1.add the vlaue"<<endl;
    cout<<"2.display the values"<<endl;
    cout<<"3.find the values"<<endl;
    cout<<"4. sort the vlaues"<<endl;
    cout<<"5. quit"<<endl;
    cout<<"enter the choice:"<<endl;
    cin>>ch;


    switch(ch){

       case 1:
             float value;
             cout<<"enter the vlaue"<<endl;
             cin>>value;
             v.push_back(value);
             break;

       case 2:
            cout<<"numbers are: "<<endl;
            for(itr=v.begin();itr!=v.end();itr++){

                cout<<*itr<<endl;

            }
            break;

       case 3:
             float target;
             cout<<"enter the value you want to find"<<endl;
             cin>>target;
             itr=find(v.begin(),v.end(),target);
             if(itr!=v.end())
             {
                 cout<<"target found"<<endl;

             }else{

                cout<<"target not found:"<<endl;

             }

          break;

       case 4:
            sort(v.begin(),v.end());
            cout<<"number sorted suceesfully"<<endl;

            break;


       case 5:
           cout<<"goodbye"<<endl;


       default:
          cout<<"invalid choice"<<endl;
          break;
    }








    } while(ch!=5);

    return 0;
}
