import java.io.*;

public class A4 {
static BufferedReader $br;
static BufferedWriter $bw;
static double $tmp_real;

public static void main(String[] args) throws Exception {
int X;
X = 3;
if (X == 3) {
$br = new BufferedReader(new FileReader("A41.input"));
X = new Integer($br.readLine()).intValue();
}
else {
}
$tmp_real = X + 100;
$bw = new BufferedWriter(new FileWriter("A4.output"));
$bw.write("" + $tmp_real);
$bw.close();
}
}
