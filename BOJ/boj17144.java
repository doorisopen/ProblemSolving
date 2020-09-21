/*
 * 17144 미세먼지 안녕!
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class boj17144 {
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	static int[][] board;
	public static void p(int r, int c) {
		System.out.println("====result===");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				System.out.print(board[i][j]+" ");
			}
			System.out.println();
		}
	}
	public static void dustSpread(int r, int c) {
		//현재 먼지 위치 저장
		ArrayList<info> dustP = new ArrayList<>();
		int[][] dustBoard = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				dustBoard[i][j] = board[i][j];
				if(board[i][j] > 0) {
					dustP.add(new info(i,j));
				}
			}
		}

		for (int i = 0; i < dustP.size(); i++) {
			int x = dustP.get(i).x;
			int y = dustP.get(i).y;
			ArrayList<info> spreadP = new ArrayList<>();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if(board[nx][ny] == -1) continue;
				spreadP.add(new info(nx,ny));
			}
			int spraedVal = board[x][y]/5;
			for (int j = 0; j < spreadP.size(); j++) {
				int nx = spreadP.get(j).x;
				int ny = spreadP.get(j).y;
				dustBoard[nx][ny] += spraedVal;
			}
			dustBoard[x][y] -= (spraedVal * spreadP.size());
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				board[i][j] = dustBoard[i][j];
			}
		}
	}
	public static void machineRun(ArrayList<info> machineP, int r, int c) {
		//반시계
		int rx = machineP.get(0).x;//시작위치
		int ry = machineP.get(0).y;
		int rcx = rx, rcy = ry;//현재위치
		for (int dir = 0; dir < 4; dir++) {
			while(true) {
				int nx = rcx + dx[dir];
				int ny = rcy + dy[dir];
				if(nx < 0 || nx > rx || ny >= c) break;
				if(nx == rx && ny == ry) break;
				if(board[rcx][rcy] == -1) {
					board[nx][ny] = 0;
				} else {
					board[rcx][rcy] = board[nx][ny];
					board[nx][ny] = 0;
				}
				rcx = nx;
				rcy = ny;
			}
		}


		//시계
		int x = machineP.get(1).x;
		int y = machineP.get(1).y;
		int cx = x, cy = y;//현재위치
		for (int dir = 0; dir < 4; dir++) {
			while(true) {
				int nx, ny;
				if(dir%2 == 0) {
					nx = cx - dx[dir];
					ny = cy - dy[dir];
				} else {
					nx = cx + dx[dir];
					ny = cy + dy[dir];
				}
				if(nx >= r || nx < x || ny >= c) break;
				if(nx == x && ny == y) break;
				if(board[cx][cy] == -1) {
					board[nx][ny] = 0;
				} else {
					board[cx][cy] = board[nx][ny];
					board[nx][ny] = 0;
				}
				cx = nx;
				cy = ny;
			}
		}

	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		//input
		String[] inputString = br.readLine().split(" ");
		int[] RCT = new int[inputString.length];
		for (int i = 0; i < RCT.length; i++) {
			RCT[i] = Integer.parseInt(inputString[i]);
		}
		int r = RCT[0], c = RCT[1], t = RCT[2];
		board = new int[r][c];
		ArrayList<info> machineP = new ArrayList<>();
		for (int i = 0; i < r; i++) {
			String[] row = br.readLine().split(" ");
			for (int j = 0; j < row.length; j++) {
				board[i][j] = Integer.parseInt(row[j]);
				if(board[i][j] == -1) {
					machineP.add(new info(i,j));
				}
			}
		}
		//run
		while(t-- > 0) {
			dustSpread(r,c);
			machineRun(machineP, r, c);
		}
		int res = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if(board[i][j] > 0) {
					res += board[i][j];
				}
			}
		}
		System.out.println(res);
		br.close();
	}
	public static class info {
		int x,y;
		public info(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}