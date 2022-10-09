/* 
Also note that, since large numbers can cause inaccuracies in floating point computation,
we should use binary search to find the floor-value of a square root,
instead of using the sqrt function in any language.
*/

ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}
