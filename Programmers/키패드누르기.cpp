#include <string>
#include <vector>

using namespace std;
int pad[4][3] = {{1,2,3},
                 {4,5,6},
                 {7,8,9},
                 {-1,0,-2}};
int myhand[2][2] = {{3,0},
                    {3,2}};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int i = 0; i < numbers.size(); i++) {
        // cout << myhand[0][0] << ", "<< myhand[0][1] << " // " << myhand[1][0] << ", " << myhand[1][1] << "\n";
        int click = numbers[i];
        if(click == 1 || click == 4 || click == 7) {
            for(int j = 0; j < 4; j++) {
                if(pad[j][0] == click) {
                    myhand[0][0] = j;
                    myhand[0][1] = 0;
                }
            }
            answer += "L";
        } else if(click == 3 || click == 6 || click == 9) {
            for(int j = 0; j < 4; j++) {
                if(pad[j][2] == click) {
                    myhand[1][0] = j;
                    myhand[1][1] = 2;
                }
            }
            answer += "R";
        } else if(click == 2 || click == 5 || click == 8 || click == 0){// middle
            int l, r, search = 0;
            for(int j = 0; j < 4; j++) {
                if(pad[j][1] == click) {
                    search = j;
                }
            }
            l=abs(myhand[0][0]-search) + abs(myhand[0][1]-1);
            r=abs(myhand[1][0]-search) + abs(myhand[1][1]-1);
            if(l == r) {// l, r 위치 동일할때
                if(hand == "right") {
                    myhand[1][0] = search;
                    myhand[1][1] = 1;
                    answer += "R";
                } else {
                    myhand[0][0] = search;
                    myhand[0][1] = 1;
                    answer += "L";
                }           
            } else if(l > r) {
                myhand[1][0] = search;
                myhand[1][1] = 1;
                answer += "R";
            } else {
                myhand[0][0] = search;
                myhand[0][1] = 1;
                answer += "L";                    
            }
        }
    }
    return answer;
}