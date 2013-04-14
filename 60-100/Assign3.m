||Class test 1 - 2010
p1 = ["Hello", "Goodbye"]
p2 = p1!1
p3 = map (3:)
p4_1 (x,y) rest = x * rest
p4 = foldr (p4_1) 1
p5 x y = "Lengths greater than 2", if #x >2 & #y >2
p5 x y = "Not greater than 2", otherwise
p6 x y = x, if x!0 >= y!0
p6 x y = y, otherwise
p7 0 = [0]
p7 n = n: p7(n - 1)
p8 [] = []
p8 (x:xs) = (x + 3): p8 xs
square n = n^2
p9 = square . sum . map square
p10 n = [m!0 | m <- n]
||2.1 a) ['d','f','t']
||    b) [(3,'w')]
||2.2 a) s   t = {x | x   s & x   t}
||    b) s   t = True iff  x x    s -> x    t
||2.3

||Class test 1 - 2006
p11 = "Hello"
p12 = p11 ++ " " ++ p11
p13 = map (+3)
p14 = foldr (*) 1
p15 x y = x, if x > y
p15 x y = y, otherwise
p16 x y = x, if #x > #y
p16 x y = y, otherwise
p17 0 = 0
p17 n = n + p17 (n - 1)
p18 [] = 0
p18 (x:xs) = 1 + p18 xs
p19 = p14 . map p18
p20 n = [m^2 | m <- n] 
