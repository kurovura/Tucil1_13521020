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
                cout << "Masukkan 4 kartu ! "<<endl;
                cin >> c1 >> c2 >> c3 >> c4;
                if(!validInp(c1) || !validInp(c2) || !validInp(c3) || !validInp(c4)){
                    cout << "Input tidak valid, masukkan lagi!"<< endl ;
                    cin >> c1 >> c2 >> c3 >> c4;
                }
                else{
                    kartu[0] = strInt(c1);kartu[1] = strInt(c2);kartu[2] = strInt(c3);kartu[3] = strInt(c4);
                    jikaInputValid();
                }
            }
            else {
                for(int i=0; i<4; i++){
                    kartu[i] = rand() % 13 + 1;
                }
                cout << "Kartu yang terpilih :";
                for(int i=0; i<4; i++){
                    cout<< intkartu(kartu[i]);
                }
                cout << endl;   
                jikaInputValid();
            }
        }   
        else if(n == 3){
            cout << "Sip!";
        }
        return 0;
    }
}
