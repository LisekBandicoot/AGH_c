#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(){
    ifstream inFile;
    inFile.open("products.txt", ios::in | ios::out);
    string products[5];
    int amounts[5];
    int product, amount;
    string readout;

    //check if the file loaded
    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    // read the list of products
    for(int i=0; i<5; i++){
        inFile >> products[i];
        inFile >> amounts[i];
    }

    // replenish the item
    string empty;
    inFile >> empty;
    if(empty == "cocacola"){amounts[0]=10;}else
    if(empty == "water"){amounts[1]=10;}else
    if(empty == "kitkat"){amounts[2]=10;}else
    if(empty == "bounty"){amounts[3]=10;}else
    if(empty == "mars"){amounts[4]=10;};

    inFile.close();

    cout << "\nWhat would you like to buy?" << endl;
    // display items
    for (int i=0;i<5;i++){
        cout << i+1 << "." << products[i] << " ";
        cout << amounts[i] << endl;
    }

    // get the product number and its amount
    cout << "\nPick a number: ";
    cin >> product;
    cout << "\nGive the amount: ";
    cin >> amount;
    cout << endl;

    // check availibility and substract the number of products
    if(amounts[product-1] >= amount){
        amounts[product-1] -= amount;
    }else{
        cout << "\nNot enough items\n";
    }

    // display the list
    for (int i=0;i<5;i++){
        cout << i+1 << "." << products[i] << " ";
        cout << amounts[i] << endl;
    }

    // write the updated list of products
    ofstream out("products.txt", ios::trunc | ios::out);

    for(int i=0; i<5; i++){
        out << products[i] << " ";
        out << amounts[i] << endl;
    }

    //add the replenish note
    if (amounts[product-1] == 0){
        out << products[product-1] << " is empty";
    }
    //inFile.close();
}
