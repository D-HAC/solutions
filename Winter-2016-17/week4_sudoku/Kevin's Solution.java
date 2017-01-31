	public static void main (String args[]) {
		//Enter puzzle with -1 being blank spaces
		int[][] board = new int[][]{
			{8,-1,5,-1,-1,7,-1,9,6},
			{-1,2,-1,9,5,-1,-1,8,-1},
			{-1,-1,-1,-1,2,-1,7,-1,4},
			{-1,1,2,-1,-1,-1,4,-1,-1},
			{-1,-1,8,4,-1,2,6,-1,-1},
			{-1,-1,9,-1,-1,-1,3,2,-1},
			{9,-1,1,-1,4,-1,-1,-1,-1},
			{-1,7,-1,-1,6,9,-1,3,-1},
			{5,3,-1,1,-1,-1,9,-1,2}
		};
		long start = System.currentTimeMillis();
		checkBoard(board);
		System.out.println("\nTime to solve: " + (System.currentTimeMillis() - start) + "ms");
	}

	//Recursively checks each board combination
	public static boolean checkBoard(int[][] board) {
		int[] tryPos = new int[2];
		boolean posFound = false;
		for (int x = 0 ; x < 9 && !posFound; x++) {
			for (int y = 0; y < 9 && !posFound; y++) {
				if (board[x][y] == -1) {
					tryPos = new int[]{x, y};
					posFound = true;
				}
			}
		}
		if (posFound) {
			for (int i = 1; i < 10; i++) {
				board[tryPos[0]][tryPos[1]] = i;
				if (goodTry(board, i, tryPos[0], tryPos[1])) {
					boolean test = checkBoard(board);
					if (test) {
						return true;
					}
				}
			}
			board[tryPos[0]][tryPos[1]] = -1;
			return false;
		}
		if (isValid(board)) {

			//Prints solution when found
			for (int x = 0 ; x < 9; x++) {
				for (int y = 0; y < 9; y++) {
					System.out.print(board[x][y] + " ");
				}
				System.out.println();
			}
			return true;
		}
		return false;
	}

	// Checks if a particular number makes sense in the spot
	public static boolean goodTry(int[][] board, int val, int x, int y) {
		int rowStart = (x / 3) * 3;
		int colStart = (y / 3) * 3;
		for (int i = 0; i < 9; i++) {
			if (board[x][i] == val) {
				if( i != y) {
					return false;
				}
			}
			if (board[i][y] == val) {
				if (i != x) {
					return false;
				}
			}
		}
		for (int i = rowStart; i < rowStart + 3; i++) {
			for (int j = colStart; j < colStart + 3; j++) {
				if (board[i][j] == val) {
					if (i != x && j != y) {
						return false;
					}
				}
			}
		}
		return true;
	}

	//Checks if board is solved
	public static boolean isValid(int[][] board) {
		for(int i = 0; i < 9; i++) {
			if (!checkCol(board[i])) {
				return false;
			}
			if (!checkRow(board,i)) {
				return false;
			}
			if (!checkBox(board,i)) {
				return false;
			}
		}
		return true;
	}

	//Checks if column makes sense
	public static boolean checkCol(int[] col) {
		boolean[] isFound = new boolean[10];
		for (int value : col) {
			if (isFound[value]) {
				return false;
			}
			isFound[value] = true;
		}
		return true;
	}

	//Checks if row makes sense
	public static boolean checkRow(int[][] board, int y) {
		boolean[] isFound = new boolean[10];
		for (int i = 0; i < 9; i++) {
			int value = board[i][y];
			if (isFound[value]) {
				return false;
			}
			isFound[value] = true;
		}
		return true;
	}

	//Checks if 3x3 box makes sense
	public static boolean checkBox(int[][] board, int boxNum) {
		boolean[] isFound = new boolean[10];
		int colStart = boxNum / 3 * 3;
		int rowStart = (boxNum - colStart) * 3;
		for (int x = colStart; x < colStart + 3; x++) {
			for (int y = rowStart; y < rowStart + 3; y++) {
				int value = board[x][y];
				if (isFound[value]) {
					return false;
				}
			}
		}
		return true;
	}
