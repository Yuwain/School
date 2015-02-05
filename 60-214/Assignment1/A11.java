import java.io.*;
import java.util.*;

public class A11 {
	public static void main(String[] args) {
		int identifierCount = 0, i;

		boolean addToList;

		String line;
		String[] identifierList = new String[100], keyWords = {"IF", "INT", "BEGIN", "RETURN", "MAIN", "READ", "WRITE", "END", "REAL", "ELSE"};

		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A1.output")));

			while ((line = in.readLine()) != null) {
				if (line.contains("\"")) {
					int start = line.indexOf("\"");
					int end = line.lastIndexOf("\"") + 1;

					if (start == end)
						line = line.replace("\"", " ");
					else
						line = line.replace(line.subSequence(start, end), " ");
				}

				StringTokenizer st = new StringTokenizer(line, " ;()*,[]#@$%^&~`_'<>?+-/!=:\t\n\r\f");

				while (st.hasMoreTokens()) {
					addToList = true;
					line = st.nextToken();


					if (Character.isLetter(line.charAt(0))) {
						for (i = 0; i < 10;)
							if (line.equals(keyWords[i++]))
								addToList = false;

						for (i = 0; i < identifierCount;)
							if (line.equals(identifierList[i++]))
								addToList = false;

						if (addToList)
							identifierList[identifierCount++] = line;
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
