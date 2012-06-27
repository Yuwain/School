p1 = "hello"
p2 = "hello " ++ p1
p3 = map (+3)
p4 = foldr (*) 1
p5 x y = x, if x >= y
p5 x y = y, otherwise
p6 x y = x, if #x >= #y
p6 x y = y, otherwise
p7 0 = 0
p7 n = n + p7(n-1)
p8 [] = 0
p8 (x:xs) = 1 + p8 xs
p9 = p4 . map (p8)
p10 x = [y^2 | y <- x]
