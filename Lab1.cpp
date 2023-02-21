#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string title;
  string heading;
  string column1;
  string column2;
  
  string data;
  string book;
  string number;
  // set up the variables
  vector<string> name;
  vector<int> num;
 int bring;

  cout << "Enter a title for the data:" << endl;
  getline(cin, heading);
  cout << "You entered: " << heading << endl;

  cout << "Enter the column 1 header:" << endl;
  getline(cin, column1);
  cout << "You entered: " << column1 << endl;

  cout << "Enter the column 2 header:" << endl;
  getline(cin, column2);
  cout << "You entered: " << column2 << endl;
//begin adding the data from the input to the strings
  bool start = true;
  //boolean is to make the data run
  while (start) {
    cout << "Enter a data point (-1 to stop input):" << endl;
    getline(cin, book);
   

    if (book.compare("-1") == 0) {
      start = false;
      //-1 is used to end the whie loop
    }
    // this check for any erros
    else if ((book.find(',')) == string::npos) {
      cout << "Error: No comma in string." << endl;
    } else if (count(book.begin(), book.end(), ',') > 1) {
      cout << "Error: Too many commas in input." << endl;
    } else {
      int delimitt = book.find(',');
      title = book.substr(0, delimitt);
      number = book.substr(delimitt + 2, book.back());
    try {
            bring = stoi(number);
            cout << "Data string: " << title << endl;
            cout << "Data integer: " << bring << endl;
            num.push_back(bring);
            name.push_back(title);
        } catch (const std::invalid_argument& e) {
      //this make sure to see if a comma added 
            cout << "Error: Comma not followed by an integer." << endl;
        }

    }
  }
  cout << endl;
  
  //this where the adding data ends.
  //and then we start setting up the data visualization
   cout << std::right<< setw(33) << heading << endl;
  cout << std::left << std::setw(20) << column1 << "|" << std::right <<
  std::setw(23)  << column2 << std::endl;
  std::cout << "--------------------------------------------" << std::endl;
  // where the charts begins 
  for(size_t i = 0; i < name.size(); i++){
  cout << std::left << std::setw(20) << name[i]
            << "|" << std::right << std::setw(23) << num[i] << std::endl;
    
  }
  cout << endl;
  
// This is for the star output
  for ( size_t i = 0; i < name.size(); i++){
    cout << std::right << setw(20) << name[i] << " "; 
    for(int j = 0; j < num[i]; j++){
        cout << "*" ;
    }
    cout << endl;
    
  }
 


  return 0;
}
