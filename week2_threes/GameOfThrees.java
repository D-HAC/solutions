public class GameOfThrees
{
	public static void main(String[] args)
	{
		int x = Integer.parseInt(args[0]);
		while(x > 1)
		{
		switch(x%3)
			{
				case 0:
					System.out.printf("%d/3\n", x);
					x = x/3;
					break;
				case 1:
					System.out.printf("%d - 1\n", x);
					x = x-1;
					break;
				case 2: 
					System.out.printf("%d + 1\n", x);
					x = x+1;
					break;
			}
		}
	}
}