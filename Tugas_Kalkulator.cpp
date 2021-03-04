#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

// membuat class operator matematika supaya coding lebih clean
class Operator{
    public:
        int penjumlahan(int a, int b){
            return a+b;
        }
        int pengurangan(int a,int b){
            return a-b;
        }
        int pembagian(int a, int b){
            return a/b;
        }
        int perkalian(int a,int b){
            return a*b;
        }
        int pangkat(int a,int n){
            return pow(a,n);
        }
        int integral(int a, int b){
            int orde,n;
            // pair ini isinya <koefisien, pangkat>
            vector<pair<int,int>> koefisien;
            cout << "Masukkan orde fungsi : "; cin >> orde;
            for(int i = 0;i<orde;i++){
                int temp;
                cout << "Masukkan koefisien pangkat " << i+1 << " : "; cin >> temp;
                if(temp!=0) koefisien.push_back(make_pair(i+1,temp));
            }
            cout << "Fungsi : ";
            // String formatting fungsi
            for(int i=koefisien.size();i>0;i--){
                if(koefisien[i-1].second == 1){
                    cout << "x^" << koefisien[i-1].first;
                }
                else{
                    cout << koefisien[i-1].second << "x^" << koefisien[i-1].first;
                }
                if(i!=1){
                    cout << " + "; 
                }
            }
            cout << endl;
            cout << "Masukkan banyak trapesium : "; cin >> n;
            // h adalah delta x (tinggi trapesium)
            long double h = (static_cast<double>(b)-static_cast<double>(a))/n;
            float hasil = 0;
            long double i = a;
            while(i<b){
                long double luas1 = 0;
                long double luas2 = 0;
                // menghitung f(x+h)
                for (int j=0;j<koefisien.size();j++){
                    luas1+=pow(i+h,koefisien[j].first) * koefisien[j].second ;
                }
                // menghitung f(x)
                for(int j=0;j<koefisien.size();j++){
                    luas2+=pow(i,koefisien[j].first) * koefisien[j].second;
                }
                hasil+=h*(luas1+luas2)/2;
                i = i + h;
            }
            cout << "Hasil integral adalah : " << hasil << endl;
            return 0;
            }
};


int main(){
    cout << "=======================================" << endl << "Program Kalkulator Sederhana" << endl << "Made by: Muhammad Sulthan Mazaya" << endl <<  "16720208" << endl << "=========================================" << endl;
    Operator Matematika;
    while (true){
        cout << "Opsi :" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "4. Pembagian" << endl;
        cout << "5. Pangkat" << endl;
        cout << "6. Integral" << endl;
        int opsi;
        cout << "Masukkan pilihan (1 s/d 6): ";
        cin >> opsi;
        
        switch (opsi)
        {
            int a,b,n;
            case 1:
                cout << "============" << endl << "a+b" << endl << "============" << endl;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;
                cout << "Hasil : " << Matematika.penjumlahan(a,b) << endl;
                break;
            case 2:
                cout << "============" << endl << "a-b" << endl << "============" << endl;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;
                cout << "Hasil : " << Matematika.pengurangan(a,b) << endl;
                break;
            case 3:
                cout << "============" << endl << "a x b" << endl << "============" << endl;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;
                cout << "Hasil : " << Matematika.perkalian(a,b) << endl;
                break;
            case 4:
                cout << "============" << endl << "a/b" << endl << "============" << endl;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;
                cout << "Hasil : " << Matematika.pembagian(a,b) << endl;
                break;
            case 5:
                cout << "============" << endl << "a^n" << endl << "============" << endl;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan n: "; cin >> n;
                cout << "Hasil : " << Matematika.pangkat(a,n) << endl;
                break;
            case 6:
                cout << "============" << endl << "integral dari a ke b dari f(x) dengan a<b" << endl << "============" << endl;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;
                Matematika.integral(a,b);
                break;
            default:
                cout << "Input Tidak Valid" << endl;
                break;
        }
        cout << "Klik apapun untuk melanjutkan" << endl;
        cin.sync();
        cin.get();
        int mengulang;
        while(true){
            cout << "Mau melakukan perhitungan lagi?" << endl << "Opsi : " << endl;
            cout << "1. Ya" << endl << "2. Tidak" << endl; 
            cout << "Jawaban (1/2) : ";
            cin >> mengulang;
            if(mengulang==1 || mengulang == 2){
                cout << endl;
                break;
            }
            else{
                cout << "Input Tidak Valid" << endl;
                cout << "Klik apapun untuk melanjutkan" << endl;
                cin.sync();
                cin.get();
            }
        }
        if (mengulang==1){
            continue;
        }
        else if(mengulang==2){
            break;
        }
    }
}