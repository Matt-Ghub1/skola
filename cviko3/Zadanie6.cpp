#include <iostream>
#include <string>

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

// class MyArr {
// public:
//     array<array<char,30>,30> arr;
//     vector<char> meno {'M','a','t','u','s',' ','G','r','u','n'};

//     int velkostMena = meno.size();
//     int velkostArr = arr.size();

//     MyArr()  {
//         // naplnit pole arr znakmi a menom
//         for (int i = 0; i < 30; i++)
//         {
//             int j=0;
//             if (i+velkostMena > velkostArr) {
//             j = i+velkostMena - velkostArr;}            //kvoli osetreniu aby som nepisal mimo pola;

//             fill(arr[i].begin(), arr[i].end(), '*');
//             copy(meno.begin(), meno.end() - j, arr[i].begin()+i);
//             rotate(meno.begin(), meno.end()-1, meno.end());
//             for (char x : arr[i])
//                 cout << x << " ";
//             cout << endl;
            
//         }
        
//     }
//     };

template <typename T>
class MyArr {
    public:
    array<array<T,30>,30> arr;
    vector<T> data;         //v podstate moze byt aj meno 
    T vypln;


    MyArr() {
        int n;
        cout << "Zadaj pocet cisel: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            T x;
            cout << "Zadaj cislo " << i + 1 << ": ";
            cin >> x;
            data.push_back(x);
        }
        cout << "Zadaj cislo, ktore nahradi '*': ";
        cin >> vypln;

        naplnit();
    }

    void naplnit()
    {
        int velkostData = data.size();
        int velkostArr = arr[0].size();
        
        for(int i = 0; i < 30; i++)
        {
            fill(arr[i].begin(),arr[i].end(),vypln);

            int j=0;
            if (i+velkostData > velkostArr) 
                j = i+velkostData - velkostArr; 

            copy(data.begin(), data.end() - j, arr[i].begin()+i);
            rotate(data.begin(), data.end() - 1, data.end());

            
        }
    }

    friend ostream& operator<<(ostream& couts, MyArr& m)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                couts << m.arr[i][j] << " ";
            }
            couts << endl;
        }
        return couts;
    }
};


// template <>
// MyArr<char>::MyArr()
// {
//     data = {'M','a','t','u','s',' ','G','r','u','n'};
//     vypln = '*';
//     naplnit();
// }

// specializacia pre char
template <>
class MyArr<char> {
private:
    array<array<char,30>,30> arr;
    vector<char> data;
    char vypln;

public:
    MyArr() {
        data = {'M','a','t','u','s',' ','G','r','u','n'};
        vypln = '*';

        int velkostData = data.size();
        int velkostArr = arr[0].size();

        for (int i = 0; i < 30; i++)
        {
            fill(arr[i].begin(), arr[i].end(), vypln);

            int j = 0;
            if (i + velkostData > velkostArr)
                j = i + velkostData - velkostArr;

            copy(data.begin(), data.end() - j, arr[i].begin() + i);
            rotate(data.begin(), data.end() - 1, data.end());
        }
    }

    friend ostream& operator<<(ostream& os, MyArr<char>& m)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                os << m.arr[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};



int main()
{
    MyArr<char> znaky;
    cout << znaky << endl;

    MyArr<int> cisla;
    cout << cisla << endl;
    return 0;
}