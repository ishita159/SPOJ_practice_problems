#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
const int inf = 0x7fffffff;
using namespace std;
ll ul,lol;
void print(ll arr[],int n,int k,ll upplmt)
{
	int slcount[500],c=0; // to record where '/' will b put
	ll sum=0;
	vector <int > v;
	int cnt = 1;
	for(int i=n-1;i>-1;i--)
	{
		if(sum+arr[i] > upplmt || i == k-cnt-1)
		{
			sum=0;
			v.pb(-1);
			cnt++;
		}
		sum+=arr[i];
		v.pb(arr[i]);
	}
	reverse(v.begin(),v.end());
	int l = v.size();
	for(int i=0;i<l;i++)
	{
		if(v[i] == -1 )
			printf("/ ");
		else
			cout << v[i] << " ";
	}
	cout << endl;
}
bool ok(ll arr[],int n,ll p,int k)
{
	int cnt = 1;
	ll sum=0;
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i] > p)
		{
			cnt = inf;
			break;
		}
		if(sum + arr[i] > p)
		{
			cnt++;
			sum=0;
		}
		sum += arr[i];
	}
	//cout << cnt << endl;
	return (cnt <= k);
}
void binary(ll arr[],int n,int k)
{
	ll low = lol;
	ll high = ul;
	while(low < high)
	{
		ll mid = low + (high - low)/2;
		if(ok(arr,n,mid,k))
			high = mid;
		else
			low = mid+1;
	} 
	
	//cout << high << endl;
	print(arr,n,k,high);
}
int main()
{
	int t,n,k;
	ll arr[505],sum=0;
	cin >> t;
	while(t--)
	{	sum=0;
		cin >> n >> k;
		ul=0;
		lol=inf;
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
			ul+=arr[i];
			if(lol>arr[i])
				lol=arr[i];
		}
		binary(arr,n,k);
	}
	return 0;
}