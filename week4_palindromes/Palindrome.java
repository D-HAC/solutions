import java.util.Scanner;

public class Palindrome {
	public static void main(String[] args) {	
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);

		while (true) {
			
			System.out.println("Enter text (Type a blank line to finish): ");
			String tmpStr = sc.nextLine();
			String str = "";

			while (!tmpStr.equals("")) {
				str = str + tmpStr;
				tmpStr = sc.nextLine();
			}

			//Actual code to check for a palindrome
			System.out.println(new StringBuilder(str.replaceAll("[^A-Za-z]", "").toLowerCase()).reverse().toString().equalsIgnoreCase(str.replaceAll("[^A-Za-z]", "").toLowerCase()) ? "It is a palindrome" : "It is not a palindrome");



			System.out.println("\n\nPress return to go again...");
			sc.nextLine();
			System.out.print("\n\n");
		}

	}
}
