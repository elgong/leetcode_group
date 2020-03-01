```java
// leetcode42 接雨水
// 思路：  中间的所有点，向前后遍历找到最高的两个柱子A,B, min(A，B)-now 就是此点的蓄水，小于0则无法蓄水

// time:  O(N^2)   space:  O(1) 


class Solution {
    public int trap(int[] height) {

        if(height==null || height.length <= 2){
            return 0;
        }
        int sumOfWater = 0;
        
        for(int i=1; i<=height.length-1; i++){

            // 记住当前高度
            int now = height[i];

            // 向前找到更高的值
            int leftMaxHight = 0;
            for(int left=i-1; left>=0; left--){
                if(height[left] > now){
                    leftMaxHight = Math.max(height[left], leftMaxHight);
                }
            }

            // 向后找到最高的值
            int rightMaxHight = 0;
            for(int right=i+1; right<height.length; right++){
                if(height[right] > now){
                    rightMaxHight = Math.max(height[right], rightMaxHight);
                }
            }

            // 能蓄水时，才会统计
            if(Math.min(rightMaxHight, leftMaxHight) > now){
                sumOfWater += (Math.min(rightMaxHight, leftMaxHight) - now);
            }


        }


        return sumOfWater;
    }
}


/*
    执行用时 :
            335 ms
            , 在所有 Java 提交中击败了
            5.09%
            的用户
            内存消耗 :
            38.5 MB
            , 在所有 Java 提交中击败了
            9.30%
            的用户
*/
```

