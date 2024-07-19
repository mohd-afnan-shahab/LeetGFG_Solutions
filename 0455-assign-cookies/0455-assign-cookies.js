/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);

    let l = 0, r = 0;
    while(l < s.length && r < g.length){
        if(s[l] >= g[r]){
            r++;
        }
        l++;
    }
    return r;

};