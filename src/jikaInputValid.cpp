#include<bits/stdc++.h>
#include <chrono>
#include "operasi24.cpp"
using namespace std;

void jikaInputValid(){
            sort(kartu, kartu+4);
            auto mulai = chrono::steady_clock::now();
            do {
                posibilitiTo24();
            }while (next_permutation(kartu, kartu+4));
            auto selesai = chrono::steady_clock::now();
            auto durasi = chrono::duration_cast<chrono::nanoseconds>(selesai - mulai);
            

            if (totalSolusi == 0){
                cout<< "Solusi nihil" ;
            }
            else{
                cout << "Banyak Solusi = "<<" "<< totalSolusi << endl;
                cout << "Solusi : " <<endl ;
                for (i = 1 ; i<= totalSolusi; i++){
                    cout << hasilOpr[i]<< endl ;
                }
                cout << "Waktu penyelesaian = " <<  durasi.count() << " " << "nanosekon"<<endl ;
            }   
            
            cout << "Apakah anda ingin menyimpan hasil pencarian ke dalam file?"<<endl;
            cout << "masukkan y atau n!"<<endl ;
            char yn;
            cin >> yn;
            while(yn != 'y' && yn != 'n'){
                cout << "Input tidak valid, masukkan lagi input!"<<endl;
                cin >> yn;
            }
            
            if(yn == 'y'){
                ofstream file;
                string namafile;
                cout << "Masukkan nama file: ";
                cin >> namafile;
                namafile = "../test/" + namafile + ".txt";
                file.open(namafile);
                file << "Kartu yang terpilih :";
                for(int i=0; i<4; i++){
                    file << intkartu(kartu[i]);
                }
                file << endl;
                if(totalSolusi == 0){
                    file << "Solusi nihil"<< endl;
                }
                else{
                    file << "Banyak solusi: " << totalSolusi << endl;
                    file << "Solusi : "<< endl;
                    for(int i = 1; i <= totalSolusi; i++){
                        file << hasilOpr[i] << endl;
                    }
                }
                file << "Waktu penyelesaian = " <<  durasi.count() << " " << endl ;
                file.close();
            }
            else{
                cout << "Hasil pencarian tidak disimpan"<<endl;
            }
            
            cout << "Apakah anda ingin melanjutkan permainan?"<<endl;
            cout << "y atau n?"<<endl;
            char yn2;
            cin >> yn2;
            while(yn2 != 'y' && yn2 != 'n'){
                cout << "Input tidak valid. Input lagi!"<<endl;
                cin >> yn2;
            }
            if(yn2 == 'n'){
                cout << "Sip. Terima kasih sudah bermain, ya!";
            }
}
