/* 
 * File:   main.cpp
 * Author: Royal Arthurs
 * Created on March 22, 2017, 12:15 PM
 * Purpose: Use the linked list developed in class placed in the repository to add and delete nodes
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

//User Libraries
#include "LList.h"

using namespace std;

//Function prototypes
Link *fillLst(int);
void printList(Link *, int);
void destLst(Link *);
Link *endOfList(Link *);
void addEndLink(Link *, int);
void delEndLink(Link *);
void addBegLink(Link *, int);
Link delBegLink(Link *);
void addLink(Link *, int, int);
void delLink(Link *, int);
int findLink(int);

int main(int argc, char** argv) {

    Link *linkList;
    int listSize = 10,
            perCol = 5;

    cout << "Filling list\n\n";
    linkList = fillLst(listSize);

    cout << "Output list";
    printList(linkList, perCol);

    cout << "Adding ''0'' to end of list\n";
    addEndLink(linkList, 0);

    cout << "Output list with new value added";
    printList(linkList, perCol);

    cout << "delete the value at the end of list\n";
    delEndLink(linkList);

    cout << "Output list with new value removed";
    printList(linkList, perCol);

    cout << "add ''15'' to position 3 of the link list\n";
    addLink(linkList, 15, 3);

    cout << "Output list with new value added";
    printList(linkList, perCol);

    cout << "delete node #3 (15) from the list \n";
    delLink(linkList, 3);

    cout << "Output list with new value removed";
    printList(linkList, perCol);

    cout << "add 21 to beginning of list\n";
    addBegLink(linkList, 21);

    cout << "Output list with new value added";
    printList(linkList, perCol);

    cout << "delete 21 from beginning of list\n";
    *linkList = delBegLink(linkList);

    cout << "Output list with new value removed";
    printList(linkList, perCol);

    return 0;
}

Link *fillLst(int n) {
    Link *front = new Link; 
    Link *prev = front; 
    prev->data = n--; 
    prev->linkPtr = NULL;
    do {
        Link *end = new Link; 
        end->data = n--; 
        end->linkPtr = NULL;
        prev->linkPtr = end;
        prev = end;
    } while (n > 0); 
    return front; 
}

void printList(Link *front, int col) {
    int counter = 0;
    Link *next = front;
    cout << endl;
    do {
        cout << setw(4) << next->data << " ";
        if (counter++ % col == (col - 1))cout << endl;
        next = next->linkPtr;
    } while (next != NULL);
    cout << endl;
}

void addEndLink(Link *front, int val) {
    Link *nx2last = endOfList(front);
    Link *last = new Link;
    last->data = val;
    last->linkPtr = NULL;
    nx2last->linkPtr = last;
}

Link *endOfList(Link *front) {
    Link *lnk = front, *end;
    do {
        end = lnk;
        lnk = lnk->linkPtr;
    } while (lnk != NULL);
    return end;
}

void delEndLink(Link *front) {
    Link *lnk = front, *end;
    do {
        end = lnk;
        lnk = lnk->linkPtr;
    } while (lnk->linkPtr->linkPtr != NULL);
    delete endOfList(front);
    lnk->linkPtr = NULL;
}

void addLink(Link *front, int value, int position) {
    Link *addedLink = new Link, *prev, *next;
    addedLink->data = value;
    int i = 1;
    do {
        prev = front;
        next = prev->linkPtr;
        front = front->linkPtr;
        i++;
    } while (i < position);
    prev->linkPtr = addedLink;
    addedLink->linkPtr = next;
}

void delLink(Link *front, int position) {
    Link *prev, *next;
    int i = 1;
    do {
        prev = front;
        next = prev->linkPtr;
        front = front->linkPtr;
        i++;
    } while (i < position);
    prev->linkPtr = next->linkPtr;
    delete front;
}

void addBegLink(Link *front, int val) {
    Link *beg = new Link;
    beg->linkPtr = front->linkPtr;
    beg->data = front->data;
    front->data = val;
    front->linkPtr = beg;
}

Link delBegLink(Link *front) {
    Link *temp = front->linkPtr;
    delete front;
    front = front->linkPtr;
    return *temp;
}