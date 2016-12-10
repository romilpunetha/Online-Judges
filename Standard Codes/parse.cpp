void parse(string s, char delim){ // careful about call by value
    s += delim;
    int prev = 0, curr  = 0;
    while((curr = s.find(delim, prev)) != string::npos){
        string subst = s.substr(prev, curr - prev);
        // do something
        // like cout << subst << endl;
        // dont change curr and prev...use temp variables if needed
        prev = curr + 1;
    }
}

// INPUT
// This is a freaking cat
//
// OUTPUT
//This
//is
//a
//freaking
//cat
//
//NOTE : Usually you'll have to use getline() to take such inputs. Remember to flush stdio if using cin and getline() together.
//cin.ignore(INT_MAX, '\n');
