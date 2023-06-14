class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         if(nums.size()==0){return 0;}
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){count++;}
        }
        /*The commented code works with swapping function and changes element from last
        int l=0;
        int h=nums.size()-1;
        int temp=0;
        while(temp<count){
            if(nums[h]==val){h--;temp++;}
            else if(nums[l]==val){swap(nums[l],nums[h]);temp++;h--;}
            else{l++;}
        }*/
        int l=0;
        int h=0;
        while(l<(nums.size()-count)){
            if(nums[h]==val){
                h++;
            }
            else{
                nums[l]=nums[h];
                l++;
                h++;
            }
        }

        return nums.size()-count;
    }
};