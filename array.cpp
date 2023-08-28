#include<iostream>

using namespace std;

class MyArray{
        int size;
        int* arr;
        
        public:
        
        MyArray(){
                cout<<"MyArray default constructor"<<endl;
                size = 10;
                arr = new int[size];
                for(int i=0;i<size;i++){
                        arr[i] = 0;
                }
        }
        
        MyArray(int s){
                cout<<"MyArray Parameterized constructor"<<endl;
                size = s;
                arr = new int[size];
                for(int i=0;i<size;i++){
                        arr[i] = 0;
                }
        }
        
        void swap(int index,int data){
                try{
                        arr[index] = data;
                }
                catch(exception e){
                        cout<<"Cannot swap the digits\n";
                }
        }
        
        void display(){
                for(int i=0;i<size;i++)
                        cout<<i+1<<"] "<<arr[i]<<endl;
        }
};


extern "C"
{
MyArray* createArray(){
        return new MyArray();
}

MyArray* createArraywithSize(int size){
        return new MyArray(size);
}

void swap(MyArray* myArray, int idx, int data){
        myArray->swap(idx,data);
}

void display(MyArray* myArray){
        myArray->display();
}

void release(MyArray* myArray){
        cout<<myArray<<endl;
        free(myArray);
        cout<<myArray<<endl;
}
}
