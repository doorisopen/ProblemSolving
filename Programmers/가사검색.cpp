/**
 * 2020 KAKAO BLIND RECRUITMENT
 * 가사검색
 */
#include <bits/stdc++.h>
using namespace std;
struct Trie {
    Trie* word[26];
    int count;
    bool end;
    Trie() : end(false), count(0) {
        memset(word, 0, sizeof(word));
    }
    ~Trie() {
        for (int i = 0; i < count; i++) {
            if(word[i]) delete word[i];
        }
    }
    void insert(const char* c) {
        if(*c == '\0') end = true;
        else {
            int next = *c - 'a';
            if(word[next] == nullptr) {
                word[next] = new Trie();
            }
            word[next]->count++;
            word[next]->insert(c+1);
        }
    }
    int find(const char* c) {
        //단어 전체가 ? 인경우
        if(*c == '?') {
            int curCnt = 0;
            for (int i = 0; i < 26; i++) {
                if(word[i] != nullptr) {
                    curCnt += word[i]->count;
                }
            }
            return curCnt;
        }
        if(word[*c-'a'] == nullptr) return 0;
        if(*(c+1) == '?') return word[*c-'a']->count;
        return word[*c-'a']->find(c+1);
    }
};

Trie* trie[10001];
Trie* retrie[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size());
    //input
    for (int i = 0; i < words.size(); i++) {
        int sz = words[i].size();

        //접두사 등록
        const char* c = words[i].c_str();
        if(trie[sz] == nullptr) trie[sz] = new Trie();
        trie[sz]->insert(c);

        //접미사 등록
        string reword = words[i];
        reverse(reword.begin(), reword.end());
        const char* rec = reword.c_str();
        if(retrie[sz] == nullptr) retrie[sz] = new Trie();
        retrie[sz]->insert(rec);
    }
    
    //search
    int count = 0;
    for (int i = 0; i < queries.size(); i++) {
        int sz = queries[i].size();
        //접두사 일때
        if(queries[i][sz-1] == '?') {
            const char* c = queries[i].c_str();
            if(trie[sz] == nullptr) continue;
            answer[i] = trie[sz]->find(c);
        }
        //접미사 일떄 
        else {
            string reword = queries[i];
            reverse(reword.begin(), reword.end());
            const char* rec = reword.c_str();
            if(retrie[sz] == nullptr) continue;
            answer[i] = retrie[sz]->find(rec);
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";        
    }
    
    return answer;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solution({"frodo", "front", "frost", "frozen", "frame", "kakao"},{"fro??", "????o", "fr???", "fro???", "pro?"});
    return 0;
}