#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

class State {
public:
    int id;
    bool isStart;
    bool isAccept;
    bool exists;

    State(int id) : id(id), isStart(false), isAccept(false), exists(false) {}
    State(int id, bool exist): id(id), isStart(false), isAccept(false), exists(exist) {}
};

class Transition {
public:
    int fromState;
    int toState;
    char input;

    Transition(int fromState, int toState, char input) 
        : fromState(fromState), toState(toState), input(input) {}
};

vector<State> states;
vector<Transition> transitions;
int maxStates = 0;

bool isValidState(int state) {
    for (const auto& s : states) {
        if (s.id == state && s.exists == true) return true;
    }
    return false;
}

int parseNFA(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file\n";
        return 1;
    }

    states.clear();
    transitions.clear();

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        
        if (!(iss >> type)) continue;

        if (type == "state") {
            int stateNum;
            string stateType1;
            
            if (!(iss >> stateNum)) {
                cerr << "Error: Invalid state format\n";
                continue;
            }
            int prevSize = states.size();
           if(stateNum >= states.size()) {
                states.resize(stateNum + 1, State(-1, false));
                for(int i = prevSize; i < states.size(); i++) {
                    states[i] = State(i, false);
                }
                states[stateNum] = State(stateNum, true);
            }
            else {
                states[stateNum].exists = true;
            }
            while (iss >> stateType1) {
                if (stateType1 == "start") {
                    states[stateNum].isStart = true;
                }
                else if (stateType1 == "accept") {
                    states[stateNum].isAccept = true;
                }
                else if (stateType1 == "acceptstart" || stateType1 == "startaccept") {
                    states[stateNum].isStart = true;
                    states[stateNum].isAccept = true;
                }
            }

        } else if (type == "transition") {
            int fromState;
            char input;
            int toState;
            string inputStr;
            
            if (!(iss >> fromState >> inputStr >> toState)) {
                cerr << "Error: Invalid transition format\n";
                continue;
            }
            input = inputStr[0];
            int prevSize = states.size();
            if(fromState >= states.size()) {
                states.resize(fromState + 1, State(-1, false));
                for(int i = prevSize; i < states.size(); i++) {
                    if(states[i].id == -1) {
                        states[i] = State(i, false);
                    }
                } 
            }
            else if(toState >= states.size()) {
                states.resize(toState + 1, State(-1, false));
                for(int i = prevSize; i < states.size(); i++) {
                    if(states[i].id == -1) {
                        states[i] = State(i, false);
                    }
                }
            }
            states[fromState].exists = true;
            states[toState].exists = true;
            
            transitions.push_back(Transition(fromState, toState, input));
        }
    }

     
    file.close();
    return 0;
}

class NFANode {
public:
    vector<bool> states;
    NFANode* parent;
    char input;
    
    NFANode(const vector<bool>& states, NFANode* parent = nullptr, char input = '\0') 
        : states(states), parent(parent), input(input) {}
};



bool processString(const string& input) {
    vector<bool> initialStates(states.size(), false);
    vector<int> acceptStates;
    vector<int> rejectStates;
    
    for (const auto& state : states) {
        if (state.isStart) {
            initialStates[state.id] = true;
        }
    }
    
    
    NFANode* root = new NFANode(initialStates);
    vector<NFANode*> currentLevel = {root};
    
    for (char ch : input) {
        vector<NFANode*> nextLevel;
        
        for (NFANode* current : currentLevel) {
            vector<bool> nextStates(states.size(), false);
            
            for (const auto& transition : transitions) {
                if (current->states[transition.fromState] && transition.input == ch) {
                    nextStates[transition.toState] = true;
                }
            }
            
            if (any_of(nextStates.begin(), nextStates.end(), [](bool b) { return b; })) {
                nextLevel.push_back(new NFANode(nextStates, current, ch));
            }
        }
        
        if (!currentLevel.empty() && currentLevel[0] != root) {
            for (auto node : currentLevel) delete node;
        }
        
        currentLevel = nextLevel;
        
    }
    
    bool hasAccept = false;
    for (NFANode* finalNode : currentLevel) {
        for (int i = 0; i < states.size(); ++i) {
            if (finalNode->states[i]) {
                if (states[i].isAccept) {
                    acceptStates.push_back(i);
                    hasAccept = true;
                } else {
                    rejectStates.push_back(i);
                }
            }
        }
    }
    
    for (auto node : currentLevel) delete node;
    delete root;
    
    if (hasAccept) {
        sort(acceptStates.begin(), acceptStates.end());
        cout << "accept";
        for (int state : acceptStates) {
            cout << " " << state;
        }
        cout << "\n";
        return true;
    } else {
        sort(rejectStates.begin(), rejectStates.end());
        cout << "reject";
        for (int state : rejectStates) {
            cout << " " << state;
        }
        cout << "\n";
        return false;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <txt_file> <input_string>\n";
        return 1;
    }

    if (parseNFA(argv[1])) {
        return 1;
    }
    
    processString(argv[2]);

    return 0;
}
