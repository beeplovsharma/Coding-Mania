/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    nums.sort((a,b)=>a-b)
    let n = nums.length
    let st = new Set();
    
    for(let i=0;i<n-3;i++){
        for(let j=i+1;j<n-2;j++){
            const ntar = target - nums[i] - nums[j];
            let l = j+1
            let r = n-1
            while(l<r){
                if(nums[l]+nums[r]<ntar) l++
                else if(nums[l]+nums[r]>ntar) r--
                else{
                    st.add([nums[i],nums[j],nums[l],nums[r]].toString());
                    l++
                    r--
                }
            }
        }
    }

    let ans = []
    for(const triplet of st){
        ans.push(triplet.split(',').map(Number));
    }
    return ans
};