// Written by Shreya Bose

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

vector<string> a, b, c; // making the variables global for access
// naming the pegs
string peg0 = "peg 0";
string peg1 = "peg 1";
string peg2 = "peg 2";


void displayTower();
void SolveHuger(int, vector<string> &, vector<string> &, vector<string> &);
void MoveStackOfPairs(int, vector<string> &, vector<string> &, vector<string> &);

int step = 1;  // instantiating step

int main() {
    while(cin.good()) {    // to check if it is valin int
        int n = 1;
        cin >> n;
        string letters [26]= {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; // adding alphabets to array of letters
        for (int i = 1; i <= n; i++) {
        	a.push_back(letters[i-1]);   // pushing the letters
                a.push_back(to_string(i));   // converting to string
               // cout << i;
                
        }
	
	cout << "Starting at: " << endl;
        displayTower();   // calling displayTower
	SolveHuger(n,a,b,c);  // calling SolveHuger
	cout << "Done!" << endl;
    }
    return 0;
}


void displayTower() {  // display of the disks
    cout << "0: ";
    for (auto iter = a.begin(); iter != a.end(); iter++)
        cout << *iter;
    cout << endl << "1: ";
    for (auto iter = b.begin(); iter != b.end(); iter++)
        cout << *iter;
    cout << endl << "2: ";
    for (auto iter = c.begin(); iter != c.end(); iter++)
        cout << *iter;
    cout << endl;
}


void SolveHuger(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
    if ( n < 2) {
	// Move a disk from peg 0 to peg 2    
    	cout << "Step " << step++ << ": Move disk "<< a.back() << " from " << peg0 << " to " << peg2 << "." << endl;
        c.push_back(a.back());
        a.pop_back();
	displayTower();

        //Move a disk from peg 0 to peg 1
        cout << "Step " << step++ << ": Move disk " << a.back() << " from " << peg0 << " to " << peg1 << "." << endl;
        b.push_back(a.back());
        a.pop_back();
	displayTower();

    } else {
	MoveStackOfPairs(n-1,a,b,c);
	// Move a disk from peg 0 to peg 2
	cout << "Step " << step++ << ": Move disk "<< a.back() << " from " << peg0 << " to " << peg2 << "." << endl;
        c.push_back(a.back());
        a.pop_back();
	displayTower();

	// Moving another disk from peg 0 to peg 2
	cout << "Step " << step++ << ": Move disk "<< a.back() << " from " << peg0 << " to " << peg2 << "." << endl;
        c.push_back(a.back());
        a.pop_back();
	displayTower();

	MoveStackOfPairs(n-1,b,a,c);
	// Moving a disk from peg 2 to peg 1
	cout << "Step " << step++ << ": Move disk "<< c.back() << " from " << peg2 << " to " << peg1 << "." << endl;
        b.push_back(c.back());
        c.pop_back();
	displayTower();

	SolveHuger(n-1,a,b,c);
    }
}

void MoveStackOfPairs(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
	if ( n < 2 ) {
		// Moving a disk peg 0 to peg 2
        	cout << "Step " << step++ << ": Move disk "<< a.back() << " from " << peg0 << " to " << peg2 << "." << endl;
                c.push_back(a.back());
                a.pop_back();
		displayTower();

		//Move a disk from peg 0 to peg 1
        	cout << "Step " << step++ << ": Move disk " << a.back() << " from " << peg0 << " to " << peg1 << "." << endl;
        	b.push_back(a.back());
        	a.pop_back();
		displayTower();

		// Move a disk from peg 2 to peg 1
		cout << "Step " << step++ << ": Move disk "<< c.back() << " from " << peg2 << " to " << peg1 << "." << endl;
       		b.push_back(c.back());
        	c.pop_back();
		displayTower();

	} else {
		MoveStackOfPairs(n-1,a,b,c);
		// Move a disk from peg 0 to peg 2
        	cout << "Step " << step++ << ": Move disk "<< a.back() << " from " << peg0 << " to " << peg2 << "." << endl;
        	c.push_back(a.back());
        	a.pop_back();
		displayTower();

        	// Moving another disk from peg 0 to peg 2
        	cout << "Step " << step++ << ": Move disk "<< a.back() << " from " << peg0 << " to " << peg2 << "." << endl;
        	c.push_back(a.back());
        	a.pop_back();
		displayTower();

        	MoveStackOfPairs(n-1,b,a,c);
        	// Moving a disk from peg 2 to peg 1
        	cout << "Step " << step++ << ": Move disk "<< c.back() << " from " << peg2 << " to " << peg1 << "." << endl;
       		b.push_back(c.back());
        	c.pop_back();
		displayTower();

		// Moving another disk from peg 2 to peg 1
                cout << "Step " << step++ << ": Move disk "<< c.back() << " from " << peg2 << " to " << peg1 << "." << endl;
                b.push_back(c.back());
                c.pop_back();
		displayTower();

		MoveStackOfPairs(n-1,a,b,c);
	}
}
