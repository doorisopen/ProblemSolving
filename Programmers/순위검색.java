import java.util.*;
class 순위검색 {
    static String[] datas;
    static List<Integer>[][][][] board = new ArrayList[4][3][3][3];
    public static int[] solution(String[] info, String[] query) {
        int infoSize = info.length;
        int querySize = query.length;
        int[] answer = new int[querySize];
        //init
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int j2 = 0; j2 <= 2; j2++) {
                    for (int k = 0; k <= 2; k++) {
                        board[i][j][j2][k] = new ArrayList<>();
                    }
                }
            }
        }
        
        datas = new String[infoSize];
        for (int i = 0; i < infoSize; i++) {
            String[] temp = info[i].split(" ");
            datas[i] = setData(temp);
            setBoard(datas[i]);
        }
        //sort
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int j2 = 0; j2 <= 2; j2++) {
                    for (int k = 0; k <= 2; k++) {
                        Collections.sort(board[i][j][j2][k]);
                    }
                }
            }
        }
        
        //search
        for (int i = 0; i < querySize; i++) {
            String[] temp = query[i].split(" ");
            String[] temp2 = new String[5];
            int idx = 0;
            for (int j = 0; j < temp.length; j++) {
                if (temp[j].equals("and")) continue;
                temp2[idx++] = temp[j];
            }
            String data = setData(temp2);
            answer[i] = checkBoard(data);
        }
        return answer;
    }

    public static String setData(String[] temp) {
        String datas = "";
        if (temp[0].equals("cpp")) {
            datas += "1";
        } else if (temp[0].equals("java")) {
            datas += "2";
        } else if (temp[0].equals("python")){
            datas += "3";
        } else {
            datas += "0";
        }
        if (temp[1].equals("backend")) {
            datas += "1";
        } else if (temp[1].equals("frontend")) {
            datas += "2";
        } else {
            datas += "0";
        }
        if (temp[2].equals("junior")) {
            datas += "1";
        } else if (temp[2].equals("senior")) {
            datas += "2";
        } else {
            datas += "0";
        }
        if (temp[3].equals("chicken")) {
            datas += "1";
        } else if (temp[3].equals("pizza")) {
            datas += "2";
        } else {
            datas += "0";
        }
        return datas+temp[4];
    }

    public static void setBoard(String data) {
        int d1 = Integer.parseInt(Character.toString(data.charAt(0)));
        int d2 = Integer.parseInt(Character.toString(data.charAt(1)));
        int d3 = Integer.parseInt(Character.toString(data.charAt(2)));
        int d4 = Integer.parseInt(Character.toString(data.charAt(3)));
        int d5 = Integer.parseInt(data.substring(4));
        board[d1][0][0][0].add(d5);
        board[d1][d2][0][0].add(d5);
        board[d1][0][d3][0].add(d5);
        board[d1][0][0][d4].add(d5);
        board[d1][d2][d3][0].add(d5);
        board[d1][d2][0][d4].add(d5);
        board[d1][0][d3][d4].add(d5);
        board[d1][d2][d3][d4].add(d5);
        board[0][d2][0][0].add(d5);
        board[0][d2][d3][0].add(d5);
        board[0][d2][0][d4].add(d5);
        board[0][d2][d3][d4].add(d5);
        board[0][0][d3][0].add(d5);
        board[0][0][d3][d4].add(d5);
        board[0][0][0][d4].add(d5);
        board[0][0][0][0].add(d5);
    }

    public static int checkBoard(String info) {
        int i1 = Integer.parseInt(Character.toString(info.charAt(0)));
        int i2 = Integer.parseInt(Character.toString(info.charAt(1)));
        int i3 = Integer.parseInt(Character.toString(info.charAt(2)));
        int i4 = Integer.parseInt(Character.toString(info.charAt(3)));
        int i5 = Integer.parseInt(info.substring(4));
        List<Integer> nums = board[i1][i2][i3][i4];
        return lowerbound(nums, i5);
    }

    public static int lowerbound(List<Integer> nums, int target) {
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            int middle = (begin + end) / 2;
            if (nums.get(middle) >= target) {
                end = middle;
            } else {
                begin = middle + 1;
            }
        }
        return nums.size()-end;
    }
}