#include <iostream>
#include <fstream> 
#include "minify.h"


using namespace std ; 

int main (){
    ifstream ifile ("ex.xml") ;
    ofstream ofile ("result.xml") ;
    while(! (ifile.is_open()))
    {
        cout << "file not found" <<endl ; 
        string name ; 
        cin >> name ; 
        ifile.open(name) ;
    }
    minify (ifile,"result.xml") ; 

    return 0 ; 
}
/* Team members : 
- Youssef Walid Abdelmoez 2101063
- Yahia Abdalah Saber 2101086
- Adham Nasreldin Mahmoud 2101137
- Khaled Mohamed Mohamed Ali 2100689
- Mahmoud Mostafa Mahmoud 2100403
- ⁠ahmed mohamed ahmed 2100299
- ⁠mariam ahmed mohamed 2100433
*/