#include<bits/stdc++.h>
#include "validator.cpp"
#include "olahInput.cpp"
#include "mathInput.cpp"
using namespace std;


int n;

void menu24(){
        cout << "Menu :"<<endl;
        cout << "1. Input 4 kartu"<<endl;
        cout << "2. Generate 4 kartu secara random\n"<<endl;
        cout << "3. Keluar"<<endl;
}

int main(){
    while(true){
        cout << "24 Game"<<endl;
        cout << "Menu :"<<endl;
        cout << "1. Input 4 kartu"<<endl;
        cout << "2. Generate 4 kartu secara random"<<endl;
        cout << "3. Keluar"<<endl;
        cout << "Masukkan pilihan :"<<" " ;
        cin>> n;


        while(!inputMenuValidator(n)){
            cout << "Input tidak valid. Masukkan lagi sesuai menu!"<<endl;
            cin>> n;
        }

        if (n==1 || n==2){
            if (n==1){
                cout << "Input 4 kartu ya!"<<  endl ;
                string c1,c2,c3,c4 ;
                cin>> c1>>c2>>c3>>c4 ;
                while (!validInp(c1)||!validInp(c2)||!validInp(c3)||!validInp(c4)){
                    cout<< "Masukan unvalid. Silakan input lagi!" ;
                    cin>> c1>>c2>>c3>>c4 ;
                }
                kartu[1] == strInt(c1); kartu[2] == strInt(c2); kartu[3] == strInt(c3); kartu[4] == strInt(c4);
            }
            else {
                int i;
                cout << "4 kartu terpilih : " << endl ;
                for (i=0; i<=3; i++){
                    kartu[i] = rand() % 13+1 ;
                }
                
                for (i=0; i<=3; i++){
                    intkartu(kartu[i]);
                    cout << kartu[i];
                }
                cout << endl; 
            }

            int totalSolusi = 0;
            string hasilOpr[99999] = {} ;
            sort(kartu, kartu+4);
            
            auto start = chrono::steady_clock::now();
            tampungHasil24();
        
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

            if (totalSolusi == 0){
                cout<< "Solusi nihil" ;
            }
            else{
                cout << "Banyak Solusi = "<<" "<< totalSolusi << endl;
                cout << "Solusi : " <<endl ;
                for (i = 1 ; i = totalSolusi; i++){
                    cout << hasilOpr[i]<< endl ;
                }
                cout << "Waktu penyelesaian = " <<  duration.count() << " " << endl ;
            }   
            
            cout << "Apakah anda ingin menyimpan hasil pencarian ke dalam file? (y/n) ";
            char c;
            cin >> c;
            while(c != 'y' and c != 'n'){
                cout << "Input tidak valid\n";
                cout << "Apakah anda ingin menyimpan hasil pencarian ke dalam file? (y/n) ";
                cin >> c;
            }
            if(c == 'y'){
                ofstream file;
                string namafile;
                cout << "Masukkan nama file: ";
                cin >> namafile;
                namafile = "../test/" + namafile + ".txt";
                file.open(namafile);
                file << "Kartu yang terpilih :";
                for(int i=0; i<4; i++){
                    if(kartu[i] == 1){
                        file << " A";
                    }
                    else if(kartu[i] == 11){
                        file << " J";
                    }
                    else if(kartu[i] == 12){
                        file << " Q";
                    }
                    else if(kartu[i] == 13){
                        file << " K";
                    }
                    else{
                        file << " " << kartu[i];
                    }
                }
                file << "\n";
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
                file << "Waktu penyelesaian = " <<  duration.count() << " " << endl ;
                file.close();
            }
            else{
                cout << "Hasil pencarian tidak disimpan\n";
            }
            cout << "Apakah anda ingin melanjutkan permainan? (y/n) ";
            char c2;
            cin >> c2;
            while(c2 != 'y' and c2 != 'n'){
                cout << "Input tidak valid\n";
                cout << "Apakah anda ingin melanjutkan permainan? (y/n) ";
                cin >> c2;
            }
            if(c2 == 'n'){
                cout << "Sip. Terima kasih sudah bermain, ya!";
                return 0;
            }
        }
        else if(n == 3){
            cout << "Terima kasih telah bermain\n";
        }
    }
    return 0;
}
    

        


