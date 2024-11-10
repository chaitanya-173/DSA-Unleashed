#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie {
    public:
    TrieNode* root;

    //constructor
    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {    //FOR RECURSION
        //base case
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }

        //assumption: word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {  //absent
            child = new TrieNode(word[0]);
            root -> childCount++;
            root -> children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {

        for(int i=0; i<str.length(); i++) {
            char ch = str[i];

            if(root -> childCount == 1) {
                ans.push_back(ch);
                //aage badhjao
                int index = ch - 'a';
                root = root -> children[index];
            }
            else {
                break;
            }

            if(root -> isTerminal)
                break;
        }
    }

};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *t = new Trie('\0');

    //insert all strings into trie
    for(int i=0; i<26; i++) {
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t -> lcp(first, ans);
    return ans;
}

//TC - O(m*n);
//SC - O(m*n);

int main() {

    vector<string> arr{"coding", "codezen", "coders", "codingninja"};

    string ans = longestCommonPrefix(arr, 4);

    for(int i=0; i<ans.length(); i++) {
        cout << ans[i];
    }

}