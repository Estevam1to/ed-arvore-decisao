/**
 * @authors Luis Estevam Rosa Chaves (536699), Gustavo Henrique Freitas de Sousa (535735)
 * @brief 
 * @date 2023-06-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

#include "binarytree.h"

using namespace std;

#define nl '\n'
#define TAB_CODE 9

vector<string> diseases, questions;
unordered_map<string, unordered_set<int>> diseasesCodes;

int lenDiseases, lenQuestions;

BinaryTree<int> * diseaseTree = new BinaryTree<int>(1);

void getDataFromFile() {
  ifstream file("in.txt");

  if (file.is_open()) {
      string line;
      getline(file, line);

      lenDiseases = stoi(line.substr(0, line.find(" ")));
      lenQuestions = stoi(line.substr(line.find(" ") + 1, line.size()));

      int itDiseases = 0, itQuestions = 0;

      if(file.is_open()) {
        while (getline(file, line)) {
          if (itDiseases < lenDiseases) {

            diseases.push_back(line);
            ++ itDiseases;

          } else if(itQuestions < lenQuestions) {

            questions.push_back(line);
            ++ itQuestions;

          } else {
            int firstTab = line.find(TAB_CODE);
            
            int keyOfDesease = stoi(line.substr(0, firstTab));
            
            string code = line.substr(firstTab + 1, line.size());
            string::iterator end_pos = remove(code.begin(), code.end(), TAB_CODE);
          
            code.erase(end_pos, code.end());
            
            diseasesCodes[code].insert(keyOfDesease);
          }
        }

        file.close();
      } else {
        cout << "Não foi possível abrir o arquivo informado!" << nl;
      }
    }
  }
  
  void buildDiseaseTree(){
    Node<int> *root = new Node<int>(1, nullptr, nullptr);
    
    Node<int> * left   = nullptr;
    Node<int> * right  = nullptr;

    queue<Node<int>  *> nodes;

    nodes.push(root);

    while(!nodes.empty()) {
      Node<int> * current = nodes.front(); 
      nodes.pop();
      
      if(current->getValue() == lenQuestions)continue;

      left  = new Node<int>(current->getValue() + 1, nullptr, nullptr);
      right = new Node<int>(current->getValue() + 1, nullptr, nullptr);

      current->setLeft(left);
      current->setRight(right);

      nodes.push(left);
      nodes.push(right);
    }
    
    diseaseTree->setRoot(root);
  }

  char doQuestion(Node<int> * root) {
    cout << "Pergunta: " << questions[root->getValue() - 1] << " (S/N)" << nl;

    char answer;
    cin >> answer;

    if(toupper(answer) == 'S') {
      return '1';
    } else {
      return '0';
    }
  }

  void searchDisease(Node<int> * root, string ans) {

    if(root->getLeft() == nullptr && root->getRight() == nullptr) {
      if(doQuestion(root) == '1') {
        ans[root->getValue() - 1] = '1';
        root = root->getLeft();
      } else {
        ans[root->getValue() - 1] = '0';
        root = root->getRight();
      }

      cout << "Resposta: " << ans << nl;
      
      unordered_set<int> diseasesKeys = diseasesCodes[ans];

      if(diseasesKeys.size()) {
        for(int i: diseasesKeys) {
          cout << "Doença: " << diseases[i - 1] << nl;
        }

        return;
      }

      cout << "Doença não identificada!" << nl;

      return;
    }

    if(doQuestion(root) == '1') {
      ans[root->getValue() - 1] = '1';
      root = root->getLeft();
    } else {
      ans[root->getValue() - 1] = '0';
      root = root->getRight();
    }

    return searchDisease(root, ans);
  }

  int main() {
    cin.tie(0)->sync_with_stdio(0);

    getDataFromFile();

    buildDiseaseTree();

    string ans = "";
    
    for(int i = 0; i < lenQuestions; ++ i) 
      ans += "0";

    searchDisease(diseaseTree->getRoot(), ans);

    return 0;
  }
