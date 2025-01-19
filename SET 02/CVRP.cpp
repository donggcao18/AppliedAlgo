#include <bits/stdc++.h>
using namespace std;

#define maxN 13
#define maxQ 50
#define maxK 6

int n, K, Q,  nbSegment;
int f;
int f_min;
int d[maxN], c[maxN][maxN];
bool used[maxN];
int x[maxN], y[maxN]; //y[k]= khach hang dau tien xe k
int load[maxN]; // loadK = tai trong tich luy route K

void input() {
	cin >> n>>K>>Q;
	for (int i =1; i<=n; i++) cin >> d[i];
	for (int j = 0; j<=n; j++)
		for (int k = 0; k<=n; k++) cin>>c[j][k];
}

bool checkY(int v, int k) { // gia tri v co the gan cho y[k] hay khong
	if (load[k]+d[v] > Q) return false;
	return true;
}

bool checkX(int v, int i, int k) { // gia tri v cos the gan cho x[i] tren xe k hay khong
	if (v==0) return true;
	if (load[k]+d[v] > Q) return false;
	if (used[v]==true) return false;
	return true;
}

void Solution() {
	//update f_min neu can
	if (f < f_min) f_min = f; 
}

void TryX(int i, int k, int K2) {
	for (int v=0; v <= n; v++) {
		if (checkX(v,i,k)) {
			x[i] = v;
			
			load[k] += d[v]; 
			nbSegment ++;
			f+=c[i][v];
			used[v] = true;
			
			if (v==0) { // ve 0
				if (k == K2) { 
					if (nbSegment == n+k) Solution();
				} else {
					TryX(y[k+1], k+1, K2);
				}
			} else {
				TryX(v,k, K2);
			}
			//tra bien ve trang thai cu
			
			load[k] -= d[v];
			nbSegment --;
			f-=c[i][v];
			used[v] = false;
			
		}
	}
}

void TryY(int k, int K2) { // thu gia tri cho y[k]
	for(int v = y[k-1]+1; v<=n-K+k; v++) {
		if (checkY(v,k)) {
			y[k] = v;
			nbSegment++;
			used[v] = true;
			load[k] += d[v];
			f+=c[0][v];
			
			if(k == K2) TryX(y[1],1, K2);
		 	else TryY(k+1, K2);
		 	//tra bien ve trang thai cu
			nbSegment --;
			load[k] -= d[v];
			used[v] = false;
			f-=c[0][v];
		}
	}
}

int main() {
	input();
	f=0; nbSegment =0; f_min =1e9;
	for (int i =1; i<=n; i++) used[i] =false;
	for (int j =1; j<=K; j++) load[j] =0;
	
	for (int k =1; k<=K; k++) TryY(1, k);
	cout<<f_min;
	return 0;
}
