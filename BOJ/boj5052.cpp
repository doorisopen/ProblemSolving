#include <cstdio>
#include <cstring>

using namespace std;

const int ALPHABETS = 26;
const int PHONE = 10;
int toNumber(char ch) {return ch - '0';}

struct TrieNode {
    TrieNode* children[PHONE];
    bool terminal;
    TrieNode() : terminal(false){
        memset(children, 0, sizeof(children));
    }

    ~TrieNode() {
        for (int i = 0; i < PHONE; ++i) {
            if(children[i]) {
                delete children[i];
            }
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {//입력받은 words가 '\0'일 경우, 즉 문자열 끝인 경우.
            terminal = true;
        } else {
            int next = toNumber(*key);
            if (children[next] == NULL) {
                children[next] = new TrieNode();
            }
            children[next]->insert(key+1);
        }
    }
    bool find(const char* key) {
        if(*key == '\0') return false;
        if(terminal) return true;

        int next = toNumber(*key);
        return children[next]->find(key+1);
    }
};

int t, n;
char arr[10001][11];
int main(void) {
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",&arr[i]);
        }
        TrieNode* root = new TrieNode();
        bool check = false;
        for (int i = 0; i < n; i++) {
            root->insert(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if(root->find(arr[i])) {
                check = true;
            }
        }
        printf("%s\n",check ? "NO" : "YES");
    }
    
    

    return 0;
}