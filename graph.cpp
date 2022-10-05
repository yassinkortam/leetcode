#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
using namespace std;

int main() {
  
  //Our weighted DAG structure
  unordered_map <string, vector<pair<string, double>>> exchangeRates;
  
  //start and end nodes for our search
  string start;
  string target;
  
  //**********************READING START**********************
  string line;
  int lineNumber = 0;
  while (getline(cin, line)) {
    
    //this loop is to read the data and place it in the graph
    unsigned long int i = 0;
    while (i < line.length() && lineNumber == 0){
    
      string currency1 = "", currency2 = "", strRate = "";
      double rate;
    
      //reading the first currency
      while(line[i] != ',' && i < line.length()){
        currency1 += line[i];
        i++;
      }
      i++;
      
      //reading the second currency
      while(line[i] != ',' && i < line.length()){
        currency2 += line[i];
        i++;
      }
      i++;
      
      //reading the FX rate
      while(line[i] != ';' && i < line.length()){
        strRate += line[i];
        i++;
      }
      i++;
      
      //converting rate from string to double
      rate = stod(strRate);
        
      //populating the graph
      pair<string, double> exchangeRate;
      exchangeRate.first = currency2;
      exchangeRate.second = rate;
      if (exchangeRates.find(currency1) != exchangeRates.end()){
        exchangeRates[currency1].push_back(exchangeRate);
      }
      else{
        vector <pair<string, double>> exchanges;
        exchanges.push_back(exchangeRate);
        exchangeRates[currency1] = exchanges;
      }
    }
    
    //finding the start and target currencies
    if (lineNumber == 1) start = line;
    if (lineNumber == 2) target = line;
    lineNumber++;
  }
  
  //**********************IMPROVISED BFS SEARCH THROUGH A WEIGHTED DAG**********************
  //vector to store all the paths that lead to target
  vector <stack<pair<string, double>>> pathsToTarget;
  
  //queue to store the paths
  queue <stack<pair<string, double>>> paths;
  
  //stack to store the current path
  stack <pair<string, double>> path;
  
  //pair to store current exchange
  pair <string, double> currentExchange;
  
  double tempFX = 1;
  double maxFX = 1;
  
  //initializing variables
  currentExchange.first = start;
  currentExchange.second = 1;
  path.push(currentExchange);
  paths.push(path);
  
  //find all the paths that lead to target
  //save them in a vector
  while (!paths.empty()){
    path = paths.front();
    paths.pop();
    pair <string, double> last = path.top();
    
    //if the path ends with the target, save it
    if (last.first == target){
      pathsToTarget.push_back(path);
    }
    
    //visit each of the children of the last node in the path
    for (unsigned long int i = 0; i < exchangeRates[last.first].size(); i++){
      
       //finding new paths in the weighted DAG
       stack <pair<string, double>> newPath;
      
       //order of previous steps doesnt matter
       //while loop will reverse the old parts of the path
       while (!path.empty()){newPath.push(path.top()); path.pop();}
       
       newPath.push(exchangeRates[last.first].at(i));
       paths.push(newPath);
    }
  }
  
  //finding the highest FX rate aka longest path through the weighted DAG
  for (unsigned long int i = 0; i < pathsToTarget.size(); i++){
      
    //reset tempFX to 1
    tempFX = 1;
    
    //find the FX rate for each path
    while (!pathsToTarget[i].empty()){ 
      tempFX *= pathsToTarget[i].top().second;
      pathsToTarget[i].pop(); 
    }
 
    //update the maxFX rate
    maxFX = max(tempFX, maxFX);
  }
  
  //if there are no paths to the target, return -1.0
  if (!pathsToTarget.empty()) cout << maxFX;
  else cout << "-1.0";
    
  
}
