/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(nums, newInterval) {
    let merged = []
    let n = nums.length
    let i;
    for(i=0;i<n;i++){
        if(nums[i][1] < newInterval[0]) merged.push(nums[i]);
        else if(newInterval[1] < nums[i][0]){
            break;
        }else{
            newInterval[0] = Math.min(nums[i][0],newInterval[0]);
            newInterval[1] = Math.max(nums[i][1],newInterval[1]);
        }
    }
    merged.push(newInterval);

    while(i<n) merged.push(nums[i++]);
    return merged;
};