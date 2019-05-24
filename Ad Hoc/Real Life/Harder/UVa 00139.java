import java.util.Scanner;
import java.util.HashMap;
class Main
{
	private static class Locality{
		String name;
		int price;
		private Locality(String name,int price)
		{
			this.name = name;
			this.price = price;
		}
	}


	static HashMap<String,Locality> codes = new HashMap<>();

	static String[] splitNumber(String number)
	{
		for(String code : codes.keySet()) {
			if(code.length()<=number.length())
			{
				String subsNumber = number.substring(code.length());
				if(number.charAt(1) == '0') {
					if(subsNumber.length()<4 || 10<subsNumber.length()) continue;
				} else {
					if(subsNumber.length()<4 || 7<subsNumber.length()) continue;
				}
				String numberCode = number.substring(0,code.length());
				if(numberCode.equals(code))
				{
					String[] ret = {code,subsNumber};
					return ret;
				}
			}
		}
		return null;
	}

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		
		while(true)
		{
			String code = scan.next();
			if(code.equals("000000"))break;
		 	scan.useDelimiter("\\$");
		 	String name = scan.next().substring(1);
		 	scan.reset();
		 	int price = Integer.parseInt(scan.next().split("\\$")[1]);
			codes.put(code,new Locality(name,price));
		}
		while(true)
		{
			String number = scan.next();
			if(number.equals("#"))break;
			int minutes = scan.nextInt();

			System.out.printf("%-16s",number);
			String[] parts = splitNumber(number);

			boolean isLocal = number.charAt(0) != '0';
			boolean isUnknown = parts == null;
			if(isLocal)
				System.out.printf("%-25s%10s","Local",number);
			else if(isUnknown)
				System.out.printf("%-35s","Unknown");
			else
				System.out.printf("%-25s%10s",codes.get(parts[0]).name,parts[1]);
			
			System.out.printf("%5s",String.valueOf(minutes));

			if(isLocal)
				System.out.println("  0.00   0.00");
			else if(isUnknown)
				System.out.println("        -1.00");
			else
				{
					int price = codes.get(parts[0]).price * minutes;
					System.out.printf("%3d.%02d",codes.get(parts[0]).price/100,codes.get(parts[0]).price%100);
					System.out.printf("%4d.%02d\n",price/100,price%100);
				}

		}
	}
}
