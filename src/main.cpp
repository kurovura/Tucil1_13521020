#include<bits/stdc++.h>
#include <chrono>
using namespace std;


int n,i,j,k ;
int kartu[4];
string c1,c2,c3,c4, op1, op2, op3;
int totalSolusi = 0;
string hasilOpr[99999] = {} ;
char yn,yn2;

int strInt (string str){
    int nilai ;
    if (str == "A"){
        nilai = 1;
    } else if (str == "2") {
        nilai = 2;
    } else if (str == "3") {
        nilai = 3;
    } else if (str == "4") {
        nilai = 4;
    } else if (str == "5"){
        nilai = 5;
    } else if (str == "6") {
        nilai = 6;
    } else if (str == "7") {
        nilai = 7;
    } else if (str == "8") {
        nilai = 8;
    } else if (str == "9"){
        nilai = 9;
    } else if (str == "10") {
        nilai  = 10;
    } else if (str == "J") {
        nilai = 11;
    } else if (str == "Q") {
        nilai = 12;
    }else if (str == "K"){
        nilai = 13;
    }
    return nilai;
}

string intkartu(double nilai){
    string remi;
    if (nilai == 1){
        remi == "A" ;
    }
    else if (nilai == 2){
        remi == "2" ;
    }
    else if (nilai == 3){
        remi == "3" ;
    }
    else if (nilai == 4){
        remi == "4" ;
    }
    else if (nilai ==  5){
        remi == "5" ;
    }
    else if (nilai == 6){
        remi == "6" ;
    }
    else if (nilai == 7){
        remi == "7" ;
    }
    else if (nilai == 8){
        remi == "8" ;
    }
    else if (nilai == 9){
        remi == "9" ;
    }
    else if (nilai == 10){
        remi == "10" ;
    }
    else if (nilai == 11){
        remi == "J" ;
    }
    else if (nilai == 12){
        remi == "Q" ;
    }
    else if (nilai == 13){
        remi == "K" ;
    }
    return remi ;
}

void intTandaStr(int angkaTanda, string *simbol){
    if(angkaTanda == 0) {*simbol = "+" ;}
    else if(angkaTanda == 1) {*simbol = "-" ;}
    else if(angkaTanda == 2) {*simbol = "*"; }
    else if(angkaTanda == 3) {*simbol = "/"; }
}


double perhitungan (int a, int b, int tanda){
    int hasil;
    switch (tanda){
        case 0 :
            hasil = a+b ;
        case 1 :
            hasil = a-b ;
        case 2 :
            hasil = a*b ;
        case 3 : 
            if (b!=0){
                hasil =  a/b ;
            } 
            else{ //b=0
                hasil = 999999999;
            }
    }
    return hasil;
}

void posibilitiTo24(){
    for (i=0; i=3; i++){
                    for (j=0; j=3; j++){
                        for (k=0; k=3; k++){
                            string op1, op2, op3 ;
                            intTandaStr(i, &op1);  intTandaStr(j, &op2);  intTandaStr(k, &op3);
                            
                            // ((ab)c)d
                            if (kalkulasi1( kartu, i,  j, k)== 24){
                                totalSolusi ++ ;
                                hasilOpr[totalSolusi] = "((" + intkartu(kartu[0]) + " " + op1 + " " + intkartu(kartu[1]) + ") " + op2 + " " + intkartu(kartu[2]) + ") " + op3 + " " + intkartu(kartu[3]);
                            }
                            // (ab)(cd)
                            if (kalkulasi2( kartu, i,  j, k)== 24){
                                totalSolusi ++ ;
                                hasilOpr[totalSolusi] = "(" + intkartu(kartu[0]) + " " + op1 + " " + intkartu(kartu[1]) + ") " + op2 + " (" + intkartu(kartu[2]) + " " + op3 + " " + intkartu(kartu[3]) + ")";
                            }
                            // (a(bc))d
                            if (kalkulasi3( kartu, i,  j, k)== 24){
                                totalSolusi ++ ;
                                hasilOpr[totalSolusi] =   "(" + intkartu(kartu[0]) + " " + op1 + " (" + intkartu(kartu[1]) + " " + op2 + " " + intkartu(kartu[2]) + ")) " + op3 + " " + intkartu(kartu[3]) ;
                            }
                            // a((bc)d)
                            if (kalkulasi4( kartu, i,  j, k)== 24){
                                totalSolusi ++ ;
                                hasilOpr[totalSolusi] = intkartu(kartu[0]) + " " + op1 + " ((" + intkartu(kartu[1]) + " " + op2 + " " + intkartu(kartu[2]) + ") " + op3 + " " + intkartu(kartu[3]) + ")" ;
                            }
                            // a(b(cd))
                            if (kalkulasi5( kartu, i,  j, k)== 24){
                                totalSolusi ++ ;
                                hasilOpr[totalSolusi] = intkartu(kartu[0]) + " " + op1 + " " + "(" + intkartu(kartu[1]) + " " + op2 + " " + "("+ intkartu(kartu[2]) + " " + op2 + " " + intkartu(kartu[3]) + "))" ;
                            }
                        }
                    }
    }
}
   
// ((ab)c)d
double kalkulasi1 (int input[4], int op1, int op2, int op3){
    double hasil ;
    hasil = perhitungan(input[0], input[1], op1) ;
    hasil = perhitungan(hasil, input[2], op2) ;
    hasil = perhitungan(hasil, input[3], op3) ;
    return hasil;
}

// (ab)(cd)
double kalkulasi2 (int input[4], int op1, int op2, int op3){
    double hasil1, hasil2, hasil ;
    hasil1 = perhitungan(input[0], input[1], op1) ;
    hasil2 = perhitungan(input[2], input[3], op3) ;
    hasil = perhitungan(hasil1, hasil2, op2) ;
    return hasil;
}

// (a(bc))d
double kalkulasi3 (int input[4], int op1, int op2, int op3){
    double hasil ;
    hasil = perhitungan(input[1], input[2], op2) ;
    hasil  = perhitungan(input[0], hasil, op1) ;
    hasil = perhitungan(hasil, input[3], op3) ;
    return hasil;
}

// a((bc)d)
double kalkulasi4 (int input[4], int op1, int op2, int op3){
    double hasil ;
    hasil = perhitungan(input[1], input[2], op2) ;
    hasil = perhitungan(hasil, input[3], op3) ;
    hasil = perhitungan(input[0], hasil, op1) ;
    return hasil;
}

// a(b(cd))
double kalkulasi5 (int input[4], int op1, int op2, int op3){
    double hasil ;
    hasil = perhitungan(input[2], input[3], op3) ;
    hasil = perhitungan(input[1], hasil, op2) ;
    hasil = perhitungan(input[0], hasil, op1) ;
    return hasil;
}

bool inputMenuValidator(int n){
    return (n==1||n==2||n==3);
}

int validInp (string typing){
    
    if (typing.length() == 1 ){
        return (typing[0] == 'A' ||typing[0] == '2'||typing[0] == '3'||typing[0] == '4'||typing[0] == '5'||typing[0] == '6'||typing[0] == '7'||typing[0] == '8'||typing[0] == '9'||typing[0] == 'J'||typing[0] == 'Q'||typing[0] == 'K');
    }
    else if (typing.length()== 2){
        return (typing[0]=='1' && typing[1]== '0');
    }
    else{
        return false;
    }
}

void menu24(){
        cout << "Menu :"<<endl;
        cout << "1. Input 4 kartu"<<endl;
        cout << "2. Generate 4 kartu secara random\n"<<endl;
        cout << "3. Keluar"<<endl;
}



int main(){
    while(true){
        cout << "24 Game"<<endl;
        menu24();
        cout << "Masukkan pilihan :"<<" " ;
        cin>> n;

        while(!inputMenuValidator(n)){
            cout << "Input tidak valid. Masukkan lagi sesuai menu!"<<endl;
            cin>> n;
        }

        if(n==1 or n==2){
            if(n==1){
                cout << "Masukkan 4 kartu ! ";
                cin >> c1 >> c2 >> c3 >> c4;
                while(!validInp(c1) || !validInp(c2) || !validInp(c3) || !validInp(c4)){
                    cout << "Input tidak valid, masukkan lagi!"<< endl ;
                    cin >> c1 >> c2 >> c3 >> c4;
                }
                kartu[0] = strInt(c1);kartu[1] = strInt(c2);kartu[2] = strInt(c3);kartu[3] = strInt(c4);
            }
            else {
                for(int i=0; i<4; i++){
                    kartu[i] = rand() % 13 + 1;
                }
                cout << "Kartu yang terpilih :";
                for(int i=0; i<4; i++){
                    cout<< intkartu(kartu[i]);
                }
                cout << endl;   }   
            
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
            cin >> yn2;
            while(yn2 != 'y' && yn2 != 'n'){
                cout << "Input tidak valid. Input lagi!"<<endl;
                cin >> yn2;
            }
            if (yn=='y'){
                main();
            }
            if(yn2 == 'n'){
                cout << "Sip. Terima kasih sudah bermain, ya!";
            }
        }
    
        else if(n == 3){
            cout << "Sip!";
        }

        return 0;
    }
}



        


