import java.util.*;
class 베스트앨범 {
    public static class Album implements Comparable<Album> {
        int id;
        int plays;
        Album (int id, int plays) {
            this.id = id;
            this.plays = plays;
        }
        
        @Override
        public int compareTo(Album album) {
            if (this.plays < album.plays) {
                return 1;
            } else if (this.plays == album.plays) {
                if (this.id < album.id) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return -1;
        }
    }
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        int length = genres.length;
        Map<String, Integer> genresCount = new HashMap<>();
        Map<String, List<Album>> genresSet = new HashMap<>();
        for (int i = 0; i < length; i++) {
            if (genresCount.containsKey(genres[i])) {
                genresCount.put(genres[i], genresCount.get(genres[i])+plays[i]);
            } else {
                genresCount.put(genres[i], plays[i]);
            }
            genresSet.computeIfAbsent(genres[i], V->new ArrayList<>()).add(new Album(i, plays[i]));
        }
        List<String> genresCountKeyList = new ArrayList<>(genresCount.keySet());
        Collections.sort(genresCountKeyList, (o1,o2)->(genresCount.get(o2).compareTo(genresCount.get(o1))));
        // 가장 많이 재생된 장르 순서
        List<Integer> albumList = new ArrayList<>();
        for (String key : genresCountKeyList) {
            // 장르 내에서 재생 수 내림차순 and 고유 번호 오름차순
            List<Album> album = genresSet.get(key);
            Collections.sort(album);
            for (int i = 0; i < album.size(); i++) {
                if (i > 1) break;
                albumList.add(album.get(i).id);
            }
        }
        int albumSize = albumList.size();
        answer = new int[albumSize];
        for (int i = 0; i < albumSize; i++) {
            answer[i] = albumList.get(i);
        }
        return answer;
    }
}
