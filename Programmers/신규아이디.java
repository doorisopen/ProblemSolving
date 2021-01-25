import java.util.*;
class 신규아이디 {
    public String solution(String new_id) {
        String answer = toLowerCase(new_id); // 1
        answer = removeCharacter(answer); // 2
        answer = mergeOne(answer); // 3
        answer = removeStartAndEnd(answer); // 4
        answer = isIdEmpty(answer); // 5
        answer = isIdLengthMoreThan16(answer); // 6
        answer = isIdLengthBelow2(answer); // 7
        return answer;
    }
    
    public static String toLowerCase(String id) {
        return id.toLowerCase();
    }
    
    public static String removeCharacter(String id) {
        String regex = "abcdefghijklnmopqrstuvwxyz0123456789-_.";
        List<String> regexs = Arrays.asList(regex.split(""));
        String new_id = "";
        for (int i = 0; i < id.length(); i++) {
            String str = Character.toString(id.charAt(i));
            if (regexs.contains(str)) {
                new_id += str;
            }
        }
        return new_id;
    }

    public static String mergeOne(String id) {
        String new_id = Character.toString(id.charAt(0));
        for (int i = 1; i < id.length(); i++) {
            String cur = Character.toString(id.charAt(i));
            if (new_id.charAt(new_id.length()-1) != '.' || !cur.equals(".")) {
                new_id += cur;
            }
        }
        return new_id;
    }

    public static String removeStartAndEnd(String id) {
        int idLength = id.length();
        if (idLength == 0) return id;
        if (id.charAt(0) == '.') {
            id = id.substring(1, idLength);
        }
        idLength = id.length();
        if (idLength == 0) return id;
        if (id.charAt(idLength-1) == '.') {
            id = id.substring(0, idLength-1);
        }
        return id;
    }

    public static String isIdEmpty(String id) {
        return id.length() == 0 ? id+"a" : id;
    }

    public static String isIdLengthMoreThan16(String id) {
        id = id.length() >= 16 ? id.substring(0, 15) : id;
        if (id.charAt(id.length()-1) == '.') {
            id = id.substring(0, id.length()-1);
        }
        return id;
    }

    public static String isIdLengthBelow2(String id) {
        while (id.length() <= 2) {
            id += id.charAt(id.length()-1);
        }
        return id;
    }
}