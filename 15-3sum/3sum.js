/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a,b)=>a-b)
    let n = nums.length
    let st = new Set()
    let tar = 0;
    for(let i=0;i<n;i++){
        let ntar = tar-nums[i]
        let l = i+1
        let r = n-1

        while(l<r){
            if(nums[l]+nums[r]<ntar) l++;
            else if(nums[l]+nums[r]>ntar) r--;
            else{
                st.add([nums[i],nums[l],nums[r]].toString());
                l++;
                r--;
            }
        }
    }
    let ans = []
    for(let triplet of st){
        ans.push(triplet.split(',').map(Number));
    }
    return ans;
};