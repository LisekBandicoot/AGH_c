#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(){

    while(true){
        fstream fs;
        fs.open("products.txt", ios::in);
        string products[5];
        int amounts[5];
        float prices[5];
        int product_nr, amount;

        // put in the money
        cout << "\nType in the amount of money you want to put in: \n";
        float money = 0;
        int coin_values[6];
        cout << "give a number of coins for \n5zl, 2zl, 1zl, 0.5zl, 0.2zl, 0.1zl respectively\nand press enter after each entry\n";
        for (int i=0;i<6;i++){
            cin >> coin_values[i];
        }

        money = 5*coin_values[0]+2*coin_values[1]+coin_values[2]+0.5*coin_values[3]+0.2*coin_values[4]+0.1*coin_values[5];
        float* ptr;
        ptr = &money;

        // read the list of products
        for(int i=0; i<5; i++){
            fs >> products[i];
            fs >> amounts[i];
            fs >> prices[i];
        }

        // replenish the item if needed
        string empty;
        fs >> empty;
        if(empty == "cocacola"){amounts[0]=10;}else
        if(empty == "water"){amounts[1]=10;}else
        if(empty == "kitkat"){amounts[2]=10;}else
        if(empty == "bounty"){amounts[3]=10;}else
        if(empty == "mars"){amounts[4]=10;};

        fs.close();


        cout << "\nWhat would you like to buy?" << endl;
        // display items to the console
        for (int i=0;i<5;i++){
            cout << i+1 << "." << products[i] <<endl<< " available amount: ";
            cout << amounts[i] << " cost: ";
            cout << prices[i] << " PLN" << endl;
        }

        // get the product number and its amount from the user
        cout << "\nPick a number: ";
        cin >> product_nr;
        cout << "\nGive the amount: ";
        cin >> amount;
        cout << endl;

        // check availibility and substract the number of products
        if(amounts[product_nr-1] >= amount){
            amounts[product_nr-1] -= amount;
        }else{
            cout << "\nNot enough items\n";
        }

        // display the updated list
        for (int i=0;i<5;i++){
            cout << i+1 << "." << products[i] <<endl<< " available amount: ";
            cout << amounts[i] << " cost: ";
            cout << prices[i] << " PLN" << endl;
        }


        // read the cash register file
        fs.open("cash.txt", ios::in);
        float coins[7];
        float coins2[7];

        for(int i=0; i<7;i++){
            fs >> coins[i];
            coins2[i]=coins[i];
        }

        fs.close();


        // the vending machine loses the coins from the rest
        coins[0] = coins[0] + (amount * prices[product_nr-1]);
        cout << endl;
        // substract product cost from money put in, ptr becomes the rest
        *ptr = *ptr - (amount * prices[product_nr-1]);

        //add the input coins to the machine
        for (int i=0; i<7;i++){
            coins[i+1] += coin_values[i];
        }
        //calculate how much coins it lost in giving the rest
        while (*ptr >= 5){
            *ptr -= 5;
            coins[1] -= 1;
        }
        while (*ptr >= 2){
            *ptr -= 2;
            coins[2] -= 1;
        }
        while (*ptr >= 1){
            *ptr -= 1;
            coins[3] -= 1;
        }
        while (*ptr >= 0.5){
            *ptr -= 0.5;
            coins[4] -= 1;
        }
        while (*ptr >= 0.2){
            *ptr -= 0.2;
            coins[5] -= 1;
        }
        while (*ptr >= 0.1){
            *ptr -= 0.1;
            coins[6] -= 1;
        }


        //write updated money list to the file
        fs.open("cash.txt", ios::trunc | ios::out);
        cout << "your rest is: ";

        for(int i=0; i<7; i++){
            fs << coins[i] << endl;
            if(i!=0){cout << coin_values[i-1]-coins[i]+coins2[i] << " ";};
        }
        cout << "of " << endl << " 5zl, 2zl, 1zl, 0.5zl, 0.2zl, 0.1zl";
        fs.close();


        // write the updated list of products
        fs.open("products.txt", ios::trunc | ios::out);

        for(int i=0; i<5; i++){
            fs << products[i] << " ";
            fs << amounts[i] << " ";
            fs << prices[i] << endl;
        }

        //add the replenish note
        if (amounts[product_nr-1] == 0){
            fs << products[product_nr-1] << " is empty";
        }
        fs.close();

        // ask if the program should run again
        cout << endl << "Do you want to buy another item?\n press Y/N" << endl;
        char another_one;
        cin >> another_one;
        if (another_one == 'X'){
            cout << "\nYou're now in cash editing mode\nhere's the current status of the 5zl, 2zl, 1zl, 0.5zl, 0.2zl, 0.1zl coins inside\n";
            fs.open("cash.txt",  ios::in);
            for(int i=1; i<7; i++){
                fs >> coins[i];
                cout << coins[i] << " ";
            };
            cout << "\ntype the new amounts of coins: \n";
            for(int i=1; i<7; i++){
                cin >> coins[i];
            };
            coins[0] = 5*coins[1]+2*coins[2]+1*coins[3]+0.5*coins[4]+0.2*coins[5]+0.1*coins[6];
            fs.close();
            fs.open("cash.txt", ios::trunc | ios::out);
            for(int i=0; i<7; i++){
                fs << coins[i] << endl;
            };
            cout << "ok, updated\n\n";
            fs.close();
            break;
        }else if (another_one != 'Y'){
             break;
        };
    };
}
