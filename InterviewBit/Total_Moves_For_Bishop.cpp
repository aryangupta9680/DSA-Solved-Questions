int Solution::solve(int A, int B) {
    int count = 0;
    
    count += min(8-A,8-B);
    count += min(8-A,B-1);
    count += min(A-1,B-1);
    count += min(A-1,8-B);
    
    return count;
}