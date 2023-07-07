#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#include "binarytree.h"

using namespace std;

#define nl '\n'

vector<string> diseases, questions;
map<string, int> diseasesCodes;

int lenDiseases, lenQuestions;

BinaryTree<int> * diseaseTree;

// get data from file and set to vector the diseases and in map the code of diseases:
void getDataFromFile() {
  ifstream file("in.txt");

  if (file.is_open()) {
      // get first line from file:
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
            int firstTab = line.find(9);
            cout <<  line.substr(0, firstTab) << endl;
            int keyOfDesease = stoi(line.substr(0, firstTab));
            
            string code = line.substr(firstTab + 1, line.size());
            string::iterator end_pos = remove(code.begin(), code.end(), 9);
          
            code.erase(end_pos, code.end());
            
            cout << code << nl;
            //  set key of desease to deseasesCodes map:
            diseasesCodes[code] = keyOfDesease;
          }
        }

        file.close();
      } else {
        cout << "Não foi possível abrir o arquivo informado!" << nl;
      }
    }
  }

  BinaryTree<int> * buildDiseaseTree(int node, int left, int right) {
    if(node > lenDiseases) 
      return nullptr;

    int middle = (left + right) / 2;

    BinaryTree<int> &leftTree = (*buildDiseaseTree(node * 2, left, middle));
    BinaryTree<int> &rightTree = (*buildDiseaseTree(node * 2 + 1, middle + 1, right));

    BinaryTree<int> * tree = new BinaryTree<int>(node, leftTree, rightTree);

    return tree;
  }

  int main() {

    getDataFromFile();

    diseaseTree = new BinaryTree<int>();

    diseaseTree = buildDiseaseTree(1, 0, lenDiseases - 1);

    // while(!diseaseTree->is_empty()) {
    //   Node<int> * node = diseaseTree->getRoot();

    //   if(node->getLeft() == nullptr && node->getRight() == nullptr) {
    //     cout << "Doença encontrada: " << diseases[node->getValue() - 1] << nl;
    //     break;
    //   }

    //   cout << "Pergunta: " << diseases[node->getValue() - 1] << " (S/N)" << nl;

    //   string answer;
    //   cin >> answer;

    //   if(answer == "S") {
    //     diseaseTree->setRoot(node->getLeft());
    //   } else {
    //     diseaseTree->setRoot(node->getRight());
    //   }
    // }

    return 0;
  }
