/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const mp = {};
    for(const num of nums){
        if(!mp[num]) mp[num]=0;
        mp[num]++;
    }

    console.log(mp);

    for(const num of nums){
        if(mp[num]>=2) return true;
    }

    return false;
};