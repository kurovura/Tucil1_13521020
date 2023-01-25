#include "olahInput.cpp"
#include "mathTo24.cpp"
using namespace std;

int totalSolusi = 0;
string hasilOpr[99999] = {} ;
int i,j,k;
int kartu[4];

void posibilitiTo24(){
    for (i=0; i=3; i++){
                    for (j=0; j=3; j++){
                        for (k=0; k=3; k++){
                            string op1, op2, op3 ;
                            
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
