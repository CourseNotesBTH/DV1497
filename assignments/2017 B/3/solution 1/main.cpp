//
//  main.cpp
//  Inlämning C 2
//
//  Created by Alex Gustafsson on 2017-04-01.
//  Copyright © 2017 Alex Gustafsson. All rights reserved.
//

#include <iostream>
#include <string>

#include "Set.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Creating a set containing integers and adding three elements (1, 2, 3)" << endl;
    Set<int> intSet;
    intSet.insert(1);
    intSet.insert(2);
    intSet.insert(3);
    
    cout << "Creating a copy of the initial set using the copy constructor" << endl;
    Set<int> intSet2(intSet);
    
    cout << "Comparing the sets. Should be equal" << endl;
    cout << (intSet == intSet2 ? "equal" : "not equal") << endl;
    
    cout << "Creating a set using the default constructor and adding three elements (4, 5, 6)" << endl;
    Set<int> intSet3;
    intSet3.insert(4);
    intSet3.insert(5);
    intSet3.insert(6);
    cout << "Assigning to the set using the initial set" << endl;
    intSet3 = intSet;
    
    cout << "Comparing the sets. Should be equal" << endl;
    cout << (intSet == intSet3 ? "equal" : "not equal") << endl;
    
    cout << "Removing all elements from the initial set" << endl;
    intSet.remove(1);
    intSet.remove(2);
    intSet.remove(3);
    cout << "Removing a non-existing element from the initial set, throwing an error" << endl;
    try {
        intSet.remove(0);
    } catch(const char* error) {
        cout << "error: " << error << endl;
    }
    
    cout << "Adding three elements to the initial set (3, 1, 2)" << endl;
    intSet.insert(3);
    intSet.insert(1);
    intSet.insert(2);
    
    cout << "Comparing the sets. Should be equal (no matter order)" << endl;
    cout << (intSet == intSet3 ? "equal" : "not equal") << endl;
    
    cout << "Creating a set containing doubles and adding three elements (0.5, 0.25, 0.10)" << endl;
    Set<double> stringSet;
    stringSet.insert(0.5);
    stringSet.insert(0.25);
    stringSet.insert(0.10);
    
    cout << "Creating a set containing doubles and adding three elements (0.25, 0.5, 0.10)" << endl;
    Set<double> stringSet2;
    stringSet2.insert(0.25);
    stringSet2.insert(0.5);
    stringSet2.insert(0.10);
    
    
    cout << "Comparing the sets of doubles. Should be equal (no matter order)" << endl;
    cout << (stringSet == stringSet2 ? "equal" : "not equal") << endl;
    
    cout << "Creating a set containing doubles and adding three elements (0, 0.10, 10)" << endl;
    Set<double> stringSet3;
    stringSet2.insert(0);
    stringSet2.insert(0.1);
    stringSet2.insert(10);
    
    cout << "Comparing the sets of doubles. Should not be equal" << endl;
    cout << (stringSet3 == stringSet2 ? "equal" : "not equal") << endl;
    
    return 0;
}
