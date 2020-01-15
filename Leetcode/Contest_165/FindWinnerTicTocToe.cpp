class Solution {
public:
    string checkWinner(vector<vector<int>>& b) {
	for(int i=0;i<3;i++) {
		if(b[i][0] && b[i][0]==b[i][1] && b[i][1]==b[i][2]) return b[i][0]==1?"A":"B";
		if(b[0][i] && b[0][i]==b[1][i] && b[1][i]==b[2][i]) return b[0][i]==1?"A":"B";
	}
	if(b[0][0] && b[0][0]==b[1][1] && b[1][1]==b[2][2]) return b[0][0]==1?"A":"B";
	if(b[0][2] && b[0][2]==b[1][1] && b[1][1]==b[2][0]) return b[0][2]==1?"A":"B";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(b[i][j]==0) return "Pending";
	return "Draw";
}
string tictactoe(vector<vector<int>>& moves) {
	vector<vector<int>> board(3,vector<int>(3,0));
	for(int i=0;i<moves.size();i++) {
		int x = moves[i][0];
		int y = moves[i][1];
		if(i%2 == 0) board[x][y] = 1;
		else         board[x][y] = 2;
		string winner = checkWinner(board);
		if(winner == "A" || winner == "B") return winner;
	}
	return checkWinner(board);
}
};
