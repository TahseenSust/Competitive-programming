int n, a[1002];
while(cin >> n){
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i]=a[i];
    if(i){
         sum[i]+=sum[i-1];
    }
  }

  for (int s = 1; s <= n; s++) {
    for (int l = 0; l + s - 1 < n; l++)
    {
      int r = l + s - 1;
      if (s == 1)
      {
        res[l][r] = 0;
        mid[l][r] = l;
        continue;
      }
      int mleft = mid[l][r - 1];
      int mright = mid[l + 1][r];
      res[l][r] = 1e18;
      for (int m = mleft; m <= mright; m++)
      {
        ll tmp = res[l][m-1] + res[m + 1][r] + SUM(l,r)-a[m];
        if (res[l][r] > tmp)
        {
          res[l][r] = tmp;
          mid[l][r] = m;
        }
      }
    }
  }
  ll ans = res[0][n - 1];
  cout << ans << endl;
}

