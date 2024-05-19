#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Trie {
public:
    class Node {
    public:
        bool isWord;
        unordered_map<char, Node* > children;
        Node() :isWord(false) {}
    };
    Node* N;
    Trie() {
        N = new Node();
    }

    void insert(string word) {
        Node* cur = N;
        for (char& c : word) {
            if (cur->children.count(c)==0) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Node* cur = N;
        for (char& c : word) {
            if (cur->children.count(c) == 0) return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        Node* cur = N;
        for (char& c : prefix) {
            if (cur->children.count(c) == 0) return false;
            cur = cur->children[c];
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    // Trie * T;
    unique_ptr<Trie> T;
    while (true) {
        cout << "Enter the cmd:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        stringstream ss(In);
        string token;
        vector<string> cmds;
        while (getline(ss, token, ',')) {
            // size_t l = token.find_first_not_of(" ");
            // size_t r = token.find_last_not_of(" ");
            cmds.push_back(token);
        }
        string cmd = cmds[0];
        string val = cmds[1];
        if (cmd == "Trie") {
            T.reset(new Trie());
        }
        else if (cmd == "insert") {
            T->insert(val);
        }
        else if (cmd == "search") {
            cout <<"Res: " << T->search(val) << endl;
        }
        else if (cmd == "startsWith") {
            cout << "Res: " << T->startsWith(val) << endl;
        }
        else {
            cout << "Cmd is not valid!" << endl;
        }
    }
}