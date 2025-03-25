#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

class DynamicArray{
    private:
        double *mem;
        int size;
    public:

        DynamicArray(int s=0){size = s; mem = new double[s];};


        void FullManually(){
            cout << "Введите размер массива:" << endl;
            int tmp;
            cin >> tmp;
            while (tmp < 0){
                cout << "Неверный размер массива"<<endl;
                cin >> tmp;
            }
            if (tmp != size){
                Resize(tmp);
            }
            size = tmp;
            cout << "Введите элементы массива" << endl;
            for (int i = 0; i < size; i++){
                cin >> mem[i];
            }
            cout << "Массив успешно заполнен" << endl;
        }

        
        

        void Resize(int s){ // задать размер массива
            if (s != size){
                cout << "resize" << endl;
                double *tmp = new double[s];
                for(int i = 0; i < s; i++){
                    tmp[i] = mem[i];
                }
                delete[] mem;
                mem = tmp;
                size = s;
            }
        }
        void Print(){
            cout << size << endl;
            for (int i = 0; i < size; i++){
                cout << mem[i] << " ";
            }
            cout << endl;
        }

        void SetIndex(int index){
            if (index > size - 1){
                cout << "Ошибка" << endl;
            }else{
                cout << "Введите элемент" << endl;
                cin >> mem[index];
            }
        }

        void DefualtArr(int s=10){
            delete[] mem;
            mem = new double[s];
            size = s;
            for (int i = 0; i < s; i++){
                mem[i] = 1.0 * i;
            }
        }

        int GetIndex(int index){
            if (index > size - 1){
                return -1;
            }else{
                return mem[index];
            }
        }

        double SearchMin(){
            double min = 1000000;
            for(int i = 0; i < size; i++){
                if (mem[i] < min){
                    min = mem[i];
                }
            }
            return min;
        }

        string CheckSort(){
            for(int i = 0; i < size - 1; i++){
                if (mem[i] > mem[i + 1]){
                    return "False";
                }
            }
            return "True";

        }

        void RangeArr(int l, int r){
            for(int i = l; i < r; i++){
                cout << mem[i] << " ";
            }
            cout << endl;

        }
        
        int GetSize(){
            return size;
        }

        DynamicArray& operator+=(const DynamicArray &a1){
            int line_a3 = min(size, a1.size);
            if (a1.size != size){
                this->Resize(min(size, a1.size));
            }
            for (int i = 0; i < line_a3; i++){
                mem[i] = mem[i] + a1.mem[i];
            }
            return *this;
        }

        DynamicArray operator+(const DynamicArray &a1){
            DynamicArray a3(min(size, a1.size));
            int line_a3 = min(size, a1.size);
            for (int i = 0; i < a3.size; i++){
                a3.mem[i] = mem[i] + a1.mem[i];
            }
            return a3;
        }

        DynamicArray operator*(const DynamicArray &a1){
            DynamicArray a3(min(size, a1.size));
            int line_a3 = min(size, a1.size);
            for (int i = 0; i < a3.size; i++){
                a3.mem[i] = mem[i] * a1.mem[i];
            }
            return a3;
        }

        DynamicArray operator-(const DynamicArray &a1){
            DynamicArray a3(min(size, a1.size));
            int line_a3 = min(size, a1.size);
            for (int i = 0; i < a3.size; i++){
                a3.mem[i] = mem[i] - a1[i];
            }
            return a3;
        }

        DynamicArray& operator=(const DynamicArray &a1){
            if (this == &a1) {
                return *this;
            }
            if (size != a1.size){
                Resize(a1.size);
            }
            size = a1.size;
            for (int i = 0; i < a1.size; i++){
                mem[i] = a1.mem[i];
            }
            return *this;
        }

        bool operator<(const DynamicArray &a1){
            return size < a1.size;
        }

        bool operator>(const DynamicArray &a1){
            return size > a1.size;
        }

        bool operator<=(const DynamicArray &a1){
            return size <= a1.size;
        }

        bool operator>=(const DynamicArray &a1){
            return size >= a1.size;
        }

        double& operator[](int i){
            return mem[i];
        }
        
        const double& operator[](int i) const {
            return mem[i];
        }


        friend ostream& operator<<(ostream &s, const DynamicArray &v){
            s << "[";
            for (int i = 0; i < v.size; i++){
                if (i + 1 == v.size){
                    s << v.mem[i];
                }else{
                    s << v.mem[i] << ", ";
                }
            }
            s << "]";
            return s;
        }
        ~DynamicArray(){delete[] mem;};
};




int main(){
    DynamicArray arr1, arr2, arr3;
    arr2.DefualtArr();
    arr2.Print();
    arr1.DefualtArr(5);
    arr1.Print();
    cout << arr2 << endl;
    cout << "------" << endl;
    arr3 = arr1 - arr2;
    arr3.Print();
    arr3 = arr1;
    arr3.Print();
    cout << (arr2 > arr1)<< endl;
    cout << arr1;
    
    

    return 0;
}

// сложение 2 двух массивов