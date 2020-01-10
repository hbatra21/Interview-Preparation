class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		int n=friends.size();
		vector<int> visited(n,-1);
		vector<string> ans;
		queue<int> qu;
		qu.push(id);
		visited[id]=0;
		while(!qu.empty()){
			int cur=qu.front();
			qu.pop();
			for(auto v:friends[cur]){
				if(visited[v]!=-1) continue;
				visited[v]=visited[cur]+1;
				qu.push(v);
			}
		}
		unordered_map<string,int> table;
		for(int i=0;i<visited.size();i++){
			if(visited[i]==level){
				for(auto x:watchedVideos[i]){
					table[x]+=1;
				}
			}
		}

		vector<pair<int,string>> temp;
		for(auto v:table){
			temp.push_back({v.second,v.first});
		}

		sort(temp.begin(),temp.end());
		for(auto x:temp){
			ans.push_back(x.second);
		}
		return ans;
	}
};
