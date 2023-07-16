/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
const numSubarraysWithSum = (nums, goal) => {
    let i = 0, answer = 0
    while(i < nums.length){
        let j = i, sum = 0
        while(j < nums.length){
            if(nums[j] == 1) sum++
            if(sum == goal) answer++
            if(sum > goal) break
            j++
        }
        i++
    }
    return answer
}