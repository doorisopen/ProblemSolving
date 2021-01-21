class 카펫 {
    public int[] solution(int brown, int yellow) {
        int sum = brown + yellow;
        int w, h = 999999;
        for (w = (sum/3); w >= 3; w--) {
            if ((sum % w) == 0) {
                h = sum/w;
                int isBrown = (w+(h-2))*2;
                if (isBrown == brown) {
                    break;
                }
            }
        }
        return new int[]{w,h};
    }
}