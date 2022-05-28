// #include <iostream>
// #include "Tree.h"

// using namespace std;

// void printOrders(Tree *tree) {
//     cout << "Preorder = ";
//     tree->preOrder();
//     cout << "Inorder = ";
//     tree->inOrder();
//     cout << "Postorder = ";
//     tree->postOrder();
// }

// int main() {

//     Tree tree;

//     cout << "Test 1: Testing simple insert" << endl;
//     tree.insert("neo");
//     tree.insert("trinity");
//     printOrders(&tree);
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 2: Search test: find \"neo\"" << endl;
//     if (tree.search("neo"))
//         cout << "Passed" << endl;
//     else
//         cout << "Failed" << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 3: Smallest value in the tree is..." << endl;
//     cout << tree.smallest() << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 4: Largest value in the tree is..." << endl;
//     cout << tree.largest() << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 5: Testing subtree heights" << endl;
//     cout << "Height of subtree rooted at \"neo\" = "
//         << tree.height("neo") << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 6: Remove testing" << endl;
//     cout << "Removing \"neo\"" << endl;
//     tree.remove("neo");
//     printOrders(&tree);
//     cout << "----------------------------------------------------------------"
//         << endl;

//     return 1;
// }

// #include <iostream>
// #include "Tree.h"

// using namespace std;

// void printOrders(Tree *tree) {
//     cout << "Preorder = ";
//     tree->preOrder();
//     cout << "Inorder = ";
//     tree->inOrder();
//     cout << "Postorder = ";
//     tree->postOrder();
// }

// int main() {

//     Tree tree;

//     cout << "Test 1: Testing simple insert" << endl;
//     tree.insert("Foxtrot");
//     tree.insert("Romeo");
//     tree.insert("Zulu");
//     tree.insert("Charlie");
//     tree.insert("Whiskey");
//     tree.insert("Tango");
//     tree.insert("Alpha");
//     tree.insert("Delta");
//     printOrders(&tree);
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 2: Search test: find \"Tango\"" << endl;
//     if (tree.search("Tango"))
//         cout << "Passed" << endl;
//     else
//         cout << "Failed" << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 3: Search test: find \"Uniform\"" << endl;
//     if (tree.search("Uniform"))
//         cout << "Passed" << endl;
//     else
//         cout << "Failed" << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 4: Smallest value in the tree is..." << endl;
//     cout << tree.smallest() << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 5: Largest value in the tree is..." << endl;
//     cout << tree.largest() << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 6: Testing subtree height:\"Kilo\",(-1 not in tree)" << endl;
//     cout << "Height of subtree rooted at \"Kilo\" = "
//         << tree.height("Kilo") << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 7: Testing subtree height:\"Charlie\",(-1 not in tree)" << endl;
//     cout << "Height of subtree rooted at \"Charlie\" = "
//         << tree.height("Charlie") << endl;
//     cout << "----------------------------------------------------------------"
//         << endl;
//     cout << "Test 8: Remove Foxtrot" << endl;
//     cout << "Removing \"Foxtrot\"" << endl;
//     tree.remove("Foxtrot");
//     printOrders(&tree);
//     cout << "----------------------------------------------------------------"
//         << endl;

//     return 1;
// }

#include <iostream>
#include "Tree.h"

using namespace std;

void
printOrders(Tree* tree) {
    cout << "Preorder = ";
    tree->preOrder();
    cout << "Inorder = ";
    tree->inOrder();
    cout << "Postorder = ";
    tree->postOrder();
}

int
main() {

    Tree tree;

    tree.insert("hoppy");
    tree.insert("gadget");
    tree.insert("hoppy");
    tree.insert("gadget");
    tree.insert("reel");
    tree.insert("trap");
    tree.insert("madness");
    tree.insert("aeon");
    tree.insert("hoppy");
    tree.insert("gadget");
    tree.insert("hoppy");
    tree.insert("gadget");
    tree.insert("reel");
    tree.insert("trap");
    tree.insert("madness");
    tree.insert("aeon");
    tree.insert("alphabet");
    tree.insert("alphabet");
    tree.insert("basket");
    tree.insert("basket");
    tree.insert("hut");
    tree.insert("hit");
    tree.insert("House");
    tree.insert("A+");
    tree.insert("jungle");
    tree.insert("ink");
    tree.insert("jab");

    tree.printTreeSideways();

    return 1;
}
