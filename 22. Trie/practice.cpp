#include <iostream>
using namespace std;

class Node {
    public:
        char data;
        Node* children[26];
        bool isTerminal;

        Node(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }   
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insertUtil(Node* root, string word) {
        //base case
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        Node* child;

        if(root -> children[index] == NULL) {
            //ch not present
            child = new Node(word[0]);
            root -> children[index] = child;
        }
        else {
            //ch present
            child = root -> children[index];
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(Node* root, string word) {
        //base case
        if(word.length() == 0) {
            return root -> isTerminal;
        }

        int index = word[0] - 'A';
        Node* child;

        if(root -> children[index] == NULL) {
            //ch not present
            return false;
        }
        else {
            //ch present
            child = root -> children[index];
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

};

int main() {

    Trie *t = new Trie();

    t -> insertWord("CODING");
    t -> insertWord("CODE");
    t -> insertWord("TIME");

    cout << t -> searchWord("CODING") << endl;
    cout << t -> searchWord("CODE") << endl;
    cout << t -> searchWord("TIMER") << endl;  
    cout << t -> searchWord("HI") << endl;

}