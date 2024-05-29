#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;
int main(){
    string inputFile, outputFile;
    cout << "Input file name: ";
    getline(cin, inputFile);
    cout << "Output file name: ";
    getline(cin, outputFile);

    int totalPages;
    cout << "how many pages? ";
    cin >> totalPages;
    cout << endl;

    const int actualTotalPages = totalPages;

    if(totalPages % 4 != 0){
        totalPages = totalPages - totalPages % 4 + 4;
        cout << "correcting to " << totalPages << endl;
    }

//    for(int i = 1; i <= totalPages/2; i+=2){
//        cout << totalPages - i + 1 << ", " << i;
//        cout << " then " << i+1 << " " << totalPages - i;
//        cout << endl;
//    }

    int bundleSize = 20;
	string bundleSizeInput;
    cout << "bundle size? ";
    cin >> bundleSizeInput;
	bundleSize = atoi(bundleSizeInput.c_str());
	if(bundleSize % 4 != 0 || bundleSize <= 0 || bundleSize > totalPages+4){
		cout<< "Error: Bad bundle size, defaulting to 20.\n\tBundle sizes MUST be multiples of 4 and not too large for a book." << endl;
		bundleSize = 20;
	}
    cout << endl;
//    int bundleCount = totalPages/bundleSize;
//    if(bundleCount*bundleSize != totalPages){
//        bundleCount++;
//    }
    stringstream ss;
    ss << "pdftk " << inputFile << " cat ";
    for(int j = 0; j < totalPages; j += bundleSize){
        if( (totalPages-j) < bundleSize){
            bundleSize = 4;
        }
        for(int i = 1; i <= bundleSize/2; i+=2){
            int page1 = (j+bundleSize) - (i)+1;
            int page2 = j+i;
            int page3 = j+i+1;
            int page4 = j+bundleSize - i;
//            if(anypageisblank) { (appropriatelyinsertblankpage) }
            ss << page1 << " " << page2 << " ";
            ss << page3 << " " << page4 << " ";
//            ss << (j+bundleSize) - (i) + 1 << " " << j+(i);
//            ss << " " << j+(i)+1 << " " << (j+bundleSize) - (i) << " ";
//            ss << endl;

//            cout << (j+bundleSize) - (i) + 1 << ", " << j+(i);
//            cout << " then " << j+(i)+1 << " " << (j+bundleSize) - (i);
//            cout << endl;
        }
    }
    ss << " output " << outputFile << "\n";
    std::cout << "Would you like to automatically run the command? [Y/n]   ";
    char yn;
    std::cin >> yn;
    if(tolower(yn) == 'y'){
        system(ss.str().c_str());
    }else{
        std::cout << ss.str();
    }
}
