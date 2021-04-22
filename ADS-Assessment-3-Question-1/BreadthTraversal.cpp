#include <windows.h>								//Library for controling windows functions
#include <fstream>									//Library for File System control
#include "BreadthTraversal.h"                       //Class which has integar variables 

// This function inserts a number into a new tree value
void BreadthTraversal::insert(numbersClass* newNumber)
{
    //IF root has no value end here
    if (root == NULL)
    {
        root = newNumber;
        return;
    }

    //Pointers for current and parent(previous)
    numbersClass* current = root; //current node we're pointing at
    numbersClass* parent = NULL; //parent of current

    //While loop that adds numbers to left and right side depnding on value
    while (true)
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT?!
        //if new students studentID is less then the student at current node, then go down LEFT
        if (newNumber->numberID < current->numberID)
        {
            //< means we go down deeper into tree on left side
            current = current->leftChild;
            //if current is NULL, we just found an empty space to insert our new Student :D
            if (current == NULL)
            {
                //done, stick student here
                parent->leftChild = newNumber;
                return; //done, bail
            }
        }
        else
        {
            //go down right path
            current = current->rightChild;
            //if current is NULL, insert there
            if (current == NULL)
            {
                parent->rightChild = newNumber;
                return;
            }
        }
    }
}



numbersClass* BreadthTraversal::search(int numberID, bool showSearchPath)
{
    //if tree empty, cant find student matching studentID then
    if (root == NULL)
    {
        return NULL;
    }

    numbersClass* current = root;

    //keep looping until I find a match
    while (current->numberID != numberID)
    {


        if (showSearchPath)
            cout << current->numberID << " " << endl;

        //havent found it yet, lefts explore left or right down in the tree
        if (numberID < current->numberID)
        {
            //go left
            current = current->leftChild;
        }
        else
        {
            //go right
            current = current->rightChild;
        }

        //if current is NULL, search studentID cannot be found
        if (current == NULL)
        {
            return NULL;
        }

    }

    return current; //should be pointing to match in tree :D
}



void BreadthTraversal::show(numbersClass* p)
{
    //Writes the result to a text file
    ofstream  writeFile;
    writeFile.open("output-a1q1.txt");

    // Base Case 
    if (root == NULL)  return;

    // Create an empty queue for level order traversal 
    queue<LevelNodeClass> q;

    // Enqueue Root and initialize height 
    q.push(LevelNodeClass(root, 0));

    int previousOutputLevel = -1;


    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue 
        LevelNodeClass node = q.front();
        if (node.level != previousOutputLevel)
        {
            cout << endl;
            writeFile << endl;
            cout << node.level << "- ";
            writeFile << node.level << "- ";
            
            previousOutputLevel = node.level;
        }
        cout << node.number->numberID  << " ";
        writeFile << node.number->numberID << " ";
        q.pop();

        /* Enqueue left child */
        if (node.number->leftChild != NULL)
            q.push(LevelNodeClass(node.number->leftChild, node.level + 1));

        /*Enqueue right child */
        if (node.number->rightChild != NULL)
            q.push(LevelNodeClass(node.number->rightChild, node.level + 1));

    }
    //close writing to file
    writeFile.close();
}