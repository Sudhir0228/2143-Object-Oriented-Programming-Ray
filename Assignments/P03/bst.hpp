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
 *             This program creates a linked list, double linked list and binary tree.
 *  It can accept new nodes. The program outputs "DOT" language syntax. The syntax can be used in the 
 *  Graphizcompiler to visualize the linked list. The nodes and edges attributes are
 *  sbased upon the data entered.
 * 
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

// bst.hpp

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string defaultbst = "  node [shape = record ,color = \"black\"  ]";

// array with 10 different colors
  string colors[10] = {"purple",
                       "red",
                       "blue",
                       "green",
                       "yellow",
                       "yellow:red",
                       "deeppink3:pink",
                       "darkgoldenrod3:gold",
                       "cornflowerblue:blue4",
                       "cyan"};

  // array with 10 different shapes for nodes
  string shapes[10] = {"box",  "polygon", "ellipse", "diamond", "triangle",
                       "star", "note",    "square",  "folder",  "tab"};


/**
 * Node
 *
 * Description:
 *      This struct provides the structure for a node in our binary searcj tree.
 *
 * Public Methods:
 *                          listNode()           
 *                          listNode(int d, int _id)
 *      void                Labels(ofstream& file) 
 *      void                Connections(ofstream& file)
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      N/A
 *
 */
struct listNode {
    int label;               
    int id;                 
    listNode *left;          
    listNode *right;     

    /**
     * Public : listNode
     * 
     * Description:
     *           Default constructor
     *      
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    listNode() {
        left = right = NULL;
    }

/**
     * Public : listNode
     * 
     * Description:
     *          Overidden constructor.
     * Params:
     *      int    :     data for the node
     *      int    :     id for the node
     * 
     * Returns:
     *      
     */

listNode(int data, int _id) {
        label = data;
        id = _id;
    }
/**
     * Public : Labels
     * 
     * Description:
     *          Prints and writes all the nodes with their specific id, data, shapes,
     *   and colors to the console as well as the file.
     *     
     * Params:
     *      ofstream &  : file to write all the things to
     * Returns:
     *      N/A
     */
    void Labels(ofstream &file) {
      
        cout <<"  "<< id <<" [label= "<< label <<","<<"shape = "<<shapes[id]<<","<<"color = "<<"\""<<colors[id]<<"\" "<<"]"<<endl;
        file <<"  "<< id <<" [label= "<< label <<","<<"shape = "<<shapes[id]<<","<<"color = "<<"\""<<colors[id]<<"\" "<<"]"<<endl;
    }

/**
     * Public : Connections
     * 
     * Description:
     *          Prints and writes all the connections of the nodes with other nodes in the 
     *     binary search tree.
     *     
     * Params:
     *      ofstream &  : file to write all the things to
     * Returns:
     *      N/A
     */
    void Connections(ofstream &file) {
        string a;
        if (left) {
            a.append("  "+to_string(id) + ":left  -> " + to_string(left->id) + ";"+"\n");
        }
        if (right) {
            a.append("  "+ to_string(id) + ":right -> " + to_string(right->id) + ";"+"\n");
        }
        cout << a;
        file << a;
    }
};


/**
 * BST
 * 
 * Description:
 *         This class adds data to the binary search tree. It compares the daata with the 
 * previous nodes and decides if it goes on the right or the left. It also prints all the
 * nodes in the binary tree and also the connection between the nodes.
 *
 * Public Methods:
 *                          BST()
 *      void                insert(int data)
 *      void                print()
 * 
 * Private Methods:
 *      listNode*            insert(listNode *node, int data)
 *      void                 print(listNode *node)
 *      void                 printConnections()
 *      void                 printLabels()
 * 
 * Usage: 
 *     
 *      
 */

class BST {
private:
    listNode *root;      
    int curr_id;       
    ofstream file;   
    /**
     * Private : insert
     * 
     * Description:
     *          Inserts the data into the binary tree.
     *      
     * 
     * Params:
     *      listNode *   : node whose data is to be compared with the data that is to be 
     *                     inserted
     *      int          : data to be inserted      
     * 
     * Returns:
     *      listNode *   : the root of the new tree
     *      
     */
    listNode *insert(listNode *node, int data) {
        if (node == NULL) {
            node = new listNode();
            node->label = data;
            node->id = curr_id;
            curr_id += 1;
            node->left = NULL;
            node->right = NULL;
        } else if (data <= node->label) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    /**
     * Private : print
     * 
     * Description:
     *      This function prints everything by calling two other functions.
     * 
     * Params:
     *      listNode *   : Node of beginning the print process.
     * 
     * Returns:
     *      N/A
     */
    void print(listNode *node) {
        printLabels(node);
        printConnections(node); 
    }

    /**
     * Private : printConnections
     * 
     * Description:
     *      Prints the node and both of its child. 
     * 
     * Params:
     *      listNode *   : Node of beginning the print process.
     * 
     * Returns:
     *      N/A
     */
    void printConnections(listNode *node) {
        if (node == NULL) return;
        node->Connections(file);
        printConnections(node->left);
        printConnections(node->right);
    }

    /**
     * Private : printLabels
     * 
     * Description:
     *      Prints the node and both of its child. 
     * 
     * Params:
     *      listNode *   : Node of beginning the print process.
     * 
     * Returns:
     *      N/A
     */
    void printLabels(listNode *node) {
        if (node == NULL) return;
        node->Labels(file);
        printLabels(node->left);
        printLabels(node->right);
    }

public:
    /**
     * Public : BST

     * Description:
     *      Default constructor for the binary search tree class. 
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    BST() {
        file.open("test.out", ios::app);
        curr_id = 1;
        root = NULL; 
    }

    /**
     * Public : insert
     * 
     * Description:
     *          Sets the node containing the info as root
     * 
     * Params:
     *      int     : data to be inserted
     * 
     * Returns:
     *      N/A
     */
    void insert(int data) {
        root = insert(root, data); 
    }

    /**
     * Public : print
     * 
     * Description:
     *      Prints the DOT syntax for the binary tree. It also writes
     *      the syntax to the output file.
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */


  
    void print() {
        if (!file.is_open()) {
            file.open("test.out", ios::app);
        };
        cout << "digraph BST {" << endl;
    cout << "  "
         << "rankdir=TD" << endl;
    cout << "  "
         << "bgcolor= \"grey\" " << endl;
    cout << "  "
            "label = \"Binary Search Tree\" "
         << endl;
        cout << defaultbst<<endl;
      file << "digraph BST {" << endl;
    file << "  "
         << "rankdir=TD" << endl;
    file << "  "
         << "bgcolor= \"grey\" " << endl;
    file << "  "
            "label = \"Binary Search Tree\" "
         << endl;
        
        file << defaultbst <<endl;;
        print(root);
        file << "}"<<endl;
        cout << "\n}"<<endl;
        file.close();
    }

    
};
