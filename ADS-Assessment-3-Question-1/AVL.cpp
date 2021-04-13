#include "AVL.h"

int AVL::height(numbersClass* node)
{
    int h = 0;
    //helps break recursion cycle when we get to nulls at the bottom of branches
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        //max gets biggest of the 2 and discards the smaller
        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    return h;
}

int AVL::difference(numbersClass* node)
{
    //if empty treee, well its balanced, its 0
    if (node == NULL)
        return 0;

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}


numbersClass* AVL::RRrotation(numbersClass* parent)
{
    numbersClass* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    if (displayRotations)
        cout << "RR rotation on " << parent->name << endl;

    return temp;
}

numbersClass* AVL::LLrotation(numbersClass* parent)
{
    numbersClass* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotations)
        cout << "RR rotation on " << parent->name << endl;

    return temp;
}
//needs 2 rotations,
//first rotation rotates bottom 2 nodes which turns the whole structure into a RR rotation
//second rotation uses RRrotation
numbersClass* AVL::LRrotation(numbersClass* parent)
{
    numbersClass* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    if (displayRotations)
        cout << "LR rotation on " << parent->name << endl;
    return LLrotation(parent);
}

numbersClass* AVL::RLrotation(numbersClass* parent)
{
    numbersClass* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
    if (displayRotations)
        cout << "RL rotation on " << parent->name << endl;
    return RRrotation(parent);
}

numbersClass* AVL::balance(numbersClass* parent)
{
    //get balance factor
    int balanceFactor = difference(parent);

    //IF balanceFactor not within -1,0,1, then lets work out what rotations to do
    if (balanceFactor > 1)
    {
        //left branch is heavy, now work out is left or right child heavy
        if (difference(parent->leftChild) > 0)
        {
            //left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            //right child unbalanced
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        //right branch is heavy, but which child
        if (difference(parent->rightChild) > 0)
        {
            //left child heavy
            parent = RLrotation(parent);
        }
        else
        {
            //right child heavy
            parent = RRrotation(parent);
        }
    }


    return parent;
}

numbersClass* AVL::insertAVL(numbersClass* parent, numbersClass* newStudent)
{
    //if sub tree empty, this becomes the parent
    if (parent == NULL)
    {
        parent = newStudent;
        return parent;
    }

    //parent not null, so we haven't found an empty space to stick new student yet
    //so we need to go down either left or right path
    if (newStudent->numberID < parent->numberID)
    {
        parent->leftChild = insertAVL(parent->leftChild, newStudent);
        parent = balance(parent);
    }
    else //assume id >= parent's id
    {
        parent->rightChild = insertAVL(parent->rightChild, newStudent);
        parent = balance(parent);
    }
}

void AVL::insert(numbersClass* newNumber)
{
    cout << "Inserting " << newNumber->name << " " << newNumber->numberID << endl;
    root = insertAVL(root, newNumber);
    cout << endl;
}
