#include<bits/stdc++.h>
using namespace std;

bool inputMenuValidator(int n){
    return (n==1||n==2||n==3);
}

bool validInp (string typing){
    
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



