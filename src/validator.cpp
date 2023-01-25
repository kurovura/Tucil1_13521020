using namespace std;

// bool menuValid(int n){
//     return (n==1||n==2||n==3);
// }
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

// vector<string> card ;

// bool validAmountInp(vector<string> card){
//     return (card.size()==4);
// }

// bool validRemiInput(vector<string> card){
//     int i, j ;
//     bool sesuaiRemi ;
//     string remiInput[13] = {'A','2','3','4','5','6','7','8','9','10','J','Q','K'} ;
//     for (i=0; i<card.size(); i++){
//         sesuaiRemi = false ;
//         for (j=0; j<13; j++){
//             if (card[i] == remiInput[j]){
//                 sesuaiRemi = true;
//             }
//         }
//     }
//     return sesuaiRemi; 
// }
