#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;


int main() {
    std::ofstream myfile;

    vector<int> numberList(0);
    int newRandomNumber;

    myfile.open("seedTime.csv");

    while(numberList.size() <= 9999){

        auto start = high_resolution_clock::now();

        for(int i = 0; i<10; i++){
            newRandomNumber = rand() %100;
            numberList.push_back(newRandomNumber);

            cout << "Numbers is now a list of size " << numberList.size() << endl;


        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);

        cout << "Time to Generate, Seed, and Print Numbers : " << duration.count() << " microseconds" << endl;

        myfile << duration.count() << ",\n";
    }
    myfile.close();
}
