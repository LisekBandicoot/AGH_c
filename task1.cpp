#include <iostream>
using namespace std;
int cocacola = 5, water = 7, kitkat = 12, bounty = 6, mars = 9;
int machine(int pro, int amo);
int check(int pr,int am);

int main() {
    int product;
    int amount;
    do{
        cout << "What would you like to buy?\n  1.cocacola: " << cocacola <<
        "\n  2.water: " << water <<
        "\n  3.kitkat: " << kitkat <<
        "\n  4.bounty: " << bounty <<
        "\n  5.mars: " << mars << endl;

        cout << "Give a number: ";

        cin >> product;
        cout << "\nGive the amount: ";
        cin >> amount;

        if((check(product, amount)) == 1){
            machine(product, amount);
        }else if(product != 6){
            cout << "There are not enough items\n";
        };
    }while(product != 6);

    return 0;
}

int check(int pr, int am){
    int result;
    switch (pr){
        case 1: if(cocacola>=am){result = 1;};break;
        case 2: if(water>=am){result = 1;};break;
        case 3: if(kitkat>=am){result = 1;};break;
        case 4: if(bounty>=am){result = 1;};break;
        case 5: if(mars>=am){result = 1;};break;
        default: result = 0;
    }
    return result;
}

int machine(int pro,int amo){
    switch (pro){
        case 1: cocacola -= amo; break;
        case 2: water -= amo; break;
        case 3: kitkat -= amo; break;
        case 4: bounty -= amo; break;
        case 5: mars -= amo; break;
    }
    return 0;
}
