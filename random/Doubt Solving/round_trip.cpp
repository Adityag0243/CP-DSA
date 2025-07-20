// //  discore id Maddy_10Nov 's code
// wrong....

// /* ------- Do everything you have to do, but not with ego, not with lust, not with envy but with love, compassion, humility, and devotion.” ― Lord Krishna --- */
 
// #include "bits/stdc++.h"
// using namespace std ;
// #define ll long long
// #define endl '\n'
// const int MOD = 1e9 + 7;
 
 
// // auto function_name = [&] (auto&&self,parameter1,.....) -> return_type {
// //     self(self,parameter1........) // recursive call)
// // };
 
// // //outside function call
// // function_name(function_name,parameter1......);
 
// template <typename T>
// void out(const std::vector<T>& vec) {
//     for (const auto& element : vec) {
//         cout << element << ' ';
//     }
//     cout << endl ;
// }
 
// const int INF = 0x3f3f3f3f; /* HexaDecimal */
// vector<int> ans;

// int start = -1;
// bool flag = true;

// void dfs(int node , int par , vector<int> adj[] , vector<bool>& used){
// 	if(used[node] ){
//         if(start == node)
//         {
//             ans.push_back(node);
//             flag = false;
//             return;
//         }
//         if(start == -1) start = node;
// 	    if(flag) ans.push_back(node);
// 		return ;
// 	}
// 	used[node] = true ;
// 	for(auto& u : adj[node]){
// 		if(u != par){
// 			dfs(u , node , adj , used);
// 		}
// 		if(ans.size() >= 1){
// 			break ;
// 		}
// 	}
// 	if(ans.size() >= 1){
// 		if(flag) ans.push_back(node);
//         else return;
// 	}
// }
 
// void test_case(){
// 	int n ,m ; cin >> n >> m;
// 	vector<int> adj[n];
// 	for(int i = 0 ;i < m ; i++){
// 		int a , b; cin >> a >> b ;
// 		a-- , b-- ;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}
	
// 	/* if graph contains cycle having edges >= 3 then it's possible */
	
// 	vector<bool> used(n , false);
// 	ans.clear();
	
// 	for(int i = 0 ;i < n ; i++){
// 		if(!used[i] && ans.empty()){
// 			dfs(i , -1 , adj , used);
// 		}
// 	}
	
// 	if(ans.empty()){
// 		cout << "IMPOSSIBLE";
// 	}else{
// 		cout << int(ans.size()) << endl ; 
// 		for(int x : ans) cout << x + 1 << ' ';
// 	}
// }
 
// int main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(nullptr);
// 	int T = 1;
// 	//cin >> T ;
// 	while(T--){
// 		test_case();
// 	}
// }