// Shreya Bose

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

vector<string> names,teamA,teamB; //vectors
vector<int> skills;
int sum = 0;
bool True;
int numLines = 0;

void possibleTable(string s,int k) {
        if(k == 0) {
                //cout << s << endl;
		int skillA = 0;
		int skillB = 0;
                skillA = skillA + skills.at(0);    // 13
		//cout << skillA << "Baby" << endl;
                teamA.push_back(names.at(0)); // first name has to be in TeamA
                for (int i = 0; i < numLines; ++i) {
                          sum += skills[i];
                          //cout << sum << endl;
                 }
		
		 for(int i = 0; i < s.length(); ++i) {
			 // cout << s[i];
                         if(s[i] == '0') {		// pushing all the 0s into teamA
                      
                                 teamA.push_back(names.at(i+1));
                                 skillA = skillA + skills.at(i+1);
                                 //cout << skillA << endl;
                         }
                         else{						// pushing all one's to teamB
                                 //skillB = skillB + skills.at(i+1);
                                 teamB.push_back(names.at(i+1));
                                 skillB = skillB + skills.at(i+1);
                                 //cout << skillB << endl;
                         }
                 }
		 //cout << skillA << " " << skillB << endl;
		  
		 if(skillA == skillB){  // checking if skillA is equal to skillB
                         cout << "Team A:" << endl;
                         for(int i = 0; i < teamA.size(); i++){
                                 cout << " " << teamA[i] << endl;  // printing out teamA
				}
                         cout << "Team B:" << endl;
                         for(int i = 0; i < teamB.size(); i++) {
                                 cout << " " << teamB[i] << endl; // printing out teamB
                         }
			 True = true;
                 }
		 
		 teamA.clear();
		 teamB.clear();

                 return;
        }
        possibleTable(s + "0", k - 1);
        possibleTable(s + "1", k -1);

}

int main(int argc, char* argv[]) {
	while(true) {

		//int numLines = 0;
		cin >> numLines;

		if(!cin.good()) 
			return 0;

		if(numLines <= 1){
			cout << "No solution" << endl;
		}

		string name;
		int skill;

		for(int i = 0; i < numLines; i++) { // reading the file
			cin >> name;
                	names.push_back(name);
                	cin >> skill;
                	skills.push_back(skill);
		//	cout << skills[i] << endl;
		}


		for (int i = 0; i < numLines; ++i) {
                            sum += skills[i];
                            //cout << sum << endl;
                    }

		string out;
                possibleTable(out, numLines-1);  // calling possibleTable

		cout << "------------" << endl;

		if(True != true) {
			cout << "No Solution." << endl;
			cout << "------------" << endl;
		}
		// clearing vectors
		names.clear(); 
		skills.clear();
		True = false;
	}

	return 0;
}
