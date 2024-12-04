#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int countXMAS(vector<vector<char>> lines, int i, int j) {
  int count = 0;
  // Horizontal Matching
  if (j <= (lines[0].size() - 3 - 1)) {
    if (lines[i][j] == 'X' && lines[i][j + 1] == 'M' && lines[i][j + 2] == 'A' && lines[i][j + 3] == 'S') {
      count++;
    }
  }
  // Horizontal Reverse
  if (j >=3) {
    if (lines[i][j] == 'X' && lines[i][j -1] == 'M' && lines[i][j - 2] == 'A' && lines[i][j - 3] == 'S') {
      count++;
    }
  }
// Vertical Upwards
  if (i >=3) {
    if (lines[i][j] == 'X' && lines[i-1][j] == 'M' && lines[i-2][j] == 'A' && lines[i-3][j] == 'S') {
      count++;
    }
  }
  // Vertical Downwards
  if (i <= (lines[0].size() - 3 - 1)) {
    if (lines[i][j] == 'X' && lines[i+1][j] == 'M' && lines[i+2][j] == 'A' && lines[i+3][j] == 'S') {
      count++;
    }
  }
// Diagonal upwards right
if (i >= 3 && j <= (lines[0].size() - 1 - 3)) {
  if (lines[i][j] == 'X' && lines[i-1][j+1] == 'M' && lines[i-2][j+2] == 'A' && lines[i-3][j+3] == 'S') {
    count++;
  }
}

// Diagonal upwards left
if (i >= 3 && j >= 3) {
  if (lines[i][j] == 'X' && lines[i-1][j-1] == 'M' && lines[i-2][j-2] == 'A' && lines[i-3][j-3] == 'S') {
    count++;
  }
}

// Diagonal downwards right
if (i <= (lines.size() - 1 - 3) && j <= (lines[0].size() - 1 - 3)) {
  if (lines[i][j] == 'X' && lines[i+1][j+1] == 'M' && lines[i+2][j+2] == 'A' && lines[i+3][j+3] == 'S') {
    count++;
  }
}

// Diagonal downwards left
if (i <= (lines.size() - 1 - 3) && j >= 3) {
  if (lines[i][j] == 'X' && lines[i+1][j-1] == 'M' && lines[i+2][j-2] == 'A' && lines[i+3][j-3] == 'S') {
    count++;
  }
}
 
  return count;
}

int countXMAS2(vector<vector<char>> lines, int i, int j) {
  int count = 0;
  if (j < 1 || j > lines[0].size() - 2) {
    return 0;
  }

  // M.M
  // .A.
  // S.S
  if (lines[i-1][j+1] == 'M' && lines[i-1][j-1] == 'M' && lines[i+1][j-1] == 'S' && lines[i+1][j+1] == 'S') {
    count++;
  }

  // S.S
  // .A.
  // M.M
  if (lines[i-1][j+1] == 'S' && lines[i-1][j-1] == 'S' && lines[i+1][j-1] == 'M' && lines[i+1][j+1] == 'M') {
    count++;
  }

  // M.S
  // .A.
  // M.S
  if (lines[i-1][j+1] == 'S' && lines[i-1][j-1] == 'M' && lines[i+1][j-1] == 'M' && lines[i+1][j+1] == 'S') {
    count++;
  }

  // S.M
  // .A.
  // S.M
  if (lines[i-1][j+1] == 'M' && lines[i-1][j-1] == 'S' && lines[i+1][j-1] == 'S' && lines[i+1][j+1] == 'M') {
    count++;
  }
  return count;

}
int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Unable to open file input.txt";
    return 1;
  }

  string line;
  vector<vector<char>> lines;

  while (getline(inputFile, line)) {
    vector<char> chars(line.begin(), line.end());
    lines.push_back(chars);
  }

  int count = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      
      if (lines[i][j] == 'X') {
        
        count += countXMAS(lines, i, j);
      }
    }
  }
  //Part 1
  cout << count << endl;
//Part 2
int count2 = 0;
  
  for (int i = 1; i < lines.size() - 1; i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      if (lines[i][j] == 'A') {
        count2 += countXMAS2(lines, i, j);
      }
    }
  }
    cout << count2 << endl;


  inputFile.close();
  return 0;
}
