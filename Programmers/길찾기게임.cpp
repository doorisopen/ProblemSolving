/**
 * 2019 KAKAO BLIND RECRUITMENT
 * 길찾기게임
 * 
 * //==접근방법==//
 * x좌표 기준으로 오름차순으로 정렬한다.
 * 그 이유는 y좌표의 최대값은 최상단 루트노드에 해당하는데 정렬 이후 
 * y좌표가 최대가 되는 idx기준으로 왼쪽 자식과 오른쪽 자식을 구분하기 위해서이다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

struct Tree {
    int data;
    Tree *left, *right;
};

vector<pair<pi,int>> info;//좌표, 노드번호
vector<int> res;
void pre(Tree *node) {
    if(node == NULL) return;
    res.push_back(node->data);
    pre(node->left);
    pre(node->right);
}
void post(Tree *node) {
    if(node == NULL) return;
    post(node->left);
    post(node->right);
    res.push_back(node->data);
}
Tree *makeTree(int s, int e) {
    if(s > e) return NULL;
    //최상단 노드를 찾는다.
    int mx = info[s].first.second, mxP = s;
    for (int i = s+1; i <= e; i++) {
        if(mx < info[i].first.second) {
            mx = info[i].first.second;
            mxP = i;
        }
    }
    //make node
    Tree *node = new Tree();
    node->data = info[mxP].second;
    node->left = makeTree(s,mxP-1);
    node->right = makeTree(mxP+1,e);    
    return node;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for (int i = 0; i < nodeinfo.size(); i++) {
        info.push_back({{nodeinfo[i][0],nodeinfo[i][1]},i+1});
    }
    sort(info.begin(),info.end());
    
    //make tree
    Tree *tree = makeTree(0,info.size()-1);
    pre(tree);
    answer.push_back(res);
    res.clear();
    post(tree);
    answer.push_back(res);
    return answer;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}});
    return 0;
}