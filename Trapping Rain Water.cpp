class Solution {
    private int n;
    private int[] prefix(int[] height){

        int[] prefixMax = new int[n];
        prefixMax[0] = height[0];

        for(int i=1; i<n; i++){
            prefixMax[i] = Math.max(prefixMax[i-1], height[i]);
        }
        return prefixMax;
    }
    private int[] suffix(int[] height){

        int[] suffixMax = new int[n];
        suffixMax[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMax[i] = Math.max(suffixMax[i+1], height[i]);
        }
        return suffixMax;
    }
    public int trap(int[] height) {

        n = height.length;
        int total = 0;

        int[] pre = prefix(height);
        int[] suff = suffix(height);

        for(int i=0; i<n; i++){
            int leftMax = pre[i];
            int rightMax = suff[i];

            total += Math.min(leftMax, rightMax) - height[i];
        }
        return total;
    }
}
