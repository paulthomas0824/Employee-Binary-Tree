#include <iostream>
using namespace std;
// This class is a template class that creates a binary
// tree that can hold values of any data type. It has
// functions to insert a node, search for a
// value
template <class T>
class BinaryTree
{
private:
 struct TreeNode
 {
  T value; // The value in the node
  TreeNode *left; // Pointer to left child node
  TreeNode *right; // Pointer to right child node
 };
 TreeNode *root; // Pointer to the root node
     // Private member functions
 void insert(TreeNode *&, TreeNode *&);
 void destroySubTree(TreeNode *);
public:
 // Constructor
 BinaryTree()
 {
  root = NULL;
 }
 // Destructor
 ~BinaryTree()
 {
  destroySubTree(root);
 }
 // Binary tree operations
 void insertNode(T);
 bool searchNode(T &);
};
// insert function accepts a TreeNode pointer and a *
// pointer to a node. The function inserts the node into *
// the tree pointer to by the TreeNode pointer. This *
// function is call recursively. *
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
 if (nodePtr == NULL)
  nodePtr = newNode; // Insert the node
 else if (newNode->value < nodePtr->value)
  insert(nodePtr->left, newNode); // Search the left branch
 else
  insert(nodePtr->right, newNode);// Search the right branch
}
// insertNode creates a new node to hold item as its value*
// and passes it to the insert function. *
template <class T>
void BinaryTree<T>::insertNode(T item)
{
 TreeNode *newNode; // Pointer to a new node
        // Create anew node and store num in it
 newNode = new TreeNode;
 newNode->value = item;
 newNode->left = newNode->right = NULL;
 // Insert the node
 insert(root, newNode);
}
// destroySubTree is called by the destructor. It deletes *
// all nodes in the tree. *
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
 if (nodePtr)
 {
  if (nodePtr->left)
   destroySubTree(nodePtr->left);
  if (nodePtr->right)
   destroySubTree(nodePtr->right);
  delete nodePtr;
 }
}
// searchNode determines if a value is present in the tree.*
// If so, the function returns true. Otherwise it returns *
// false.
template <class T>
bool BinaryTree<T>::searchNode(T &item)
{
 TreeNode *nodePtr = root;
 while (nodePtr)
 {
  if (nodePtr->value == item)
  {
   item.setEmpName(nodePtr->value.getEmpName());
   return true;
  }
  else if (item < nodePtr->value)
   nodePtr = nodePtr->left;
  else
   nodePtr = nodePtr->right;
 }
 return false;
}



####################################################################

#include<iostream>
#include<string>
using namespace std;
class EmployeeInfo
{
private:
 int empID; // To hold employee ID number
 string empName; // To hold employee name
public:
 // Default Constructor
 EmployeeInfo();
 // Constructor
 EmployeeInfo(int, string);
 // Mutators
 void setEmpID(int);
 void setEmpName(string);
 // Accessors
 int getEmpID();
 string getEmpName();
 // Overloaded operator. This works directly with
 // the insert function of BinaryTree.h more specifically
 // line 71. *For my knowledge*
 bool operator < (const EmployeeInfo &e)
 {
  if (empID < e.empID)
   return true;
  return false;
 }
 // Overloaded operator for the search function
 bool operator == (const EmployeeInfo &e)
 {
  if (empID == e.empID)
   return true;
  return false;
 }
};
// Default constructor intializes the data members *
EmployeeInfo::EmployeeInfo()
{
 empName = "";
 empID = 0;
}
// Constructor sets the data members *
EmployeeInfo::EmployeeInfo(int ID, string name)
{
 empName = name;
 empID = ID;
}
// setEmpID stores the employee ID number *
void EmployeeInfo::setEmpID(int ID)
{
 empID = ID;
}
// setEmpName stores the full name of the employee *
void EmployeeInfo::setEmpName(string name)
{
 empName = name;
}
// getEmpID returns the employee ID number *
int EmployeeInfo::getEmpID()
{
 return empID;
}
// getEmpName returns the full name of the employee *
string EmployeeInfo::getEmpName()
{
 return empName;
}


#################################################################


#include "Employee.h"
#include "Binary_Tree.h"
using namespace std;
int main()
{
 char again = 'y';
 int id;
 // Create an instance of BinaryTree
 BinaryTree<EmployeeInfo> tree;
 // Create an EmployeeInfo object
 EmployeeInfo emp1(1021, "John Williams");
 EmployeeInfo emp2(1057, "Bill Witherspoon");
 EmployeeInfo emp3(2487, "Jennifer Twain");
 EmployeeInfo emp4(3769, "Sophia Lancaster");
 EmployeeInfo emp5(1017, "Debbie Reece");
 EmployeeInfo emp6(1275, "George McMullen");
 EmployeeInfo emp7(1899, "Ashley Smith");
 EmployeeInfo emp8(4218, "Josh Plemmons");
 tree.insertNode(emp1);
 tree.insertNode(emp2);
 tree.insertNode(emp3);
 tree.insertNode(emp4);
 tree.insertNode(emp5);
 tree.insertNode(emp6);
 tree.insertNode(emp7);
 tree.insertNode(emp8);

 do
 {
  cout << "Enter the ID number of the employee: ";
  cin >> id;
  // Create an EmployeeInfo object to store the user's
  // search parameters
  EmployeeInfo info;
  info.setEmpID(id);
  // If search finds what the user entered display the
  // corresponding employee
  if (tree.searchNode(info))
  {
   cout << info.getEmpName() << endl; // Not right?
  }
  else
   cout << "ID not found!" << endl;
  cout << "\nDo you want to search for an employee y /n :";
  cin >> again;
 } while (again == 'y');
 return 0;
}
