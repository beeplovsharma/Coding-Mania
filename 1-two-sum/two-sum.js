/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let mp = {};

    for(let i=0;i<nums.length;i++){
        let curr = nums[i]
        let toFind = target-curr;

        if(mp[toFind]!==undefined) return [mp[toFind],i]
        mp[curr] = i;
    }

    return -1;
};