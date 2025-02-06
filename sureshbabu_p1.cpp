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

    State(int id) : id(id), isStart(false), isAccept(false) {}
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
    return state >= 0 && state < states.size();
}

int parseNFA(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        
        if (!(iss >> type)) continue;

        if (type == "state") {
            int stateNum;
            string stateType;
            
            if (!(iss >> stateNum >> stateType)) {
                cerr << "Error: Invalid state format\n";
                continue;
            }
                        
            if(stateNum >= states.size()) {
                states.resize(stateNum + 1, State(-1));
                states[stateNum] = State(stateNum);
            }

            if (stateType == "start" || stateType == "acceptstart" || 
                stateType == "start accept") {
                states[stateNum].isStart = true;
            }
            if (stateType == "accept" || stateType == "acceptstart" || 
                stateType == "start accept") {
                states[stateNum].isAccept = true;
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
            
            
            transitions.emplace_back(fromState, toState, input);
        }
    }

    // cout << "Final count: " << states.size() << " states and " 
    //      << transitions.size() << " transitions\n";
    
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
