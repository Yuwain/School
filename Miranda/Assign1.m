p1 = 19
p2 = "Jeremy High"
p3 x = 2 * x
p4 x y = x, if x >= y
       = y, otherwise
p5 = map (*2)
p6 x = x!0
p7 = foldr (*) 1
p8 0 = 1
p8 x = x * p8 (x-1)
p9 x y = x -- (x -- y)
rev x y = y ++ [x]
p10 = foldr rev []
p11 0 = "True"
p11 1 = "False"
p11 x = p11 (x-2)
p12_1 (x,y) = x
p12 = foldr (+) 0 . map p12_1