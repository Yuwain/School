p1 = [7,8,9]
p2 = 6:p1
p3_1 x = True, if x > 4
p3_1 x = False, otherwise
p3 y = map p3_1 y
p4 x = foldr (&) True x
p5 x y = "Yes", if x+y>5
p5 x y = "No" , otherwise
p6 x y = x, if x!0 >= y!0
p6 x y = y, otherwise
p7 [] = 0
p7 (x:xs) = x + p7 xs
p8 [] = 0
p8 (x:xs) = 1 + p8 xs
p9 = p4 . (map p4) . (map p3)
p10_1 (x,y) = (x*y)
p10 n =[m | m <- (map p10_1 n)]
