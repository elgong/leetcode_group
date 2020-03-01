```java
// leetcode42 ����ˮ
// ˼·��  �м�����е㣬��ǰ������ҵ���ߵ���������A,B, min(A��B)-now ���Ǵ˵����ˮ��С��0���޷���ˮ

// time:  O(N^2)   space:  O(1) 


class Solution {
    public int trap(int[] height) {

        if(height==null || height.length <= 2){
            return 0;
        }
        int sumOfWater = 0;
        
        for(int i=1; i<=height.length-1; i++){

            // ��ס��ǰ�߶�
            int now = height[i];

            // ��ǰ�ҵ����ߵ�ֵ
            int leftMaxHight = 0;
            for(int left=i-1; left>=0; left--){
                if(height[left] > now){
                    leftMaxHight = Math.max(height[left], leftMaxHight);
                }
            }

            // ����ҵ���ߵ�ֵ
            int rightMaxHight = 0;
            for(int right=i+1; right<height.length; right++){
                if(height[right] > now){
                    rightMaxHight = Math.max(height[right], rightMaxHight);
                }
            }

            // ����ˮʱ���Ż�ͳ��
            if(Math.min(rightMaxHight, leftMaxHight) > now){
                sumOfWater += (Math.min(rightMaxHight, leftMaxHight) - now);
            }


        }


        return sumOfWater;
    }
}


/*
    ִ����ʱ :
            335 ms
            , ������ Java �ύ�л�����
            5.09%
            ���û�
            �ڴ����� :
            38.5 MB
            , ������ Java �ύ�л�����
            9.30%
            ���û�
*/
```

