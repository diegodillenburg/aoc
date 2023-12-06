#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map>

using namespace std;

int extractDigits(string line) {
  int aux = 0;
  
  for(char c : line) {
    if (isdigit(c)) {
        aux = (atoi(&c) * 10);
        break;
    }
  }

  reverse(line.begin(), line.end());

  for(char c : line) {
    if (isdigit(c)) {
        aux += atoi(&c);
        break;
    }
  }
  
  return aux;
}

bool match(string term, char* head) {
    char* c = &term[0];

    if (*head != *c) {
        return false;
    }

    c++;
    head++;

    while (*c != '\0') {
        if (*head != *c) {
            head--;

            return false;
        }

        head++;
        c++;
    }

    head--;

    return true;
}

string mapLineToDigits(string input) {
    string output = "";
    char *head = &input[0];

    unordered_map<string, int> numbers = {
        { "one", 1 },
        { "two", 2 },
        { "three", 3 },
        { "four", 4 },
        { "five", 5 },
        { "six", 6 },
        { "seven", 7 },
        { "eight", 8 },
        { "nine", 9 },
    };

    while (*head != '\0') {
        if (isdigit(*head)) {
            output += *head;
        } else {

            for (const auto& kv : numbers) {
                if (match(kv.first, head)) {
                    output += to_string(kv.second);
                }
            }

        }

        head++;
    }

    return output;
}

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    string line;
    auto acc = 0;

    while (getline(file, line)) {
        line = mapLineToDigits(line);
        acc += extractDigits(line);
    }

  cout << "The result is: " << acc << endl;

  return 0;
}
