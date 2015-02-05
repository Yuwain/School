import java.io.*;
import java.util.regex.*;

public class A12 {
	public static void main(String[] args) {
		int identifierCount = 0, i, n;
		boolean addToList, b = Pattern.compile("[ ;,():!=/#\\[\\]\\*\\+\\-\\s]+").matcher("aa").matches();
		String line;
		String[] identifierList = new String[100], keyWords = {"IF", "INT", "BEGIN", "RETURN", "MAIN", "READ", "WRITE", "END", "REAL", "ELSE"}, word;
		
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A1.output")));
		
			while ((line = in.readLine()) != null) {
				line = line.replaceAll("\".*\"", " ");
				word = line.split("[ ;,():!=/#\\[\\]\\*\\+\\-\\s]+");

				for (n = 0; n < word.length; n++) {
					addToList = true;
					
					if (word[n].matches("^[A-Za-z]+|^[A-Za-z]\\w+")) {
						for (i = 0; i < 10;) {
							if (word[n].matches(keyWords[i++]))
								addToList = false;
						}
				
						for (i = 0; i < identifierCount;) {
							if (word[n].matches(identifierList[i++]))
								addToList = false;
						}
				
						if (addToList)
							identifierList[identifierCount++] = word[n];
					}
				}
			}

			out.println("Identifiers: " + identifierCount);
			in.close();
			out.close();
		}
		catch (Exception e) { }
	}
}
