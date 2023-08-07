#include<iostream>
#include<string>
using namespace std;

string encrypt(string text,int shift)
{
    string result="";
    for(int i=0;i<text.length();i++){
       char ch=text[i];
       int new_ch=ch+shift;
       if(new_ch>'Z'){


        new_ch=new_ch-26;
       }
        else if(new_ch<'A'){

            new_ch=new_ch+26;
                 }
      result += new_ch;
    }


    return result;

}
string decrypt(string text,int shift){
 shift=26-shift;
 return  decrypt(text,shift);

}
int main(){
string text;
int shift;
cout<<"enter the text you want to encrypt"<<endl;
getline(cin,text);
cout<<"enter the shift";
cin>>shift;
string ciphertext=encrypt(text,shift);
cout<<"\nciphertext:"<<ciphertext<<endl;
string desrypt=decrypt(ciphertext,shift);
cout<<"\ndesrypttext:"<<desrypt<<endl;
return 0;
}






