import java.util.Scanner;
class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		String input = scan.next();
		String output;int c = 1;
		while(!input.equals("#"))
		{
			if(input.equals("HELLO"))output = "ENGLISH";
			else if(input.equals("HALLO"))output = "GERMAN";
			else if(input.equals("BONJOUR"))output = "FRENCH";
			else if(input.equals("CIAO"))output = "ITALIAN";
			else if(input.equals("ZDRAVSTVUJTE"))output = "RUSSIAN";
			else if(input.equals("HOLA"))output = "SPANISH";
			else output = "UNKNOWN";
			System.out.println("Case "+(c++)+": "+output);
			input = scan.next();
		}
	}
}
