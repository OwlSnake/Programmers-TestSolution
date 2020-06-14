class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        List<Boolean> answer = new ArrayList<Boolean>();
        for(int c : candies){
            if(c > max){
                max = c;
            }
        }
        
        for(int c : candies){
            if(c >= max - extraCandies){
                answer.add(true);
            }
            else{
                answer.add(false);
            }
        }
        
        return answer;
    }
}