/*****************************************************************
 *
 *  Author:           Sudhir Ray
 *  Email:            raysudhir30@gmail.com
 *  Label:            P03
 *  Title:            Graphiz
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *             This program creates a linked list. It can accept new nodes. The
 *  program outputs "DOT" language syntax. The syntax can be used in the Graphiz
 *  compiler to visualize the linked list. The nodes and edges attributes are
 *  based upon the data entered.
 *
 *
 *  Usage:
 *       N/A
 *
 *  Files:
 *       main.cpp    : driver program
 *       dll.hpp     : header file for double linked list
 *       ll.hpp      : header file for linked list
 *       test.out    : output file with results
 *****************************************************************************/
// main.cpp

#include "dll.hpp"
#include "ll.hpp"
#include "bst.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() { // Create a new graph
  ListGraphiz list;
  Graphiz dll;
  BST B;

  ofstream file;
  file.open("test.out", ios_base::app);
  // writing name in the file
  file << "Sudhir Ray\n";
  file << "March 06, 2023\n";
  file << "Spring 2143\n";

  file << endl;

  file << "Linked List"<<endl;

  // Add nodes in linked List
  list.addNode("1");
  list.addNode("2");
  list.addNode("a");

  list.addNode("3");
  list.addNode("4");
  list.addNode("5");

  // Add edges in linked list
  list.addEdge(1, 2);
  list.addEdge(2, 3);
  list.addEdge(3, 4);
  list.addEdge(3, 5); // connects node with id 4 to node with id 5

  // Print the graph in Graphviz format
  list.print();
  list.printfile("test.out");

  file << endl;
  file << "Double Linked List"<<endl;
  dll.addNode("null");
  dll.addNode("1");
  dll.addNode("2");

  dll.addNode("3");
  dll.addNode("4");
  dll.addNode("5");
  dll.addNode("6");
  cout << endl;

  dll.print();
  dll.printfile("test.out");

  file << endl;
  file << "Binary Search Tree"<<endl;
    B.insert(20);        
    B.insert(22);        
    B.insert(33);
    B.insert(14);
    B.insert(55);
    B.insert(16);
    B.insert(7);
    B.insert(8);
    B.insert(9);
    B.print();

  file.close();
  return 0;
}
