#include "BreadthTraversal.h"


void BreadthTraversal::insert(numbersClass* newStudent)
{
    //IF the root is NULL(tree is empty), then make this student the root
    if (root == NULL)
    {
        root = newStudent;
        return; //exit function early, we are done here
    }

    //some pointers to help us navigate the tree to find where to put the new student
    numbersClass* current = root; //current node we're pointing at
    numbersClass* parent = NULL; //parent of current (node visitored last time)

    while (true)//infinite loop
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT?!
        //if new students studentID is less then the student at current node, then go down LEFT
        if (newStudent->numberID < current->numberID)
        {
            //< means we go down deeper into tree on left side
            current = current->leftChild;
            //if current is NULL, we just found an empty space to insert our new Student :D
            if (current == NULL)
            {
                //done, stick student here
                parent->leftChild = newStudent;
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
                parent->rightChild = newStudent;
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
            cout << current->numberID << " " << current->name << endl;

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



//referenced second algorithm here https://www.geeksforgeeks.org/level-order-tree-traversal/
void BreadthTraversal::show(numbersClass* p)
{
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
            cout << node.level << "- ";
            previousOutputLevel = node.level;
        }
        cout << node.number->numberID << ":" << node.number->name << " ";
        q.pop();

        /* Enqueue left child */
        if (node.number->leftChild != NULL)
            q.push(LevelNodeClass(node.number->leftChild, node.level + 1));

        /*Enqueue right child */
        if (node.number->rightChild != NULL)
            q.push(LevelNodeClass(node.number->rightChild, node.level + 1));

    }
}