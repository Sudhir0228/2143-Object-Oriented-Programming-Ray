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
 *       test.out    : output file with results
 *****************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Node
 *
 * Description:
 *      This struct provides the structure for a node in our linked list.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for a node in our linked list
 *
 */
struct Node {
  int id;
  string label;
  string shape;
  string color;
};

/**
 * Edge
 *
 * Description:
 *      This struct provides the structure for edge between two nodes in our
 * linked list.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for a edge in our linked list
 *
 */

struct Edge {
  int from;
  int to;
  string arrowhead;
  string arrowtail;
  string color;
  string dir;
};

/**
 * Graphiz
 *
 * Description:
 *      This class has methods to create and add to a linked list. It also
 * provides methods to generate "DOT" language syntax that can be used in
 * Graphiz compiler to visualize the linked list.
 *
 * Public Methods:
 *
 *      void                addNode(string label)
 *      void                addEdge(int from, int to)
 *      void                print()
 *      void                printfile(string filename)
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      list.addNode("12");       // Adds a new node with int data 12
 *      list.addNode("8");       // Adds a new node with data 8
 *      list.addedge(1,2);       // links node with id 1 to node with id 2
 *      list.addedge(4,5);       // links node with id 4 to node with id 5
 */

class Graphiz {

public:
  vector<Node> nodes; // vector of Node
  vector<Edge> edges; // vector of Edge
  int id = 0;         // id for each node
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

  // array with 10 different shapes for edges
  string edgeShapes[10] = {"box",    "vee", "diamond", "curve", "crow",
                           "icurve", "dot", "inv",     "none",  "tee"};
  /**
   * Public : addNode
   *
   * Description:
   *      Adds a node to the linked list. Creates the id for the node. The shape
   *      and color of the node are based upon the id of the node.
   * Params:
   *      int     : data to be saved in the node object
   *
   * Returns:
   *      N/A
   */

  void addNode(string label) {
    id = nodes.size() + 1;

    nodes.push_back({id, label, shapes[id], colors[id]});
  }

  /**
   * Public : addEdge
   *
   * Description:
   *      Adds a edge to the linked list. The nodes to connect are provided. The
   * shape and color of the edge are based upon the id of the nodes to connect.
   * Params:
   *       int     : id of the node where the new edge will come from
   *       int     : id of the node where the new edge will point to
   * Returns:
   *      N/A
   */

  void addEdge(int from, int to, string arrowhead = "none",
               string arrowtail = "vee", string color = "black",
               string dir = "none") {
    if (from % 2 == 0) {
      dir = "one";
    } else if (from % 2 == 1) {
      dir = "both";
    }

    edges.push_back(
        {from, to, edgeShapes[from], edgeShapes[from], colors[from], dir});
  }

  /**
   * Public : print
   *
   * Description:
   *      Prints the "DOT" syntax of the linked list. The output can be copied
   * to Graphiz compiler to visualize the linked list.
   *
   * Params: N/A
   *
   * Returns:
   *      N/A
   */

  void print() {
    cout << "digraph graphiz {" << endl;
    cout << "  "
         << "rankdir=LR" << endl;
    cout << "  "
         << "bgcolor= \"grey\" " << endl;
    cout << "  "
            "label = \"Linked List\" "
         << endl;

    cout << "  "
         << "node [shape = record ,color = black]" << endl;

    for (auto node : nodes) {
      cout << "  " << node.id << " [label="
           << "\"" << node.label << "\", shape="
           << "\"" << node.shape << "\""
           << ", color=\"" << node.color << "\"];" << endl;
    }
    cout << "  null [arrowhead ="
         << "normal"
         << ","
         << "arrowtail ="
         << "none"
         << ","
         << "color ="
         << "black"
         << ","
         << "dir="
         << "none]" << endl;

    for (auto edge : edges) {

      cout << "  " << edge.from << ""
           << "->"
           << " " << edge.to << " [arrowhead =" << edge.arrowhead << ","
           << "arrowtail =" << edge.arrowtail << ","
           << "color = \"" << edge.color << "\" ,"
           << "dir=" << edge.dir << "]"
           << ";" << endl;
    }

    cout << "}" << endl;
  };

  /**
   * Public : print
   *
   * Description:
   *      Prints the "DOT" syntax of the linked list to the output file. The
   * output can be copied to Graphiz compiler to visualize the linked list.
   *
   * Params:
   *        string : the name of the output file
   *
   * Returns:
   *      N/A
   */
  void printfile(string filename) {
    ofstream file;
    file.open(filename);
    // writing name in the file
    file << "Sudhir Ray\n";
    file << "March 06, 2023\n";
    file << "Spring 2143\n";

    file << endl;

    file << "digraph graphiz {\n";
    file << "  "
         << "rankdir=LR\n";
    file << "  "
            "bgcolor= \"grey\" \n";
    file << "  "
            "label = \"Linked List\" \n";
    file << "  "
         << "node [shape = record ,color = black]" << endl;

    for (auto node : nodes) {
      if (node.shape == "record" && node.color == "black") {
        file << "  " << node.id << " [label=" << node.label << "]" << endl;
      } else {
        file << "  " << node.id << " [label="
             << "\"" << node.label << "\", shape="
             << "\"" << node.shape << "\""
             << ", color=\"" << node.color << "\"];" << endl;
      }
    }
    file << "  null [arrowhead ="
         << "normal"
         << ","
         << "arrowtail ="
         << "none"
         << ","
         << "color ="
         << "black"
         << ","
         << "dir="
         << "none]" << endl;

    for (auto edge : edges) {
      /**

      **/
      // 1:e -> 2:w[arrowhead=vee, arrowtail=dot, color=cyan, dir=forward];
      file << "  " << edge.from << ""
           << "->"
           << " " << edge.to << " [arrowhead =" << edge.arrowhead << ","
           << "arrowtail =" << edge.arrowtail << ","
           << "color = \"" << edge.color << "\" ,"
           << "dir=" << edge.dir << "]"
           << ";" << endl;
    }
    file << "}" << endl;
    file.close();
  }
};
int main() { // Create a new graph
  Graphiz list;

  // Add nodes
  list.addNode("1");
  list.addNode("2");
  list.addNode("3");
  list.addNode("4");
  list.addNode("5");
  list.addNode("6");

  // Add edges
  list.addEdge(1, 2);
  list.addEdge(2, 3);
  list.addEdge(3, 4);
  list.addEdge(4, 5); // connects node with id 4 to node with id 5
  list.addEdge(5, 6);
  list.addEdge(6, 5);
  list.addEdge(3, 6);

  // Print the graph in Graphviz format
  list.print();
  list.printfile("test.out");

  return 0;
}
