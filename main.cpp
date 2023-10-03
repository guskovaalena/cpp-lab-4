#include <iostream>
using namespace std;

//функция поиска максимального элемента в массиве
int maximum(int *arr, int n){

    int maxi = arr[0];

    for (int i = 0; i < n; i++){
        if (arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

// фнкция поиска суммы элементов в массиве
int arrsum (int *arr, int n){

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int main () {

    int n;
    cout<<"Enter the numer of cups: ";
    cin>>n;
    cout<<endl;

    int m = 1;
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = m;
        m++;
    }

    int arrtmp[n];
    int arr1[n]; //массив граммовок мини-порций Маши
    int arr2[n]; //массив граммовок мини-порций Пети

    for (int i = 0; i < n; i++){
        arrtmp[i] = arr[i];
        arr1[i] = 0;
        arr2[i] = 0;
    }

    int k1 = 0;
    int k2 = 0;

    int s1 = 0;
    int s2 = 0;
    int count1 = 0; //счетчик количества мини-порций Маши
    int count2 = 0; //счетчик количества мини-порций Пети

    while (arrsum(arrtmp, n) != 0){

        if (s1 <= s2){
            s1 += maximum(arrtmp, n);
            arr1[k1] = maximum(arrtmp, n);
            count1++;
            k1++;
        }
        else{
            s2 += maximum(arrtmp, n);
            arr2[k2] = maximum(arrtmp, n);
            count2++;
            k2++;
        }

        for (int i = 0; i < n; i++){
            if (arrtmp[i] == maximum(arrtmp, n)){
                arrtmp[i] = 0;
                break;
            }
        }
    }

    int result;

    if (s1 <= s2){
        result = s2 - s1;
    }
    else{
        result = s1 - s2;
    }

    if (result == 0) {

        cout<<"YES"<<endl;

        cout << "Masha's cups' number: " << count1 << endl;
        cout << "Masha's cups: ";
        for (int i = 0; i < n; i++) {
            if (arr1[i] != 0)
                cout << arr1[i] << ' ';
        }
        cout << endl;
        cout << "Petya's cups' number: " << count2 << endl;
        cout << "Petya's cups: ";
        for (int i = 0; i < n; i++) {
            if (arr2[i] != 0)
                cout << arr2[i] << ' ';
        }
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}