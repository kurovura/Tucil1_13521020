#include<bits/stdc++.h>
using namespace std;

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
