#include <iostream>
#include <vector>

using namespace std;
struct bilietas{
    string vardas;
    string tipas;
    int eile = 0;
    int vieta = 0;
    int uzimta = 0;
    int tipoinfo = 0;
};

void eiles_info (bilietas vietos[3][3], bilietas b){
    int tempo;
    cout << "Iveskite eiles numeri(0,1,2): \n";
    cin >> tempo;
    for (b.vieta = 0; b.vieta < 3; ++b.vieta) {
        if (vietos[tempo][b.vieta].tipoinfo == 1)
            cout << "VIP "<< vietos[tempo][b.vieta].vardas <<" vieta "<< b.vieta<< endl;
            else if (vietos[tempo][b.vieta].tipoinfo == 2)
            cout << "Paprastas "<< vietos[tempo][b.vieta].vardas <<" vieta "<< b.vieta<< endl;
            else cout << "  Laisva vieta "<< b.vieta << endl;
    }
    cout<<endl;
}

void laisva_uzimta (bilietas vietos[3][3], bilietas b) {
    string temp;
    cout << "Iveskite bilieto tipa 'vip' ar 'paprastas'\n";
    cin >> temp;
if (temp == "vip"){
    for (b.eile = 0; b.eile < 3; ++b.eile)
        for (b.vieta = 0; b.vieta < 3; ++b.vieta) {
            if (vietos[b.eile][b.vieta].uzimta == 1 && vietos[b.eile][b.vieta].tipoinfo == 1)
                cout << "VIP nario vieta " << b.eile << " " << b.vieta << endl;
        }
    }
if (temp == "paprastas"){
    for (b.eile = 0; b.eile < 3; ++b.eile)
        for (b.vieta = 0; b.vieta < 3; ++b.vieta)
            if (vietos[b.eile][b.vieta].uzimta == 1 && vietos[b.eile][b.vieta].tipoinfo == 2)
                cout << "Paprasto nario vieta " << b.eile << " " << b.vieta << endl;
    }
}

 void bilieto_pirkimas (bilietas vietos[3][3], bilietas &b) {

     cout << "Iveskite eile: ";
     cin >> b.eile;
     cout << "Iveskite vieta: ";
     cin >> b.vieta;

         if (vietos[b.eile][b.vieta].uzimta == 0) {

             cout << "Vardas pavarde: ";
             cin >> vietos[b.eile][b.vieta].vardas;

             cout << "Koki bielieto tipa norite ieskoti 'vip' arba 'paprastas': ";
             cin >> vietos[b.eile][b.vieta].tipas;

             if(vietos[b.eile][b.vieta].tipas == "vip")
                 vietos[b.eile][b.vieta].tipoinfo = 1;

             else  vietos[b.eile][b.vieta].tipoinfo = 2;

             vietos[b.eile][b.vieta].uzimta = 1;

         }
         else cout << "Vieta uzimta pasirinkite kita laisva vieta\n";
}

void vietos_informacija (bilietas vietos[3][3], bilietas b){
    cout << "Iveskite eile ir vietos numeri ";
    cin >> b.eile >> b.vieta;
    if (vietos[b.eile][b.vieta].uzimta == 1)
         cout << vietos[b.eile][b.vieta].vardas << " " << vietos[b.eile][b.vieta].tipas<<endl;
    else cout << "Vieta tuscia\n";

 }
    int main() {
    bilietas b;
    bilietas vietos [3][3] = {
            {b, b, b},
            {b, b, b},
            {b, b, b}
    };

        int input = 1;
        while (input != 0) {
            cout << "--------------------MENIU-----------------------\n";
            cout << "1. Bilieto registracija\n";
            cout << "2. Pavaizduoti vietas pagal tipa\n";
            cout << "3. Pavaizduoti eiles informacija\n";
            cout << "4. Pavaizduoti vietos informacija\n";
            cout << "0. Baigti darba\n";
            cout << "------------------------------------------------\n";

            cin >> input;

            switch (input) {
                case 1:
                    bilieto_pirkimas(vietos,b);
                    break;
                case 2:
                    laisva_uzimta(vietos,b);
                    break;
                case 3:
                    eiles_info(vietos,b);
                    break;
                case 4:
                    vietos_informacija(vietos,b);
                    break;
                case 0:
                    cout << "ISEITI IS PROGRAMOS";
                    break;
                default:
                    cout << "BLOGAS IVEDIMAS\n";
                    break;
            }
        }

        return 0;
    }