#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> read_input(const string& filename) {
  ifstream file(filename);
  string line;
  vector<vector<int>> lines;

  while (getline(file, line)) {
    istringstream iss(line);
    vector<int> numbers;
    int number;
    while (iss >> number) {
      numbers.push_back(number);
    }
    lines.push_back(numbers);
  }

  return lines;
}

bool is_safe(const vector<int>& report) {
  bool all_inc = true;
  bool all_dec = true;

  for (size_t i = 1; i < report.size(); ++i) {
    if (report[i] - report[i - 1] < 1 || report[i] - report[i - 1] > 3) {
      all_inc = false;
    }
    if (report[i] - report[i - 1] < -3 || report[i] - report[i - 1] > -1) {
      all_dec = false;
    }
  }

  return all_inc || all_dec;
}

int count_safe(const vector<vector<int>>& reports) {
  int num = 0;
  for (const auto& report : reports) {
    if (is_safe(report)) {
      ++num;
    }
  }
  return num;
}

bool can_be_safe(const vector<int>& report) {
  for (size_t i = 0; i < report.size(); ++i) {
    vector<int> new_rep(report.begin(), report.end());
    new_rep.erase(new_rep.begin() + i);
    if (is_safe(new_rep)) {
      return true;
    }
  }
  return false;
}

int count_safe_new(const vector<vector<int>>& reports) {
  int num = 0;
  for (const auto& report : reports) {
    if (is_safe(report) || can_be_safe(report)) {
      ++num;
    }
  }
  return num;
}

int main() {
  string input_file_path = "input.txt";
  vector<vector<int>> lines = read_input(input_file_path);

  // For part 1:
  cout << count_safe(lines) << endl;

  // For part 2:
  cout << count_safe_new(lines) << endl;

  return 0;
}