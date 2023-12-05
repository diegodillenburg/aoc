#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool isNumeric(char c) {
  return isdigit(c); 
}

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    string line;
    string reversed_line;
    auto acc = 0;
    int aux;

    while (getline(file, line)) {
      for(char c : line) {
        if (isNumeric(c)) {
            aux = (atoi(&c) * 10);
            break;
        }
      }

      reverse(line.begin(), line.end());
    
      for(char c : line) {
        if (isNumeric(c)) {
            aux += atoi(&c);
            break;
        }
      }

      acc = acc + aux;
  }

  cout << "The result is: " << acc << endl;

  return 0;
}

