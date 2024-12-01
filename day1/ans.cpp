#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <map>

void printArray(int arr[], int size, std::ofstream &outfile) {
  for (int i = 0; i < size; i++) {
    outfile << arr[i] << " ";
  }
  outfile << std::endl;
}
//Part-1
void calculateDistance(int arr1[],int arr2[],int size, std::ofstream &outfile){
  int sum = 0;
  for(int i = 0;i<size;i++){
    sum+=std::abs(arr1[i]-arr2[i]);

  }
  outfile<<"Distance: " << sum<<" "<< std::endl;
}
//Part-2
void calculateSimilarity(int arr1[],int arr2[],int size, std::ofstream &outfile){
  std::map<int, int> similarityMap;
  for (int i = 0; i < size; i++) {
    similarityMap[arr1[i]] = 0;
  }
  for (int i = 0; i < size; i++) {
    if (similarityMap.find(arr2[i]) != similarityMap.end()) {
      ++similarityMap[arr2[i]];
    }
  }
  int sum = 0;
  for (const auto &pair : similarityMap) {
    sum+=pair.first*pair.second;
  }
      outfile<< "Sum: "<<sum<<" "<< std::endl;
}
int main() {
  std::ifstream infile("input.txt");
  std::ofstream outfile("output.txt");

  if (!infile || !outfile) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }

  const int size = 1000;
  int arr1[size], arr2[size];

  for (int i = 0; i < size; i++) {
    infile >> arr1[i] >> arr2[i];
  }
  std::sort(arr1, arr1 + size);
  std::sort(arr2, arr2 + size);

  calculateDistance(arr1,arr2,size,outfile);
  calculateSimilarity(arr1,arr2,size,outfile);


  infile.close();
  outfile.close();

  return 0;
}