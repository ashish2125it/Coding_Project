/* The functions which
builds the segment tree */
void build(int node, int s, int e, int arr[], int st[]){
  if(s==e){
    st[node] = arr[s];
    return;
  }
  
  int m = s + (e-s)/2;
  
  build(2*node+1, s, m, arr, st);
  build(2*node+2, m+1, e, arr, st);
  
  st[node] = min(st[2*node+1], st[2*node+2]);
  return;
}

int minq(int node, int s, int e, int l, int r, int st[]){
  if(s>r || e<l) return INT_MAX;
  if(s>=l && e<=r) return st[node];
  if(s==e) return INT_MAX;      
  
  int m = s + (e-s)/2;
  
  int left = minq(2*node+1, s, m, l, r, st);
  int right = minq(2*node+2, m+1, e, l, r, st);
  
  return min(left, right);
}


int* constructST(int arr[], int n){
  int *st = new int[4*n+1];
  build(0, 0, n-1, arr, st);
  return st;  
}

int RMQ(int st[], int n, int a, int b){
  return minq(0, 0, n-1, a, b, st);      
}
