#include<iostream>
using namespace std;
template<typename t>
class arrayminmax{
   private:
        t*data;
        size_t size;

   public:
       arrayminmax(t*array,size_t size){

        this->data=array;
        this->size=size;

       }
     t max(){
       t max=data[0];
       for(size_t i=1;i<size;i++){

        if(data[i]>max){

            max=data[i];
        }
       }

     return max;

     }

     t min(){

     t min=data[0];
     for(size_t i=1;i<size;i++){
        if(data[i]<min){


            min=data[i];
        }


     }
     return min;
     }



};

int main(){
 float numbers[5];
 cout<<"enter the values:"<<endl;
 cin>>numbers[5];
  size_t size=sizeof(numbers)/sizeof(float);
  arrayminmax<float>obj(numbers,size);
  float max=obj.max();
  float min=obj.min();

  cout<<"maximum value is:"<<max<<endl;
  cout<<"minimum value is:"<<min<<endl;

  return 0;


}
